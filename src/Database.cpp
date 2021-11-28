#include "Database.h"

#include <iostream>


using std::cout;
using std::endl;

Database::~Database() 
{

	deleteList();

}


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
	List* tail = NULL;

	for (int i = 0; i < arraySize; i++)
	{
		if (rat[i] != 0)
		{
			struct List* temp = nodeAllocate(arraySize - i - 1, rat[i]);
			//add alloccheck
			m_listSize++;

			if (m_head == NULL)
			{
				//m_head = nodeAllocate(arraySize - i - 1, rat[i]);
				//node = &m_head->next;
				m_head = tail = temp;
			}

			else
			{
				//tail = nodeAllocate(arraySize - i - 1, rat[i]);
				tail->next = temp;
				tail = temp;
			}

			//tail = &(*tail)->next;
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
	node->next;
	return node;
}

int Database::getExpo(int i) const
{
	List* node = this->m_head;

	int index = 0;

	while (index < i && index < m_listSize-1)
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
	List* node = this->m_head;

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

Database operator+ (const Database &left,const Database& right)
{
	List* lHead = left.getHead();
	List* rHead = right.getHead();
	Database newDatabase;
	List* newHead = NULL;
	List* newTail=NULL;
	int size=0;
	
		while(lHead)//head or head ->next not sure 
		{
			while(rHead)
			{
				struct List* temp = new (std::nothrow)struct List;

				if (lHead->expo == rHead->expo)
				{
					size++;
					//add aloc check
					temp->rat = lHead->rat + rHead->rat;
					temp->expo = lHead->expo;
					lHead = lHead->next;
					rHead = rHead->next;
				}
				else if (lHead->expo > rHead->expo)
				{
					size++;
					//left.plusAddList(temp);
					temp->rat = lHead->rat;
					temp->expo = lHead->expo;

					lHead = lHead->next;

				}
				else 
				{
					size++;
					//right.plusAddList(rtemp);
					temp->rat = rHead->rat;
					temp->expo = rHead->expo;
					rHead = rHead->next;
				}

				if (newHead==NULL)
				{
					newHead = newTail = temp;
				}
				else
				{
					newTail->next = temp;
					newTail = temp;
				}
			}

		}
		newDatabase.setHead(newHead, size);
		return newDatabase;

	
}
/*void Database::plusAddList(List*& temp)//need to make more generic maybe ad l r heads
{
	temp->rat = Head->rat;
	temp->expo = Head->expo;
	
	Head = Head->next;
}*/
List* Database::getHead()const
{
	return m_head;
}
Database& Database::operator=(const Database right)
{
	if(m_head!=NULL)
		deleteList();
	if (right.m_head == NULL)
		cout << "reeikkk";
	m_head = NULL;
	List** node;

	m_listSize = right.getListSize();

	for (int i = 0; i < m_listSize; i++)
	{

			if (m_head == NULL)
			{
				cout << right.getExpo(1);
				m_head = nodeAllocate(right.getExpo(i), right.getRational(i));
				node = &m_head->next;
			}

			else
			{
				*node = nodeAllocate(right.getExpo(i), right.getRational(i));
				node = &(*node)->next;
			}

			
	}
	
	return *this;
}

void Database::setHead(List*& Head,int size)
{
	m_head = Head;
	m_listSize = size;
}
void Database::deleteList()
{
	List* temp=NULL;

	while (m_head != NULL)
	{
		temp = m_head;
		m_head = m_head->next;

		free( temp);
	}
	m_head = NULL;
}

int Database::getListSize() const
{
	return m_listSize;
}

