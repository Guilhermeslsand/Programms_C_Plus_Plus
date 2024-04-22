#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> vetor;
    int i;

    // INSERINDO 5 VALORES DE 1 A 5  USANDO PUSH_BACK
   for(i = 0; i < 5; i++){
      vetor.push_back(i);
   }
    // PEGANDO O TAMANHO DO VETOR
    cout << "Tamanho do Vetor = " << vetor.size() << endl;

    // ACESSANDO OS 5 VALORES DO VETOR PASSANDO PELO INDEX
    for(i = 0; i < 5; i++){
      cout << "Valor do vetor [" << i << "] = " << vetor[i] << endl;
   }

   // OU USANDO O ITERATOR PARA ACESSAR OS VALORES.
   vector<int>::iterator v = vetor.begin();
   while( v != vetor.end()) {
      cout << "Valor do vetor = " << *v << endl;
      v++;
   }
    return 0;
}