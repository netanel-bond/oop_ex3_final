
#include <vector>;

#include "Rational.h"
#include "List.h"

class Poly;

class Database {
public:

    ~Database();

    Database(const Rational);                 //  c-tor for scalar
    Database(const int, const Rational);   //  c-tor for scalar and exponent
    Database(const std::vector<Rational> &);     //  c-tor for array of rationals

    int getExpo(int) const;

    Rational getRational(int) const;

    int getListSize() const;

    Database& operator=(const Database right);

private:

    List* m_head = NULL;
    int m_listSize = 0;

    void deleteList();
    List* nodeAllocate(const int expo, const Rational& rat);
};


Database operator+ (const Database&);