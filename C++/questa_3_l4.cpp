#include<iostream>
using namespace std;

int main (){
    int l[10];
    int i = 0;
    int tam = 0;
    int escolha;
    int aux;
    l[0] = 1;
    l[1] = 3;
    l[2] = 4;
    l[3] = 7;
    l[4] = 11;
    l[5] = 14;
    while(i<10){
        if(l[i]!=0){
            tam++;
        }
        i++;
    }
    do(escolha<1 || escolha>2){
        cin>>escolha;
        switch (escolha){
            case 1:
            i = 0;
            cin>>aux;
            while(i<tam){
                if(aux>l[i]){
                    tam++;
                    l[tam-1] = l[i+1];
                    l[i+1] = aux;
                    aux = l[tam-1];
                }
            }
        }

     }
     for(i=0; i<tam; i++){
        cout<<l[tam]<<" ";
     }
}
