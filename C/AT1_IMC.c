#include <stdio.h>
#include <locale.h>

int main(void) {
  setlocale(LC_ALL,"Portuguese_Brazil");

  float peso, altura, imc;
  char nome[15];
  printf("\n Ol�! Qual seu nome? ");
  scanf("%s",&nome);
  printf("\n%s, informe seu peso, em quilos.\nUtilize o ponto para separar valores inteiros e fracionados: ",nome);
  scanf("%f",&peso);
  printf("\n%s, agora informe sua altura, em metros.\nUtilize o ponto para separar valores inteiros e fracionados: ",nome);
  scanf("%f(",&altura);
  imc=peso/(altura*altura);
    if(imc<=20){
    printf("\n%s, seu IMC �: %.2f\nSua classifica��o �: ABAIXO DO PESO IDEAL",nome,imc);
      }else{
        if(imc>20 && imc<=25){
        printf("\n%s, seu IMC �: %.2f\nSua classifica��o �: PESO IDEAL",nome,imc);
          }else{
            if(imc>25 && imc<=34){
            printf("\n%s, seu IMC �: %.2f\nSua classifica��o �: SOBREPESO",nome,imc);
              }else{
                if(imc>34 && imc<=40){
                printf("\n%s, seu IMC �: %.2f\nSua classifica��o �: OBESIDADE",nome,imc);
                  }else{
                    if(imc>40){
                    printf("\n%s, seu IMC �: %.2f\nSua classifica��o �: OBESIDADE M�RBIDA",nome,imc);
                    }
                  }
              }
          }
      }
}