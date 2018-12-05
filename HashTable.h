/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */
#include <array>
#include "LinkedList.h"
#include <iostream>
using namespace std;

/*
*Class to define the HashTable data Structure
*/
template <class T>
class HashTable
{
  private:
    LinkedList<T> *hashArray;  //array of linked lists for the table
    int size;                  //size of the array
    int hashFunction(T &item); //function to generate the index from the key

  public:
    //default constructor
    HashTable(int _size = 1000)
    {
        size = _size;
        hashArray = new LinkedList<T>[size];
    }
    //deconstructor
    ~HashTable()
    {
        delete[] hashArray;
    }
    void put(T &item);
    void print();
    void remove(T &item);
    T search(T &item);
};

/*
 *Generates the key to use for the HashArray
 *
 * @param &item the item to generate the index for
 */
template <class T>
int HashTable<T>::hashFunction(T &item)
{
    int tableSize = 1000; //for size of the array
    int hashVal = 0;
    hashVal += 37 * item();
    hashVal %= tableSize;
    return hashVal; //the index of the array
}

/*
 *Puts the function in the array of linked lists
 *
 * @param &item the item to be put in the list
 */
template <class T>
void HashTable<T>::put(T &item)
{
    int index = hashFunction(item);    //finds the index
    hashArray[index].insertLast(item); //removes from index in array
}

/*
*Prints the contents of the entire Hash Table
*
*/
template <class T>
void HashTable<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << "index: " << i << " ";
        hashArray[i].print();
    }
}

/*
*Removes an item from the Hash Table
*
*@param &item the item to be removed 
*/
template <class T>
void HashTable<T>::remove(T &item)
{
    int index = hashFunction(item); //finds the index
    hashArray[index].deleteNode();    //removes from index in array
}

/*
*Searches for an item in the Hash Table
*
*@param &item to be searched for
*/
template <class T>
T HashTable<T>::search(T &item)
{
    int index = hashFunction(item);         //finds the index
    return hashArray[index].retrieve(item); //removes from index in array
};