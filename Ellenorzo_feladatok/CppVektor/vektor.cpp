#include "vektor.h"

size_t Vektor::defSize = 7;
double Vektor::defValue = 7;
Vektor::Vektor(const Vektor& rhs)
{
    this->pVec = NULL;
    *this=rhs;
}
Vektor::~Vektor()
{
    delete[] pVec;
}
Vektor& Vektor::operator=(const Vektor& rhs)
{
    if(&rhs == this)
    {
        return *this;
    }
    delete[] pVec;
    this->nElements = rhs.nElements;
    pVec = new double[rhs.nElements];
    for(size_t i = 0; i< rhs.nElements; i++)
    {
        this->pVec[i] = rhs.pVec[i];
    }
    return *this;
}
double& Vektor::operator[](size_t idx)
{

    if(idx >= this->nElements)
    {
        throw "IB72D1";
    }
    return this->pVec[idx];
}
const double& Vektor::operator[](size_t idx) const
{
    if(idx >= this->nElements)
    {
        throw "IB72D1";
    }
    return this->pVec[idx];
}
Vektor operator*(double val, const Vektor& vec)
{
    Vektor asd(vec);

    for(size_t i = 0;i <vec.size();i++)
    {
        asd[i] = vec[i]*val;
    }
    return asd;
}
