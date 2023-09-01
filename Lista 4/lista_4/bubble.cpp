#include<iostream>
using namespace std;

int main (){
    int l [5];
    l[0] = 10;
    l[1] = 5;
    l[2] = 15;
    l[3] = 0;
    l[4] = 12;
    int aux;
    int i = 0;
    while(i<5){
        int j = i+1;
        while(j<5){
            if(l[j]<l[i]){
                aux = l[i];
                l[i]=l[j];
                l[j]=aux;
            }
            j++;
        }
        i++;
    }
    for(i=0; i<5; i++){
        cout<<l[i]<<" ";
    }
}
