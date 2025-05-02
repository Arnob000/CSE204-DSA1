#include<iostream>
#include<fstream>
#include "BST.cpp"

using namespace std;

int main()
{
    BST<int> a;
    ifstream file("Input.txt");

    char q;
    int p;
    string st;
    if(file.is_open()){
        while(!file.eof()){
            file>>q;
            q=toupper(q);

            switch(q){
            case 'F':
                file>>p;
                if(a.Find(p)==true)
                    cout<<"True\n";
                else
                    cout<<"False\n";
                break;

            case 'I':
                file>>p;
                a.insert(p);
                a.print();
                break;

            case 'D':
                file>>p;
                if(a.Delete(p))
                    a.print();
                else
                    cout<<"Invalid Operation\n";
                break;

            case 'T':
                file>>st;
                if(st.compare("Pre") == 0)
                    a.preOrder();
                else if(st.compare("In") == 0)
                    a.inOrder();
                else if(st.compare("Post") == 0)
                    a.postOrder();
                break;

            default:
                break;
            }
        }
    }
    file.close();
}
