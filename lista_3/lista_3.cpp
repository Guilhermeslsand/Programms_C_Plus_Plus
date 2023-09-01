#include <iostream>
using namespace std;

void trocar_linha(int i, int j, float** mat, int n, int m){
    int aux;
    int k;
    cout<<"Qual linha voce quer trocar"<<endl;
    cin>>i;
    cout<<"Por qual linha voce quer trocar"<<endl;
    cin>>j;
    for(k=0; k<m; k++){
        aux = mat[i-1][k];
        mat[i-1][k] = mat[j-1][k];
        mat [j-1][k] = aux;        
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void multiplicar_linha(int i, int j, float a, float** mat, int n, int m){
    int k;
    cout<<"Qual linha voce quer multiplicar"<<endl;
    cin>>i;
    cout<<"Por quanto voce quer multiplicar"<<endl;
    cin>>a;
    for(k=0; k<m; k++){
        mat[i-1][k] = a * mat[i-1][k];
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void somar_linha(int i, int j, float a, float **mat, int n, int m){
    int k;
    cout<<"Qual linha voce quer alterar"<<endl;
    cin>>i;
    cout<<"Qual linha voce quer somar"<<endl;
    cin>>j;
    cout<<"Por quanto voce vai multiplicar"<<endl;
    cin>>a;
    for(k=0; k<m; k++){
        mat[i-1][k] = mat[i-1][k] + a*mat[j-1][k];
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void zerar_posicao_abaixo(int i, int j, float **mat, int n, int m){
    cout<<"Indique uma posicao da matriz"<<endl;
    cin>>i; 
    cin>>j; 
    mat[i-1][j-1] = mat[i-1][j-1]-(mat[i-1][j-1]/mat[j-1][j-1])*mat[j-1][j-1];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void zerar_coluna_abaixo (int i, int j, float **mat, int n, int m){
    cout<<"Indique qual coluna voce quer zerar"<<endl;
    cin>>j;
    for(i=j; i<n; i++){
        mat[i][j-1] = 0;
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void triangular_superior (int i, int j, float **mat, int n, int m){
    for (i=1; i<n; i++){
        for(j=0; j<i; j++){
        mat[i][j] = 0;    
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void zerar_posicao_acima (int i, int j, float **mat, int n, int m){
    cout<<"Indique uma posicao da matriz"<<endl;
    cin>>i; //i=1 
    cin>>j; //j=2
    mat[i-1][j-1] = mat[i-1][j-1]-(mat[i-1][j-1]/mat[j-1][j-1])*mat[j-1][j-1];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void zerar_coluna_acima (int i, int j, float **mat, int n, int m){
    cout<<"Indique qual coluna voce quer zerar"<<endl;
    cin>>j;
    for(i=0; i<j-1; i++){
        mat[i][j-1] = 0;;
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void triangular_inferior (int i, int j, float **mat, int n, int m){
    for (j=1; j<m; j++){
        for(i=0; i<j; i++){
        mat[i][j] = 0;    
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matriz_diagonal (int i, int j, float **mat, int n, int m){
    for (i=1; i<n; i++){
        for(j=0; j<i; j++){
        mat[i][j] = 0;
        mat[j][i] = 0;  
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int i, j;
    int n, m;
    float a;
    n = 4;
    m = 4;
    float** mat = new float * [n];
    for (int i = 0; i < n; i++){
        mat[i] = new float[m];
    }
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;
    mat[0][3] = 4;
    mat[1][0] = 1;
    mat[1][1] = 2;
    mat[1][2] = 4;
    mat[1][3] = 3;
    mat[2][0] = 2;
    mat[2][1] = 1;
    mat[2][2] = 3;
    mat[2][3] = 4;
    mat[3][0] = 4;
    mat[3][1] = 3;
    mat[3][2] = 2;
    mat[3][3] = 1;
    //trocar_linha (i, j, mat, n, m);
    //multiplicar_linha (i, j, a, mat, n, m);
    //somar_linha (i, j, a, mat, n, m);
    //zerar_posicao_abaixo (i, j, mat, n, m);
    //zerar_coluna_abaixo (i, j, mat, n, m);
    //triangular_superior (i, j, mat, n, m);
    //zerar_posicao_acima (i, j, mat, n, m);
    //zerar_coluna_acima (i, j, mat, n, m);
    //triangular_inferior (i, j, mat, n, m);
    //matriz_diagonal (i, j, mat, n, m);
}   

