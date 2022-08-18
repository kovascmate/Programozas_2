/**
 * \file pirodistak.h
 * Minden származtatott irodista osztály perzisztens változatának deklarációját ebbe a fájlba tegye!
 * Az egyszerűség kedvéért minden tagfüggvényt inline valósítson meg!
 *
 */
#ifndef PIRODISTAK_H
#define PIRODISTAK_H

#include <stdexcept>
#include "palkalmazott.h"
#include "irodistak.h"




/**
 * Perzisztens csoportvezető
 */
        struct PCsopVez : public CsopVez, public Serializable
        {
            PCsopVez(const std::string& n, double f, csop_t cs)
            : Alkalmazott(n, f),
            CsopVez(n, f, cs) {}
        PCsopVez(const CsopVez& csv) : Alkalmazott(csv), CsopVez(csv) {}

         void write(std::ostream& os) const
         {
            os << "PCsopVez" << std::endl;
            PAlkalmazott(*this).write(os);
            os << getCs() << std::endl;
        }

    void read(std::istream& is)
    {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PCsopVez")
            throw std::out_of_range("PCsopvez_R "+tmp);
        PAlkalmazott pa("",0);
        pa.read(is);
        *((Alkalmazott*)this) = pa;
        csop_t cs;
        (is >> cs).ignore(1);
        setCs(cs);
    }
};

/**
 * Perzisztens Határozott idejű alkalmazott
 */
    struct PHatIdeju : public HatIdeju, public Serializable {
    PHatIdeju(const std::string& n, double f, time_t t)
        : Alkalmazott(n, f),
          HatIdeju(n, f, t) {}
    PHatIdeju(const HatIdeju& hati) : Alkalmazott(hati), HatIdeju(hati) {}

    void write(std::ostream& os) const {
        os << "PHatIdeju" << std::endl;
        PAlkalmazott(*this).write(os);
        os << getIdo() << std::endl;
    }

    void read(std::istream& is) {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PHatIdeju")
            throw std::out_of_range("PHatIdeju_R "+tmp);
        PAlkalmazott pa("",0);
        pa.read(is);
        *((Alkalmazott*)this) = pa;
        time_t t;
        (is >> t).ignore(1);
        setIdo(t);
    }
};

/**
 * Perzisztens Határozott idejű csoportvezető
 */


#endif // IRODISTAK_H

