#include<iostream>
#include<fstream>
#include "Arr.cpp"
//#include "LL.cpp"

using namespace std;

class TNL{
    ArrayList<int> RS;
    ArrayList<int> BS;
    ArrayList<int> TS;
    int totalStop;

    //LinkedList<int> RS;
    //LinkedList<int> BS;
    //LinkedList<int> TS;

public:
    TNL(){
        totalStop=0;
    }

    TNL(int stop){
        totalStop=stop;
    }

    void appendRS(int stop){
        RS.append(stop);
    }

    void appendBS(int stop){
        BS.append(stop);
    }

    void appendTS(int station){
        TS.append(station);
    }

    void task1(){
        for(int i=0; i<totalStop; i++){
            cout<<i;
            if(i==totalStop-1)
                cout<<endl;
            else
                cout<<",";
        }

        printSpots(BS);
        printSpots(TS);
    }

    void printSpots(ArrayList<int> &S)
    //void printSpots(LinkedList<int> &S)

    {
        for(int i=0; i<totalStop; i++){
            for(int j=0; j<S.length(); j++){
                S.moveToPos(j);
                if(i==S.getValue())
                    cout<<S.getValue();
            }
            S.moveToStart();

            if(i==totalStop-1)
                cout<<endl;
            else
                cout<<",";
        }
    }

    //CSV file
    void createCSV(ofstream& f){
        for(int i=0; i<totalStop; i++){
            f<<i;
            if(i==totalStop-1)
                f<<endl;
            else
                f<<",";
        }

        printCell(BS, f);
        printCell(TS, f);
    }

    void printCell(ArrayList<int> &S, ofstream& f)
    //void printCell(LinkedList<int> &S, ofstream& f)
    {
        for(int i=0; i<totalStop; i++){
            for(int j=0; j<S.length(); j++){
                S.moveToPos(j);
                if(i==S.getValue())
                    f<<S.getValue();
            }
            S.moveToStart();

            if(i==totalStop-1)
                f<<endl;
            else
                f<<",";
        }
    }
};


int main(){
    int rickshawStop, busStop, trainStation, stop;
    cin>>rickshawStop;
    TNL tnl(rickshawStop);

    cin>>busStop;
    for(int i=0; i<busStop; i++){
        cin>>stop;
        tnl.appendBS(stop);
    }

    cin>>trainStation;
    for(int i=0; i<trainStation; i++){
        cin>>stop;
        tnl.appendTS(stop);
    }

    int task;
    cin>>task;

    cout<<endl<<endl;

    if(task==1){
        tnl.task1();

        //CSV file
        ofstream tranNetLine;
        tranNetLine.open("Transit network line.csv");
        tnl.createCSV(tranNetLine);
        tranNetLine.close();
    }
}
