# include <cstdio>

class FilaInt {
public :
int * v ;
int tam_max ;
int ini ;
int fim ;
int cont ;
// m é todo construtor , inicializa a fila
FilaInt (int tamanho ){
v = new int[ tamanho ]; // cria vetor de inteiros com o tamanho desejado
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
FilaInt f (10); // cria fila de tamanho 10
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