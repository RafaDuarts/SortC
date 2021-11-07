#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *vet, int left, int right);

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
        
        QuickSort(vetor, 0, nVetor-1);

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

void QuickSort(int *data, int left, int right){
    int mid,tmp,i,j;
    i = left;
    j = right;
    mid = data[(left + right)/2];
    do {
        while(data[i] < mid)
            i++;
        while(mid < data[j])
            j--;
        if (i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        QuickSort(data,left,j);
    if (i < right)
        QuickSort(data,i,right);
}