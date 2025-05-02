#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

#define INF 999999999

void Merge(int *arr, int p, int q, int r);
int Partition(int *arr, int p, int r);

void MergeSort(int *arr, int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        MergeSort(arr, p, q);
        MergeSort(arr, q+1, r);
        Merge(arr, p, q, r);
    }
}

void Merge(int *arr, int p, int q, int r){
    int n1,n2,i,j;
    n1=q-p+1;
    n2=r-q;
    int left[n1+1];
    int right[n2+1];

    for(int m=0; m<n1; m++)
        left[m]=arr[p+m];

    for(int m=0; m<n2; m++)
        right[m]=arr[q+1+m];

    left[n1]=INF;
    right[n2]=INF;

    i=0;
    j=0;

    for(int k=p; k<=r; k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }

    }
}

void InsertionSort(int *arr, int n){
    int min, t;
    for(int i=0; i<n; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        t=arr[min];
        arr[min]=arr[i];
        arr[i]=t;
    }
}

void QuickSort(int *arr, int p, int r){
    int q;
    if(p<r){
        q=Partition(arr, p, r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q+1, r);
    }
}

int Partition(int *arr, int p, int r){
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

void RandQuickSort(int *arr, int p, int r) {            //Randomize Qiucksort
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

void print(int *a, int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void creatArray(int* a, int n, int seed){
    srand(seed);

    for(int i=0; i<n; i++){
        a[i]=rand();
    }
}

int main(){
    int *a;
    int set[6]={5,10,100,1000,10000,40000};
    int index, n, seed;
    float mt=0, it=0, qt=0, rt=0, sqt=0, srt=0, st=0;

    ofstream file;
    file.open("Time in sorting.csv");
    file<<",,,,,Time required in ms"<<endl;
    file<<"n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with sorted input,Randomized Quicksort with sorted input,STL sort() function"<<endl;

    for(int i=0; i<6; i++){
        n=set[i];
        a=new int[n];
        mt=0;
        it=0;
        qt=0;
        rt=0;
        sqt=0;
        srt=0;
        st=0;

        for(int j=0; j<20; j++){
            srand(time(NULL)*n*(j+1));
            seed=rand();

            creatArray(a, n, seed);
            //print(a,n);
            clock_t time = clock();
            MergeSort(a, 0, n-1);
            mt+=float(clock()-time);
            //print(a,n);

            creatArray(a, n, seed);
            time = clock();
            QuickSort(a, 0, n-1);
            qt+=float(clock()-time) ;
            //print(a, n);

            creatArray(a, n, seed);
            time = clock();
            RandQuickSort(a, 0, n-1);
            rt+=float(clock()-time) ;
            //print(a, n);

            creatArray(a, n, seed);
            time = clock();
            InsertionSort(a,n);
            it+=float(clock()-time) ;
            //print(a, n);

            //for sorted array
            time = clock();
            QuickSort(a, 0, n-1);
            sqt+=float(clock()-time) ;
            //print(a, n);

            //for sorted array
            time = clock();
            RandQuickSort(a, 0, n-1);
            srt+=float(clock()-time) ;
            //print(a, n);

            creatArray(a, n, seed);
            time = clock();
            sort(a, a+n);           //STL sort()
            st+=float(clock()-time);
            //print(a, n);
        }

        delete [] a;
        mt=mt/20.0;
        it=it/20.0;
        qt=qt/20.0;
        rt=rt/20.0;
        sqt=sqt/20.0;
        srt=srt/20.0;
        st=st/20.0;

        file<<n<<","<<mt<<","<<qt<<","<<rt<<","<<it<<","<<sqt<<","<<srt<<","<<st<<endl;
    }
    file.close();
}
