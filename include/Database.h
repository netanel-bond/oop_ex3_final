
class Rational;

#include <vector>;

class Database{
    public:


    Database(const Rational=0);                 //  c-tor for scalar 
    Database(const Rational=0, const int=0 );   //  c-tor for scalar and exponent
    Database(const std::vector<Rational>&);     //

private:
    int *m_coeffes ;        //  array of exponents
    Rational *m_rat;        //  array of rationals
    int m_arrSize;

    void checkAllocate();

};