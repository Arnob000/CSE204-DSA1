#include<iostream>
#include "QueueADT.cpp"
#include "Node.cpp"

using namespace std;

#define defaultSize 10

template<class T>
class LinkedQueue:public Queue<T>{
    Node<T>* front;
    Node<T>* rear;
    int len;

public:
    LinkedQueue(int l = defaultSize)
    {
        front=new Node<T>();
        rear=front;
        len=0;
    }

    LinkedQueue(const LinkedQueue<T>& al){
        delete front;
        this->front=new Node<T>();
        this->rear=front;
        this->len=al.len;

        Node<T>* temp = al.front->next;
        for(int i=0; temp!=NULL; i++){
            rear->next=new Node<T>();
            rear->next->element=temp->element;
            rear=rear->next;
            temp=temp->next;
        }
        delete temp;
    }

    LinkedQueue<T> operator=(const LinkedQueue<T>& al){
        delete front;
        front=new Node<T>();
        rear=front;
        len=al.length();

        Node<T>* temp = al.front->next;
        for(int i=0; temp!=NULL; i++){
            rear->next=new Node<T>();
            rear->next->element=temp->element;
            rear=rear->next;
            temp=temp->next;
        }
        delete temp;
    }

    void clear(){
        while(front!=NULL){
            rear=front;
            front=front->next;
            delete rear;
        }
        front=new Node<T>();
        rear=front;
        len=0;
    }

    void enqueue(const T& item){
        rear->next = new Node<T>(item, NULL);
        rear=rear->next;
        len++;
    }

    T dequeue(){
        T val = (T)(-1);
        if(len <= 0 && front->next == NULL){
            cout<<"Queue is empty\n";
            return val;
        }
        else{
            val = front->next->element;
            Node<T>* temp = front->next;
            front->next = front->next->next;
            if(rear==temp)
                rear=front;
            delete temp;
            len--;
            return val;
        }
    }

    int length(){
        return len;
    }

    T frontValue(){
        T val=(T)(-1);
        if(len>0){
            val= front->next->element;
        }
        return val;
    }

    T rearValue(){
        T val=(T)(-1);
        if(len>0)
            return rear->element;
        else
            return val;
    }

    T leaveQueue(){
        T val = (T)-1;
        if(len <= 0 && front->next == NULL){
            cout<<"Queue is empty\n";
            return val;
        }
        else{
            val = rear->element;
            Node<T>* temp = rear;

            Node<T>* t = front;
            for(int i=0; t!=NULL; i++){
                if(t->next==rear)
                    break;
                else
                    t=t->next;
            }
            rear=t;
            rear->next=NULL;

            delete temp;
            len--;
            return val;
        }
    }

    ~LinkedQueue(){
        while(front!=NULL){
            rear=front;
            front=front->next;
            delete rear;
        }
    }
};
