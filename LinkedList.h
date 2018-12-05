/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <string>
#include <array>

using namespace std;

//node Template
template <class T>
struct node
{
	T data;
	node *next;
};
/**
 * LinkedList class to create a list of nodes
 */
template <class T>
class LinkedList
{
  private:
	LinkedList(const LinkedList &) = delete; //copy constructor

  protected:
	int count;
	node<T> *head, *last;

  public:
	LinkedList();
	bool isEmpty();
	int length();
	T front();
	T back();
	void insertFirst(T &);
	void insertLast(T &);
	void insertPos(T &);
	void print();
	void deleteNode(T &);
	bool search(T &);
	T retrieve(T &);
	void destroylist();
	LinkedList<T> &operator=(LinkedList<T> &);
	template <class U>
	friend ostream &operator<<(ostream &os, LinkedList<U> &list);
	~LinkedList();
};

//constructor
template <class T>
LinkedList<T>::LinkedList()
{
	head = last = NULL;
	count = 0;
}
/**
 * Checks if the list is empty.
 */
template <class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}
/**
 * Gets the length of the list.
 * 
 * @return count the length of the list.
 */
template <class T>
int LinkedList<T>::length()
{
	return count;
}

/**
 * Gets the data in the head node of the list.
 * 
 * @return the data in the head node.
 */
template <class T>
T LinkedList<T>::front()
{
	return head->data;
}
/**
 * Gets the data in the last node node of the list.
 * 
 * @return the data in the last node.
 */
template <class T>
T LinkedList<T>::back()
{
	return last->data;
}

/**
 * inserts the node at the beginning of the list.
 * 
 * @param item to be inserted.
 */
template <class T>
void LinkedList<T>::insertFirst(T &item)
{
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if (last == NULL)
		last = temp;
}

/**
 * inserts the node at the end of the list.
 * 
 * @param item to be inserted.
 */
template <class T>
void LinkedList<T>::insertLast(T &item)
{

	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if (head == NULL)
	{

		head = last = newnode;
	}
	else
	{
		last->next = newnode;
		last = newnode;
	}
	count++;
}
/**
 * inserts the node at a certain position.
 * 
 * @param item to be inserted.
 */
template <class T>
void LinkedList<T>::insertPos(T &item)
{

	node<T> *p, *q, *r = new node<T>;
	p = head;
	r->data = item;

	if (p == NULL)
	{
		insertFirst(item);
	}
	else
	{
		q = p->next;
		while (q != NULL && item >= q->data)
		{

			p = p->next;
			q = q->next;
		}

		count++;
		r->next = q;
		p->next = r;
	}
}
/**
 * deletes a specific node.
 * 
 * @param item to be deleted.
 */
template <class T>
void LinkedList<T>::deleteNode(T &item)
{

	if (head == NULL)
	{
		cout << "empty list";
	}

	else if ((head->data).getLastName() == item.getLastName())
	{
		node<T> *t = head;
		head = head->next;
		delete t;
		count--;
		if (head == NULL)
			last = NULL;
	}

	else
	{
		node<T> *p, *q;
		p = head;
		q = p->next;
		cout << p << " p" << endl;
		cout << q << " q" << endl;
		while (q != NULL && ((q->data).getLastName() != item.getLastName()))
		{
			p = q;
			q = q->next;
			cout << "test" << endl;
		}

		if (q == NULL)
		{
			cout << "Item not found" << endl;
		}
		else
		{
			if (q->next == NULL)
			{
				last = p;
			}
			delete q;
			count--;
		}
	}
}

/**
 * print function for a linked list
 */
template <class T>
void LinkedList<T>::print()
{
	node<T> *p = new node<T>;
	p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

/**
 * searches for a specific node with certain data.
 * 
 * @param item to be searched.
 */
template <class T>
bool LinkedList<T>::search(T &item)
{

	node<T> *p = new node<T>();
	p = head;

	while (p != NULL)
	{
		if (p->data == item)
		{
			return true;
		}
		p = p->next;
	}

	return false;
}
template <class T>
T LinkedList<T>::retrieve(T &item)
{

	node<T> *p = new node<T>();
	p = head;

	while (p != NULL)
	{
		if (p->data == item)
		{
			return p->data;
		}
		p = p->next;
	}

	return item;
}
/**
* Destroys the list.
 */
template <class T>
void LinkedList<T>::destroylist()
{
	node<T> *p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
/**
 * Overrides the = operator.
 * 
 * @param list to overload.
 */
template <class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &list)
{
	if (this != &list)
	{
		copylist(list);
	}
	return *this;
}
/**
 * Overrides the output operator for a list
 * 
 * @param os output to be sent out.
 * @param list List to overload.
 */
template <class T>
ostream &operator<<(ostream &os, LinkedList<T> &list)
{
	node<T> *p = list.head;
	while (p != NULL)
	{
		os << p->data << " " << endl;
		p = p->next;
	}
}

/**
 * Destroys the list.
 */
template <class T>
LinkedList<T>::~LinkedList()
{

	destroylist();
}

#endif /* LINKEDLIST_H_ */
