
#include <iosfwd> //need to add ostream on cpp file too

class Rational {

public:

    Rational(int numer = 0, int denom = 1);

    int getNumer() const;

    int getDenom() const;
    //int numerator() const;
    //int denominator() const;

    Rational& operator=(const Rational &);

    Rational& operator+=(const Rational&);

private:

    int m_numer, m_denom;

//      reducing the fraction
    void reduction();

//      gcd finder
    int gcdFinder(const int num1, const int num2);

//      lcm finder
    int lcmFinder(const int num1, const int num2);

    Rational *getRational() const;      //why?
};

Rational operator+(const Rational &, const Rational &);

Rational operator-(const Rational &, const Rational &);

Rational& operator-=(Rational&, const Rational&);

Rational operator*(const Rational &, const Rational &);

Rational& operator*=(Rational&, const Rational&);

Rational operator/(const Rational &, const Rational &);

Rational& operator/=(Rational&, const Rational&);

Rational& operator+(Rational& rat);

Rational& operator-(Rational& rat);

bool operator>(const Rational&, const Rational&);

bool operator==(const Rational&, const Rational&);

bool operator!=(const Rational &, const Rational &);

bool operator<=(const Rational &, const Rational &);

bool operator>=(const Rational &, const Rational &);

bool operator<(const Rational &, const Rational &);


std::ostream& operator<<(std::ostream &, const Rational &);