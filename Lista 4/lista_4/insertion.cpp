#include<iostream>
using namespace std;

int main (){
    int l [5];
    l[0] = 9;
    l[1] = 5;
    l[2] = 1;
    l[3] = 4;
    l[4] = 3;

    for(int i=1; i<5; i++){
        int aux = l[i];
        int j = i-1;
        while(aux<l[j] && j >=0){
            l[j+1] = l[j];
            j--;
        }
        l[j+1] = aux;
    }
    for(int i=0; i<5; i++){
        cout<<l[i]<<" ";
    }
}