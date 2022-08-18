
template <typename Iter>
void printEach(Iter first, Iter last, std::ostream& os = std::cout, std::string szep = ", ") {
    while (first != last)
        {
           os<<*first++;
           if(first==last)
           {
               os<<std::endl;
           }
           else
           {
               os<<szep;
           }
        }
}
template <typename Iter>
int szamol_ha_negativ(Iter first, Iter last)
{
    int i = 0;
    while(first != last)
    {
        if(*first<0)
        {
            i = i +1;
        }
        first++;
    }
    return i;
}
template <typename T>
class nagyobb_mint {
    T r;
public:
    nagyobb_mint(T input) :r(input) {}
    bool operator()(const T& a) {
        return a > r;
    }
};

template <typename Iter, typename P>
int szamol_ha(Iter first,Iter last,P predikatum)
{
    int i = 0;
    while(first != last)
    {
        if(predikatum(*first))
        {
            i++;
        }
        first++;
    }
    return i;
}
