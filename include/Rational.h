
#include <iosfwd.h> //need to add ostream on cpp file too

class Rational {

public:

	Rational(int numer = 0, int denom = 1);

	int getNumer() const;

	int getDenom() const;
    int numerator() const;
    int denominator() const;

    Rational &operator=(const Rational &);

    bool operator==(const Rational &)const;
    bool operator>(const Rational&)const;

private:

	int m_numer, m_denom;
};

Rational operator+(const Rational&,const Rational& );
Rational operator-(const Rational&,const Rational& );
Rational operator*(const Rational&,const Rational& );
Rational operator+(const Rational&);
Rational operator-(const Rational&);

bool operator!=(const Rational&,const Rational&);
bool operator<=(const Rational&,const Rational&);
bool operator>=(const Rational&,const Rational&);
bool operator<(const Rational&,const Rational&);




std::ostream& operator<<(std::ostream&,const Rational&);

