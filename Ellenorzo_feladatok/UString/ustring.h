#ifndef USTRING_H
#define USTRING_H
#include "string5.h"
//#error "itt deklarĂˇlja az UString osztĂˇlyt"
class UString :public String{
        static bool ucase;
    public:
            UString():String(){};
            UString(const UString& ustring):String(ustring){};
            UString(const String& stirng):String(stirng){};
            bool UCase() const;
            static void UCase(bool allapot);
};
std::ostream& operator<<(std::ostream& lib, const UString& ustring);
#endif // USTRING_H
