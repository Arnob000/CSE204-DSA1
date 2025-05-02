#include <iostream>
#include "ListADT.cpp"
#include "Node.cpp"

using namespace std;


template <class T>
class LinkedList: public List<T>{
private:
    Node<T>* head;
    Node<T>* curr;
    Node<T>* tail;
    int len;

public:
     LinkedList(){                          //Constructor
        head= new Node<T> ();
        curr=head;
        tail=head;
        len=0;
    }

    LinkedList(int size){                   //Constructor
        head= new Node<T> ();
        curr=head;
        tail=head;
        len=0;
    }

    LinkedList(T* arr, int l, int size) {    //Constructor
        head= new Node<T> ();
        curr=head;
        tail=head;
        len=0;

        for(int i=0; i<l; i++){
            append(arr[i]);
        }
    }

    void clear(){
        while(head!=NULL){
            curr=head;
            head=head->next;
            delete curr;
        }

        head= new Node<T> ();
        curr=head;
        tail=head;
        len=0;
    }

    void insert(const T &item){
        Node<T>* newNode= new Node<T>(item, curr->next);
        curr->next=newNode;
        len++;
    }

    void append(const T &item){
         Node<T>* newNode= new Node<T>(item, NULL);
         tail->next=newNode;
         tail=newNode;
         len++;
    }

    T& remove(){
        if(curr->next != NULL){
            Node<T>* temp =curr->next;
            T val=curr->next->element;

            if (tail == curr->next)
                tail = curr;

            curr->next=curr->next->next;
            len--;
            delete temp;

            if(tail == curr)        //for last position
                prev();

            return val;
        }
    }

    void moveToStart(){
        curr=head;
    }

    void moveToEnd(){
        if(curr->next !=tail){
            curr=head;
            for(int i=0; i<len-1; i++)
                curr=curr->next;
        }
    }

    void prev(){
        if(curr==head)
            cout<<"Already at first position\n";
        else
            {
                Node<T>* temp = head;
                for(int i=0; i<len-1; i++){
                    if(temp->next==curr)
                        break;
                    else
                        temp=temp->next;
                }
                curr=temp;
            }
    }

    void next(){
        if (curr->next != tail)
            curr=curr->next;
        else
            cout<<"Already at last position"<<endl;
    }

    int length(){
        return len;
    }

    int currPos(){
        Node<T>* temp = head;
        int i;
        for(i=0; temp!=curr; i++){
            temp=temp->next;
        }
        return i;
    }

    void moveToPos(int pos){
        if(pos>=0 && pos<len){
            curr=head;
            for(int i=0; i<pos; i++)
                curr=curr->next;
        }
        else
            cout<<"Given position is out of range\n";
    }

    T& getValue(){
        if(len>0 && curr->next != NULL)
            return curr->next->element;
    }

    int Search(const T &item){
        int pos=-1;
        curr=head;
        for(int i=0; i<len-1; i++){
            if(item == curr->next->element){
                pos=i;
                break;
            }
            curr=curr->next;
        }
        return pos;
    }

    ~LinkedList(){
        while(head!=NULL){
            curr=head;
            head=head->next;
            delete curr;
        }
    }

};
