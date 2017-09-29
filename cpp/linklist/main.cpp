/*************************************************************************
	> File Name: main.cpp
	> Author: jinlin
	> Mail: 898141731@qq.com
	> Created Time: Friday, September 29, 2017 PM01:26:07 HKT
 ************************************************************************/

#include<iostream>
#include"linklist.h"
using namespace std;


int main(void){
    LinkList<int> list;
    for(int i = 0; i < 130; i++)
        list.InsertTail(i);
    list.Print();
    cout << "list length:" << list.getLength() << endl;
    list.Remove(19);
    list.InsertTail(234);
    list.Print();
    cout << "list length:" << list.getLength() << endl;
    return 0;
}

