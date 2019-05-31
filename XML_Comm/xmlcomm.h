#ifndef XMLCOMM_H
#define XMLCOMM_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QDataStream>
#include <QDomDocument>
#include <QDir>
#include <QtXmlPatterns>

//---------------------------------------------------------------------------------------
/// <summary>
/// MessageReceivedEventArgs
/// Public class for interfacing with MainForm
/// </summary>
//---------------------------------------------------------------------------------------
class MessageReceivedEventArgs
{
  public:
    QString Message;
    QString MessageName;
    QString Info;

    enum MessageType_e
    {
     CommandMsg,
     DeviceConfigurationMsg
    };

    MessageReceivedEventArgs(QString msg, QString msg_name, QString info)
    {
     Message = msg;
     MessageName = msg_name;
     Info = info;
    }

}; // End MessageReceivedEventArgs class

//---------------------------------------------------------------------------------------
// Handler is used in validation process
//---------------------------------------------------------------------------------------
class MessageHandler : public QAbstractMessageHandler
{
public:
    MessageHandler()
        : QAbstractMessageHandler(0)
    {
    }

    QString statusMessage() const
    {
        return m_description;
    }

    int line() const
    {
        return m_sourceLocation.line();
    }

    int column() const
    {
        return m_sourceLocation.column();
    }

protected:
    virtual void handleMessage(QtMsgType type, const QString &description,
                               const QUrl &identifier, const QSourceLocation &sourceLocation)
    {
        Q_UNUSED(type);
        Q_UNUSED(identifier);

        m_description = description;
        m_sourceLocation = sourceLocation;
    }

private:
    QString m_description;
    QSourceLocation m_sourceLocation;
};


//---------------------------------------------------------------------------------------
/// <summary>
/// SEIWGComm_c
/// Primary TCP/IP & XML comm class
/// </summary>
//---------------------------------------------------------------------------------------
class XMLComm : public QObject
{
    Q_OBJECT

    QTcpSocket *tcpSocket;
    qint16 port;
    QDataStream in;
    QString msgBuffer;
    QString currXML;
    QString rootNode;

public:
    explicit XMLComm(QObject *parent = nullptr);
    XMLComm(quint16 port, QObject *parent = nullptr);

    virtual ~XMLComm();

    void openSocket(quint16 &port);

private:
    Q_SLOT void readData();
    bool validateMsg(QString msg);

public:
    Q_SIGNAL void OnDeviceStatusReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnDeviceConfigurationReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnDeviceDetectionReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnDeviceInitializationMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnGeometryReportMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnCommandMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnInvalidMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnPlatformDetectionReportMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnPlatformStatusReportMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnSubscriptionConfigurationMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnTrackReportMsgReceived(MessageReceivedEventArgs &);
    Q_SIGNAL void OnMsgSent(MessageReceivedEventArgs &);


};

#endif // XMLCOMM_H
