#ifndef KIFLI_H
#define KIFLI_H
#include "string5.h"


class Kifli : public Aru
{
    String fajta;
    public:
        Kifli(double money,String fajta):Aru("Kifli","db",money),fajta(fajta){}

        std::ostream& print(std::ostream& os)const
        {
            return os<<"Kifli"<<" "<<fajta<<"; "<<ar<<"Ft/db";
        }
};
#endif // KIFLI_H
