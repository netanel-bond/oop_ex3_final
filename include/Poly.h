
class Rational;
class Database;
class Poly
        {
    public:
           Poly();  // default c-tor
           Poly(const std:vector<Rational>& coeffes);
           Poly(const Rational rat);
           Poly(const int coeffes);

        private:
    Database theData;
};