#include "xmlcomm.h"

XMLComm::XMLComm(QObject *parent) : QObject(parent)
{
    tcpSocket = nullptr;
    port_m = 0;
}

XMLComm::XMLComm(quint16 port, QObject *parent) : QObject(parent)
{
    openSocket(port);
}

XMLComm::~XMLComm()
{
    tcpSocket->disconnectFromHost();

    tcpSocket = nullptr;
    port_m = 0;
}

void XMLComm::openSocket(quint16 &port)
{
    tcpSocket = new QTcpSocket;

    // connect readReady signal to method for reading
    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    QObject::connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));

    // be sure that socket is unused
    tcpSocket->abort();

    // set buffer size to 4kB
    tcpSocket -> setReadBufferSize(4096);

    // connect socket
    //tcpSocket->setProxy(QNetworkProxy::NoProxy);
    QHostAddress address("192.168.224.1");
    tcpSocket->bind(address, port);
    port_m = port;
    tcpSocket -> connectToHost(tcpSocket ->localAddress(), tcpSocket ->localPort());
    qDebug() << tcpSocket ->localAddress();
    qDebug() << tcpSocket ->localPort();

    if (tcpSocket -> waitForConnected()) {
        qDebug("Connected!!!");

        in.setDevice(tcpSocket);
        in.setVersion(QDataStream::Qt_4_0);

    }
    else {
        qDebug("Not Connected!!!");
        qDebug() << tcpSocket->errorString();
        // release socket
        tcpSocket -> abort();
    }
}

void XMLComm::connected()
{
    qDebug() << "connected...";

}

Q_SLOT void XMLComm::readData()
{

    in.startTransaction();
    //
    QString nextRead;
    in >> nextRead;

    // concatenate previous message and new read
    msgBuffer = msgBuffer % nextRead;

    //try to find ENDOFXML in msgBuffer
    int idx = msgBuffer.indexOf("<ENDOFXML/>");

    // if in msgBugger is found ENDOFXML then make substring with xml
    if (idx >= 0) {
        // Grab everything up to ENDOFXML as a message
        currXML = msgBuffer.mid(0, idx);

        if (validateMsg(currXML)) {
            // Prepare to dispatch based on identity of root tag
            MessageReceivedEventArgs args (currXML, rootNode, "");

            // DeviceStatusReport
            if (rootNode == "DeviceStatusReport") {
                emit OnDeviceStatusReceived(args);
            }
            // DeviceConfiguration
            else if (rootNode == "DeviceConfiguration") {
                emit OnDeviceConfigurationReceived(args);
            }
            // DeviceDetectionReport
            else if (rootNode == "DeviceDetectionReport") {
                emit OnDeviceDetectionReceived(args);
            }
            else if (rootNode == "CommandMessage") {
               emit OnCommandMsgReceived(args);
            }
            else if (rootNode == "DeviceInitialization") {
               emit OnDeviceInitializationMsgReceived(args);
            }
            else if (rootNode == "GeometryReport") {
               emit OnGeometryReportMsgReceived(args);
            }
            else if (rootNode == "PlatformDetectionReport") {
               emit OnPlatformDetectionReportMsgReceived(args);
            }
            else if (rootNode == "PlatformStatusReport") {
               emit OnPlatformStatusReportMsgReceived(args);
            }
            else if (rootNode == "SubscriptionConfiguration") {
               emit OnSubscriptionConfigurationMsgReceived(args);
            }
            else if (rootNode == "TrackReport") {
               emit OnTrackReportMsgReceived(args);
            }

        }
    }
    else
    // Invalid message
    {
        MessageReceivedEventArgs args(currXML, "", "");
        emit OnInvalidMsgReceived(args);
    }


}

bool XMLComm::validateMsg(QString msg)
{
    // Convert XML string to QDomDocument
    QDomDocument doc;
    if (!doc.setContent(msg)) {
        qDebug("XML is not valid!!!");
        return false;
    }

    // get root of current XML
    rootNode = doc.documentElement().text();
    // find path to schema files
    QDir schema_dir = QDir::current();
    schema_dir.cd("../Schema");
    QString schema_path = schema_dir.currentPath() + "/" + rootNode + ".xsd";

    // open current schema
    QFile schemaFile(schema_path);
    if (!schemaFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open" << QDir::toNativeSeparators(schema_path)
            << ':' << schemaFile.errorString();
        return false;
    }

    // read schemaFile with readAll(). Read caracters are in a Ucf8 format
    const QByteArray schemaData = schemaFile.readAll();
    // convert msg to Ucf8 format
    const QByteArray instanceData = msg.toUtf8();

    // instance of handler
    MessageHandler messageHandler;

    QXmlSchema schema;
    schema.setMessageHandler(&messageHandler);

    // load to schema schema data
    schema.load(schemaData);

    bool errorOccurred = false;
    // is schema valid
    if (!schema.isValid()) {
        errorOccurred = true;
    } else {
        // validate schema
        QXmlSchemaValidator validator(schema);
        if (!validator.validate(instanceData))
            errorOccurred = true;
    }

    if (errorOccurred) {
        qDebug() << messageHandler.statusMessage();
    }
    else {
        qDebug("Validation successful");
    }

    return !errorOccurred;


}
