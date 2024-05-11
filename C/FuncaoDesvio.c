#include <stdio.h>
#include <locale.h>

void tela();

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int numero;
   
    tela();
    printf("\nInforme um número: ");
        scanf("%d",&numero);
    tela();
    printf("\n Numero %d",numero);
    tela();

}

void tela(){
    printf("\n================================");
}