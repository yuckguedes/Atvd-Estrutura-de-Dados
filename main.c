#include <stdio.h>
#include <stdlib.h>
#include "atividades/ponto.h"
#include "atividades/reta.h"
#include "atividades/polinomio.h"
#include "atividades/lista_de_inteiros.h"
#include "atividades/agenda.h"

int main(void) {
  int atividade;
  printf("Qual atividade deseja testar?\n1-ponto\n2-reta\n3-funcao de segundo grau\n4-lista de inteiros\n5-agenda de enderecos\n");
  scanf("%d", &atividade);
  if(atividade == 1){
    testePonto();
  }else if(atividade == 2){
    testeReta();
  }else if(atividade == 3){
    teste_Funcao_segundoGrau();
  }else if(atividade == 4){
    testeLista_inteiros();
  }else if(atividade == 5){
    testeAgenda();
  }else{
    printf("Invalido...\n");
  }

  system("pause");
  return 0;
}