#include "CoolVector.h"
#include <iostream>
#include <sstream>

using namespace std;

/*
 * Default constructor.  Constructs a new, empty CoolVector with size=0 and capacity=SIZE_INCREMENT.
 */
 //initializes an empty CoolVector 
CoolVector::CoolVector() 
{
  //initializes size of array (from user's perspective)
  thesize = 0; 
  //used to allocate a block (array) of elements of type int 
  data = new int [SIZE_INCREMENT];
  //capacity of the array (actual number of elements current allocated)
  capacity = SIZE_INCREMENT; 
}

/*
 * Copy constructor.  Called when constructing one CoolVector from another.
 * Copies the contents of the other CoolVector into ourselves, including size and capacity (so we become
 * an exact copy of the other CoolVector).
 */
CoolVector::CoolVector(const CoolVector & other) 
{
  data = new int [other.capacity]; 
  thesize = other.thesize; 
  capacity = other.capacity; 

  //copies everything over 
  for (int x = 0; x < thesize; ++x) {
    data[x] = other.data[x]; 
  }
}

/*
 * Destructor.  Called when a CoolVector goes out of scope.  Deallocates the memory for the CoolVector.
 */
CoolVector::~CoolVector()
{   
  //releases the memory allocated for array of elements using new   
  delete [] data; 
}

/*
 * Returns the size of this CoolVector.
 */
int CoolVector::size() const
{
    return thesize; 
}

/*
 * Returns whether or not this CoolVector is empty.
 */
bool CoolVector::isEmpty() const
{
  if (thesize == 0) {
    return true; 
  }
  else {
    return false; 
  }
}

/*
 * toString() returns a string representation of this CoolVector, showing
 * the contents, size, and capacity.
 */
string CoolVector::toString() const
{
  ostringstream s1; 
  for (int i = 0; i < thesize; ++i) {
    s1 << data[i]; 
  }
  string cvString = s1.str(); 
  return cvString; 
}

/*
 * Returns the integer at a given position in this CoolVector.
 */
int CoolVector::get(int pos) const
{
  if (0 <= pos < thesize) { //checks in range
    return data[pos]; 
  }
}

/*
 * Sets the integer at a given position in this CoolVector.
 */
void CoolVector::set(int pos, int value)
{
  if (0 <= pos < thesize) { //checks in range
    data[pos] = value;
  } 
}

/*
 * Appends a single integer to the end of this CoolVector.
 * If there is no capacity for more integers, capacity should be increased by SIZE_INCREMENT.
 */
void CoolVector::append(int value)
{
  //nest expand function from IntVector to expand if no more capacity
  if (thesize == capacity) {
    int newcapacity = capacity + SIZE_INCREMENT; 
    int *newdata = new int [newcapacity]; 

    for (int x = 0; x < thesize; ++x) {   //copies everything over
      newdata[x] = data[x]; 
    } 
    delete[] data; 
    data = newdata; 
    capacity = newcapacity; 
  }
  data[thesize] = value; 
  thesize++;  
}

/*
 * Appends an entire CoolVector to the end of this CoolVector.
 * If the existing capacity of the CoolVector will not accommodate all of the old and new items, then the capacity
 * should be increased to exactly match the number of old items plus the number of new items.
 */
void CoolVector::append(const CoolVector & other)
{
  int newcapacity = capacity + other.thesize; 
  int *newdata = new int [newcapacity]; 

  for (int x = 0; x < thesize; ++x) {   //copies everything over
    newdata[x] = data[x]; 
  } 
  for (int i = 0; i < other.thesize; ++i) {
    data[thesize] = other.data[i];
    ++thesize;  
  }
  delete[] data; 
  data = newdata; 
  capacity = newcapacity; 
}

/*
 * Appends a single integer to the start of this CoolVector.
 * If there is no capacity for more integers, capacity should be increased by SIZE_INCREMENT.
 */
void CoolVector::prepend(int value)
{
  if (thesize == capacity) {
    int newcapacity = capacity + SIZE_INCREMENT; 
    int *newdata = new int [newcapacity]; 

    for (int x = 0; x < thesize; ++x) {   //copies everything over
      newdata[x] = data[x]; 
    } 
    delete[] data; 
    data = newdata; 
    capacity = newcapacity; 
  }
  for (int x = thesize; x > 0; --x) {
    data[x] = data[x-1]; 
  }
  data[0] = value; 
  ++thesize; 
}

/*
 * Prepends an entire CoolVector to the start of this CoolVector.
 * If the existing capacity of the CoolVector will not accommodate all of the old and new items, then the capacity
 * should be increased to exactly match the number of old items plus the number of new items.
 */
void CoolVector::prepend(const CoolVector & other)
{
  int newcapacity = capacity + other.thesize; 
  int *newdata = new int [newcapacity]; 

  for (int x = 0; x < thesize; ++x) {
    newdata[x] = data[x]; 
  }
  delete [] data; 
  data = newdata; 
  capacity = newcapacity; 

  for (int j = 0; j < thesize; ++j) { 
    data[j + thesize] = data[j]; 
    for (int i = 0; i < thesize; ++i) {
      data[i] = other.data[i]; 
    }
  }
}    

/*
 * Inserts an integer at a given position in the CoolVector.
 * pos may be between 0 and size() --- note that if pos == size(),
 * then the new value is inserted at the end of the CoolVector.
 * If there is no capacity for more integers, capacity should be increased by SIZE_INCREMENT.
 */
void CoolVector::insert(int pos, int value)
{
  if (0 <= pos <= thesize) {
    if (capacity == thesize) {
      int newcapacity = capacity + SIZE_INCREMENT; 
      int *newdata = new int [newcapacity]; 
      
      for (int x = 0; x < thesize; ++x) {   //copies everything over
      newdata[x] = data[x]; 
      } 
      delete[] data; 
      data = newdata; 
      capacity = newcapacity;
    }
    for (int j = thesize - 1; j > pos; --j) {
      data[j] = data[j-1]; 
    }
    data[pos] = value; 
  }
}

/*
 * Inserts the contents of a CoolVector at a given position in the CoolVector.
 * pos may be between 0 and size() --- note that if pos == size(),
 * then the new value is inserted at the end of the CoolVector.
 * If the existing capacity of the CoolVector will not accommodate all of the old and new items, then the capacity
 * should be increased to exactly match the number of old items plus the number of new items.
 */
void CoolVector::insert(int pos, const CoolVector & other)
{
  if (0 <= pos <= thesize) {
    if (capacity == thesize) {
      int newcapacity = capacity + other.thesize; 
      int *newdata = new int [newcapacity]; 

      for (int x = 0; x < thesize; ++x) {
        newdata[x] = data[x]; //copies everything over
      }
      delete [] data; 
      data = newdata; 
      capacity = newcapacity; 
    }
    for (int j = pos; j < thesize; ++j) {
      data[j + thesize] = data[j]; 
      for (int i = pos; i < thesize; ++i) {
        data[i] = other.data[i]; 
      } 
    }
  }

}

/*
 * Removes the item at the specified position from the CoolVector.
 * Items to the right of pos are slid over to fill the gap.  Capacity is not changed.
 */
void CoolVector::remove(int pos)
{
    for (int i = 0; i < thesize; ++i) {
      if (i == pos) {
        data[i] = data[i + 1]; 
        for (i = pos + 1; i < thesize; ++i) {
          data[i] = data[i + 1]; 
        }
        --thesize; 
      }
    }
}


 /* Removes the items at positions start, start+1, start+2, ..., end-1 from the CoolVector.
 * Notice that the item at position end is not removed.
 * Items to the right of the removed section are slid over to fill the gap.  Capacity is not changed.
 */
void CoolVector::remove(int start, int end)
{
  for (int i = start; i < end; ++i) {
    data[i] = data[i + 1]; 
  }
  --thesize; 
}

/*
 * Removes all the items from this CoolVector, and resets it to the starting conditions of size=0
 * and capacity=SIZE_INCREMENT.
 */
void CoolVector::clear()
{
  delete [] data; 
  CoolVector(); 
}


 /* Creates a new CoolVector containing items at positions start, start+1, start+2, ..., end-1 from
 * the original CoolVector.  In the new CoolVector, the capacity should match the number of items (do not
 * allocate any extra space).
 * If start <= end, then a zero-length slice is created, with size=0 and capacity=SIZE_INCREMENT.
 */
CoolVector CoolVector::slice(int start, int end) const
{  
  if (start <= end) {
    int newcapacity = SIZE_INCREMENT; 
    int *newdata = new int [newcapacity]; 
  
  }
  else {
    int newcapacity = capacity; 
    int *newdata = new int[newcapacity];
    for (int i = start; i < end; ++i) {
      newdata[i] = data[i]; 
    }
    delete [] data;  
    //capacity = newcapacity;
  }
} 

/*
 * Assignment operator.  This is called whenever one CoolVector is assigned to another.
 * Should make an exact copy of the other CoolVector, including contents, size, and capacity.
 */
CoolVector & CoolVector::operator=(const CoolVector & other)
{
  if (this != &other) {
    data = new int [other.capacity]; 
    thesize = other.thesize; 
    capacity = other.capacity; 

    for (int x = 0; x < thesize; ++x) {
      data[x] = other.data[x]; 
    }
  }
  return *this; 
}

/*
 * ostream insertion operator overload.  Used for cout'ing a CoolVector, among other things.
 */
ostream & operator<<(ostream & out, const CoolVector & coolvec)
{
  if (coolvec.thesize == 0) out << "[] size=" << coolvec.thesize << " cap=" << coolvec.capacity; 

  else {
    out << "["; 
    for (int x = 0; x < coolvec.thesize; ++x) {
      out << coolvec.data[x]; 
      if (x != coolvec.thesize - 1) {
        out << " "; 
      } 
    } 
    out << " ] size=" << coolvec.thesize << " cap=" << coolvec.capacity; 
  }
  return out; 
}
