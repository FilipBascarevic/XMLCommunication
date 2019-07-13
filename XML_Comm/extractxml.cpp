#include "extractxml.h"

extractXML::extractXML(QObject *parent) : QObject(parent)
{
    // Create new reader
    XMLReader = new QXmlStreamReader;

    longitude = 0.0;
    latitude = 0.0;
}

extractXML::~extractXML(){
    delete XMLReader;

    longitude = 0.0;
    latitude = 0.0;
}

Q_SLOT void extractXML::onDeviceStatusReceived(const MessageReceivedEventArgs &curr_XML) {

    XMLReader->addData(curr_XML.Message);

    //Parse the XML until we reach end of it
    while(!XMLReader->atEnd() && !XMLReader->hasError()) {
        // Read next element
        QXmlStreamReader::TokenType token = XMLReader->readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument) {
                continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement) {

            if(XMLReader->name() == "Latitude") {
                latitude = XMLReader->readElementText().toDouble();
                qDebug() << "Latitude : " << latitude << endl;
            }
            if(XMLReader->name() == "Longitude") {
                longitude = XMLReader->readElementText().toDouble();
                qDebug() << "Longitude : " << longitude << endl;
            }

        }
    }

    if(XMLReader->hasError()) {
        qDebug() << XMLReader->errorString();
        return;
    }

    //clear reader
    XMLReader->clear();

    return;

}


