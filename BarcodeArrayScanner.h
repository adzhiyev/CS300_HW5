/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */
#ifndef BARCODE_ARRAY_SCANNER_H_
#define BARCODE_ARRAY_SCANNER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include "BinarySearchTree.h"
#include "Item.h"

using namespace std;

/*
 *UPC Scanner class for Arrays
 */

class BarcodeArrayScanner
{
  private:
    string upcCode;
    int sizeArr = 1100000;

  public:
    void setUPC(string);
    void searchUPC();
};

/*
 *Sets the UPC Code
 *
 * @param userInput the upc input from user
 */
void BarcodeArrayScanner::setUPC(string userInput)
{
    upcCode = userInput;
}

/*
 * Creates the Array of UPC codes from textfile
 * and searches through it to see if it matches
 * the user input
 */
void BarcodeArrayScanner::searchUPC()
{
    string input;
    ifstream file;
    Item *arr = new Item[sizeArr]; //array to store item objects
    //opens the text file to read the UPC's and Descriptions
    file.open("upc_corpus.txt");
    int j = 0; //index of the array

    //loops through creating an item object with UPC code and description
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
            arr[j] = item; //stores item in array
        }
        j++;
    }

    Item itemSearch; //dummy Item object to search through array
    itemSearch.setUpcCode(upcCode);
    //Default description which is returned incase item is not found
    itemSearch.setDescription("Error: Item not found");
    clock_t t; // clock to keep track of execution time
    t = clock();
    // size_t size = 100000;
    //loops through array, if UPC code is found it breaks from loop
    for (int k = 0; k < sizeArr; k++)
    {

        if (arr[k].getUpcCode() == itemSearch.getUpcCode())

            break;
    }

    t = clock() - t; //execution time

    cout << "Array time: " << t << " micro seconds" << endl;
    delete[] arr; //deletes the array
}

#endif /* BARCODE_ARRAY_SCANNER_H_ */