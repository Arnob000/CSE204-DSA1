#include<iostream>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

void printList(ArrayList<int> &al)          //Array based implementation
//void printList(LinkedList<int> &al)       //LinkedList based implementation
{
    int current;
    current=al.currPos();
    al.moveToStart();

    cout<<endl<<"<";
    for(int i=0; i<al.length(); i++){
        if(i==current)
            cout<<"| ";
        if(i==al.length()-1)
            cout<<al.getValue();
        else {
            cout<<al.getValue()<<" ";
            al.next();
        }
    }
    cout<<">"<<endl;

    if(al.length()>0 && current<al.length())
        al.moveToPos(current);
}


int main()
{
    int a,len,memChunk;
    cin>>len;
    cin>>memChunk;

    ArrayList<int> al(memChunk);
    //LinkedList<int> al(memChunk);
    for(int i=0; i<len; i++){
        cin>>a;
        al.append(a);
    }

    printList(al);
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
            al.insert(p);
            break;
        case 3:
            al.append(p);
            break;
        case 4:
            ret=al.remove();
            break;
        case 5:
            al.moveToStart();
            break;
        case 6:
            al.moveToEnd();
            break;
        case 7:
            al.prev();
            break;
        case 8:
            al.next();
            break;
        case 9:
            ret=al.length();
            break;
        case 10:
            ret=al.currPos();
            break;
        case 11:
            al.moveToPos(p);
            break;
        case 12:
            ret=al.getValue();
            break;
        case 13:
            ret=al.Search(p);
        default:
            break;
        }

        if (q!=0) {
            printList(al);
            cout<<ret<<endl<<endl;
        }
    }
}
