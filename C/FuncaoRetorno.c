#include <stdio.h>
#include <locale.h>

int quadrado (int x){
    return x*x;
}

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int numero;
    printf("\nInforme um número: ");
        scanf("%d", &numero);
    printf("\nNúmero %d", numero);
    printf("\Se elevado ao quadrado, %d", quadrado(numero));
    quadrado(numero);

}


