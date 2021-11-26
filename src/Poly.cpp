
#include "Poly.h"

//c-tor for array of rationals
Poly::Poly(const std::vector<Rational> &rationals) : m_theData(rationals) {}

// default c-tor, builds poly with 0 as rational
Poly::Poly() : m_theData(0) {}

//  c-tor for rational as scalar
Poly::Poly(const Rational rat) : m_theData(rat) {}

//  c-tor for an int for the exponent and rational
Poly::Poly(const int coeffe, const Rational rat) : m_theData(coeffe, rat) {}

Poly &Poly::operator=(const Poly &right) {
    // this.~m_theData();

        Database newDatabase(right.m_theData);
        this->m_theData = newDatabase;

    return *this;
}

Poly &Poly::operator+(const Poly &right) const{


        Database newDatabase(this->m_theData,right.m_theData);


        Poly newPoly;
        newPoly.m_theData=newDatabase;


}
/*Poly &Poly::operator-(const Poly left7,const Poly &right) const{

    Database newDatabase(this->m_theData,right.m_theData);


    Poly newPoly;
    newPoly.m_theData=newDatabase;


}*/
Poly Poly::operator-()
{
    Database newDatabase(this->m_theData);
    newDatabase.minus();
    Poly newPoly;
    newPoly.m_theData=newDatabase;
    return newPoly;

}

Poly & operator+=(Poly &left, const Poly &right) {

    Poly newPoly=left+right;
    return newPoly;
}


bool Poly :: operator==( const Poly &right)const  {
    int expoL=deg(), expoR=deg();

    return(this ->m_theData.checkEquals(expoL, expoR));
}

bool  operator!=( const Poly &left,const Poly &right)  {
    return!(left==right);
}

int Poly ::deg() const {
    return this->m_theData.getExpo(0);
}