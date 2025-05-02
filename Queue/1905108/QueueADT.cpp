#include<iostream>

using namespace std;

template <class T>
class Queue{
    Queue(const Queue&){}
    void operator=(const Queue&){}
public:
    Queue(){}
    virtual ~Queue(){}

    virtual void clear() = 0;
    virtual void enqueue(const T&) = 0;
    virtual T dequeue() = 0;
    virtual int length() = 0;
    virtual T frontValue() = 0;
    virtual T rearValue() = 0;
    virtual T leaveQueue() = 0;
};
