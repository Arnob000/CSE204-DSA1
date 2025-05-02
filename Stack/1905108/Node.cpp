#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    T element;
    Node* next;

    Node(const T &el, Node* n=NULL){
        element=el;
        next=n;
    }

    Node(Node* n=NULL){
        next=n;
    }
};
