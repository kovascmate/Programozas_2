#ifndef STRING_HPP
#define STRING_HPP
#include <string.h>
#include <iostream>
#include "memtrace.h"

/////////////////////////////////////////////////////////////////////
///  String osztaly segitsegevel taroljuk el az adatokat melyek szoveges formatumuak.
//
//Függvények:
//          -konstruktor
//          -destruktor
//          -strmasol:{
//                      ez a fuggveny bemeneten kapott char* tartalmat masolja at egy egy masik char* ba}
//          -getdata:{
//                      ez a fuggveny visszaadja a String altal tarolt szoveg kezdo pointeret}
//          -getmeret:{
//                      ez a fuggveny visszaadja a String altal tarolt adat meretet}
//          -print:{
//                      jelenleg ez a fuggveny felesleges, elavult}
//          -operator[]:{
//                      ennek az operatornak a segitsegevel lehetoseg lesz a String egy adott karakteret elerni, kereso fuggvenyhez szukseges}
//          -operator==:{
//                      kereso fuggveny prototipusakent van jelenleg elkepzelve}
//          -operator<<:{
//                      ennek az operatornak a segitsegevel lesz lehetseges kiiratni egy adott Stringet, kulonbozo ostreamekre}
/////////////////////////////////////////////////////////////////////

class String{
	int meret;
	char* szoveg;
public:
        static String nd;
        String(){}
        String(const String&  input)
        {
            std::cout<<"STRING MASOLO\n";
            std::cout<<input.szoveg;
            szoveg = new char[input.meret];
            strcpy(szoveg,input.szoveg);

            meret = input.meret;
        }
        String& operator=(const String& s) {
            if (this != &s ) {
                delete[] szoveg;
                szoveg = new char[s.meret];
                strcpy(szoveg, s.szoveg);
                meret = s.meret;
            }
            return *this;
        }

        String(const char* input)
        {
            std::cout<<"string konst\n";
            std::cout<<input<<"\n";
            meret = strlen(input) + 1;
            szoveg = new char[meret];
            strcpy(szoveg,input);
        }

        ~String(){
            std::cout<<"string destr\n";
            std::cout<<this->szoveg<<"\n";
            std::cout<<this->meret<<"\n";
            delete[] this->szoveg;
        }
	    void strmasol(char* ebbe,const char* ezt){
	        std::cout<<"strmasol\n";
            int i = 0;
            do
            {

                ebbe[i] = ezt[i];
                i++;
            }while(ezt[i] != '\0');
            ebbe[i] = '\0';
        }
	    char* getdata() const {return szoveg;}
	    int     getmeret() const  {return meret;}
        char operator[] (int i) const
        {
            return szoveg[i];
        }
        bool operator!=(String const input)const
        {
            if(this->getmeret() != input.getmeret())
            {
                return false;
            }
            for(int i = 0; i< this->getmeret();i++)
            {
                if(this->szoveg[i] != input[i])
                {
                    return false;
                }
            }
            return true;
        }
};
std::ostream& operator<<(std::ostream& os, String const & str);

bool matches(const String& alap, const String& beadott);


#endif // STRING_HPP
