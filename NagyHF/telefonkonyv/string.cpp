#include "memtrace.h"
#include "string.hpp"
String String::nd("ND");
std::ostream& operator<<(std::ostream& os, String const & str)
{
    os << str.getdata();
    return os;
}
bool matches(const String& alap,const String& beadott)
{
    if(alap.getmeret() != beadott.getmeret())
    {
        return false;
    }
    for(int i = 0; i < alap.getmeret();i++)
    {
        if(beadott[i] != '*')
        {
        if(alap[i] != beadott[i])
        {
            return false;
        }
        }
    }
    return true;
}
