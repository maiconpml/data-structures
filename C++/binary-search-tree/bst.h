#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "iostream"
using namespace std;

int max(const int a, const int b){

    if(a > b) return a;

    return b;
}

class Node{

    public:

        int value;
        Node* left;
        Node* right;
        
        Node(int newValue){

            value = newValue;
            left = NULL;
            right = NULL;
        }
};

class BST{

    public:

        Node* root;

        BST(){

            root = NULL;
        }

        bool insert_value(const int val){

            return rec_insertion(&root, val);
        }

        bool remove_value(const int val){

            return rec_remotion(&root, val);
        }

        int height(){

            return rec_height(root);
        }

        void print(){

            rec_print(root);

            cout << endl;
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

        int rec_height(Node * nodePtr){

            if(!nodePtr) return 0;

            else if(!nodePtr -> left && !nodePtr -> right) return 1;

            return max(rec_height(nodePtr -> left), rec_height(nodePtr -> right));
        }

        int predecessor(Node * nodePtr){

            if(!nodePtr -> right) return nodePtr -> value;

            return predecessor(nodePtr -> right);
        }

        bool rec_insertion(Node** nodePtrPtr, const int val){

            if(!(*nodePtrPtr)){

                (*nodePtrPtr) = new Node(val);

                return true;
            }

            if(val < (*nodePtrPtr) -> value) return rec_insertion(&(*nodePtrPtr) -> left, val);

            else if(val > (*nodePtrPtr) -> value) return rec_insertion(&(*nodePtrPtr) -> right, val);

            else return false;
        }

        bool rec_remotion(Node** nodePtrPtr, const int val){

            if(!(*nodePtrPtr)) return false;

            if(val < (*nodePtrPtr) -> value) return rec_remotion(&(*nodePtrPtr) -> left, val);

            else if(val > (*nodePtrPtr) -> value) return rec_remotion(&(*nodePtrPtr) -> right, val);

            else{

                Node * nodePtr;

                if(!((*nodePtrPtr) -> left) && !((*nodePtrPtr) -> right)){

                    delete(*nodePtrPtr);
                    *nodePtrPtr = NULL;
                }else if(!((*nodePtrPtr) -> left) && (*nodePtrPtr) -> right != NULL){

                    nodePtr = (*nodePtrPtr);

                    (*nodePtrPtr) = (*nodePtrPtr) -> right;

                    delete(nodePtr);
                }else if((*nodePtrPtr) -> left != NULL && !((*nodePtrPtr) -> right)){

                    nodePtr = (*nodePtrPtr);

                    (*nodePtrPtr) = (*nodePtrPtr) -> left;

                    delete(nodePtr);
                }else{

                    int predec = predecessor((*nodePtrPtr) -> left);

                    rec_remotion(nodePtrPtr, predec);

                    (*nodePtrPtr) -> value = predec;
                }

                return true;
            }
        }
};

#endif