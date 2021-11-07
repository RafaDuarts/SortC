#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void MergeSort(int *v, int inicio, int fim);
void merge (int *v, int ini, int meio, int fim);

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
        

        MergeSort(vetor, 0, nVetor-1);

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

void MergeSort(int *v, int inicio, int fim){
   int meio;
    if (inicio < fim){
        meio = floor((inicio + fim)/2);
        MergeSort(v, inicio, meio);
        MergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}    

void merge (int *v, int ini, int meio, int fim){
    int *temp, p1, p2, tam, i, j, k;
    int fim1 = 0, fim2 = 0;
    tam = fim - ini + 1;
    p1 = ini;
    p2 = meio + 1;
    temp = (int *) malloc(tam * sizeof(int));
    
    if(temp != NULL){
        for(i = 0; i < tam; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
                if(p1 > meio)
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            }
            else{
                if(!fim1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
    
        for(j = 0, k = ini; j < tam; j++, k++)
        v[k] = temp[j];
    }
    
    free(temp);
}