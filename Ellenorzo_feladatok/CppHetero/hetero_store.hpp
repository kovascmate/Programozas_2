/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>
template<class T,size_t meret=100,class kivetel = std::out_of_range>
class HeteroStore{
    T** tarolo;
    size_t elemszam;
public:
    void clear()
    {
        for(size_t i = 0;i<elemszam;i++)
            {
                delete tarolo[i];

            }
            elemszam = 0;
    }
    HeteroStore():elemszam(0){tarolo = new T*[meret];}
    ~HeteroStore()
    {clear();
    delete[] tarolo;
    }
    size_t size(){return elemszam;}
    size_t capacity(){return meret;}
    void add(T* ujelem)
    {
        if(elemszam >= meret)
        {
            delete ujelem;
            throw kivetel("");
        }
        tarolo[elemszam++]= ujelem;
    }
    template<class Tk>
    void traverse(Tk funktor)
    {
        for(size_t i = 0;i<elemszam;i++)
        {
            funktor(tarolo[i]);
        }
    }

}  ;


#endif // HETEROSTORE_HPP
