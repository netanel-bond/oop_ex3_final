
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

Poly& Poly::operator=(const Poly &right) 
{

    this->m_theData = right.m_theData;

    return *this;

}

Poly operator+(const Poly& left ,const Poly &right)
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


Poly Poly::operator-() 
{


}

Poly &operator+=(Poly &left, const Poly &right)
{


}


bool Poly::operator==(const Poly &right) const 
{

}

bool operator!=(const Poly &left, const Poly &right) 
{
    return !(left == right);
}

int Poly::deg(int i) const {
    
}

Rational Poly::operator[](int i) const 
{


}

int Poly::getDataSize() const
{
    return m_theData.getArrSize();
}

int Poly::getExpo(int index) const
{
    
}

Rational Poly::getRational(int index) const
{
    
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