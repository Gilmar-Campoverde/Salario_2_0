#include "principal.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Ingles" << "Japones";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL, "Idioma", "Seleccione un idioma", idiomas);
    QTranslator traduccion;
    // Dependiendo del idioma seleccionado, carga el archivo de traducción
    if (idiomaSeleccionado == "Ingles"){
        traduccion.load(":/traducciones/Salario_2_0_en_US.qm");
    }else if (idiomaSeleccionado == "Japones"){
        traduccion.load(":/traducciones/Salario_2_0_ja_JA.qm");
    }else{
        traduccion.load(":/traducciones/Salario_2_0_es_EC.qm");
    }
    a.installTranslator(&traduccion);

    Principal w;
    w.show();

    return a.exec();
}
