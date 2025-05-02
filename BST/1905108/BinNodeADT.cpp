#include<iostream>

using namespace std;

template <typename E>
class BinNode {
    public:
        virtual ~BinNode(){}

        virtual E& element() = 0;
        virtual void setElement(const E& e) = 0;
        virtual BinNode* left() const = 0;
        virtual void setLeft(BinNode<E>* l) = 0;
        virtual BinNode* right() const = 0;
        virtual void setRight(BinNode<E>* r) = 0;
        virtual bool isLeaf() = 0;
};
