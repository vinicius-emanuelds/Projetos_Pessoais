#include <stdio.h>
#include <locale.h>

int quadrado (int x){
    return x*x;
}

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int numero;
    printf("\nInforme um n�mero: ");
        scanf("%d", &numero);
    printf("\nN�mero %d", numero);
    printf("\Se elevado ao quadrado, %d", quadrado(numero));
    quadrado(numero);

}


