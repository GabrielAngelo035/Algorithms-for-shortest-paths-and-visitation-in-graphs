#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"DFS.h"
#include"BFS.h"
const int SIZE=10;

int min(int x,int y){
	if(x<y){
		return x;
	}else
		return y;
}

void Dijkstra(int  **matriz,int primeiro){
	int i,j=0,op=0,x=100000,v,aux;
	int C[SIZE];
	int D[SIZE];
	
	for(i=0;i<SIZE;i++){//Completa vetor c e coloca -1 na posicao inicial, o menos um significa que essa posicao ja foi usada
			C[i]=i;	
	}
	C[primeiro]=-1;

	for(i=0;i<SIZE;i++){
		if(matriz[primeiro][i]==0){
			D[i]= 99999;//se tiver 0 nas conexoes do primeiro vertice coloca-se 99999 como infinito
			aux++;
		}else{
			D[i]=matriz[primeiro][i];	
		}
	}

	while(op<SIZE){// repete n-2 vzs
		for(i=0;i<SIZE;i++){//pega o menor do vetor d que ainda n foi usado
			if((D[i]<x) && (C[i]!=-1)){
				v=C[i];
				x=D[i];
			}
		}x=100000;//volta o x inicial para comparacao
		
		for(i=0;i<SIZE;i++){//coloca -1 na posicao referente no c para mostrar que ja foi visitado
			if(C[i]==v){
				C[i]=-1;
			}
		}
		for(i=0;i<SIZE;i++){
			if((C[i]!=-1) && (matriz[v][i]!=0)){
				D[i] = min(D[i],(D[v]+matriz[v][i]));//calcula os minimos 
			}
		}
		op++;
	}
	
	for(i=0;i<SIZE;i++){
			if(D[i]<10){
			printf("[%d]      ",D[i]);
			}
			if(D[i]>=10 && D[i]<100 ){
			printf("[%d]     ",D[i]);
			}
			if(D[i]>=100 && D[i]<1000){
			printf("[%d]    ",D[i]);
			}
			if(D[i]>=1000 && D[i]<10000){
			printf("[%d]   ",D[i]);
			}
			if(D[i]>=10000){
			printf("[%d]  ",D[i]);
			}
	}printf("\n");
}

void Bellman(int  **matriz,int primeiro){
	int i,j,k,op=0,x=99999,v,y;
	int C[SIZE];
	int D[SIZE];
	
	for(j=0;j<SIZE;j++){
		D[j]=x;
	}
	D[primeiro]=0;
	
	for(i=0;i<SIZE-1;i++){
		for(j=0;j<SIZE;j++){
			for(k=0;k<SIZE;k++){
				if(matriz[j][k]!=0){
					D[k] = min(D[k],(D[j]+matriz[j][k])); 
				}
			}
		}
	}

	for(i=0;i<SIZE;i++){
			if(D[i]<10){
			printf("[%d]      ",D[i]);
			}
			if(D[i]>=10 && D[i]<100 ){
			printf("[%d]     ",D[i]);
			}
			if(D[i]>=100 && D[i]<1000){
			printf("[%d]    ",D[i]);
			}
			if(D[i]>=1000 && D[i]<10000){
			printf("[%d]   ",D[i]);
			}
			if(D[i]>=10000){
			printf("[%d]  ",D[i]);
			}
	}printf("\n");
}

void Floyd(int **matriz){
	int **D = (int**)malloc(sizeof(int*)*SIZE);
	int i,j,k;
	for(i=0;i<SIZE;i++){
		D[i]=(int*) malloc(sizeof(int)*SIZE);
		for(j=0;j<SIZE;j++){
			if(matriz[i][j]==0){
				D[i][j]=99999;
			}else{
				D[i][j]=matriz[i][j];
			}
			
		}
	}
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			for(k=0;k<SIZE;k++){
				D[j][k]=min(D[j][k],(D[j][i]+D[i][k]));
			}
		}
	}
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(D[i][j]<10){
			printf("[%d]      ",D[i][j]);
			}
			if(D[i][j]>=10 && D[i][j]<100 ){
			printf("[%d]     ",D[i][j]);
			}
			if(D[i][j]>=100 && D[i][j]<1000){
			printf("[%d]    ",D[i][j]);
			}
			if(D[i][j]>=1000 && D[i][j]<10000){
			printf("[%d]   ",D[i][j]);
			}
			if(D[i][j]>=10000){
			printf("[%d]  ",D[i][j]);
			}
		}
	printf("\n");
	}
	
	for(i=0;i<SIZE;i++){
		free(D[i]);
	}free(D);
}

void Create(int **matriz,float x,float densidade){
	int i,j,op=0;
	int aresta = x;

	do{
		i= rand()%(SIZE);
		j= rand()%(SIZE);
		if((j!=i) && (matriz[i][j]==0)){
			matriz[i][j]=(1+rand()%998);
			op++;
		}
	}while(op<aresta);
}

void Create2(int **matriz,float x,float densidade){
	int i,j,aresta=x,op=0;
	
	if(densidade>0.6){//Se a matriz tiver densidade maior que 0.6 faz-se o processo inverso 
		for(i=0;i<SIZE;i++){//completa ela toda com numeros aleatorios e faz o sorteio e coloca 0
			for(j=0;j<SIZE;j++){
				if(j>i){
					matriz[i][j]=(1+rand()%998);
					matriz[j][i]=matriz[i][j];
				}
			}
		}
		op=((SIZE*SIZE-SIZE))/2;

		while(op>aresta){
			i = rand()%(SIZE-1);
			j = rand()%(SIZE-1);
			if(matriz[i][j]!=0){
				matriz[i][j]=0;
				matriz[j][i]=matriz[i][j];
				op--;
			}
		}
		return;
	}
	else{
		while(op<aresta){
			i = rand()%(SIZE-1);
			j = rand()%(SIZE-1);
			if((j!=i) && (matriz[i][j]==0)){
				matriz[i][j]=(1+rand()%999);
				matriz[j][i]=matriz[i][j];
				op++;
			}
		}
		return;
	}
}

void Exibe(int **matriz){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(matriz[i][j]<10){
				printf("%d    ",matriz[i][j]);
			}
			if(matriz[i][j]>=10 && matriz[i][j]<100 ){
				printf("%d   ",matriz[i][j]);
			}
			if(matriz[i][j]>=100){
				printf("%d  ",matriz[i][j]);
			}
		}
		printf("\n");
	}
}

void ZeraGrafo(int **matriz){
	int i,j;
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			matriz[i][j]=0;
		}
	}
}

void graph(int n, int aresta, int **matriz){
	int i,j;
	FILE *graph;

	graph = fopen("graph.dat","w");
	fprintf(graph, "%d %d\n", n, aresta);//Coloco n e aresta

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(matriz[i][j]!=0){
				fprintf(graph, "%d %d %d\n", i, j, matriz[i][j]);//coloca vertice para vertice e peso
			}
		}
	}
	
	fclose(graph);
	system("graph.dat"); 
}

int main(){
	clock_t inicio, fim;
	unsigned long int tempo;
	int **matriz = (int**)malloc(sizeof(int*)*SIZE);
	unsigned int i,j,n=SIZE,op=-1;
	float densidade,aresta;
	srand(time(NULL));
	
	for(i=0;i<SIZE;i++){
		matriz[i]=(int*) malloc(sizeof(int)*SIZE);
		for(j=0;j<SIZE;j++){
			matriz[i][j]=0;
		}
	}

	while(op!=0){
		system("cls");
		printf(" A quantidade de vertices e: %d \n",n);
		printf("\n 0-Sair\n 1-Digitar a Densidade\n 2-Criar Grafo Orientado\n 3-Criar Grafo nao Orientado\n 4-Executar teste de tempo de caminhos minimos\n 5-Executar teste de tempo para visitação\n 6-Mostar Grafo\n 7-Gerar Arquivo\n");
		scanf("%d",&op);
		aresta = ((n*n-n)/2)*densidade;
		switch(op){
			case 0:
				break;
				
			case 1:
				scanf("%f",&densidade);
				aresta = ((n*n-n)/2)*densidade;
				printf(" O numero de arestas e %f\n",aresta);
				system("pause");
				break;
			
			case 2:
				ZeraGrafo(matriz);
				Create(matriz,aresta,densidade);
				printf("\n Grafo criado\n");
				Exibe(matriz);
				system("pause");
				break;
			
			case 3:
				ZeraGrafo(matriz);
				Create2(matriz,aresta,densidade);
				printf("\n Grafo criado\n");
				Exibe(matriz);
				system("pause");
				break;
				
			case 4:
				Exibe(matriz);
				printf("\n\nDjikstra\n");
				inicio = clock();
				for(i=0;i<SIZE;i++){
					Dijkstra(matriz,i);
				}
				fim = clock();
				tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
				printf("tempo: %lu milissegundos\n",tempo);
								
				printf("\n\nBellman\n");
				inicio = clock();
				for(i=0;i<SIZE;i++){
					Bellman(matriz,i);
				}
				fim = clock();
				tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
				printf("tempo: %lu milissegundos\n",tempo);
				
				printf("\n\nFloyd\n");
				inicio = clock();
				Floyd(matriz);
				fim = clock();
				tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
				printf("tempo: %lu milissegundos\n",tempo);
				system("pause");
				break;
			
			case 5:
				printf("1-Crescente e 2-Descrescente\n");scanf("%d",&op);
				if(op==1){
					Exibe(matriz);
					printf("\n\nDFS\n");
					inicio = clock();
					DFS(matriz,0,SIZE);
					fim = clock();
					tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
					printf("tempo: %lu milissegundos\n",tempo);
					
					printf("\n\nBFS\n");
					inicio = clock();
					BFS(matriz,0,SIZE);
					fim = clock();
					tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
					printf("tempo: %lu milissegundos\n",tempo);
					system("pause");
				}
				if(op==2){
					Exibe(matriz);
					printf("\n\nDFS2\n");
					inicio = clock();
					DFS2(matriz,0,SIZE);
					fim = clock();
					tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
					printf("tempo: %lu milissegundos\n",tempo);
					
					printf("\n\nBFS2\n");
					inicio = clock();
					BFS2(matriz,0,SIZE);
					fim = clock();
					tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
					printf("tempo: %lu milissegundos\n",tempo);
					system("pause");
					system("pause");
				}
				break;
				
			case 6:
				Exibe(matriz);
				system("pause");
				break;
				
			case 7:
				graph(SIZE,aresta,matriz);
				break;
		}
	}		

	for(i=0;i<SIZE;i++){
		free(matriz[i]);
	}free(matriz);
	
	return 0;
}
