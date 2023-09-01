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