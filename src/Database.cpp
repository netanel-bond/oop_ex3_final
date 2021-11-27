#include "Database.h"

#include <iostream>


using std::cout;
using std::endl;

Database::~Database() 
{

	

}

//Database::Database(const Database &right)
//{
//
//
//
//}

Database::Database(const Rational rat) 
{
	m_head = nodeAllocate(0, rat);

	m_listSize = 1;
}

Database::Database(const int expo, const Rational rat)
{

	m_head = nodeAllocate(expo, rat);

	m_listSize = 1;

}

Database::Database(const std::vector<Rational> &rat) 
{

	int arraySize = rat.size();

	m_head = NULL;
	List** node = NULL;

	for (int i = 0; i < arraySize; i++)
	{
		if (rat[i] != 0)
		{
			m_listSize++;

			if (m_head == NULL)
			{
				m_head = nodeAllocate(arraySize - i - 1, rat[i]);
				node = &m_head->next;
			}

			else
			{
				*node = nodeAllocate(arraySize - i - 1, rat[i]);
			}

			node = &(*node)->next;
		}
	}
}

List* Database::nodeAllocate(const int expo, const Rational& rat)
{

	List* node = new List;

	if (node == NULL)
	{
		cout << "node allocation failed" << endl;
		exit(EXIT_FAILURE);
	}

	node->expo = expo;
	node->rat = rat;

	return node;
}

int Database::getExpo(int i) const
{
	List* node = m_head;

	int index = 0;

	while (index < i && index < m_listSize)
	{
		node = node->next;
		index++;
	}

	if (index >= m_listSize)
	{
		cout << "index out of bounds" << endl;
		exit(EXIT_FAILURE);
	}

	return node->expo;
}

Rational Database::getRational(int i) const 
{
	List* node = m_head;

	int index = 0;

	while (index < i && index < m_listSize)
	{
		node = node->next;
		index++;
	}

	if (index >= m_listSize)
	{
		cout << "index out of bounds" << endl;
		exit(EXIT_FAILURE);
	}

	return node->rat;
}

Database operator+ (const Database&)
{

}

Database& Database::operator=(const Database right)
{
	deleteList();

	m_head = NULL;
	List** node;

	m_listSize = right.getListSize();

	for (int i = 0; i < m_listSize; i++)
	{

			if (m_head == NULL)
			{
				m_head = nodeAllocate(right.getExpo(i), right.getRational(i));
				node = &m_head->next;
			}

			else
			{
				*node = nodeAllocate(right.getExpo(i), right.getRational(i));
			}

			node = &(*node)->next;
	}
	
	return *this;
}

void Database::deleteList()
{
	List* node;

	while (m_head != NULL)
	{
		node = m_head;

		m_head = m_head->next;

		delete node;
	}
}

int Database::getListSize() const
{
	return m_listSize;
}

