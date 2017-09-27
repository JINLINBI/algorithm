#include <iostream>
#include "BSTtree.h"
using namespace std;

int main(){
    Tree* tree = new Tree(5);
    TNode *n;
    int array[10] = {0, 2, 1, 3, 4, 8, 9, 7, 10, 0};
    for(int i=0; i < 10; i++){
        n= new TNode;
        n->data = array[i];
        tree->Insert(n);
    }
    tree->Print();
    return 0;
}
