#include<iostream>
using namespace std;

void merge_3(){
    int i = 0;
    int j = 8;
    int k = 4;
    int p = 0;
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
    while(i < 4){
        if(l[i]>l[k] || l[i]>l[j]){
            if(l[k]<l[j]){
                M[p] = l[k];
                k++;
            }
            else{
                M[p] = l[j];
                j++;
            }
        }
        else{
            M[p] = l[i];
            i++;
        }
        p++;
    }

    for(p=0; p<12; p++){
        cout<<M[p]<<" ";
    }
}

int main (){ 
    merge_3();
}
