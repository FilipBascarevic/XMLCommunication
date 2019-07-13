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
    tcpServer = new QTcpServer;

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if(!tcpServer->listen(QHostAddress("192.168.224.1"), port))
        qDebug() << "<DataReceiver> Server could not start. ";
    else
        qDebug() << "<DataReceiver> Server started !";

    qDebug() << tcpServer->serverPort();
    qDebug() << tcpServer->serverAddress();

    port_m = port;

    //qDebug() << "onNewConnection called !";
    //tcpSocket = tcpServer->nextPendingConnection();

    //connect(tcpSocket, SIGNAL(readyRead()),    this, SLOT(readData()));
    //connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
}

void XMLComm::onNewConnection(){
    qDebug() << "onNewConnection called !";
    tcpSocket = tcpServer->nextPendingConnection();

    connect(tcpSocket, SIGNAL(readyRead()),    this, SLOT(readData()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));

    if (tcpSocket -> waitForConnected()) {
        qDebug("Connected!!!");

    }
    else {
        qDebug("Not Connected!!!");
        qDebug() << tcpSocket->errorString();
    }
}

void XMLComm::onConnect()
{
    qDebug() << "connected...";

}

void XMLComm::onDisconnect(){
    qDebug() << "QTcpSocket disconnected...";
    disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    disconnect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
}

Q_SLOT void XMLComm::readData()
{

    qDebug("readReady is occurred!!!");
    //
    QByteArray nextRead;

    //QByteArray readData = ;

    //qDebug() << readData;

    nextRead = tcpSocket -> readAll();

    // concatenate previous message and new read
    msgBuffer = msgBuffer.append(nextRead);

    //qDebug() << msgBuffer;

    //try to find ENDOFXML in msgBuffer
    int idx = msgBuffer.indexOf("<ENDOFXML/>");

    // if in msgBugger is found ENDOFXML then make substring with xml
    while (idx >= 0) {

        // Grab everything up to ENDOFXML as a message
        currXML = msgBuffer.mid(0, idx);

        if (validateMsg(currXML)) {
            // Prepare to dispatch based on identity of root tag
            MessageReceivedEventArgs args (currXML, rootNode, "");

            // DeviceStatusReport
            if (rootNode == "DeviceStatusReport") {
                emit DeviceStatusReceived(args);
                qDebug() << "DeviceStatusReport";
            }
            // DeviceConfiguration
            else if (rootNode == "DeviceConfiguration") {
                emit OnDeviceConfigurationReceived(args);
                qDebug() << "DeviceConfiguration";
            }
            // DeviceDetectionReport
            else if (rootNode == "DeviceDetectionReport") {
                emit OnDeviceDetectionReceived(args);
                qDebug() << "DeviceDetectionReport";
            }
            else if (rootNode == "CommandMessage") {
               emit OnCommandMsgReceived(args);
               qDebug() << "CommandMessage";
            }
            else if (rootNode == "DeviceInitialization") {
               emit OnDeviceInitializationMsgReceived(args);
               qDebug() << "DeviceInitialization";
            }
            else if (rootNode == "GeometryReport") {
               emit OnGeometryReportMsgReceived(args);
               qDebug() << "GeometryReport";
            }
            else if (rootNode == "PlatformDetectionReport") {
               emit OnPlatformDetectionReportMsgReceived(args);
               qDebug() << "PlatformDetectionReport";
            }
            else if (rootNode == "PlatformStatusReport") {
               emit OnPlatformStatusReportMsgReceived(args);
               qDebug() << "PlatformStatusReport";
            }
            else if (rootNode == "SubscriptionConfiguration") {
               emit OnSubscriptionConfigurationMsgReceived(args);
               qDebug() << "SubscriptionConfiguration";
            }
            else if (rootNode == "TrackReport") {
               emit OnTrackReportMsgReceived(args);
               qDebug() << "TrackReport";
            }

        }
        else
        // Invalid message
        {
            MessageReceivedEventArgs args(currXML, "", "");
            emit OnInvalidMsgReceived(args);
            qDebug() << "InvalidMsgReceived";
        }

        // remove current XML from buffer
        msgBuffer.remove(0, idx+11);

        // In rest of buffer try to find ENDOFXML again
        idx = msgBuffer.indexOf("<ENDOFXML/>");
    }


}

bool XMLComm::validateMsg(QByteArray msg)
{
    // Convert XML string to QDomDocument
    QDomDocument doc;
    if (!doc.setContent(msg)) {
        qDebug("XML is not valid!!!");
        return false;
    }

    // get root of current XML
	QDomElement root = doc.documentElement();
	rootNode = root.tagName();
	//rootNode = doc.documentElement().text();
    // find path to schema files
    QDir schema_dir = QDir::current();
	schema_dir.cdUp();
    schema_dir.cd("Schema");

    QString schema_path = schema_dir.path() + "/" + rootNode + ".xsd";

    //QString schema_path = "C:/Users/cofib/Desktop/simple_shema.xsd";

    // open current schema
    QFile schemaFile(schema_path);
    if (!schemaFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open" << QDir::toNativeSeparators(schema_path)
            << ':' << schemaFile.errorString();
        return false;
    }

    // read schemaFile with readAll(). Read caracters are in a Ucf8 format
    //const QByteArray schemaData = schemaFile.readAll();

    // convert msg to Ucf8 format
    //const QByteArray instanceData = msg.toUtf8();

    // instance of handler
    MessageHandler messageHandler;

    QXmlSchema schema;

    schema.setMessageHandler(&messageHandler);
    // load to schema schema data
    if (schema.load(&schemaFile, QUrl::fromLocalFile(schemaFile.fileName())) == true)
        qDebug() << "schema is valid";
    else
        qDebug() << "schema is invalid";

    bool errorOccurred = false;
    // is schema valid
    if (!schema.isValid()) {
        errorOccurred = true;
    } else {
        // validate schema
        QXmlSchemaValidator validator(schema);
        if (!validator.validate(msg))
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
