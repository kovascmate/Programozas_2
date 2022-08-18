/**
 *  \file haromszog.cpp
 *  Haromszog osztály tagfüggvényeinek megvalósítása
 */
#include "haromszog.h"
void Haromszog::rajzol() const
{
    std::cout<<"Rajzol: "<<*this<<std::endl;
}
std::ostream& operator<<(std::ostream& os, const Haromszog& a)
{
    return os<<"Haromszog "<<(Alakzat&)a<<",p1="<<a.getp1()<<",p2="<<a.getp2();
}
