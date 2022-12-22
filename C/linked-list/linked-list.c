#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void initialize_list(List * list_pt){

   *list_pt = (Node *) malloc(sizeof(Node));

   (*list_pt) -> next = *list_pt;
   (*list_pt) -> prev = *list_pt;
}

void insert_next(Node* nodePtr, int value){

   Node* newNode = (Node*) malloc(sizeof(Node));

   newNode -> value = value;
   newNode -> prev = nodePtr;
   newNode -> next = nodePtr -> next;
   nodePtr -> next -> prev = newNode;
   nodePtr -> next = newNode;
}

void insert_last(List list, int value){
   
   insert_next(list -> prev, value);
}

void insert_first(List list, int value){

   insert_next(list, value);
}

bool insert_position(List list, int value, int position){

   Node* nodePtr = list;
   int i = 0;

   while(i < position && nodePtr -> next != list){

      nodePtr = nodePtr -> next;
      i++;
   }

   if(nodePtr -> next != list) insert_next(nodePtr, value);

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

bool remove_value(List list, int val){

   Node* nodePtr = list;

   while(nodePtr -> next != list){

      if(nodePtr -> value == val){

         remove_node(nodePtr);

         return true;
      }

      nodePtr = nodePtr -> next;
   }

   return false;
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

/* Return a copy of a given list.*/
Node* clone(List list){

   List newList;
   Node * nodePtr = list -> next;

   initialize_list(&newList);

   while(nodePtr != list){

      insert_last(newList, nodePtr -> value);

      nodePtr = nodePtr -> next;
   }

   return newList;
}

int indexOf(List list, int value){

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

void clear_list(List list){

   while(list ->  next != list){
      remove_node(list -> prev);
   }
}

void deallocate_list(List *list_pt){

   while((*list_pt) -> prev != (*list_pt)){
      remove_node((*list_pt) -> prev);
   }
}