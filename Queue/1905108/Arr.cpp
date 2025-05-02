#include<iostream>
#include "QueueADT.cpp"

using namespace std;

#define defaultSize 10

template <class T>
class ArrayQueue: public Queue<T>{
    T* arrQ;
    int front;
    int rear;
    int maxSize;

    void increaseSize(){
        T* temp =new T[maxSize*2];

        for(int i=0; i<maxSize; i++){
            temp[i]=arrQ[i];
        }
        delete [] arrQ;

        maxSize=maxSize*2;
        arrQ =new T[maxSize];

        for(int i=0; i<maxSize; i++){
            arrQ[i]=temp[i];
        }
        delete [] temp;
    }

public:
    ArrayQueue(int size = defaultSize){
        maxSize=size+1;
        front=1;
        rear=0;
        arrQ=new T[maxSize];
    }

    ArrayQueue(ArrayQueue<T>* aq){
        maxSize=aq.maxSize;
        front=1;
        rear=0;
        arrQ=aq.arrQ;
    }

    ArrayQueue(const ArrayQueue<T> &al){
        this->maxSize = al.maxSize;
        this->front = al.front;
        this->rear = al.rear;
        this->arrQ = new T[maxSize];

        for(int i=0; i<maxSize; i++)
            this->arrQ[i] = al.arrQ[i];
    }

    ArrayQueue<T> operator=(const ArrayQueue<T> &al){
        this->maxSize = al.maxSize;
        this->front = al.front;
        this->rear = al.rear;
        this->arrQ = new T[maxSize];

        for(int i=0; i<maxSize; i++)
            this->arrQ[i] = al.arrQ[i];

        return *this;
    }

    void clear(){
        delete [] arrQ;
        front=1;
        rear=0;
        arrQ = new T[maxSize];
    }

    void enqueue(const T& item) {
        if(length()==maxSize-1)
            increaseSize();

        rear = (rear+1)%maxSize;
        arrQ[rear]=item;
    }

    T dequeue(){
        T val = (T)-1;
        if(length()==0){
            cout<<"Queue is empty\n";
            return val;
        }
        val=arrQ[front];
        front=(front+1)%maxSize;
        return val;
    }

    int length(){
        return ((rear+maxSize)-front+1)%maxSize;
    }

    T frontValue(){
        if(length()>0)
            return arrQ[front];
        else
            return (T)(-1);
    }

    T rearValue(){
         if(length()>0)
            return arrQ[rear];
        else
            return (T)(-1);
    }
    T leaveQueue(){
        T val = (T)-1;
        if(length()==0){
            cout<<"Queue is empty\n";
            return val;
        }

        val=arrQ[rear];
        rear=rear-1;
        if(rear<0)
            rear=maxSize-1;

        return val;
    }

    ~ArrayQueue(){
        delete [] arrQ;
    }
};
