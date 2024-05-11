#include <stdio.h>

//DESAFIO 1 - CORRIDA DE MOTO
// MOTOS 1, 2 e 3
// Cada moto dará 3 voltas no circuito;
// Armazenar os segundos de cada volta
// Classificar em 1º, 2º e 3º lugar

int main(void) {
int MotoVER=0,MotoAMA=0,MotoAZU=0,volta,i;
  for (i=1;i<4;i++){
      printf("\nInforme o tempo da %dª volta para a Moto Vermelha: ",i);
      scanf("%d",&volta);
      MotoVER=MotoVER+volta;
        
      printf("\nInforme o tempo da %dª volta para a Moto Amarela: ",i);
      scanf("%d",&volta);
      MotoAMA=MotoAMA+volta;

      printf("\nInforme o tempo da %dª volta para a Moto Azul: ",i);
      scanf("%d",&volta);
      MotoAZU=MotoAZU+volta;
  }
    if (MotoVER<MotoAZU && MotoVER<MotoAMA){
    printf("\nA Moto Vermelha é a primeira colocada, com tempo de %d segundos.",MotoVER);
      if (MotoAZU<MotoAMA){
      printf("\nA Moto Azul é a segunda colocada, com tempo de %d segundos.\nA Moto Amarela é a terceira colocada, com tempo de %d segundos.",MotoAZU,MotoAMA);
        }else{
        printf("\nA Moto Amarela é a segunda colocada, com tempo de %d segundos.\nA Moto Azul é a terceira colocada, com tempo de %d segundos.",MotoAMA,MotoAZU);}
    }else{
      if (MotoAMA<MotoAZU && MotoAMA<MotoVER){
      printf("\nA Moto Amarela é a primeira colocada, com tempo de %d segundos.",MotoAMA);
        if (MotoAZU<MotoVER){
        printf("\nA Moto Azul é a segunda colocada, com tempo de %d segundos.\nA Moto Vermelha é a terceira colocada, com tempo de %d segundos.",MotoAZU,MotoVER);
          }else{
          printf("\nA Moto Vermelha é a segunda colocada, com tempo de %d segundos.\nA Moto Azul é a terceira colocada, com tempo de %d segundos.",MotoVER,MotoAZU);}
      }else{
        if (MotoAZU<MotoAMA && MotoAZU<MotoVER){
        printf("\nA Moto Azul é a primeira colocada, com tempo de %d segundos.",MotoAZU);
          if (MotoAMA<MotoVER){
          printf("\nA Moto Amarela é a segunda colocada, com tempo de %d segundos.\nA Moto Vermelha é a terceira colocada, com tempo de %d segundos.",MotoAMA,MotoVER);
            }else{
            printf("\nA Moto Vermelha é a segunda colocada, com tempo de %d segundos.\nA Moto Amarela é a terceira colocada, com tempo de %d segundos.",MotoVER,MotoAMA);}
        }
      }
    }
}