/*************************************************************************
	> File Name: linklist.h
	> Author: jinlin
	> Mail: 898141731@qq.com
	> Created Time: Friday, September 29, 2017 PM12:50:00 HKT
 ************************************************************************/

#include<iostream>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T> class LinkList{
public:
    LinkList();
    ~LinkList();
    bool InsertHead(T);
    bool InsertTail(T);
    bool Remove(T);
    int FindByElement(T);
    T FindByPos(int);
    bool Destroy(Node<T> *);
    void Print();
    void Reverse();
    inline int getLength();
private:
    int length;
    Node<T> *head;
    Node<T> *tail;
};

template <typename T>
inline int LinkList<T>::getLength(){
    return length;
}

template <typename T> 
LinkList<T>::LinkList(){
    length = 0;
    head = new Node<T>;
    head->next = nullptr;
    tail = nullptr;
}

template <typename T>
LinkList<T>::~LinkList(){
    Destroy(head);
}

template <typename T>
bool LinkList<T>::Remove(T e){
    Node<T> *p = head->next, *pre = head;
    while(p){
        if(p->data == e){
            pre->next = p->next;
            if(p == tail)
                tail = nullptr;
            delete p;
            length -= 1;
            
            return 1;
        }
        pre = p;
        p = p->next;
    }

    return 0;
}

template <typename T>
bool LinkList<T>::InsertHead(T e){
    Node<T> *pre = head, *p = head;
    p = new Node<T>;
    if(p){
        length += 1;
        p->data = e;
        p->next = head->next;
        if(head->next == nullptr)
            tail = p;
        head->next = p;

        return 1;
    }

    return 0;
}

template <typename T>
bool LinkList<T>::InsertTail(T e){
    Node<T>* pre=head, *p=head;
    if(tail){
        p = new Node<T>;
        p->data = e;
        p->next = nullptr;
        tail->next = p;
        tail = p;
        length += 1;
        return 1;
    }
    while(p){
        pre = p;
        p = p->next;
    }
    p = new Node<T>;
    if(p){
        p->data = e;
        p->next = nullptr;
        pre->next = p;
        tail = p;
        length += 1;
        cout << " Insert not using tail ptr!" << endl;
        return 1;
    }

    return 0;
}

template <typename T>
bool LinkList<T>::Destroy(Node<T> *N){
    Node<T>* temp;
    if(N){
        temp = N;
        N = N->next;
        free(temp);
    }
}

template <typename T>
void LinkList<T>::Print(){
    Node<T> * p = head->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <typename T>
void LinkList<T>::Reverse(){
    Node<T> *pTemp, *pCur = head->next, *pNext = pCur->next;
    pCur->next = nullptr;
    tail = pCur;
    while(pNext != nullptr){
        pTemp = pNext->next;
        pNext->next = pCur;
        pCur = pNext;
        pNext = pTemp;
    }
    head->next = pCur;
}
