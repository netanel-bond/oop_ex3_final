#include "Database.h"

#include <iostream>


using std::cout;

Database::~Database() {
    delete[]m_expo;
    delete[]m_rat;
}

Database::Database(const Database &right) {
    delete[]this->m_expo;
    delete[]this->m_rat;

    this->m_arrSize = right.getArrSize();

    m_expo = new int[this->m_arrSize];
    m_rat = new Rational[this->m_arrSize];
    checkAllocate();

    for (int i = 0; i < this->m_arrSize; ++i) {
        if (right.getRational(i) != 0) {
            m_rat[i] = right.getRational(i);
            m_expo[i] = i;
        }
    }

}

Database::Database(const Rational rat) {
    m_expo = new int[1];

    m_rat = new Rational[1];

    checkAllocate();

    m_expo[0] = 0;
    m_rat[0] = rat;
}

Database::Database(const int coeffes, const Rational rat) {

    m_expo = new int[1];

    m_rat = new Rational[1];

    checkAllocate();

    m_expo[0] = coeffes;
    m_rat[0] = rat;
}

Database::Database(const std::vector<Rational> &rat) {
    int decress_size = 0;
    m_arrSize = sizeof(rat) / sizeof(rat[0]);

    for (int i = 0; i < m_arrSize; i++) {
        if (rat[i] == 0)
            decress_size++;
    }

    m_arrSize -= decress_size;
    m_expo = new int[m_arrSize];
    m_rat = new Rational[m_arrSize];
    checkAllocate();

    for (int i = 0; i < m_arrSize; ++i) {
        if (rat[i] != 0) {
            m_rat[i] = rat[i];
            m_expo[i] = m_arrSize - i;
        }
    }
}

void Database::checkAllocate() {
    if (m_expo == nullptr || m_rat == nullptr) {
        cout << "error in allocation data";
        exit(EXIT_FAILURE);
    }
}

int Database::getExpo(int i) const {

    return m_expo[i];
}

Rational Database::getRational(int i) const {
    return m_rat[i];
}

int Database::getArrSize() const {
    return this->m_arrSize;
}

void Database::reAllocate(int size) {
    delete[] m_rat;
    delete[] m_expo;

    m_rat = new Rational[size];
    m_expo = new int[size];
}

Database::Database(const Database left, const Database right) {
    int arrIncSize = 0;
    for (int i = 0; i < left.getArrSize(); i++) {
        for (int j = 0; i < right.getArrSize(); j++) {
            if (left.m_expo[i] == right.m_expo[j])
                arrIncSize++;
        }
    }

    m_arrSize += arrIncSize;
    int startJ = 0;
    bool notFound = false;
    m_rat = new Rational[m_arrSize];
    m_expo = new int[m_arrSize];
    int lCounter = 0, rCounter = 0, newCounter = 0;
    while (lCounter < left.getArrSize() && rCounter < right.getArrSize()) {
        if (left.m_expo[lCounter] < right.m_expo[rCounter]) {
            m_rat[newCounter] = right.m_rat[rCounter];
            m_expo[newCounter] = m_arrSize - newCounter;
            rCounter++;
        } else if (left.m_expo[lCounter] > right.m_expo[rCounter]) {
            m_rat[newCounter] = left.m_rat[lCounter];
            m_expo[newCounter] = m_arrSize - newCounter;
        } else {
            m_rat[newCounter] = left.m_rat[lCounter] + right.m_rat[rCounter];
            m_expo[newCounter] = m_arrSize - newCounter;
        }
        newCounter++;
    }
    insertRest(left, lCounter, newCounter);
    insertRest(right, rCounter, newCounter);

}

void Database::insertRest(const Database data, int count, int newCounter) {
    while (count < data.getArrSize()) {
        m_rat[newCounter] = data.m_rat[count];
        m_expo[newCounter] = m_arrSize - newCounter;
        newCounter++;
        count++;
    }
}

void Database::minus() {
    for (int i = 0; i < m_arrSize; i++) {
        m_rat[i] = -m_rat[i];
    }
}

bool Database::checkEquals(int expoL, int expoR) const {
    return (expoL == expoR);
}

Rational Database::rationalMekadem(int x) const {
    for (int i = 0; i < this->getArrSize(); i++) {
        if (x == this->getExpo(i))
            return this->m_rat[i];
    }
    std::cout << "eror";
    return -1;
}

int Database::polinom(Rational r) const {
    for (int i = 0; i < this->getArrSize(); i++) {
        if (r == this->getRational(i))
            return this->m_expo[i];
    }
    std::cout << "eror";
    return -1;
}