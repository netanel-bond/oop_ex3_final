
#include "Poly.h"
#include <iostream>

using std::cout;

//c-tor for array of rationals
Poly::Poly(const std::vector<Rational> &rationals) : m_theData(rationals) {}

// default c-tor, builds poly with 0 as rational
Poly::Poly() : m_theData(0) {}

//  c-tor for rational as scalar
Poly::Poly(const Rational rat) : m_theData(rat) {}

//  c-tor for an int for the exponent and rational
Poly::Poly(const int expo, const Rational rat) : m_theData(expo, rat) {}

Poly::Poly(const Database& other) : m_theData(other) {}
    ;
Poly& Poly::operator=(const Poly& right)
{

    Poly temp(right);
    std::swap(temp.m_theData,m_theData);
    return *this;

}
Poly operator+(const Poly& left, const Poly& right)
{
   Poly new_poly = left;

    new_poly += right;

    return new_poly;
}

Poly& Poly::operator+=(const Poly& poly)
{
    this->m_theData = this->m_theData + poly.m_theData;

    return *this;
}

int Poly::getDataSize()const {
    return m_theData.getListSize();
}
int Poly::getExpo(int i)const {
    return m_theData.getExpo(i);
}

Rational Poly::getRational(int i)const
{
    return m_theData.getRational(i);
        
}
std::ostream& operator<<(std::ostream& output, const Poly& poly)
{
    int dataSize = poly.getDataSize();
    for (int i = 0; i < dataSize; i++)
    {
        if (poly.getExpo(i) == 0)
            cout << poly.getRational(i);
        else
            cout << poly.getRational(i) << "*X^"  << poly.getExpo(i) << ' ' << "+ ";
    }
        
    return output;
}
int Poly::deg()const
{
    return m_theData.getExpo(0);
}

bool operator==(const Poly& left,const Poly & right)
{
    return (left.deg() == right.deg());
}

bool operator!=(const Poly & left,const Poly & right)
{
    return !(left.deg() == right.deg());
}

Rational Poly::operator[](int expo)const
{
    for (int i = 0; i < this->getDataSize();i++)
    {
        if (expo == this->getExpo(i))
        {
            return this->getRational(i);
        }
    }

    cout << "not found";
    return -1;
}
int Poly::operator()(Rational rat)const
{
    for (int i = 0; i < this->getDataSize();i++)
    {
        if (rat == this->getRational(i))
        {
            return this->getExpo(i);
        }
    }

    cout << "not found";
    return -1;
}
Poly operator*(const Poly& left, const Poly& right)
{
    Poly temp = left;

    temp *= right;
    return temp;
}
Poly &Poly :: operator*=(const Poly& right)
{
    this->m_theData = this->m_theData * right.m_theData;
    return *this;
}
//Poly operator-(const Poly& left,const Poly& right)
//{
  //  return (left + (-1) * right);
//}