/*
  nome: BuscaBinaria.cpp
  autor: Giovanni Rafael Serafim
  data: 05/6/2024
  descrição: informa a posição do elemento que o usuario pedir de um vetor ordenado.
*/

#include <stdio.h>

void buscabinaria(int *, int, int); //prototipando a função da busca binaria

void InsertionSort (int*, int);//prototipando a função do insertionSort


int main()
{
    int vet[10];
    int tam = sizeof(vet)/sizeof(int);
    puts("vetor de tamanho 10 ");
    
    for(int i=0;i<tam;i++)//preenchendo o vetor
    {
    	printf("digite a posicao %d do vetor: ", i+1);
    	scanf("%d", &vet[i]);
	}
    
    printf("vetor atual: ");

		for (int i=0; i<tam; i++) //printando o vetor
	{
		printf("%d|", vet[i]);
	}
	
	InsertionSort(vet, tam);

	printf("\nvetor ordenado pelo insertionSort: ");
	
		for (int i=0; i<tam; i++) //printando o vetor ordenado
	{
		printf("%d|", vet[i]);
	}
	
	
	buscabinaria( vet,  0,  tam-1); //chamando a função da busca binaria
	
}

void InsertionSort(int *lista, int tamanho) 
{
int i,j,aux;
  for(i=0; i<tamanho-1; i++) //percorre o vetor
  {
    if(lista[i]>lista[i+1]) //se o numero atual for maior que o da frente
	{
     aux=lista[i+1];
     lista[i+1]=lista[i]; lista[i]=aux; //troca
     j=i-1; // j recebe o numero anterior
      while(j>=0) //enquanto tiver numeros pro j voltar
	  {
       if(aux<lista[j]) //se o numero trocado for menor que o anterior
	    {
        lista[j+1]=lista[j]; lista[j]=aux;
        }
		else{
         break;
             }
         j=j-1; // j volta mais um até voltar todo o vetor ou até o numero não ser menor que ele
         }
      }
   }
}


void buscabinaria (int *v, int ini, int fim)
{
	int elem;//elemento pedido pelo usuario
	int meio;
	int achou = 0;//variavel para caso o elemento não seja achado
	
	printf("\ndigite o elemento desejado: ");
	scanf("%d", &elem);
	
	while (ini<=fim) //enquanto o vetor existir
	{
		meio = (ini+fim)/2;
		
		if (elem == v[meio])
		{
			achou = 1;
			break;
			
		}
		
		else if(elem < v[meio])//se menor, cortar a metade maior do vetor
		{
			fim = meio - 1;
	
		}
		else//se maior, cortar a metade menor do vetor
		{
			ini = meio + 1;
		}		
	}
	
	if(achou == 1)
	{
		printf("o %d esta na posicao %d", elem, meio+1);
	}
	else
	{
		printf("o %d nao existe nesse vetor", elem);
	}
	
}
