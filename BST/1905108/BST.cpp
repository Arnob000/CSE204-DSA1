#include<iostream>
#include "BSTNode.cpp"

using namespace std;

template <typename E>
class BST{
    BSTNode<E>* root;
    int nodecount;

    void clearhelp(BSTNode<E>* root);
    BSTNode<E>* inserthelp(BSTNode<E>* rt, const E& e);
    BSTNode<E>* deletemax(BSTNode<E>* rt);
    BSTNode<E>* getmin(BSTNode<E>* rt);
    BSTNode<E>* getmax(BSTNode<E>* rt);
    BSTNode<E>* removehelpMax(BSTNode<E>* rt, const E& e);
    bool findhelp(BSTNode<E>* rt, const E& e);
    void printhelp(BSTNode<E>* rt);
    void pre(BSTNode<E>* rt);
    void post(BSTNode<E>* rt);
    void in(BSTNode<E>* rt);

public:
    BST(){
        root = NULL;
        nodecount=0;
    }

    ~BST(){
        clearhelp(root);
    }

    void clear(){
        clearhelp(root);
        root=NULL;
        nodecount=0;
    }

    void insert(const E& e){
        root = inserthelp(root, e);
        nodecount++;
    }

    bool Delete(const E& e){
        if(Find(e)){
            root = removehelpMax(root, e);
            nodecount--;
            return true;
        }
        else
            return false;
    }

    bool Find(const E& e){
        if(findhelp(root, e))
            return true;
        else
            return false;
    }

    int size(){
        return nodecount;
    }

    void print(){
        if(root != NULL){
            printhelp(root);
            cout<<endl;
        }
        else
            cout<<"BST is empty.\n";
    }

    //Traversal
    void preOrder(){
        pre(root);
        cout<<endl;
    }

    void postOrder(){
        post(root);
        cout<<endl;
    }

    void inOrder(){
        in(root);
        cout<<endl;
    }
};

//find
template <typename E>
bool BST<E> :: findhelp(BSTNode<E>* rt, const E& e){
    if(rt == NULL)
        return false;

    if(e < rt->element())
        return findhelp(rt->left(), e);
    else if (e > rt->element())
        return findhelp(rt->right(), e);
    else
        return true;
}

//insert
template <typename E>
BSTNode<E>* BST<E>::inserthelp(BSTNode<E>* rt, const E& item){
     if (rt == NULL)                                        // Empty tree: create node
        return new BSTNode<E>(item, NULL, NULL);
     if (item < rt->element())
        rt->setLeft(inserthelp(rt->left(), item));
     else
        rt->setRight(inserthelp(rt->right(), item));
     return rt;
}

//delete max
template <typename E>
BSTNode<E>* BST<E>::deletemax(BSTNode<E>* rt){
    if(rt->right() == NULL)
        return rt->left();
    else{
        rt->setRight(deletemax(rt->right()));
        return rt;
    }
}

//get min
template <typename E>
BSTNode<E>* BST<E>:: getmin(BSTNode<E>* rt) {
    if (rt->left() == NULL)
        return rt;
    else
        return getmin(rt->left());
}

//get max
template <typename E>
BSTNode<E>* BST<E>:: getmax(BSTNode<E>* rt) {
    if (rt->right() == NULL)
        return rt;
    else
        return getmax(rt->right());
}

//remove with left max
template <typename E>
BSTNode<E>* BST<E>::removehelpMax(BSTNode<E>* rt, const E& e){
    if(rt == NULL)
        return NULL;
    else if(e < rt->element())
        rt->setLeft(removehelpMax(rt->left(), e));
    else if(e > rt->element())
        rt->setRight(removehelpMax(rt->right(), e));
    else{
        BSTNode<E>* temp = rt;
        if(rt->left() == NULL){
            rt=rt->right();
            delete temp;
        }
        else if(rt->right() == NULL){
            rt=rt->left();
            delete temp;
        }
        else{
            BSTNode<E>* temp = getmax(rt->left());
            rt->setElement(temp->element());
            rt->setLeft(deletemax(rt->left()));
            delete temp;
        }
    }
    return rt;
}

//clear
template <typename E>
void BST<E>:: clearhelp(BSTNode<E>* rt){
    if(rt == NULL)
        return;
    clearhelp(rt->left());
    clearhelp(rt->right());
    delete rt;
}

//print
template <typename E>
void BST<E>:: printhelp(BSTNode<E>* rt){
    if (rt == NULL)
        return;
    int a=1;
    if(rt->left() == NULL && rt->right() == NULL)
        a=-1;
    cout<<rt->element();
    if(a==1)
        cout<<"(";
    printhelp(rt->left());
    if(a==1)
        cout<<")(";
    printhelp(rt->right());
    if(a==1)
        cout<<")";
}

//preOrder traversal
template <typename E>
void BST<E>:: pre(BSTNode<E>* rt){
    if(rt ==NULL)
        return;

    cout<<rt->element()<<" ";
    pre(rt->left());
    pre(rt->right());
}

//postOrder traversal
template <typename E>
void BST<E>:: post(BSTNode<E>* rt){
    if(rt ==NULL)
        return;

    post(rt->left());
    post(rt->right());
    cout<<rt->element()<<" ";
}

//inOrder traversal
template <typename E>
void BST<E>:: in(BSTNode<E>* rt){
    if(rt ==NULL)
        return;

    in(rt->left());
    cout<<rt->element()<<" ";
    in(rt->right());
}
