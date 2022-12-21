#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void initialize_list(List * list_pt){

   *list_pt = (Node *) malloc(sizeof(Node));

   (*list_pt) -> next = *list_pt;
   (*list_pt) -> prev = *list_pt;
}

void insert_last(List list, int value){
   
   Node * new_node = (Node *) malloc(sizeof(Node));

   new_node -> value = value;
   new_node -> prev = list -> prev;
   new_node -> next = list;
   list -> prev -> next = new_node;
   list -> prev = new_node;
}

void insert_first(List list, int value){

   Node * new_node = (Node *) malloc(sizeof(Node));

   new_node -> value = value;
   new_node -> prev = list;
   new_node -> next = list -> next;
   list -> next -> prev = new_node;
   list -> next = new_node;
}

void remove_node(Node * node_pt){

   node_pt -> prev -> next = node_pt -> next;
   node_pt -> next -> prev = node_pt -> prev;

   free(node_pt);
}

int remove_last(List list){

   int value = list -> prev -> value;

   remove_node(list -> prev);

   return value;
}

int remove_first(List list){

   int value = list -> next -> value;

   remove_node(list -> next);

   return value;
}

int remove_occurrences(List list, int value){

   Node * currentNode = list -> next;
   Node * auxPt;
   int occurrences = 0;

   while(currentNode != list){

      if(currentNode -> value == value){

         auxPt = currentNode;
         currentNode = currentNode -> next;
         
         occurrences++;
         
         remove_node(auxPt);
      }else{
         currentNode = currentNode -> next;
      }
   }

   return occurrences;
}

int index(List list, int value){

   Node * currentNode = list -> next;
   int position = 0;

   while(currentNode != list){

      if(currentNode -> value == value) return position;

      currentNode = currentNode -> next;

      position++;
   }

   return -1;
}

void print(List list){

   Node * currentNode = list -> next;

   printf("[");

   while(currentNode != list){
      printf("%d", currentNode -> value);

      if(currentNode -> next != list) printf(",");

      currentNode = currentNode -> next;
   }

   printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void deallocate_list(List *list_pt){

   while((*list_pt) -> prev != (*list_pt)){
      remove_node((*list_pt) -> prev);
   }
}