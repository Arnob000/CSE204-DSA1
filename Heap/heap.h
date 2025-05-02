#include<iostream>

using namespace std;

class Heap{
    int* arr;
    int maxSize;
    int len;

public:
    Heap(int m=10){             //constructor
        maxSize = m+1;
        arr = new int[maxSize];
        arr[0]=0;
        len=1;
    }

    Heap(vector<int> &n){         //constructor
        maxSize=n.size()+1;
        arr = new int[maxSize];
        arr[0]=0;
        len=1;

        for(int i = 0; i < n.size(); i++)
            insert(n[i]);
    }

    ~Heap(){
        delete [] arr;
    }

    int leftchild(int i){
        return 2*i;
    }

    int rightchild(int i){
        return (2*i)+1;
    }

    void insert(int n){
        if(len<maxSize){
            arr[len]=n;
            int  pos=len;
            int t;
            while(pos/2 > 0){
                if(arr[pos/2] < arr[pos]){
                    t=arr[pos/2];
                    arr[pos/2]=arr[pos];
                    arr[pos]=t;
                    pos=pos/2;
                }
                else
                    break;
            }
            len++;
        }
        else
            cout<<"Heap is full\n";
    }

    int getMax(){
        if(len>1)
            return arr[1];
        else
            cout<<"Heap is empty\n";
    }

    int size(){
        return len-1;
    }

    void deleteKey(){
        if(len<=1){
            cout<<"Heap is empty\n";
            return;
        }

        arr[1]=arr[--len];
        int i=1, l, r, largest, t;

        while(i<len){
            l=leftchild(i);
            r=rightchild(i);

            if(l<len && arr[l]>arr[i])
                largest=l;
            else
                largest=i;

            if(r<len && arr[r]>arr[largest])
                largest=r;

            if(largest!=i){
                t=arr[i];
                arr[i]=arr[largest];
                arr[largest]=t;
                i=largest;
            }
            else
                break;
        }
    }

    friend void heapsort(vector<int>&v);

};

//heapsort function
void heapsort(vector<int> &v){
    Heap h(v);
    int i=0;
    while(h.size()>0){
        v[i]=h.getMax();
        h.deleteKey();
        i++;
    }
}
