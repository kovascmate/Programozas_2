#include "nevjegy.hpp"
#include "kontakt.hpp"
#ifndef LANCOLTLISTA_HPP
#define LANCOLTLISTA_HPP
#include <iostream>
#include "memtrace.h"

template <typename T>
class Lista
{
    struct Listaelem
    {
        T listadata;
        Listaelem* kovetkezo = nullptr;
    };
    Listaelem* eleje;
    int listameret;
public:
    Lista()
    {
        std::cout<<"lista konst\n";
        eleje = nullptr;
        listameret = 0;
    }
    ~Lista()
    {
        auto lemarado = eleje;
        auto mozgo = eleje;
        while(mozgo->kovetkezo != nullptr)
        {
            lemarado = mozgo;
            mozgo = mozgo->kovetkezo;
            delete lemarado;
        }
        delete mozgo;
    }
    T& operator[](const int& index)
    {
        std::cout<<"index operator";
        //hibakezeles
        int i = 0;
        Listaelem* mozgo = this->eleje;
        while(mozgo->kovetkezo != nullptr || i != index)
        {
            i++;
            mozgo = mozgo->kovetkezo;
        }
        return mozgo->listadata;
    }
    void pushback( T& val)
    {
        std::cout<<"pushback\n";
        this->listameret++;
        Listaelem* mozgo = this->eleje;
        if(mozgo == nullptr)
        {
            auto uj = new Listaelem();
            uj->listadata = T(val);
            mozgo = uj;
            uj->kovetkezo = nullptr;
        }
        else{
        while(mozgo->kovetkezo != nullptr)
        {
            mozgo = mozgo->kovetkezo;
        }
        auto uj = new Listaelem();
        uj->listadata = T(val);
        mozgo->kovetkezo = uj;
        uj->kovetkezo = nullptr;

        }std::cout<<"asd";
    }
    int size()const
    {
        std::cout<<"size";
        std::cout<<" "<<listameret;
        return listameret;
    }
    void torol()
    {
        /*this.~Listaelem();*/
    }
};
#endif // LANCOLTLISTA_HPP
