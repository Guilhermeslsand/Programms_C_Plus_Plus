***************
***Questão_1***
***************
# include <cstdio>

class FilaInt {
    public :
    int * v ;
    int tam_max ;
    int ini ;
    int fim ;
    int cont ;

    FilaInt (int tamanho ){
        v = new int[ tamanho ];
        tam_max = tamanho ;
        ini = 0;
        fim = -1;
        cont = 0;
    }

    void enfileirar ( int x ){
        if(fim == tam_max){
            fim = 0;
        }
        fim ++;
        v[fim] = x;
        cont ++;
    }

    int desenfileirar (){
        int l;
        if(ini == tam_max){
            ini = 0;
        }
        l = v[ini];
        ini ++;
        cont --;
        return l;
    }

    int vazia (){
        if(cont == 0){
            return 1;
        }
        return 0;
    }
};

int main (){
    FilaInt f (10);
    for ( int i = 0; i < 10; i ++){
        f.enfileirar ( i );
    }
    for ( int i = 0; i < 5; i ++){
        printf ( " %d , " , f.desenfileirar ());
    }
    printf ( " \n " );
    for ( int i = 0; i < 5; i ++){
        f.enfileirar ( i );
    }
    while (! f.vazia ()){
    printf ( " %d , " , f.desenfileirar ());
    }
}

***************
***Questão_2***
***************
# include <cstdio>

class Posicao {
    public :
    int l ;
    int c ;
};

class FilaPosicao {
    public :
    Posicao * v ;
    int tam_max ;
    int ini ;
    int fim ;
    int cont ;

    FilaPosicao ( int tamanho ){
        v = new Posicao [ tamanho ];
        tam_max = tamanho;
        ini = 0;
        fim = -1;
        cont = 0;
    }

    void enfileirar ( Posicao p ){
        if(fim == tam_max){
            fim = 0;
        }
        fim ++;
        v[fim] = p;
        cont ++;
    }

    Posicao desenfileirar (){
        Posicao l;
        if(ini == tam_max){
            ini = 0;
        }
        l = v[ini];
        ini ++;
        cont --;
        return l;
    }

    int vazia (){
        if(cont == 0){
            return 1;
        }
        return 0;
    }
};

int main (){
    FilaPosicao f (10);
    Posicao p ;
    for (int i = 0; i < 10; i ++){
        p.l = i * i ;
        p.c = i * i * i ;
        f.enfileirar ( p );
    }
    for ( int i = 0; i < 5; i ++){
        p = f.desenfileirar ();
        printf ( " linha %d , coluna % d \n " , p.l , p.c );
    }
    printf ( " \n " );
    for ( int i = 0; i < 5; i ++){
        p.l = i * i ;
        p.c = i * i * i ;
        f.enfileirar ( p );
    }
    while (! f.vazia ()){
        p = f.desenfileirar ();
        printf ( " linha %d , coluna % d \n " , p.l , p.c );
    }
}

***************
***Questão_3***
***************
#include <iostream>
using namespace std;

class Posicao {
    public :
    int l ;
    int c ;
};

class FilaPosicao {
    public :
    Posicao * v ;
    int tam_max ;
    int ini ;
    int fim ;
    int cont ;

    FilaPosicao ( int tamanho ){
        v = new Posicao [ tamanho ];
        tam_max = tamanho;
        ini = 0;
        fim = -1;
        cont = 0;
    }

    void enfileirar ( Posicao pos ){
        if(fim == tam_max){
            fim = 0;
        }
        fim ++;
        v[fim] = pos;
        cont ++;
    }

    Posicao desenfileirar (){
        Posicao l;
        if(ini == tam_max){
            ini = 0;
        }
        l = v[ini];
        ini ++;
        cont --;
        return l;
    }

    int vazia (){
        if(cont == 0){
            return 1;
        }
        return 0;
    }
};

int main (){
    int n =10;
    FilaPosicao f(100);
    Posicao p;
    Posicao q;
    int M[n][n];
    float D[n][n];
    int i;
    int j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            M[i][j] = 0;
            D[i][j] = -1;
        }
    }
    M[9][0]=1;
    M[5][3]=1;
    M[5][4]=1;
    M[5][5]=1;
    M[5][6]=1;
    M[4][4]=1;
    M[4][5]=1;
    M[9][4]=1;
    M[9][5]=1;
    M[9][6]=1;
    M[0][8]=1;
    M[0][9]=1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(M[i][j] == 1){
                p.l = i;
                p.c = j;
                f.enfileirar(p);
                D[i][j] = 0;
            }
        }
    }

    while(!f.vazia()){
        p=f.desenfileirar();
        if(D[p.l-1][p.c] == -1 && p.l-1>=0){
            D[p.l-1][p.c] = D[p.l][p.c] + 1;
            q.l = p.l-1;
            q.c = p.c;
            f.enfileirar(q);
        }
        if(D[p.l][p.c-1] == -1 && p.c-1>=0){
            D[p.l][p.c-1] = D[p.l][p.c] + 1;
            q.l = p.l;
            q.c = p.c-1;
            f.enfileirar(q);
        }
        if(D[p.l+1][p.c] == -1 && p.l+1<n){
            D[p.l+1][p.c] = D[p.l][p.c] + 1;
            q.l = p.l+1;
            q.c = p.c;
            f.enfileirar(q);
        }
        if(D[p.l][p.c+1] == -1 && p.c+1<n){
            D[p.l][p.c+1] = D[p.l][p.c] + 1;
            q.l = p.l;
            q.c = p.c+1;
            f.enfileirar(q);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<D[i][j]<<" ";
        }
        cout<<"\n";
    }

}
