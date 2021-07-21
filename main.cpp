#include "principal.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;
    // Dependiendo del idioma seleccionado, carga el archivo de traducción
    traduccion.load(":/Traducciones/Salario_2_0" + QLocale::system().name() + ".qm");
    a.installTranslator(&traduccion);

    Principal w;
    w.show();

    return a.exec();
}
