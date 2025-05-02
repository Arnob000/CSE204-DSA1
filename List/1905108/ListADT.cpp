#include <iostream>
using namespace std;

template <class T>
class List{

public:
    List(){}

    virtual void clear() = 0;                   //clear the list
    virtual void insert(const T &item) = 0;     //insert a item
    virtual void append(const T &item) = 0;     //add a item at last
    virtual T& remove() = 0;                    //remove current item and return that
    virtual void moveToStart() = 0;             //move curr position at start
    virtual void moveToEnd() = 0;               //move curr position
    virtual void prev() = 0;                    //move curr one step back
    virtual void next() = 0;                    //move curr one step forward
    virtual int length() = 0;                   //return the length of list
    virtual int currPos() = 0;                  //return current position
    virtual void moveToPos(int pos) = 0;        //move curr to specific position
    virtual T& getValue() = 0;                  //rturn curr value
    virtual int Search(const T &item) = 0;      //search a item and return its position
};
