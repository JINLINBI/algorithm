#include <iostream>
#include "BSTtree.h"
using namespace std;

int main(){
    Tree* tree = new Tree(5);
    TNode *n;
    int array[10] = {2, 3, 8, 33, 14, 8, 15, 7, 10, 0};
    //int array[10] = {0, 2, 1, 3, 4, 8, 9, 7, 10, 0};
    for(int i=0; i < 10; i++){
        n= new TNode;
        n->data = array[i];
        tree->Insert(n);
    }
    tree->Print();
    tree->PreOrderTraverse();
    tree->InOrderTraverse();
    return 0;
}
