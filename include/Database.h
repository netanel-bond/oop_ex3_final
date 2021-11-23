
class Rational;

class Database{
    public:


    Database(const Rational=0);
    Database(const Rational=0, const int=0 );//for defult scalar and munom
    Database(const std::vector<Rational>&);
private:
    int *m_coeffes ;
    Rational *m_rat;
    int m_arrSize;
    m_checkAllocate();

};