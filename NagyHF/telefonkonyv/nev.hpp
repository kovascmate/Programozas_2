#ifndef NEV_HPP
#define NEV_HPP
#include "memtrace.h"
#include "string.hpp"




/////////////////////////////////////////////////////////////////////
///  Nev osztaly tarolja majd a felhasznalok neveit a String osztaly segitsegevel
//
//Fuggvenyek:
//          -konstruktor
//          -destruktor
//          -getvezetek:{
//                          ennek a fuggvenynek a segitsegevel tudjuk majd elerni az adott Nevjegyek vezetekneveit}
//          -getkereszt:{
//                          ennek a fuggvenynek a segitsegevel tudjuk majd elerni az adott Nevjegyek keresztneveit}
//          -getbece:{
//                          ennek a fuggvenynek a segitsegevel tudjuk majd elerni az adott Nevjegyek beceneveit}
//          -kiir{
//                          jelenleg ez a fuggveny felesleges, listazas prototipusakent volt eltervezve}
/////////////////////////////////////////////////////////////////////
class Nev{
	String vezetek;
	String kereszt;
	String becenev;
	public:
        String getvezetek()const         {return vezetek;}
        String getkereszt()const         {return kereszt;}
        String getbece()   const         {return becenev;}
        //Nev()                            {std::cout<<"nev konst\n";}
        Nev(String& vez= String::nd, String& ker= String::nd,String& bec= String::nd):vezetek(vez),kereszt(ker),becenev(bec){}
        //Nev(String& vez, String& ker,String& bec):vezetek(vez),kereszt(ker),becenev(bec){}
        ~Nev()                  {std::cout<<"nev dest\n";}
        void operator=(Nev const input)
        {
            this->becenev = input.becenev;
            this->kereszt = input.kereszt;
            this->vezetek = input.vezetek;
        }
};
#endif // NEV_HPP
