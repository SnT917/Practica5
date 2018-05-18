#include <iostream>
#include <math.h>
#define G 1/*6.67384*pow(10,-11)*/
#include <planeta.h>

using namespace std;

//Métodos de asignación de valores a las variables.
float Planeta::getX() const
{
    return x;
}

void Planeta::setX(float value)
{
    x = value;
}

float Planeta::getY() const
{
    return y;
}

void Planeta::setY(float value)
{
    y = value;
}

float Planeta::getAx() const
{
    return ax;
}

void Planeta::setAx(float value)
{
    ax = value;
}

float Planeta::getAy() const
{
    return ay;
}

void Planeta::setAy(float value)
{
    ay = value;
}

float Planeta::getVx() const
{
    return vx;
}

void Planeta::setVx(float value)
{
    vx = value;
}

float Planeta::getVy() const
{
    return vy;
}

void Planeta::setVy(float value)
{
    vy = value;
}

float Planeta::getMasa() const
{
    return masa;
}

void Planeta::setMasa(float value)
{
    masa = value;
}

float Planeta::getRadio() const
{
    return radio;
}

void Planeta::setRadio(float value)
{
    radio = value;
}

void Planeta::aceleracion(Planeta planeta){ //Método de acelaración, distancia y ángulo.
    float Distancia, Aceleracion, Angulo;

    Distancia = distancia(planeta.getX(), planeta.getY());
    Angulo = angulo(planeta.getX(), planeta.getY());
    Aceleracion = G*planeta.getMasa()/Distancia;
    ax = Aceleracion*cos(Angulo);
    ay = Aceleracion*sin(Angulo);
}

float Planeta::distancia(float xi, float yi){ //Método de distancia.
    float Distancia;

    Distancia = pow((xi - x), 2) + pow((yi - y), 2);
    return Distancia;

}

float Planeta::angulo(float xi, float yi){ //Método de angulo.
    float Angulo;

    Angulo = (yi - y)/(xi - x);
    Angulo = atan2((yi-y), (xi-x));
    return Angulo;

}

void Planeta::posicion(){ //Posición.
    x = x + vx + 0.5 * ax;
    y = y + vy + 0.5 * ay;
    vx = ax;
    vy = ay;

}

Planeta::Planeta():x(0),y(0),vx(0),vy(0),masa(0){
    masa = 0;
    ax = 0;
    ay = 0;
}

Planeta::Planeta(float _x, float _y, float _vx, float _vy, float _masa, float _radio): x(_x),y(_y),vx(_vx),vy(_vy),masa(_masa){
    radio=_radio;
}
