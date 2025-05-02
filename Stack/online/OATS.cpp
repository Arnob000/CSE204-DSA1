#include<iostream>
#include "Arr.cpp"

using namespace std;


class OATS{
    int* arr;
    int len;
    int dir;


public:
    ArrayStack<int> A;
    ArrayStack<int> B;
    ArrayStack<int> AA;

    OATS(int len){
        arr=new int[len];
        A =  ArrayStack<int> (arr, dir, len);
        B =  ArrayStack<int> (arr, dir, len);
    }
    OATS(){

        ArrayStack<int>A(&AA, 1);
        ArrayStack<int>B(&AA, -1);
    }

    void pushA(int item){
        A.push(item);
    }

    void pushB(int item){
        B.push(item);
    }

    int popA(){
        return A.pop();
    }

    int popB(){
        return B.pop();
    }

    int topValueA(){
        return A.topValue();
    }

    int topValueB(){
        return B.topValue();
    }


};

void printStack(ArrayStack<int> al)             //Array based implementation

{

        int len =al.length();
        cout<<endl<<"<";
        for(int i=0; i<len; i++){
            if(i==len-1)
                cout<<al.pop();
            else {
                cout<<al.pop()<<" ";
            }
        }
        cout<<">"<<endl;


}


int main(){

    OATS al();

    int q=-1, p;
    while(q!=0){
        cin>>q;
        cin>>p;

        int ret=-1;

        switch(q){
        case 1:
//            al.clearA();
            break;
        case 2:
            al.pushA(p);
            break;
        case 3:
            ret=al.popA();
            break;
        case 4:
//            ret=al.lengthA();
            break;
        case 5:
            ret=al.topValueA();
            break;
        case 6:
//            al.clearB();
            break;
        case 7:
            al.pushB(p);
            break;
        case 8:
            ret=al.popB();
            break;
        case 9:
//            ret=al.lengthB();
            break;
        case 10:
            ret=al.topValueB();
            break;
        default:
            break;
        }

        if (q!=0) {
            printStack(al.A);
            printStack(al.B);
            cout<<ret<<endl<<endl;
        }
    }

}
