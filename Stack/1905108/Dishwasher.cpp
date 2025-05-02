#include<iostream>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

int main(){
    int n,x,f;
    cin>>n;
    cin>>x;
    ArrayStack<int> dirty, clean, fullcourse;
    //LinkedStack<int> dirty,clean, fullcourse;

    int* foodtime = new int[x];
    for(int i=0; i<x; i++){
        cin>>f;
        foodtime[i]=f;
    }

    int k=0,t=0,s=0, sum=-1;

    while(true){
        cin>>k>>t>>s;
        if(k!=0){
            if(s==x)
                fullcourse.push(k);

            if((t-sum)<=0)      //for t <= total time
                dirty.push(s-1);
            else{
                while(dirty.length()!=0 && (t-sum)>0){ //t-sum >0 and there is more dirty plate
                    sum+=foodtime[dirty.pop()];
                    clean.push(sum);
                }
                dirty.push(s-1);
            }

            if(t>sum){
                sum=t-1;
                sum+=foodtime[dirty.pop()];
                clean.push(sum);
            }
            else if(t==sum){
                sum+=foodtime[dirty.pop()];
                clean.push(sum);
            }
            else if(t<sum)
                continue;
        }
        while(dirty.length()!=0 && k == 0){
            sum+=foodtime[dirty.pop()];
            clean.push(sum);
        }

        if(k==0 && dirty.length()==0)
            break;
    }
    cout<<endl;
    cout<<endl<<sum<<endl;

    ArrayStack<int> cleanRev;
    //LinkedStack<int> cleanRev;
    while(clean.length()!=0){
        cleanRev.push(clean.pop());
    }
    int len =cleanRev.length();
    for(int i=0; i<len; i++){
        if(i==len-1)
            cout<<cleanRev.pop()<<endl;
        else
            cout<<cleanRev.pop()<<", ";
    }

    if(fullcourse.length() == n)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;

    if(fullcourse.length()>0){
        int len =fullcourse.length();
        for(int i=0; i<len; i++){
            if(i==len-1)
                cout<<fullcourse.pop()<<endl;
            else
                cout<<fullcourse.pop()<<", ";
        }
    }
    else
        cout<<endl;
}
