#include <iostream>
#include "ListADT.cpp"

using namespace std;

#define defaultSize 10

template <class T>
class ArrayList: public List<T>{
private:
    T* arrLt;
    int curr;
    int maxSize;
    int len;

    void increaseSize(){
        T* temp =new T[maxSize*2];

        for(int i=0; i<len; i++){
            temp[i]=arrLt[i];
        }
        delete [] arrLt;

        maxSize=maxSize*2;
        arrLt =new T[maxSize];

        for(int i=0; i<len; i++){
            arrLt[i]=temp[i];
        }
        delete [] temp;
    }

public:
    ArrayList(int size=defaultSize) { // Constructor
        maxSize = size;
        curr = 0;
        len=0;
        arrLt = new T[maxSize];
    }

    ArrayList(T* arr, int l, int size=defaultSize) {    //Constructor
        maxSize = size;
        curr = 0;
        len=0;
        arrLt = new T[maxSize];
        for(int i=0; i<l; i++){
            arrLt[i]=arr[i];
            len++;
        }
    }

    void clear(){
        delete [] arrLt;
        maxSize = defaultSize;
        curr = 0;
        len=0;
        arrLt = new T[maxSize];
    }

    void insert(const T &item){
        if(len >= maxSize)
            increaseSize();

        for(int i=len; i>curr; i--){
            arrLt[i]=arrLt[i-1];
        }
        arrLt[curr]=item;
        len++;
    }

    void append(const T &item){
        if(len >= maxSize)
            increaseSize();
        arrLt[len++]=item;
    }

    T& remove(){
        if(len>0){
            T val=arrLt[curr];
            for(int i=curr; i<len-1; i++){
                arrLt[i]=arrLt[i+1];
            }
            len--;

            if(curr==len)       //for last pos
                curr=len-1;

            return val;
        }
    }

    void moveToStart(){
        curr=0;
    }

    void moveToEnd(){
        curr=len-1;
    }

    void prev(){
        if(curr<=0)
            cout<<"Already at first position\n";
        else
            curr=curr-1;
    }

    void next(){
        if(curr>=len-1)
            cout<<"Already at last position\n";
        else
            curr=curr+1;
    }

    int length(){
        return len;
    }

    int currPos(){
        return curr;
    }

    void moveToPos(int pos){
        if(pos>=0 && pos<len)
            curr=pos;
        else
            cout<<"Given pos is out of range\n";
    }

    T& getValue(){
        if(len>0)
            return arrLt[curr];
    }

    int Search(const T &item){
        int pos=-1;
        for(int i=0; i<len; i++){
            if(item == arrLt[i]){
                pos=i;
                break;
            }
        }
        return pos;
    }

    ~ArrayList(){
        delete [] arrLt;
    }

};
