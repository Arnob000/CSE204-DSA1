#include<iostream>
#include<cstdlib>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

class user{
public:
    int entry, service;

    user(int a=0, int b=0){
        entry=a;
        service=b;
    }
};

int main()
{
    ArrayQueue<user> q1,q2;
    //LinkedQueue<user> q1,q2;
    int n, entry=0, service=0, sum1=0, sum2=0;
    user a;
    cin>>n;

    while(true){
        while(n!=0){
            n--;
            cin>>entry>>service;
            a=user(entry, service);

            //enqueue
            if(q1.length()==0 && q2.length()==0){
                if(entry>=sum1 && entry>=sum2){
                    if(rand()%2)
                        q1.enqueue(a);
                    else
                        q2.enqueue(a);
                }
                else if(entry>=sum1)
                    q1.enqueue(a);
                else
                    q2.enqueue(a);
            }

            else if(q1.length()<q2.length())
                q1.enqueue(a);

            else if(q1.length()==q2.length()){
                if(entry>=sum1 && entry>=sum2){
                    if(rand()%2)
                        q1.enqueue(a);
                    else
                        q2.enqueue(a);
                }
                else if(entry>=sum1)
                    q1.enqueue(a);
                else if(entry>=sum2)
                    q2.enqueue(a);
                else{                      //entry<sum1 && entry<sum2
                    if(rand()%2)
                        q1.enqueue(a);
                    else
                        q2.enqueue(a);
                }
            }
            else if(q1.length()>q2.length())
                q2.enqueue(a);

            //dequeue
            while(entry>=sum1 && q1.length()!=0){
                if(q1.frontValue().entry > sum1)
                    sum1=q1.frontValue().entry + q1.dequeue().service;
                else if(q1.frontValue().entry<=sum1)
                    sum1+=q1.dequeue().service;
            }

            while(entry>=sum2 && q2.length()!=0){
                if(q2.frontValue().entry>sum2)
                    sum2=q2.frontValue().entry+q2.dequeue().service;
                else if(q2.frontValue().entry<=sum2)
                    sum2+=q2.dequeue().service;
            }

            //leave queue
            while(true){
                if(q1.length()>q2.length()+1)
                    q2.enqueue(q1.leaveQueue());
                else if(q2.length()>q1.length()+1)
                    q1.enqueue(q2.leaveQueue());
                else
                    break;
            }
//            cout<<"time1: "<<sum1<<endl;
//            cout<<"time2: "<<sum2<<endl;
        }

        if(q1.frontValue().entry>sum1)
            sum1=q1.frontValue().entry+q1.dequeue().service;
        else if(q1.frontValue().entry<=sum1)
            sum1+=q1.dequeue().service;

        if(q2.frontValue().entry>sum2)
            sum2=q2.frontValue().entry+q2.dequeue().service;
        else if(q2.frontValue().entry<=sum2)
            sum2+=q2.dequeue().service;

        //leave queue
        while(true){
            if(q1.length()>q2.length()+1)
                q2.enqueue(q1.leaveQueue());
            else if(q2.length()>q1.length()+1)
                q1.enqueue(q2.leaveQueue());
            else
                break;
        }

        if(q1.length()==0 && q2.length()==0)
            break;
    }

    cout<<"Booth1 finishes service at t: "<<sum1<<endl;
    cout<<"Booth2 finishes service at t: "<<sum2<<endl;
}
