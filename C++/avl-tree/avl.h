#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "iostream"
using namespace std;

int max(int a, int b){

    if(a > b) return a;

    return b;
}

class Node{

    public:
        
        int value, height;
        Node* left;
        Node* right;

        Node(const int val){

            value = val;
            height = 1;
            left = NULL;
            right = NULL;
        }

        int calc_height(){

            int leftHeight, rightHeight;
            if(!left) leftHeight = 0;

            else leftHeight = left->height;

            if(!right) rightHeight = 0;

            else rightHeight = right->height;

            return max(leftHeight, rightHeight) + 1;
        }

        int balancing_factor(){

            int leftHeight, rightHeight;
            if(!left) leftHeight = 0;

            else leftHeight = left->height;

            if(!right) rightHeight = 0;

            else rightHeight = right->height;

            return leftHeight - rightHeight;
        }
};

class AVL{

    public:

        Node* root;

        AVL(){
            root = NULL;
        }

        bool insert_value(const int val){

            return rec_insertion(&root, val);
        }

        void print(){

            rec_print(root);

            cout << endl;
        }

        bool remove_value(const int val){

            return rec_remotion(&root, val);
        }

        bool search(const int val){

            return rec_search(root, val);
        }

    private:

        void rec_print(Node * nodePtr){

            if (nodePtr == NULL) {
                cout << ".";
                return;
            }

            cout << "[" << nodePtr -> value << ":l=";
            rec_print(nodePtr -> left);

            cout << ",r=";
            rec_print(nodePtr -> right);

            cout << "]";
        }

        void left_rotation(Node** nodePtrPtr){

            Node* auxPtr = (*nodePtrPtr) -> right -> left;

            (*nodePtrPtr) -> right -> left = *nodePtrPtr;
            (*nodePtrPtr) = (*nodePtrPtr) -> right;
            (*nodePtrPtr) -> left -> right = auxPtr;

            (*nodePtrPtr) -> left -> height = (*nodePtrPtr) -> left -> calc_height();
            (*nodePtrPtr) -> height = (*nodePtrPtr) -> calc_height();
        }

        void right_rotation(Node** nodePtrPtr){

            Node* auxPtr = (*nodePtrPtr) -> left -> right;

            (*nodePtrPtr) -> left -> right = *nodePtrPtr;
            (*nodePtrPtr) = (*nodePtrPtr) -> left;
            (*nodePtrPtr) -> right -> left = auxPtr;

            (*nodePtrPtr) -> right -> height = (*nodePtrPtr) -> right -> calc_height();
            (*nodePtrPtr) -> height = (*nodePtrPtr) -> calc_height();
        }

        void balance_tree(Node** nodePtrPtr){

            int balancingFactor = (*nodePtrPtr) -> balancing_factor();

            if(balancingFactor > 1){

                int leftPtrBalancing = (*nodePtrPtr) -> left -> balancing_factor();
                
                if(leftPtrBalancing < 0) left_rotation(&((*nodePtrPtr) -> left));

                right_rotation(nodePtrPtr);

            }else if(balancingFactor < -1){

                int rightPtrBlancing = (*nodePtrPtr) -> right -> balancing_factor();
                
                if(rightPtrBlancing > 0) right_rotation(&((*nodePtrPtr) -> right));

                left_rotation(nodePtrPtr);
            }
        }

        bool rec_insertion(Node** treePtr, const int val){

            bool retrn;
            
            if(!(*treePtr)){

                (*treePtr) = new Node(val);
                
                return true;
            }

            if(val < (*treePtr) ->  value) retrn = rec_insertion(&((*treePtr) -> left), val);

            else if(val > (*treePtr) ->  value) retrn = rec_insertion(&((*treePtr) -> right), val);

            else return false;

            if(retrn){

                balance_tree(treePtr);

                (*treePtr) -> height = (*treePtr) -> calc_height();

                return true;
            }

            return false;
        }

        int predecessor(Node * nodePtr){

            if(!nodePtr -> right) return nodePtr -> value;

            return predecessor(nodePtr -> right);
        }

        bool rec_remotion(Node** treePtr, const int val){

            bool retrn;
            
            if(!(*treePtr)) return false;

            if(val < (*treePtr) ->  value) retrn = rec_remotion(&((*treePtr) -> left), val);

            else if(val > (*treePtr) ->  value) retrn = rec_remotion(&((*treePtr) -> right), val);

            else{

                Node * nodePtr;

                if(!((*treePtr) -> left) && !((*treePtr) -> right)){

                    delete(*treePtr);
                    *treePtr = NULL;
                }else if(!((*treePtr) -> left) && (*treePtr) -> right != NULL){

                    nodePtr = (*treePtr);

                    (*treePtr) = (*treePtr) -> right;

                    delete(nodePtr);
                }else if((*treePtr) -> left != NULL && !((*treePtr) -> right)){

                    nodePtr = (*treePtr);

                    (*treePtr) = (*treePtr) -> left;

                    delete(nodePtr);
                }else{

                    int predec = predecessor((*treePtr) -> left);

                    rec_remotion(treePtr, predec);

                    (*treePtr) -> value = predec;
                }

                return true;
            }

            if(retrn){

                balance_tree(treePtr);

                (*treePtr) -> height = (*treePtr) -> calc_height();

                return true;
            }

            return false;
        }

        bool rec_search(Node* tree, const int val){

            if(!tree) return false;

            if(val < tree -> value) return rec_search(tree -> left, val);

            else if(val > tree -> value) return rec_search(tree -> right, val);

            else return true;
        }
};


#endif