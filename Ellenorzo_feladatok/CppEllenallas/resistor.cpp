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
void Resistor::setDef(double r)
{
    defR = r;
}
double Resistor::defR = 7;
Resistor::Resistor()
{
    R=defR;
}
Resistor::Resistor(double r)
{
    this->R = r;
}
Resistor Resistor::operator+(const Resistor& r) const
{
    return Resistor(this->R+r.R);
}
Resistor Resistor::operator%(const Resistor& r) const
{
    return Resistor(1/((1/this->R)+(1/r.R)));
}
Resistor operator*(int n, const Resistor& r)
{
    if(n<=0)
    {
        throw "IB72D1";
    }
    return (r.getR()*n);
}
