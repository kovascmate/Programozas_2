#include "ustring.h"

//#error "itt valósítsa meg az UString osztály tagfüggvényeit!"
//#error "ne feledkezzen meg a statikus adattagról sem!"
bool UString::ucase = false;

void UString::UCase(bool allapot)
{
    ucase = allapot;
}

bool UString::UCase() const
{
    return this->ucase;
}
std::ostream& operator<<(std::ostream& lib, const UString& ustring)
{
    size_t hosz = ustring.size();
    if(ustring.UCase() == true)
    {
        for(size_t i = 0; i < hosz; i++)
        {
            char asd = toupper(ustring[i]);
            lib << asd;
        }
    }
    else if(ustring.UCase() == false)
    {
        for(size_t i = 0; i < hosz; i++)
        {
            lib << ustring[i];
        }
    }
    return lib;
}

