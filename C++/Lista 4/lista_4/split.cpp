#include<iostream>
using namespace std;

int main (){
    int l[10];
    l[0] = 48;
    l[1] = 29;
    l[2] = 22;
    l[3] = 33;
    l[4] = 39;
    l[5] = 42;
    l[6] = 8;
    l[7] = 41;
    l[8] = 19;
    l[9] = 16;
    int i = 0;
    int j = 9;
    int aux;
    int meio = (i+j)/2;
    j = meio + 1;
    while(i<meio){
        if(l[i]>l[meio]){
            if(l[j]>l[meio]){
                j++;
            }
            else{
            aux = l[j];
            l[j] = l[i];
            l[i] = aux;    
            }
        }
        else {
            i++;
        }
    }
    while(j<10){
        if(l[j]<l[meio]){
            aux = l[j];
            l[j] = l[meio+1];
            l[meio+1] = l[meio];
            l[meio] = aux;
            meio++;
        }
        else{
              j++;
        }
    }
    for(i=0; i<10; i++){
        cout<<l[i]<<" ";
    }
}