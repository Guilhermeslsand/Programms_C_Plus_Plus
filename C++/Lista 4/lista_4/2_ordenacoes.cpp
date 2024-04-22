#include <iostream>
using namespace std;

int main (){
    int l[n];
    int aux;
    int i = 0;
    int j;
    while(i<n){
        j = i+2;
        while(j<n){
            if(l[j]<l[i]){
                aux = l[i];
                l[i] = l[j];
                l[j] = aux;
            }
            j = j+2;
        }
        i = i+2;
    }
    i = 1;
    while(i<n-1){
        int min=i;
        j = i+2;
        while(j<n){
            if(l[j]<l[min]){
                min = j;
            }
            j = j+2;
        }
        aux = l[min];
        l[min] = l[i];
        l[i] = aux;
        i = i+2;
    }
    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}