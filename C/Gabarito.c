#include <stdio.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"Portuguese_Brazil");

    int i;
    char gabarito[5]={'A','B','C','D','E'};
    char respostas[5];
    int cont=0, porc=0;

    printf("Para lan�ar as respostas, utilize as letras de A at� E, mai�sculas!");

    for (i=0;i<5;i++){
        printf("\nDigite a %d� resposta: ",i+1);
            scanf(" %c",&respostas[i]);
        if (respostas[i]== gabarito[i]){
            cont=cont+1;
        }
    }
    porc=cont*20;

    printf("\nA porcentagem de acertos � de %d%%.",porc);

}
