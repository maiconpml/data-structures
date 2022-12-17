#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){

   *ap_lista = (No *) malloc(sizeof(No));

   (*ap_lista) -> prox = *ap_lista;
   (*ap_lista) -> antec = *ap_lista; 
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor){
   
   No * ap_novo = (No *) malloc(sizeof(No));

   ap_novo -> valor = valor;
   ap_novo -> antec = ap_lista -> antec;
   ap_novo -> prox = ap_lista;
   ap_lista -> antec -> prox = ap_novo;
   ap_lista -> antec = ap_novo;
}

/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor){

   No * ap_novo = (No *) malloc(sizeof(No));

   ap_novo -> valor = valor;
   ap_novo -> antec = ap_lista;
   ap_novo -> prox = ap_lista -> prox;
   ap_lista -> prox -> antec = ap_novo;
   ap_lista -> prox = ap_novo;
}

void remove_no(No * ap_no){

   ap_no -> antec -> prox = ap_no -> prox;
   ap_no -> prox -> antec = ap_no -> antec;

   free(ap_no);
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista){

   TipoDado valor = ap_lista -> antec -> valor;

   remove_no(ap_lista -> antec);

   return valor;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista){

   TipoDado valor = ap_lista -> prox -> valor;

   remove_no(ap_lista -> prox);

   return valor;
}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor){

   No * noAtual = ap_lista -> prox;
   No * apAux;
   int ocorrencias = 0;

   while(noAtual != ap_lista){

      if(noAtual -> valor.coef == valor.coef && noAtual -> valor.grau == valor.grau){

         apAux = noAtual;
         ocorrencias++;
         noAtual = noAtual -> prox;
         remove_no(apAux);
      }else{
         noAtual = noAtual -> prox;
      }
   }

   return ocorrencias;
}

/* Busca elemento valor na lista. 
   Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor){

   No * noAtual = lista -> prox;
   int posicao = 0;

   while(noAtual != lista){

      if(noAtual -> valor.grau == valor.grau && noAtual -> valor.coef == valor.coef) return posicao;

      noAtual = noAtual -> prox;
      posicao++;
   }

   return posicao;
}

/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau, 
   e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau){
   
   No * noAtual = lista -> prox;

   while(noAtual != lista){

      if(noAtual -> valor.grau == grau) return noAtual -> valor.coef;

      noAtual = noAtual -> prox;
   }

   return 0;
}

/* Imprime a lista na saida padrao, no formato:
   [(1,3),(2,3),(4,2),(3,1),(4,17)]
   em uma linha separada. */
void imprime(Lista lista){

   No * apAtual = lista -> prox;

   printf("[");

   while(apAtual != lista){
      printf("(%d,%d)", apAtual -> valor.grau, apAtual -> valor.coef);

      if(apAtual -> prox != lista) printf(",");

      apAtual = apAtual -> prox;
   }

   printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista){

   while((*ap_lista) -> antec != (*ap_lista)){
      remove_no((*ap_lista) -> antec);
   }
}