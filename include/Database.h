
#include <vector>;

#include "Rational.h"



class Database{
public:


    Database(const Rational);                 //  c-tor for scalar 
    Database(const int, const Rational);   //  c-tor for scalar and exponent
    Database(const std::vector<Rational>&);     //  c-tor for array of rationals

private:

    int *m_coeffes ;        //  array of exponents
    Rational *m_rat;        //  array of rationals
//    int m_arrSize;

    void checkAllocate();

};