#include<stdio.h>
#include<stdlib.h>
#define DFS_H
//const int SIZE=8;

typedef struct TipoItem{ 
    int vertice; 
}TipoItem; 

typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;


// Funções de manipulação da pilha dinâmica

void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontador Aux; 
	Aux = (TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++; 
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontador q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

void DFS(int **matriz,int primeiro,int SIZE){
	int aux,i,j=0,visitados[SIZE];
	TipoPilha pilha;
	FPVazia(&pilha);
	for(i=0;i<SIZE;i++){
		visitados[i]=0;
	}
	
	TipoItem item;
	item.vertice=primeiro;
	Empilha(item,&pilha);
	visitados[primeiro]=1;
	
	while(!Vazia(pilha)){
		i=pilha.Topo->Prox->Item.vertice;
		//printf(" [%d]",i);
		
		for(j=0;j<SIZE;j++){
			if((matriz[i][j] != 0) && (visitados[j]==0)){
				visitados[j]=1;
				item.vertice=j;
				//printf(" %d ",item.vertice);
				Empilha(item,&pilha);
				break;
			}
		}
		if(j==SIZE){
			Desempilha(&pilha,&item);
			//printf("\ndesempilha %d\n",item.vertice);
			}
	}
}

void DFS2(int **matriz,int primeiro,int SIZE){
	int aux,i,j,visitados[SIZE];
	TipoPilha pilha;
	FPVazia(&pilha);
	for(i=0;i<SIZE;i++){
		visitados[i]=0;
	}
	
	TipoItem item;
	item.vertice=primeiro;
	Empilha(item,&pilha);
	visitados[primeiro]=1;
	
	while(!Vazia(pilha)){
		i=pilha.Topo->Prox->Item.vertice;
		//printf(" [%d]",i);
		
		for(j=SIZE-1;j>=0;j--){
			if((matriz[i][j] != 0) && (visitados[j]==0)){
				visitados[j]=1;
				item.vertice=j;
				//printf(" %d ",item.vertice);
				Empilha(item,&pilha);
				break;
			}
		}
		if(j==-1){
			Desempilha(&pilha,&item);
			//printf("\ndesempilha %d\n",item.vertice);
		}
	}
}
