
#ifndef ALAPTIPUS_H
#define ALAPTIPUS_H
template <typename T>
class Alaptipus{

    T cucc;
public:
    Alaptipus(T i = 0) :cucc(i) {}
    operator T&() { return cucc; }
    operator T() const { return cucc; }
    T* operator&() {   return &cucc; }
    const T* operator&() const {   return &cucc; }




    virtual ~Alaptipus() {}


};

#endif // ALAPTIPUS_H
