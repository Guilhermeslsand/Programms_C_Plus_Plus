#include<iostream>
using namespace std;

int main (){
    int i = 0;
    int inv = 0;
    int  l[12];
    l[0] = 1;
    l[1] = 2;
    l[2] = 18;
    l[3] = 99;
    l[4] = 4;
    l[5] = 17;
    l[6] = 96;
    l[7] = 97;
    l[8] = 19;
    l[9] = 77;
    l[10] = 84;
    l[11] = 85;
    while(i<11){
        int j = i+1;
        while(j<12){
            if(l[i] > l[j]){
                inv = 1 + inv;
            }
            j++;
        }
        i++;
    }
    cout<<inv<<"\n";
}