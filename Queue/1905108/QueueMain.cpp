#include<iostream>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

void printQueue(ArrayQueue<int> al)          //Array based implementation
//void printQueue(LinkedQueue<int> al)       //Linked based implementation
{
    int len = al.length();
    cout<<endl<<"<";
    for(int i=0; i<len; i++){
        if(i==len-1)
            cout<<al.dequeue();
        else {
            cout<<al.dequeue()<<" ";
        }
    }
    cout<<">"<<endl;
}


int main()
{
    int a,len;
    cin>>len;

    ArrayQueue<int> al(len);
    //LinkedQueue<int> al(len);
    for(int i=0; i<len; i++){
        cin>>a;
        al.enqueue(a);
    }

    printQueue(al);
    cout<<endl;

    int q, p;
    while(q!=0){
        cin>>q;
        cin>>p;

        int ret=-1;

        switch(q){
        case 1:
            al.clear();
            break;
        case 2:
            al.enqueue(p);
            break;
        case 3:
            ret=al.dequeue();
            break;
        case 4:
            ret=al.length();
            break;
        case 5:
            ret=al.frontValue();
            break;
        case 6:
            ret=al.rearValue();
            break;
        case 7:
            ret=al.leaveQueue();
            break;
        default:
            break;
        }

        if (q!=0) {
            printQueue(al);
            cout<<ret<<endl<<endl;
        }
    }
}
