#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 20
#define NotFound 0

typedef int Position;
typedef int ElementType;
typedef struct Node *List;
struct Node {
    ElementType Data[MAXSIZE];
    Position Last;
};

Position BinarySearch(List L, ElementType X);

Position BinarySearch(List L, ElementType X){
    if(L == NULL){
        return NotFound;
    }
    int left  = 1;
    int right = L->Last;
    int mid = (left + right)/2;
    while(left <= right){
        if(L->Data[mid] > X ){
            right = mid - 1;
            mid = (left + right) / 2;
        }else if(L->Data[mid] < X){
            left = mid + 1;
            mid = (left + right) / 2;
        }else{
            return mid;
        }
    }

    return NotFound;
}