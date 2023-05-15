#include <QApplication>

#include "vuepartie.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    VuePartie partie;
    partie.show();

    return app.exec();

}
