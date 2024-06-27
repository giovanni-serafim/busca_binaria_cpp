/*
  nome: BuscaBinaria.cpp
  autor: Giovanni Rafael Serafim
  data: 05/6/2024
  descrição: informa a posição do elemento que o usuario pedir de um vetor ordenado.
*/



#include <stdio.h>

void buscabinaria(int *, int, int); //prototipando a função


int main()
{
	int vet[] = {-5, 1, 3, 8, 10, 12, 15, 17, 19, 24};
	
    int tam = sizeof(vet)/sizeof(int);
	
		for (int i=0; i<tam; i++) //printando o vetor
	{
		printf("%d|", vet[i]);
	}
	
	buscabinaria( vet,  0,  tam-1); //chamando a função
	
}

void buscabinaria (int *v, int ini, int fim)
{
	int elem;
	int meio;
	int achou = 0;
	
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
