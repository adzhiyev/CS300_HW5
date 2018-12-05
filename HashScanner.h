/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */
#ifndef HASH_SCANNER_H_
#define HASH_SCANNER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HashTable.h"
#include "Item.h"

using namespace std;

/*
 *UPC Scanner class for HashTable
 */

class HashScanner
{
  private:
    string upcCode;
    int inputIndex;
    int index;

  public:
    void setUPC(string);
    void searchUPC();
};

/*
 *Sets the UPC Code
 *
 * @param userInput the upc input from user
 */

void HashScanner::setUPC(string userInput)
{

    upcCode = userInput;
}

/*
 * Creates the HashTable of UPC codes from textfile
 * and searches through it to see if it matches
 * the user input
 */

void HashScanner::searchUPC()
{
    string input;
    ifstream file;
    HashTable<Item> upcHashTable(1000); //HashTable for Items
    //opens the text file to read the UPC's and Descriptions
    file.open("upc_corpus.txt");
    //loops through creating an item object with UPC code and description
    //and inserting them in the table.
    while (getline(file, input))
    {

        istringstream ss(input);
        string token;
        Item item;
        //Splits string in two based in first comma
        for (int i = 0; i < 2; i++)
        {
            getline(ss, token, ',');

            if (i == 0)
            {
                item.setUpcCode(token); //sets UPC code
            }
            else
            {
                item.setDescription(token); //sets item description
            }
        }

        upcHashTable.put(item); //stores item in HashTable
    }

    Item itemSearch; //dummy Item object to search through HashTable
    itemSearch.setUpcCode(upcCode);
    //Default description which is returned incase item is not found
    itemSearch.setDescription("Error: Item not Found");

    clock_t t;
    t = clock(); // clock to keep track of execution time

    //searches through the table for the item's upc and prints its description
    string description = upcHashTable.search(itemSearch).getDescription();
    t = clock() - t; //execution time

    cout << "HashTable time: " << t << " micro seconds" << endl;
    cout << description << endl;
}

#endif /* HASH_SCANNER_H_ */