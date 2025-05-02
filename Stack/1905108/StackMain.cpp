#include <iostream>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

void printStack(ArrayStack<int> al)             //Array based implementation
//void printStack(LinkedStack<int> al)       //LinkedList based implementation
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



int main()
{
    int a,len;
    cin>>len;

    ArrayStack<int> al(len);
    //LinkedStack<int> al(len);
    for(int i=0; i<len; i++){
        cin>>a;
        al.push(a);
    }

    printStack(al);
    cout<<endl;

    int q=-1, p;
    while(q!=0){
        cin>>q;
        cin>>p;

        int ret=-1;

        switch(q){
        case 1:
            al.clear();
            break;
        case 2:
            al.push(p);
            break;
        case 3:
            ret=al.pop();
            break;
        case 4:
            ret=al.length();
            break;
        case 5:
            ret=al.topValue();
            break;
        case 6:
            al.setDireaction(p);
            break;
        default:
            break;
        }

        if (q!=0) {
            printStack(al);
            cout<<ret<<endl<<endl;
        }
    }

}
