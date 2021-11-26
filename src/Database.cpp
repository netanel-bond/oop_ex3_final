#include <Database.cpp>

Database::Database(const Rational rat)
{
    m_coeffes=new int [1];
    m_rat= new Rational[1];
    m_allocate();
    m_coeffes[0]=0;
    m_rat[0]=rat;
}
Database::Database(const Rational rat,const int coeffes)
{
    m_coeffes=new int [1];
    m_rat= new Rational[1];
    m_allocate();
    m_coeffes[0]=coeffes;
    m_rat[0]=rat;
}
Database::Database(const std::vector<Rational>& rat)
{
    int decress_size=0;
    int rat_given_size =sizeof(rat)/sizeof(rat[0]);
    for (int i= 0; i < m_arrSize; i++)
    {
        if(rat[i]==0)
            decress_size++;

    }
    m_arrSize-=decress_size
    m_coeffes=new int [m_arrSize];
    m_rat=new int [m_arrSize];
    m_checkAllocate();

    for (int i = 0; i <rat_given_size ; ++i) {
        if(rat[i]!=0)
        {
            m_rat[i] =rat[i];
            m_coeffes[i]=i;
        }
    }



}

void Database::m_checkAllocate()
{
    if(m_coeffes==nullptr||m_rat==nullptr)
    {
        cout <<"error in allocation data";
        return EXIT_FAILURE;
    }
}
