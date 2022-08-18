
#ifndef MYSET_HPP
#define MYSET_HPP
#define ELKESZULT 2
template <typename T, int meret = 20>

class Set{
    T data[meret];
    size_t tarolomeret;
public:
    Set():tarolomeret(0){}
    size_t size()const {return tarolomeret;}
    bool isElement(const T& elem)const;
    void insert(const T& elem);
};
template <typename T, int meret>
bool Set<T, meret>::isElement(const T& elem)const{
    for(size_t i = 0; i < tarolomeret;i++)
    {
        if(elem == data[i])
        {
            return true;
        }
    }
    return false;
}
template<typename T, int meret>
void Set<T, meret>::insert(const T& elem)
{
    if(isElement(elem))
    {
        return;
    }
    if(tarolomeret >= meret)
    {
        throw "NINCS HELY";
        return;
    }
    else
    data[tarolomeret++] = elem;
}
bool operator==(const Point& a,const Point& b)
{
    if(a.getX()==b.getX() && a.getY()==b.getY())
        return true;
    else
        return false;
}
#endif
