#include <QCoreApplication>
#include "xmlcomm.h"
#include "extractxml.h"
#include <QThread>

class Thread final : public QThread { public: ~Thread() { quit(); wait(); } };

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //qRegisterMetaType<MessageReceivedEventArgs>();
    qRegisterMetaType<MessageReceivedEventArgs>();

    Thread receiveThread;

    XMLComm comm(4444);
    extractXML extr;

    receiveThread.start();
    comm.moveToThread(&receiveThread);

    QObject::connect(&comm, &XMLComm::DeviceStatusReceived, &extr, &extractXML::onDeviceStatusReceived);

    return a.exec();
}
