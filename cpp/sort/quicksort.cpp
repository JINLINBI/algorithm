/*************************************************************************
	> File Name: quicksort.cpp
	> Author: jinlin
	> Mail: 898141731@qq.com
	> Created Time: Wednesday, September 27, 2017 PM07:37:34 HKT
 ************************************************************************/

#include<iostream>
using namespace std;
#define DataType int

int Partition(DataType *A, int q, int r){
    int i = q - 1;
    int j;
    DataType temp;
    for(j = q; j < r; j++){
        if(A[j] < A[r]){
            i += 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}


void QuickSort(DataType* A, int q, int r){
    int p;
    if(q < r){
        p = Partition(A, q, r);
        QuickSort(A, q, p - 1);
        QuickSort(A, p + 1, r);
    }
}

int main(void){
    int A[] = { 2, 234, 34, 341,
                334 ,334 , 12, 97,
                34 ,334 , 12, 97,
                699, 15, 197, 46,
                83, 27, 177, 38,
                3, 29, 92, 295,
                265, 294, 292, 73,
                6, 16, 17, 46,
                87, 27, 177, 38,
                38, 29, 9, 295,
                526, 229, 29342, 73,
                25, 329, 2934, 73,
                265, 932, 2342, 73,
                29, 34, 22, 38};
    QuickSort(A, 0, (14 * 4) - 1);
    for(int i = 0; i < (14 * 4); i++){
        cout << A[i] << " ";
    }
    return 0;
}
