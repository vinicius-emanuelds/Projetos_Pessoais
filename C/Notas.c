#include <stdio.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"Portuguese_Brazil");

    int qtdnotas;
    int nota, i=0, maior=0, qtdap=0, qtdrep=0, soma=0, menor=11;
    float media=0;

    printf("\nInforme a quantidade de notas a serem calculadas: ");
        scanf("%d",&qtdnotas);

    int notas[qtdnotas];

    printf("\nInforme a nota, de 1 a 10\n(Caso deseje encerrar a contagem, insira 99) ");

    while(i < qtdnotas){
        scanf("%d",&nota);

        if (nota<0 || nota>10){
            printf("Nota inv?lida. Digite um valor inteiro entre 0 e 10");
            continue;
        }

        notas[i]=nota;
        soma=soma+notas[i];

        if (nota>maior){
            maior=nota;
        }
        if (nota<menor){
            menor=nota;
        }
        if (nota > 6){
            qtdap++;
        }else{
            qtdrep++;
        }
        if (nota == 99){
            break;
        }

        i++;
        printf("\nInforme a nota: ");
    }
    media=(soma/qtdnotas);
    printf("\nQuantidade de Aprovados: %d.",qtdap);
    printf("\nQuantidade de Reprovados: %d.",qtdrep);
    printf("\nA maior nota foi: %d.",maior);
    printf("\nA menor nota foi: %d.",menor);
    printf("\nA m?dia geral ?: %.2f.",media);
}
