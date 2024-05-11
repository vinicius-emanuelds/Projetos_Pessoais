#include <stdio.h>
#include <locale.h>

void quadrado();

int main(void){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int numero;
    printf("\nInforme um número: ");
        scanf("%d", &numero);
    printf("\nNumero %d", numero);
    quadrado(numero);

    int y;
    y=2;

    quadrado(y);
    quadrado(6);
    
}


void quadrado(int x){
    int resultado;
    resultado = x * x;
    printf("\nResultado = %d",resultado);
}