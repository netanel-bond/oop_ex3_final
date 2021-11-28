
#include <vector>;

#include "Rational.h"
#include "List.h"

class Poly;

class Database {
public:

    ~Database();
   // Databse();
    Database(const Rational rat =0);                 //  c-tor for scalar
    Database(const int, const Rational);   //  c-tor for scalar and exponent
    Database(const std::vector<Rational> &);     //  c-tor for array of rationals
    Database(const Database&);
    int getExpo(int) const;

    Rational getRational(int) const;

    int getListSize() const;
    List* getHead()const;
    void setHead(List*&,int size);

    Database& operator=(const Database right);
    
   // void plusAddList(List*&temp);


private:

    List* m_head = NULL;
    int m_listSize = 0;

    void deleteList();
    List* nodeAllocate(const int expo, const Rational& rat);
};
Database operator+ (const Database&, const Database&);
Database operator *(const Database& ,const Database&right);

