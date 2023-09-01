***************
***Questao_1***
***************

void insertion (int n, int l[[n]){
    for(int i=1; i<n; i++){
        int aux = l[i];
        int j = i-1;
        while(aux<l[j] && j >=0){
            l[j+1] = l[j];
            j--;
        }
        l[j+1] = aux;
    }
    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}

void bubble (int n, int l[n]{
    int aux;
    int i = 0;
    while(i<n){
        int j = i+1;
        while(j<n){
            if(l[j]<l[i]){
                aux = l[i];
                l[i]=l[j];
                l[j]=aux;
            }
            j++;
        }
        i++;
    }
    for(i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}

void selection (int n, int l[n]{
    int aux;
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(l[j]<l[min]){
                min = j;
            }
        }
        aux = l[min];
        l[min] = l[i];
        l[i] = aux;
    }
    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}

***************
***Questao_2***
***************

#include <iostream>
using namespace std;

int main (){
    int n;
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
}

 tamanho de comandos na pior das hipoteses: 13/2n2 - 7n + 17
 n2 é n ao quadrado.

***************
***Questao_3***
***************

#include <iostream>
using namespace std;

int main (){
    int n;
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

***************
***Questao_4***
***************

int main (){
    int n;
    int l [n];
    int i=0;
    int j;
    int aux;
    while(i<n){
        j=i+1;
        while(j<n){
            if(i%2==0){
                if(l[j]<l[i]){
                    aux = l[i];
                    l[i] = l[j];
                    l[j] = aux;
                }
            }
            if(i%2!=0){
                if(l[j]<l[i]){
                    aux = l[j];
                    l[j] = l[i];
                    l[i] = aux;
                }
            }
            j++;
        }
        i++;
    }
    for(i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}
