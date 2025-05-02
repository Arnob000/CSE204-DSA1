#include<iostream>
#include "StackADT.cpp"

using namespace std;

#define defaultSize 15

template <class T>
class ArrayStack: public Stack<T>{
private:
    int maxSize;
    int top;
    T* arrStk;
    int direction;
    int len;

    void increaseSize(){
        T* temp =new T[maxSize*2];

        if(direction==1){
            for(int i=0; i<length(); i++){
                temp[i]=arrStk[i];
            }
            delete [] arrStk;

            maxSize=maxSize*2;
            arrStk =new T[maxSize];

            for(int i=0; i<length(); i++){
                arrStk[i]=temp[i];
            }
            delete [] temp;
        }
        else if(direction == -1){
            for(int i=maxSize-1; i>top; i--){
                temp[i]=arrStk[i];
            }
            delete [] arrStk;

            maxSize=maxSize*2;
            arrStk =new T[maxSize];

            for(int i=maxSize-1; i>top; i--){
                arrStk[i]=temp[i];
            }
            delete [] temp;
        }
    }

public:
    ArrayStack(int size= defaultSize){
        maxSize = size;
        top = 0;
        len=0;
        direction = 1;
        arrStk = new T[maxSize];
    }

    ArrayStack(ArrayStack<T>* al, int dir){         //for 1array 2stack
        maxSize = al->maxSize;
        arrStk = al->arrStk;
        if(dir==1)
            top = 0;
        else if(dir==-1)
            top=maxSize-1;
        len=0;
        direction = dir;
    }

    ArrayStack(int* arr, int dir, int len){         //for 1array 2stack

        arrStk = arr;
        maxSize=len;
        if(dir==1)
            top = 0;
        else if(dir==-1)
            top=maxSize-1;
        len=0;
        direction = dir;
    }

    ArrayStack(const ArrayStack<T> &al){
        this->maxSize = al.maxSize;
        this->top = al.top;
        this->len=al.len;
        this->direction= al.direction;
        this->arrStk = new T[maxSize];

        if(direction == 1){
            for(int i=0; i<top; i++){
                this->arrStk[i] = al.arrStk[i];
            }
        }
        else if(direction == -1){
            for(int i=maxSize-1; i>top; i--){
                this->arrStk[i] = al.arrStk[i];
            }
        }
    }

    ArrayStack<T> operator=(const ArrayStack<T> &al){
        this->maxSize = al.maxSize;
        this->top = al.top;
        this->len=al.len;
        this->direction= al.direction;
        this->arrStk = new T[maxSize];

        if(direction == 1){
            for(int i=0; i<top; i++){
                this->arrStk[i] = al.arrStk[i];
            }
        }
        else if(direction == -1){
            for(int i=maxSize-1; i>top; i--){
                this->arrStk[i] = al.arrStk[i];
            }
        }
        return *this;
    }

    void clear(){
        delete [] arrStk;
        top = 0;
        len = 0;
        direction = 1;
        arrStk = new T[maxSize];
    }

    void push(const T& item){
        if(len >= maxSize)
                increaseSize();
        if(direction == 1){
            arrStk[top++] = item;
        }
        else if(direction == -1){
            arrStk[top--] = item;
        }
        len++;
    }

    T pop(){
        T val = (T)-1;
        if(len <= 0){
            cout<<"Stack is empty\n";
            return val;
        }
        else if(direction==1){
            len--;
            return arrStk[--top];
        }
        else if(direction==-1){
            len--;
            return arrStk[++top];
        }

    }

    int length(){
        return len;
    }

    T topValue(){
        T val = (T)-1;
        if(len <= 0){
            cout<<"Stack is empty\n";
            return val;
        }
        else if(direction==1)
            return arrStk[top-1];
        else if(direction==-1)
            return arrStk[top+1];
    }
    void setDireaction(int direction){
        if(len==0){
            if(direction == -1){
                this->direction=direction;
                top=maxSize-1;
            }
            else if(direction == 1){
                this->direction=direction;
                top=0;
            }
        }
    }

    ~ArrayStack(){
        delete [] arrStk;
        top = 0;
        len = 0;
        direction = 0;
    }

};
