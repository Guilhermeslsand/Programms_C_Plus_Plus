#include<iostream>
using namespace std;

int main (){
    int l [5];
    l[0] = 20;
    l[1] = 12;
    l[2] = 10;
    l[3] = 15;
    l[4] = 2;
    int aux;
    //O i marca da onde vai começar minha busca e mudança.
    for(int i=0; i<4; i++){
        //O min marca a posicao do menor elemento.
        int min=i;
        //J vai servir para fazer a comparacao com o menor elemento.
        for(int j=i+1; j<5; j++){
            if(l[j]<l[min]){
                min = j;
            }
        }
        aux = l[min];
        l[min] = l[i];
        l[i] = aux;
    }
    for(int i=0; i<5; i++){
        cout<<l[i]<<" ";
    }
}