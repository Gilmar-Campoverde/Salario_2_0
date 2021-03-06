QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca.cpp \
    calculosalario.cpp \
    main.cpp \
    principal.cpp \
    trabajadores.cpp

HEADERS += \
    acerca.h \
    calculosalario.h \
    principal.h \
    trabajadores.h

FORMS += \
    acerca.ui \
    principal.ui

TRANSLATIONS += \
    Salario_2_0_es_EC.ts \
    Salario_2_0_en_US.ts \
    Salario_2_0_ja_JA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Recursos.qrc \
    Recursos.qrc
