#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *vet, int nVetor);

int main(){

    int nVetor=0, controle=0, i=0;
    srand(time(NULL));

       do{
        printf("\nTamanho do vetor desejado: ");
        scanf("%d", &nVetor);


        int *vetor = malloc(sizeof(int)*nVetor);
        
        for(i = 0; i < nVetor; i++){
            vetor[i] = rand()%100;
        }

        printf("\nValores Gerados:");
        for (i = 0; i < nVetor; i++){
            printf("\n n[%d]: %d", nVetor, vetor[i]);
        }
        

        InsertionSort(vetor, nVetor);

        printf("\n\nValores Ordenados:");
        for (i = 0; i < nVetor; i++){
            printf("\n n[%d]: %d", nVetor, vetor[i]);
        }

        free(vetor);
        printf("\n\nDeseja realizar a operacao novamente?\n1 = Sim \n2 = Nao\n");
        scanf("%d", &controle);
    } while(controle == 1);
    
    printf("\nPrograma Finalizado! =)");

}

void InsertionSort(int *vet, int nVetor){
    int value=0, i=0, j=0;

    for(i = 1; i < nVetor; i++){
        value = vet[i];

        for(j = i - 1; j >= 0 && vet[j] > value; j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = value;
    }
}