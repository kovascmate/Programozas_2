#ifndef MONOTON_HPP
#define MONOTON_HPP

template<class T,typename Pred>
bool monoton(T first,T last,Pred p)
{
    if(first == last)
    {
        return true;
    }

    for(T i = first++; first != last; i = first++)
    {
        if(!p(*first,*i))
        {
            return false;
        }
    }
    return true;
}

#endif // MONOTON_HPP
