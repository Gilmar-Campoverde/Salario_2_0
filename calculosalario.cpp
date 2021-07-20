#include "calculosalario.h"

float CalculoSalario::salarioBruto() const{
    return m_salarioBruto;
}
float CalculoSalario::descuento() const{
    return m_descuento;
}
float CalculoSalario::salarioNeto() const{
    return m_salarioNeto;
}

QString CalculoSalario::getJornada(){
    switch(trabajadores->jornada()){
    case 'V':
        return tr("Vespertina");
        break;
    case 'M':
        return tr("Matutina");
        break;
    case 'N':
        return tr("Nocturna");
        break;
    }
    return "N/D";
}

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent){
}

CalculoSalario::CalculoSalario(Trabajadores &trabajadores)
{
    this->trabajadores = &trabajadores;
}

void CalculoSalario::calcular(){
    float  valorHora = 0;
    switch(trabajadores->jornada()){
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }
    m_salarioBruto = trabajadores->horas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO /100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

QString CalculoSalario::resultado(){
    QString str;
    str = tr("Obrero: %1").arg(trabajadores->nombre() + "\n");
    str += tr("Horas: %1").arg(QString::number(trabajadores->horas())) + "\n";
    str += tr("Jornada: %1").arg(getJornada())+ "\n";
    str += tr("Salario Bruto: $ %1").arg(QString::number(m_salarioBruto)) + "\n";
    str += tr("Descuento: $ %1").arg(QString::number(m_descuento)) + "\n";
    str += tr("Salario Neto: $ %1").arg(QString::number(m_salarioNeto)) + "\n\n";
    return str;
}
