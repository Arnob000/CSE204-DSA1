//LCS
#include <iostream>
#include <string>

using namespace std;

void LCS(string x, string y){
    int c[x.length()+1][y.length()+1];

    for(int i=1; i<=x.length(); i++)
        c[i][0]=0;

    for(int i=0; i<=y.length(); i++)
        c[0][i]=0;

    for(int i=1; i<=x.length(); i++){       //calculating length
        for(int j=1; j<=y.length(); j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
            }
            else{
                c[i][j]=c[i][j-1];
            }
        }
    }

    cout<<c[x.length()][y.length()]<<endl;

    int i,j;
    string l="";
    i=x.length();
    j=y.length();

    while(true){                //creating LCS
        if( i==0 || j==0)
            break;

        if (x[i-1]==y[j-1]){
            l=l+x[i-1];
            i=i-1;
            j=j-1;
        }
        else if (c[i-1][j]>=c[i][j-1])
            i=i-1;
        else
            j=j-1;
    }

    for(int i=l.length()-1; i>=0; i--)
        cout<<l[i];
}

int main(){
    string s1, s2;
    cin>>s1;
    cin>>s2;
    cout<<endl;

    LCS(s1, s2);
}
