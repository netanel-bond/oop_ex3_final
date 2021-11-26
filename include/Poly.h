#include <iosfwd.h> //need to add ostream on cpp file too
class Rational;
class Database;
class Poly
        {

    public:
           Poly();  // default c-tor
           Poly(const std:vector<Rational>& coeffes);
           Poly(const Rational rat);
           Poly(const int coeffes);

        Poly &operator=(const Poly &);
        Poly &operator+=(const Poly &);
        Poly &operator-=(const Poly &);
        Poly &operator*=(const Poly &);
        bool operator==(const Poly &)const;
        bool operator>(const Poly&)const;

        Rational operator[](int);
        Poly operator()(Rational );
        private:
    Database theData;
};
Poly operator+(const Poly&,const Poly& );
Poly operator-(const Poly&,const Poly& );
Poly operator+(const Poly&);
Poly operator-(const Poly&);

bool operator!=(const Poly&,const Poly&);
bool operator<=(const Poly&,const Poly&);
bool operator>=(const Poly&,const Poly&);
bool operator<(const Poly&,const Poly&);

