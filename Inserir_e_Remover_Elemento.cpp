#include <iostream>
using namespace std;

int inserir_ele(int *l, int tam, int i){
    int aux;
    cout<<"Qual numero voce quer inserir\n";
    cin>>aux;
    while(i<tam){
        if(aux<l[i]){
            l[tam]=l[i];
            l[i] = aux;
            aux = l[tam];
        }
        i++;
    }
    tam++;
    return tam;
}

int remover_ele(int *l, int tam, int i){
    int aux;
    cout<<"Qual numero voce quer remover\n";
    cin>>aux;
    while(i<tam){
        if(aux == l[i]){
            l[tam] = l[i];
            l[i] = l[i+1];
            aux = l[i+1];
        }
        i++;
    }
    l[tam] = 0;
    tam--;
    return tam;

}

int main (){
    int i = 0;
    int *l = new int[m];//m é o tamanho do vetor;
    int tam = n;//n é o numero de elementos;
    int escolha;
    int aux;
    cout<<"Digite 1 para inserir \nDigite 2 para remover\n";
    cin>>escolha;
    do{
        switch (escolha)
        {
        case 1:
            tam = inserir_ele(l, tam, i);
            break;
        
        case 2:
            tam = remover_ele(l, tam, i);
            break;
        
        default:
            break;
        }
    }while(escolha < 1 || escolha > 2);
    for(i=0; i<tam; i++){
        cout<<l[i]<<" ";
    }

    delete []l;
}