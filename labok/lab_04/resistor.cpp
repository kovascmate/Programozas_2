/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"
#include <limits>
#include <cmath>
void Resistor::setDef(double r)
{
    defR = r;
    //Pr("ctor0");
}
double Resistor::defR = 7;
Resistor::Resistor()
{
    R=defR;
    //Pr(ctor1);
}
Resistor::Resistor(double r)
{
    this->R = r;
    //Pr(ctor1);
}
Resistor Resistor::operator+(const Resistor& r) const
{
    return Resistor(this->R+r.R);
    //Pr(ctor1);
}
Resistor Resistor::operator%(const Resistor& r) const
{
    return Resistor(1/((1/this->R)+(1/r.R)));
    //Pr(ctor1);
}
Resistor operator*(int n, const Resistor& r)
{
    //Pr(ctor1);
    if(n<=0)
    {
        throw "IB72D1";
    }
    return (r.getR()*n);
}
Resistor::Resistor(const Resistor& rhs):R(rhs.R)
{
    //Pr("Copy");
}
Resistor::~Resistor(){
    //Pr("dtor");
}
Resistor& Resistor::operator=(const Resistor& r)
{
    //Pr("assign");
    this->R = r.R;
    return *this;
}
double Resistor::getU(double i)const
{
    return i * this->R;
}
double Resistor::getI(double u)const
{
    return u/this->R;
}/*
bool Resistor::operator==(const Resistor& r)const
{

    double kicsi =10 * std::numeric_limits<double>::epsilon();
    double elso = fabs(r.R)/1000;
    double masodik = fabs(this->R/1000);
    double diff = fabs(elso-masodik);
    if(this->R==r.R)
    {
        return true;
    }
    else if(diff<=kicsi)
    {
        return true;
    }
    else
    {
        return false;
    }
    if (elso < masodik) {
        elso = masodik;
        masodik = fabs(elso);
    }
    return (elso - masodik) < elso * kicsi;
}*/



