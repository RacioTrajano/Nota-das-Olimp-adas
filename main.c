#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criação da struct dos avaliadores

typedef struct notas{

char nome [20];
float nota[10];
char **descricao;

}avaliador;



int main () {
// definição das variáveis
int N;
int M;
int soma_maior=0;
int soma_menor=0;
int menor=100;
int menor_pos;
int maior=0;
int maior_pos;
int E;


scanf("%d %d", &N, &M);
avaliador atleta[N];
// alocação da descrição dos atletas
for (int i=0; i<N; i++){
  atleta[i].descricao = calloc(10,sizeof(char*));
  for (int k=0; k<10; k++){
    atleta[i].descricao[k] = calloc(100,sizeof(char));
  }
}

// leitura da entrada
for (int i=0; i< N; i++){
  fgets(atleta[i].nome,20, stdin);
  // tratamento do \n
  if(atleta[i].nome[strlen(atleta[i].nome)-1]=='\n')
  atleta[i].nome[strlen(atleta[i].nome)-1]= '\0';
  // leitura das notas e das descrições de cada atleta
  for(int k=0; k<M; k++){
    scanf("\n%f", &atleta[i].nota[k]);
    fgets(atleta[i].descricao[k],100, stdin);
    // tratamento do \n no final
    atleta[i].descricao[k][strlen(atleta[i].descricao[k]-1)]= '\0';
  }
}
scanf("\n%d", &E);
E = E -1;

// verificar os desclassificados por maior nota
for (int i=0; i<N; i++){
  soma_maior=0;
  for(int k=0; k<M; k++){
    soma_maior = atleta[i].nota[k] + soma_maior;
  }
  if (soma_maior > maior){
    maior =soma_maior;
    maior_pos =i;
  }
}

// verificar os desclassificados por menor nota;
for (int i=0; i<N; i++){
  soma_menor=0;
  for(int k=0; k<M; k++){
    soma_menor = atleta[i].nota[k] + soma_menor;
  }
  if (soma_menor < menor){
    menor =soma_menor;
    menor_pos =i;
  }
}


// impressao da saída
for (int i=0; i<N; i++){
  if (i != menor_pos && i!= maior_pos)
  printf("%s - %.1f %s", atleta[i].nome,atleta[i].nota[E], atleta[i].descricao[E]);
  else if(i == menor_pos)
  printf("%s - Descartado: menor nota ", atleta[i].nome);
  else if(i == maior_pos)
  printf("%s - Descartado: maior nota", atleta[i].nome);
}
  return 0;
}