#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int *vet, int nVetor);

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
            printf("\n n[%d]: %d", i, vetor[i]);
        }

        SelectionSort(vetor, nVetor);

        printf("\n\nValores Ordenados:");
        for (i = 0; i < nVetor; i++){
            printf("\n n[%d]: %d", i, vetor[i]);
        }

        free(vetor);
        printf("\n\nDeseja realizar a operacao novamente?\n1 = Sim \n2 = Nao\n");
        scanf("%d", &controle);
    } while(controle == 1);
    
    printf("\nPrograma Finalizado! =)");

}

void SelectionSort(int *vet, int nVetor){
    int i=0, j=0, menor=0, troca=0;

    for (i = 0; i < nVetor-1; i++){
        menor = i;

        for(j = i + 1; j < nVetor; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = vet[i];
            vet[i] = vet[menor];
            vet[menor] = troca;
        }
    }
}