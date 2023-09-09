#include<stdio.h>
#include<stdlib.h>
#define BFS_H
//const int SIZE=8;

typedef struct TipoItem2{ 
	int vertice;
}TipoItem2;

typedef struct TipoCelula2 *TipoApontador2; 

typedef struct TipoCelula2{
	TipoItem2 Item;
	TipoApontador2 Prox;
}TipoCelula2; 

typedef struct TipoFila{
	TipoApontador2 Frente, Tras;
}TipoFila;

void FFVazia(TipoFila *Fila ) { 
	Fila ->Frente = (TipoApontador2) malloc(sizeof(TipoCelula2 )); 
	Fila ->Tras = Fila ->Frente; 
	Fila ->Frente ->Prox = NULL; 
}

int Vazia(TipoFila Fila ) { 
	return ( Fila.Frente == Fila.Tras) ;
}

void Enfileira (TipoItem2 x, TipoFila *Fila ) { 
	Fila ->Tras ->Prox = (TipoApontador2) malloc(sizeof(TipoCelula2 )); 
	Fila ->Tras = Fila ->Tras ->Prox;
	Fila ->Tras ->Item = x; 
	Fila ->Tras ->Prox = NULL; 
}

void Desenfileira(TipoFila *Fila , TipoItem2 *Item) { 
	TipoApontador2 q; 
	if (Vazia( *Fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ; return;
	} 
	q = Fila ->Frente; 
	Fila ->Frente = Fila ->Frente ->Prox; 
	*Item = Fila ->Frente ->Item; 
	free(q); 
}
void BFS(int **matriz,int primeiro,int SIZE){
	int aux,i,j,visitados[SIZE];
	TipoFila fila;
	FFVazia(&fila);
	for(i=0;i<SIZE;i++){
		visitados[i]=0;
	}
	
	TipoItem2 item;
	item.vertice=primeiro;
	Enfileira(item,&fila);
	visitados[primeiro]=1;
	
	while(!Vazia(fila)){
		i=fila.Frente->Prox->Item.vertice;
		Desenfileira(&fila,&item);
		for(j=0;j<SIZE;j++){
			if((matriz[i][j] != 0) && (visitados[j]==0)){
				visitados[j]=1;
				item.vertice=j;
				//printf(" %d ",item.vertice);
				Enfileira(item,&fila);
			}
		}
	}
}
void BFS2(int **matriz,int primeiro,int SIZE){
	int aux,i,j,visitados[SIZE];
	TipoFila fila;
	FFVazia(&fila);
	for(i=0;i<SIZE;i++){
		visitados[i]=0;
	}
	
	TipoItem2 item;
	item.vertice=primeiro;
	Enfileira(item,&fila);
	visitados[primeiro]=1;
	
	while(!Vazia(fila)){
		i=fila.Frente->Prox->Item.vertice;
		Desenfileira(&fila,&item);
		for(j=SIZE-1;j>=0;j--){
			if((matriz[i][j] != 0) && (visitados[j]==0)){
				visitados[j]=1;
				item.vertice=j;
				//printf(" %d ",item.vertice);
				Enfileira(item,&fila);
			}
		}
	}
}
