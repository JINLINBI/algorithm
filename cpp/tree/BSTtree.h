#include <iostream>
#include <deque>
#define DataType int

using namespace std;


class TNode{
public:
    DataType data;
    TNode* lchild;
    TNode* rchild;
};

class Tree{
    TNode *root;
public:
    Tree(DataType);
    Tree();
    bool Insert(TNode*);
    bool _preOrder(TNode* root);
    bool preOrder();
    void Print();
    void _Print(TNode*);
    void PreOrderTraverse();
    void _preOrderTraverse(TNode *);
    void InOrderTraverse();
    void _inOrderTraverse(TNode *);
};

Tree::Tree(DataType e){
    root = new TNode;
    root->data = e;
    root->lchild = NULL;
    root->rchild = NULL;
}

Tree::Tree(){
    root = new TNode;
    if(root){
        root->lchild = NULL;
        root->rchild = NULL;
    }
}

bool Tree::Insert(TNode *n){
    TNode * pre = root;
    TNode * p = root;
    while(p){
        pre = p;
	if(n->data == p->data)
	    return false;
        if(n->data < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(!pre){
        root = n;
        return true;
    }
    if(n->data < pre->data)
        pre->lchild = n;
    else
        pre->rchild = n;

    return true;
}

bool Tree::preOrder(){
    _preOrder(root);
}
bool Tree::_preOrder(TNode* rt){
    if(rt){
        cout << rt->data << endl;
        _preOrder(rt->rchild);
        _preOrder(rt->lchild);
    }
}

void Tree::Print(){
    _Print(root);
}

void Tree::_Print(TNode* root){
    if(!root)
        return ;
    deque<TNode*> q;
    q.push_back(root);
    TNode *t, *nlast=root;
    while(q.size() > 0){
        t = q.front();
        q.pop_front();
        cout << t->data << " ";
        if(t->lchild)
            q.push_back(t->lchild);
        if(t->rchild)
            q.push_back(t->rchild);

        if(t == nlast){
            nlast = q.back();
            cout << endl;
        }
    }
}

void Tree::PreOrderTraverse(){
    _preOrderTraverse(root);
    cout << endl;
}

void Tree::_preOrderTraverse(TNode* t){
   if(t){
        cout << t->data << " ";
        _preOrderTraverse(t->lchild);
        _preOrderTraverse(t->rchild);
   }
}

void Tree::InOrderTraverse(){
    _inOrderTraverse(root);
    cout << endl;
}

void Tree::_inOrderTraverse(TNode* t){
   if(t){
        _inOrderTraverse(t->lchild);
        cout << t->data << " ";
        _inOrderTraverse(t->rchild);
   }
}
