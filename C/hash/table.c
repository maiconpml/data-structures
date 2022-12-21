#include "hash.h"
#include "table.h"
#include <stdlib.h>

bool alloc_table(Table *tablePtr, int n_elem_max){

    int nElem = SIZE_FACTOR * n_elem_max;

    tablePtr -> T = (TableElement *) malloc(nElem * sizeof(TableElement));
    tablePtr -> n_pos = nElem; 

   for(int i = 0; i < nElem; ++i){
      tablePtr -> T[i].deleted = false;
      tablePtr -> T[i].occupied = false;
   }

   return true;
}

void deallocate_table(Table *tablePtr){

   free(tablePtr -> T);

}

int insert_value(Table T, int elem){

   int h;

   for(int i = 0; i < T.n_pos; ++i){
      h = hash(elem, i, T.n_pos);

      if(!T.T[h].occupied){
         T.T[h].value = elem;
         //T.T[h].deleted = true;
         T.T[h].occupied = true;
         return h;
      }
   }

   return -1;
}

int search(Table T, int elem){

   int h;

   for(int i=0; i < T.n_pos; ++i){

      h = hash(elem, i, T.n_pos);

      if(T.T[h].value == elem && T.T[h].occupied){
         return h;
      }else if(!T.T[h].occupied && !T.T[h].deleted){
         return -1;
      }
   }

   return -1;
}

int remove_value(Table T, int elem){

   int position = search(T, elem);

   if(position == -1) return -1;
   
   T.T[position].occupied = false;
   T.T[position].deleted = true;

   return position;
}