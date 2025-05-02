#include<iostream>
#include "BinNodeADT.cpp"

using namespace std;

template <typename E>
class BSTNode: public BinNode<E>{
    E data;
    BSTNode<E>* leftChild;
    BSTNode<E>* rightChild;

public:
    BSTNode(){
        leftChild=NULL;
        rightChild=NULL;
    }

    BSTNode(E ele, BSTNode<E>* l=NULL, BSTNode<E>* r=NULL){
        data=ele;
        leftChild=l;
        rightChild=r;
    }

    ~BSTNode(){}

    E& element() {
        return data;
    }
    void setElement(const E& e) {
        data = e;
    }
    inline BSTNode<E>* left() const {
        return leftChild;
    }
    void setLeft(BinNode<E>* l){
        leftChild=(BSTNode*) l;
    }
    inline BSTNode<E>* right() const{
        return rightChild;
    }
    void setRight(BinNode<E>* r){
        rightChild=(BSTNode*) r;
    }
    bool isLeaf(){
        if((leftChild == NULL) && (rightChild == NULL))
            return true;
        else
            return false;
    }
};
