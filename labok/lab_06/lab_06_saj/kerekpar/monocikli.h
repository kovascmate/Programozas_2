#ifndef MONOCIKLI_H
#define MONOCIKLI_H
#include "monocikli.h"
class  Kerek{
    int atmero;
    public:
        Kerek(){std::cout << "\tKerek ctor\n";}
        Kerek(int ertek)  {this->atmero =   ertek; std::cout << "\tKerek ctor\n";}
        ~Kerek() { std::cout << "\tKerek dtor\n";}
        Kerek(const Kerek& k){ this->atmero = k.atmero; std::cout<< "\tKerek copy\n"<<std::endl;}
        void kiir(){ std::cout << "atmero=" << atmero << std::endl; }

};
class  Monocikli{
    Kerek k;
    public:
        Monocikli() :k(16){std::cout<<"\tMonocikli ctor\n";}
        Monocikli(const Monocikli& m){this->k = m.k; std::cout<<"\tMonocikli copy\n"<<std::endl;}
        void kiir(){ std::cout << "\tk."; k.kiir(); }
};
#endif
