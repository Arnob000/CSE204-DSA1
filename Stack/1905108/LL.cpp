#include<iostream>
#include "StackADT.cpp"
#include "Node.cpp"

using namespace std;
#define defaultSize 0

template <class T>
class LinkedStack: public Stack<T>{
    Node<T>* top;
    Node<T>* tail;
    int len;
public:
    LinkedStack(int size = defaultSize){
        top = NULL;
        len = 0;
    }

    LinkedStack(const LinkedStack<T> & al){
        delete top;
        this->top = new Node<T>();
        this->tail=this->top;
        this->len = al.len;

        Node<T>* temp = al.top;
        for(int i=0; temp!=NULL; i++){
            tail->element=temp->element;
            tail->next=new Node<T>();
            tail=tail->next;
            temp=temp->next;
        }
        delete temp;
    }


    LinkedStack<T> operator=(const LinkedStack<T> & al){
        delete top;
        this->top = new Node<T>();
        this->tail=this->top;
        this->len = al.len;

        Node<T>* temp = al.top;
        for(int i=0; temp!=NULL; i++){
            tail->element=temp->element;
            tail->next=new Node<T>();
            tail=tail->next;
            temp=temp->next;
        }
        delete temp;
        return *this;
    }

    void clear(){
        while(top!=NULL){
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        len=0;
    }

    void push(const T& item){
        Node<T>* newNode = new Node<T>(item, top);
        top=newNode;
        len++;
    }


    T pop(){
        T val = (T)-1;
        if(len <= 0 && top == NULL){
            cout<<"Stack is empty\n";
            return val;
        }
        else{
            val = top->element;
            Node<T>* temp = top;
            top = top->next;
            delete temp;
            len--;
            return val;
        }

    }

    int length(){
        return len;
    }

    T topValue(){
        T val = (T) -1;
        if(len <= 0){
            cout<<"Stack is empty\n";
            return val;
        }
        else
            return top->element;
    }

    void setDireaction(int direction){

    }

    ~LinkedStack(){
        clear();
    }

};
