#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int vetor[5];
    int i,j,temp;

    for (i=0; i<5;i++){
        printf("\n Valor %d: ",i);
            scanf("%d",&vetor[i]);
    }
    
    printf("\n");

    for (i=0; i<5;i++){
        printf("| %d ",vetor[i]);
    }
    
    printf("|");


    for (i=0; i<5;i++){
        for (j=i+1;j<5;j++){
            if (vetor[i]>vetor[j]){
                temp = vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=temp;
            }
        }

    }

    printf("\n");

    for (i=0; i<5;i++){
        printf("| %d ",vetor[i]);
    }

    printf("|");
}