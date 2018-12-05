/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */

#ifndef ITEM_H_
#define ITEM_H_

using namespace std;
/**
 * Creates an item object with a UPC code and description
 * 
 */
class Item
{
  private:
    string upcCode;
    string description; //description of item
  public:
    void setUpcCode(string code) { upcCode = code; }
    string getUpcCode() { return upcCode; }
    void setDescription(string desc) { description = desc; }
    string getDescription() { return description; }

    //to compare within a BST based on UPC code.
    friend bool operator<(Item const &a, Item const &b)
    {
        return a.upcCode < b.upcCode;
    }

    //to compare within a BST based on UPC code.
    friend bool operator>(Item const &a, Item const &b)
    {
        return a.upcCode > b.upcCode;
    }

    //outputs the item description when printing the item
    friend ostream &operator<<(ostream &os, Item &item)
    {
        os << item.getDescription();
        return os;
    }

    //overloads the == operator to check if the UPC codes are equal
    //in the item object
    friend bool operator==(Item const &a, Item const &b)
    {
        return a.upcCode == b.upcCode;
    }

    //overloads the () operator to get the UPC code.
    int operator()()
    {
        int sum = 0;
        for (int i = 0; i < upcCode.length(); i++) {
            sum+=upcCode[i];
        }
        return sum;
    }
};

#endif /* ITEM_H_ */
