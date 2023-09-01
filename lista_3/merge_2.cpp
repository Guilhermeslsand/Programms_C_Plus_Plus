#include <iostream>
using namespace std;

int main (){
    int l[n];
    int aux;
    int i;
    int r [n];
    int j;
    for(i=0; i<n/2; i++){
        for(j= i+1; j<n/2; j++){
            if(l[j]<l[i]){
                aux = l[i];
                l[i]=l[j];
                l[j]=aux;
            }   
        }
    }    
    for(i=n/2; i<n; i++){
        for(j= i+1; j<n; j++){
            if(l[j]<l[i]){
                aux = l[i];
                l[i]=l[j];
                l[j]=aux;
            }   
        }
    }
    i = 0;
    j = n/2;
    int k = 0;
    while(k<n){
        if(l[i]<l[j] && i<n/2){
            r[k] = l[i];
            i++;
            k++;
        }
        if(l[j]<l[i] && j<n){
            r[k] = l[j];
            j++;
            k++;
        }
        if(i>=n/2){
            while(j<n){
                r[k] = l[j];
                j++;
                k++;
            }
        }
        if(j>=n){
            while(i<n/2){
                r[k] = l[i];
                i++;
                k++;
            }
        }
    }    
    for(i=0; i<n; i++){
        cout<<r[i]<<" ";
    }
}