#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void rec_print(BST tree) {
  
  if (tree == NULL) {
    printf(".");
    return;
  }

  printf("[%d:l=", tree -> value);
  rec_print(tree -> left);

  printf(",r=");
  rec_print(tree -> right);

  printf("]");
}

void print(BST tree) {
  
  rec_print(tree);
  printf("\n");
}

void alloc_element(BST * treePtr, int val){
  
  Node * newNode = (Node *) malloc(sizeof(Node));

  newNode -> right = NULL;
  newNode -> left = NULL;
  newNode -> value = val;

  (*treePtr) = newNode;
}

bool insert(BST* treePtr, int x){

  if(!(*treePtr)){
    
    alloc_element(treePtr, x);
    
    return true;
  }

  if(x < (*treePtr) -> value) return insert(&((*treePtr) -> left), x);

  else if(x > (*treePtr) -> value) return insert(&((*treePtr) -> right), x);

  return false;

}

int predecessor(BST* treePtr, int x){

  if((*treePtr) -> value == x) return predecessor(&((*treePtr) -> left), x);

  if(!((*treePtr) -> right)) return (*treePtr) -> value;
  
  else return predecessor(&(*treePtr) -> right, x);
}

bool remove_node(BST* treePtr, int x){

  if(!(*treePtr)){
    return false;
  }

  if((*treePtr) -> value == x){

    Node * nodePtr;

    if(!((*treePtr) -> left) && !((*treePtr) -> right)){

      free(*treePtr);
      *treePtr = NULL;
    }else if(!((*treePtr) -> left) && (*treePtr) -> right != NULL){

      nodePtr = (*treePtr);

      (*treePtr) = (*treePtr) -> right;

      free(nodePtr);
    }else if((*treePtr) -> left != NULL && !((*treePtr) -> right)){

      nodePtr = (*treePtr);

      (*treePtr) = (*treePtr) -> left;

      free(nodePtr);
    }else{

      int antecessor = predecessor(treePtr, (*treePtr) -> value);

      remove_node(treePtr, antecessor);

      (*treePtr) -> value = antecessor;
    }

    return true;
  }

  if(x < (*treePtr) -> value) return remove_node(&((*treePtr) -> left), x);

  if(x > (*treePtr) -> value) return remove_node(&((*treePtr) -> right), x);

  return false;
}

bool search(BST tree, int x){

  if(!tree){
    return false;
  }

  if(tree -> value == x) return true;

  if(x < tree -> value) return search(tree -> left, x);

  if(x > tree -> value) return search(tree -> right, x);

  return false;
}