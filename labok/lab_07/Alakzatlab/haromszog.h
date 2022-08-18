/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#ifndef HAROMSZOG_H
#define HAROMSZOG_H
#include "alakzat.h"
/// Ügyeljen arra, hogy a csúcspontokat az alaposztály orgiójához relatívan tárolja!

class Haromszog : public Alakzat{

    Pont p1;
    Pont p2;
        public:
            Haromszog(const Pont& p0, const Pont& p1, const Pont& p2,const Szin& sz) :Alakzat(p0,sz),p1(p1),p2(p2){}
            Pont getp1() const {return p1;}
            Pont getp2() const {return p2;}
            void rajzol() const;
};

std::ostream& operator<<(std::ostream& os, const Haromszog& a);
#endif // KOR_H

