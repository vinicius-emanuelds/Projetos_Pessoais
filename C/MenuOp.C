#include <stdio.h>
#include <locale.h>


 float imposto(float x){
        return x*0.08;
    }

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    int vetor[8];
    int i, j, temp, op;
    float sal, saliq;
    
    while(op != 5){

        printf("\n==========================================");
        printf("\n------------- MENU DE OP��ES -----------");
        printf("\n1 - Preenche um vetor com 8 posi��es");
        printf("\n2 - Ordenar valores de forma crescente");
        printf("\n3 - Ordenar valores de forma decrescente");
        printf("\n4 - Calcular imposto de 8%%");
        printf("\n5 - Sair");
        printf("\n===========================================");
    
            printf("\nDigite a op��o desejada: ");
            scanf("%d",&op);

        switch (op){
            case 1:
                for (i=0; i<8; i++){
                    printf("\nDigite o valor para a %d posi��o: ",i+1);
                        scanf("%d",&vetor[i]);
                }

                for (i=0; i<8;i++){
                printf("| %d ",vetor[i]);
                }
                printf("|");
                break;
            
            case 2:
                for (i=0; i<8; i++){
                    for (j=i+1; j<8; j++){
                        if (vetor[i]>vetor[j]){
                            temp = vetor[i];
                            vetor[i]=vetor[j];
                            vetor[j]=temp;
                        }
                    }
                }
                    for (i=0; i<8;i++){
                        printf("| %d ",vetor[i]);
                    }
                    printf("|");
                
                break;

            case 3:
                for (i=0; i<8; i++){
                    for (j=i+1; j<8; j++){
                        if (vetor[i]<vetor[j]){
                            temp = vetor[i];
                            vetor[i]=vetor[j];
                            vetor[j]=temp;
                        }
                    }
                }
                    for (i=0; i<8;i++){
                        printf("| %d ",vetor[i]);
                    }
                    printf("|");
                
                break;

            case 4:
                printf("\nInforme o valor do sal�rio: ");
                    scanf("%f",&sal);
                    saliq=sal-(imposto(sal));
                printf("O imposto sobre o sal�rio informado foi de R$ %.2f. Seu sal�rio l�quido � de R$ %.2f.",imposto(sal),saliq);
                break;

            case 5:
                printf("\nFim!");
                break;

            default:
                printf("\nEntrada inv�lida");
                break;
        }
    }

}