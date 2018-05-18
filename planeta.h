#ifndef PLANETA_H
#define PLANETA_H
#include <iostream>
#include <math.h>
#define G 1/*6.67384*pow(10,-11)*/

#endif // PLANETA_H

using namespace std;

class Planeta{
    float x, y; //Posición.
    float vx, vy; //Velocidad en posición.
    float ax, ay; //Aceleración en posición.
    float masa, radio; //Masa y radio.

public:
    Planeta(); //Constructor.
    Planeta(float _x, float _y, float _masa, float _radio, float _vx, float _vy);
    ~Planeta(){} //Destructor.

    //Get
    float getX() const;
    float getY() const;
    float getMasa() const;
    float getRadio() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;

    //Set
    void setX(float value);
    void setY(float value);
    void setMasa(float value);
    void setRadio(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);

    void aceleracion(Planeta planeta);
    float distancia(float x, float y);
    float angulo(float x, float y);
    void posicion();


};
