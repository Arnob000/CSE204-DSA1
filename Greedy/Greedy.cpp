#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int Partition(int *arr, int p, int r){              //partition for RandQuickSort
    int x,i,t;
    x=arr[r];
    i=p-1;
    for(int j=p; j<r; j++){
        if(arr[j]<=x){
            i++;
            t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    t=arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=t;

    return (i+1);
}

void RandQuickSort(int *arr, int p, int r) {        //Randomize Qiucksort
    srand(time(NULL)*r);
    int t,index,q;
    if(p<r){
        index=p+(rand()%(r-p+1));
        t=arr[index];
        arr[index]=arr[r];
        arr[r]=t;

        q=Partition(arr, p, r);
        RandQuickSort(arr, p, q-1);
        RandQuickSort(arr, q+1, r);
    }
}

int greedy(int *price, int n, int k){               //Greedy approach
    int *arr=new int[k];
    int sum=0,j;

    RandQuickSort(price, 0, n-1);                   //sorting the price

    for(int i=0; i<k; i++)
        arr[i]=0;

    j=0;
    for(int i=n-1; i>=0; i--){
        if(j >= k)
            j=0;
        sum += price[i]*(arr[j]+1);                 // calculating price
        arr[j]=arr[j]+1;                            // storing the number of plants a friend buy
        j++;
    }
    delete [] arr;
    return sum;
}

int main(){
    int n, k, p=0;
    int *price;

    while(true){
        cin>>n>>k;
        if(n>1 && n<=100 && k>1 && k<=100)
            break;
        else
            cout<<"Enter N, K again\n";
    }
    price = new int[n];

    for(int i=0; i<n; i++){
        cin>>p;
        if(p>1 && p<=1000000)
            price[i]=p;
        else{
            i--;
            cout<<"Enter price again against price = "<<p<<endl;
        }
    }

    cout<<greedy(price, n, k);
    delete [] price;
}
