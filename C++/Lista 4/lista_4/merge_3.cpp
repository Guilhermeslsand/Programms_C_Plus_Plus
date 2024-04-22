#include<iostream>
using namespace std;

void merge_3(){
    int i = 0;
    int k = 4;
    int aux;
    int M [12];
    int  l[12];
    l[0] = 1;
    l[1] = 2;
    l[2] = 18;
    l[3] = 99;
    l[4] = 4;
    l[5] = 17;
    l[6] = 96;
    l[7] = 97;
    l[8] = 19;
    l[9] = 77;
    l[10] = 84;
    l[11] = 85;
    while(i < k){
        M[i] = l[i];
        i++;
    }
    while (k<8){
        i=k-1;
        while(i>=0){
            if(M[i]>l[k]){
                    M[i+1] = M[i];
                    M[i] = l[k];
                }
                M[i] = l[k];
            }    
            else{
            M[k-1] = l[k];
            }
        }
        k++;
    }    

    for(i=0; i<12; i++){
        cout<<M[i]<<" ";
    }
}

int main (){ 
    merge_3();
}
