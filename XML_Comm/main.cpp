#include <QCoreApplication>
#include "xmlcomm.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XMLComm comm(4444);

    return a.exec();
}
