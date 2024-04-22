***********************
*******Questao 2*******
***********************
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *l;
  int aux;
  int i;
  int tam;
  int metade;

  printf("Digite um valor PAR para tamanho do vetor: ");
  scanf("%d", &tam);
  l = (int*)malloc(tam*sizeof(int));
  if(l == NULL)
  {
    printf("Erro:Espaco insuficiente\n");
    exit(1);
  }

  if(tam == 2)
  {
    for(i = 0; i < tam; i++)
    {
      printf("l[%d]: ",i);
      scanf("%d", &l[i]);
    }
    for(i = 0; i < tam; i++)
    {
      printf("%d ", l[i]);
    }
  }

  else
  {
    metade = (tam-1)/2;
    if(metade%2 == 0)
    {
      metade++;
    }
    for(i = 0; i < tam; i++)
    {
      printf("l[%d]: ", i);
      scanf("%d", &l[i]);
    }
    for(i = 0; i < tam/2; i++)
    {
      if(i%2 == 1)
      {
        aux = l[i];
        l[i] = l[i+metade];
        l[i+metade] = aux;
      }
    }
    for(i = 0; i < tam; i++)
    {
      printf("%d ", l[i]);
    }
  }
  free (l);
  return 0;
}

***********************
*******Questao 3*******
***********************
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *l, *h;
    int tam;
    int i;
    int j = 0;
    int aux;

    printf("Digite um valor PAR para tamanho do vetor: ");
    scanf("%d", &tam);
    l = (int*)malloc(tam*sizeof(int));
    if(l == NULL)
    {
      printf("Erro:Espaco insuficiente\n");
      exit(1);
    }
    h = (int*)malloc(tam*sizeof(int));
    if(h == NULL)
    {
      printf("Erro:Espaco insuficiente\n");
      exit(1);
    }
    for(i = 0; i < tam; i++)
    {
      printf("l[%d]: ",i);
      scanf("%d", &l[i]);
      if(i>=(tam+1)/2)
      {
        h[j] = l[i];
        j++;
      }
    }
    for(i=tam-2; i>0; i--)
    {
        if(i<=tam/2)
        {
          l[i+i] = l[i];
        }
    }
    j=0;
    for(i = 0; i < tam; i++)
    {
      if(i%2==1)
      {
        l[i] = h[j];
        j++;
      }
      printf("%d ",l[i]);
    }
    free (l);
    free (h);
    return 0;
  }

***********************
*******Questao 4*******
***********************
#include <stdio.h>
#include <stdlib.h>
#define tam 10

int main()
{
  int l[tam];
  int aux;
  int n=0;
  int i;

  for(i = 0; i < tam; i++)
  {
    printf("l[%d]: ",i);
    scanf("%d", &l[i]);
    if(l[i]!=0)
    {
        n++;
    }
  }
  for(i=0; i<tam; i++){
    if(l[i] == 0)
    {
        aux = l[i];
        l[i] = l[i+1];
        l[i+1] = aux;
    }
  }
  printf("\n");
  for(i=0; i<n/2; i++)
  {
    aux = l[i];
    l[i]=l[n-1-i];
    l[n-1-i]=aux;
  }
  for(i=0; i<n; i++)
  {
  printf("%d ", l[i]);
  }
  printf("\n");
  printf("n:%d\n", n);
  return 0;
}

***********************
*******Questao 5*******
***********************

#include <stdio.h>
#include <stdlib.h>
#define tam 10

int main()
{
  int l[tam];
  int aux;
  int n;
  int i;

  for(i = 0; i < tam; i++)
  {
    printf("l[%d]: ",i);
    scanf("%d", &l[i]);
    if(l[i] != '\0')
    {
      n++;
    }
  }
  for(i=0; i<tam; i++){
    if(l[i]==0)
    {
      aux = l[i];
      l[i] = l[i+1];
      l[i+1] = aux;
    }
  }
  aux = l[n-1];
  for(i=n-1; i>=0; i--){
    l[i]=l[i-1];
    if(i == 0)
    {
      l[i]=aux;
    }
  }
  for(i=0; i<n; i++){
  printf("%d ", l[i]);
  }
  printf("\n");
  printf("%d\n", n);
  return 0;
}
