#ifndef _COOLVECTOR_H
#define _COOLVECTOR_H

// <iosfwd> contains forward declarations of the iostream types one usually finds in <iostream>
// but since this is just a header file, it speeds up compile time to only include the declarations here.
#include <iosfwd>
#include <string>

using namespace std;

class CoolVector
{
public:
    CoolVector();                           // default constructor
    CoolVector(const CoolVector & other);   // copy constructor
    ~CoolVector();                          // destructor

    int size() const;           // retrieve the size
    bool isEmpty() const;       // test if empty
    string toString() const;    // get the string representation

    int get(int pos) const;         // get an element at a certain position 
    void set(int pos, int value);   // set an element at a certain position 

    void append(int value);                 // append one value
    void prepend(int value);                // prepend one value
    void append(const CoolVector & other);  // append a whole CoolVector
    void prepend(const CoolVector & other); // prepend a whole CoolVector

    void insert(int pos, int value);                // insert one item
    void insert(int pos, const CoolVector & other); // insert a whole CoolVector

    void remove(int pos);               // remove one item
    void remove(int start, int end);    // remove a range of items
    void clear();                       // remove all the elements

    CoolVector slice(int start, int end) const;         // get a sub-CoolVector with a start and an end

    CoolVector & operator=(const CoolVector & other);    // assignment operator

    friend ostream & operator<<(ostream & out, const CoolVector & coolvec);   // for cout'ing

private:
    int *data;		// pointer to C++ array of integers
    int thesize;	// size of the array (from the user's perspective)
    int capacity; // capacity of the array (actual number of elements current allocated)

    static const int SIZE_INCREMENT = 3;
};

#endif 
