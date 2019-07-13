#ifndef EXTRACTXML_H
#define EXTRACTXML_H

#include <QObject>
#include <QXmlStreamReader>
#include "received_args.h"

class extractXML : public QObject
{
    Q_OBJECT
public:
    explicit extractXML(QObject *parent = nullptr);
    ~extractXML();


public:
    Q_SLOT void onDeviceStatusReceived(const MessageReceivedEventArgs &curr_XML);

 public:
    double longitude;
    double latitude;
    QXmlStreamReader *XMLReader;
};

#endif // EXTRACTXML_H
