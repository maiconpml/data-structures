#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "iostream"
using namespace std;

class Node{
 
    public:
        
        int value;
        Node * prev;
        Node * next;

        Node(int newValue){
            
            value = newValue;
        }
};

class linkedList{

    public:

        Node* list;

        linkedList(){

            list = new Node(0);
            list -> prev = list;
            list -> next = list;
        }

        void insert_first(const int value){

            Node * newNode = new Node(value);

            newNode -> next = list -> next;
            newNode -> prev = list;
            list -> next -> prev = newNode;
            list -> next = newNode;
        }

        void insert_last(const int value){

            Node * newNode = new Node(value);

            newNode -> next = list;
            newNode -> prev = list -> prev;
            list -> prev -> next = newNode;
            list -> prev = newNode;
        }

        int remove_last(){

            int removedVal = list -> prev -> value;

            remove_node(list -> prev);

            return removedVal;
        }

        int remove_first(){

            int removedVal = list -> next -> value;
            
            remove_node(list -> next);

            return removedVal;
        }

        int remove_occurrences(const int value){
            
            Node * currentNode = list -> next;
            Node * auxPtr;
            int occurrences = 0;

            while(currentNode != list){

                if(currentNode -> value == value){

                    auxPtr = currentNode;
                    currentNode = currentNode -> next;
         
                    occurrences++;
         
                    remove_node(auxPtr);
                }else{
                    
                    currentNode = currentNode -> next;
                }
            }

            return occurrences;
        }

        bool index(const int reqValue){

            Node * currentNode = list -> next;
            int position = 0;

            while(currentNode != list){

                if(currentNode -> value == reqValue) return position;
                
                currentNode = currentNode -> next;

                position++;
            }

            return position;
        }

        void print(){

            Node * currentNode = list -> next;
            
            cout << "(";

            while(currentNode != list){

                cout << currentNode -> value;

                if(currentNode -> next != list) cout << ",";

                currentNode = currentNode -> next;
            }

            cout << ")\n";
        }
    
    private:

        void remove_node(Node * nodePtr){

            nodePtr -> prev -> next = nodePtr -> next;
            nodePtr -> next -> prev = nodePtr -> prev;

            delete(nodePtr);
        }
        
};

#endif
