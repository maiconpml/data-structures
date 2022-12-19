#include "avl.h"
#include<stdio.h>
#include<stdlib.h>

void rec_print(AVL tree){

  if (tree == NULL){
    printf(".");
    return;
  }

  printf("[%d:l=", tree -> value);
  rec_print(tree -> left);
  
  printf(",r=");
  rec_print(tree -> right);
  
  printf("]");
}

void print(AVL tree) {

  rec_print(tree);
  printf("\n");
}

void alloc_element(AVL* treePtr, int val){
  
  Node * newNode = (Node *) malloc(sizeof(Node));

  newNode -> right = NULL;
  newNode -> left = NULL;
  newNode -> value = val;
  newNode -> height = 1;

  (*treePtr) = newNode;
}

int height(Node * nodePtr){

  if(!nodePtr) return 0;

  return nodePtr -> height;
}

int max(int a, int b){

  if(a > b) return a;

  return b;
}

void calc_node_height(Node* nodePtr){

  nodePtr -> height = max(height(nodePtr -> left), height(nodePtr -> right)) + 1;
}

void right_rotation(AVL* treePtr){

  Node* auxPtr = (*treePtr) -> left -> right;

  (*treePtr) -> left -> right = *treePtr;
  (*treePtr) = (*treePtr) -> left;
  (*treePtr) -> right -> left = auxPtr;

  calc_node_height((*treePtr) -> right);
  calc_node_height(*treePtr);
}

void left_rotation(AVL * treePtr){

  Node* auxPtr = (*treePtr) -> right -> left;

  (*treePtr) -> right -> left = *treePtr;
  (*treePtr) = (*treePtr) -> right;
  (*treePtr) -> left -> right = auxPtr;

  calc_node_height((*treePtr) -> left);
  calc_node_height(*treePtr);
}


bool balance_tree(AVL* treePtr, int balancingFactor){

  if(balancingFactor > 1){

    int hll = height((*treePtr) -> left -> left);
    int hlr = height((*treePtr) -> left -> right);
    
    if(hll < hlr) left_rotation(&((*treePtr) -> left));

    right_rotation(treePtr);

    return true;
  }else if(balancingFactor < -1){

    int hrl = height((*treePtr) -> right -> left);
    int hrr = height((*treePtr) -> right -> right);
    
    if(hrl > hrr) right_rotation(&((*treePtr) -> right));

    left_rotation(treePtr);

    return true;
  }

  return false;
}

bool insert_value(AVL* treePtr, int x){

  bool retrn;
  int balancingFactor, rightHeight = 0, leftHeight = 0;
  
  if(!(*treePtr)){

    alloc_element(treePtr, x);
    
    return true;
  }

  if(x < (*treePtr) ->  value) retrn = insert_value(&((*treePtr) -> left), x);

  else if(x > (*treePtr) ->  value) retrn = insert_value(&((*treePtr) -> right), x);

  else return false;

  if(retrn){

    balancingFactor = height((*treePtr) -> left) - height((*treePtr) -> right);

    balance_tree(treePtr, balancingFactor);

    calc_node_height(*treePtr);

    return true;
  }

  return false;
}

int predecessor(AVL * treePtr){

  if(!((*treePtr) -> right)) return (*treePtr) -> value;
  
  else return predecessor(&(*treePtr) -> right);
}

bool remove_value(AVL* treePtr, int x){

  bool retrn;

  if(!(*treePtr)) return false;

  if(x < (*treePtr) -> value) retrn = remove_value(&((*treePtr) -> left), x);

  else if(x > (*treePtr) -> value) retrn = remove_value(&((*treePtr) -> right), x);

  else{

    Node* auxPtr;

    if((*treePtr) -> left && (*treePtr) -> right){

      (*treePtr) -> value = predecessor(&((*treePtr) -> left));

      remove_value(&((*treePtr) -> left), (*treePtr) -> value);
    }else if((*treePtr) -> left){

      auxPtr = (*treePtr);

      (*treePtr) = (*treePtr) -> left;

      free(auxPtr);
    }else if((*treePtr) -> right){

      auxPtr = (*treePtr);

      (*treePtr) = (*treePtr) -> right;

      free(auxPtr);
    }else{

      free(*treePtr);

      *treePtr = NULL;
    }

    return true;
  }

  if(retrn){

    int balancingFactor = height((*treePtr) -> left) - height((*treePtr) -> right);

    balance_tree(treePtr, balancingFactor);

    calc_node_height((*treePtr));

    return true;
  }

  return false;
}

bool search(AVL tree, int x){

  if(!tree){
    
    return false;
  }

  if(tree -> value == x) return true;

  if(x < tree -> value) return search(tree -> left, x);

  if(x > tree -> value) return search(tree -> right, x);

  return false;
}