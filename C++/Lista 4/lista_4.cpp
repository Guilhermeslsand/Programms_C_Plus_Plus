#include <iostream>
using namespace std;

int busca_binaria (){
    int i = 0;
    int j = n;
    int meio = 5;
    int busca;
    int vet[n];
    vet [0] = 1;
    vet [1] = 2;
    vet [2] = 18;
    vet [3] = 20;
    vet [4] = 29;
    vet [5] = 30;
    vet [6] = 39;
    vet [7] = 44;
    vet [8] = 55;
    vet [9] = 56;
    vet [10] = 84;
    vet [11] = 96;
    cout<<"Digite um numero para buscar:\n";
    cin>>busca;
    while(i<j){
        int meio = (j+i)/2;
        if(vet[meio]==busca){
            return 1;
        }
        else if(vet[meio]<busca){
            i= meio +1;
        }
        else{
            j = meio;
        }
    }
    return -1;
}

int busca_ternaria (int vet, int n){
    //vet[3n];
    int i = 0;
    int k = n;
    int j = 2n;
    int busca;
    cout<<"Digite um numero para buscar:\n";
    cin>>busca;
    while(i<j){
        if(busca==vet[k]){
            cout<<k<<endl;
            return 1;
        }
        else if(busca<vet[k]){
            j=k;
        }
        else if(busca>vet[k] && busca<vet[j]){
            i=k;
            j--;
        }
        else{
            i=j;
            j=11;

        }
        k=(j+i)/2;
    }
    return -1;
}

void merge_3 (){
    int i = 0;
    int k = 4;
    int j = 8;
    int p = 0;
    int vet[12];
    int M[12];
    vet [0] = 1;
    vet [1] = 2;
    vet [2] = 18;
    vet [3] = 20;
    vet [4] = 4;
    vet [5] = 17;
    vet [6] = 96;
    vet [7] = 97;
    vet [8] = 19;
    vet [9] = 77;
    vet [10] = 84;
    vet [11] = 85;
    while(p<12){
        if(vet[i]<vet[k] && vet[i]<vet[j]){
            M[p]=vet[i];
            i++;
        }
        else if(vet[k]<vet[i] && vet[k]<vet[j]){
            M[p]=vet[k];
            k++;
        }
        else if(vet[j]<vet[i] && vet[j]<vet[k]){
            M[p]=vet[j];
            j++;
        }
        p++;
    }
    for(p=0; p < 12; p++){
        cout<< M[p]<<" ";
    }
}

int main (){
    //busca_binaria();
    //busca_ternaria();
    merge_3();
}
