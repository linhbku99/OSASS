#include <fstream>
#include <iostream>
using namespace std;

int main (){
    int n;
    int a[6];
    cout<<"N=";
    cin>>n;
    for (int i=0;i<n;i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
    ofstream outfile;
    outfile.open("phan_tich.txt");
    for (int i=0;i<n;i++){
        outfile<<a[i]<<"=";
        if (a[i]<0) {
            outfile<<"-";
            a[i]=-a[i];
        }
        if (a[i]<2) outfile<<a[i]<<endl;
        else {
            int t=2;
            while (a[i]>1) {
                if (a[i]%t==0) {
                    a[i]=a[i]/t;
                    if (a[i]==1) {
                        outfile<<t<<endl;
                        break;
                    }
                    else outfile<<t<<"*";
                }
                else t++;
            }
        }
    }
    outfile.close();
}
