#include<iostream>

using namespace std;

template <class T>
class Stack{
    void operator =(const Stack<T>& s) {}   // Protect assignment
    Stack(const Stack<T>& s) {}             // Protect copy constructor
public:
    Stack(){}
    virtual ~Stack(){}

    virtual void clear() = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual int length() = 0;
    virtual T topValue() = 0;
    virtual void setDireaction(int direction) = 0;
};
