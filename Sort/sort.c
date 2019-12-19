#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include "util.h"

typedef int ElementType;


typedef struct Node *PtrToNode;
typedef struct Node {
    ElementType Data;
    PtrToNode   Next;
} Node;
typedef PtrToNode List;



List Merge(List L1, List L2);
List Read();
void Print_List(List L);

int main(int argc, char* argv[]){
    PtrToNode L1 = Read();
    PtrToNode L2 = Read();
    Print_List(L1);
    Print_List(L2);
    List L = Merge(L1,L2);
    Print_List(L);
    Print_List(L1);
    Print_List(L2);
    return 0;
}

List Merge(List p, List q){
    List t = (List)malloc(sizeof(struct Node));
    if(t == NULL){
        exit(-1);
    }
    t->Next = NULL;

    PtrToNode L1 = p->Next, L2 = q->Next, L = t;

    if(L1 == NULL){
        L->Next = L2;
        L2 = NULL;
        return t;
    }

/*
    if(L1->Data < L2->Data){
        L = L1;
        L1 = L1->Next;
        L->Next = NULL;
    }else{
        Headead = L2;
        L2 = L2->Next;
        Head->Next = NULL;
    }
    PtrToNode Last = Head;
*/

    while((L1 != NULL) && (L2 != NULL) ){
        if(L1->Data < L2->Data){
            L->Next = L1;
            L1 = L1->Next;
         }else{
            L->Next = L2;
            L2 = L2->Next;
        }
        L = L->Next;
        L->Next = NULL;
        p->Next = L1;
        q->Next = L2;
    }

/*
    if(L1 != NULL){
        Last ->Next = L1;
        L1 = NULL;
    }else if (L2 != NULL)
    {
        Last ->Next = L2;
        L2 = NULL;
    }else{
        Last->Next = NULL;
    }
*/
    L->Next = L1 == NULL?L2:L1;
    p->Next = NULL;
    q->Next = NULL;

    return t;
}


List Read(){
    int num = 0;
    scanf("%d",&num);
    List L = (List)malloc(sizeof(struct Node));
    if(L == NULL){
        exit(-1);
    }
    L->Next = NULL;
    PtrToNode q = L;

    for(int i = 0; i < num; i++){
        PtrToNode p = (PtrToNode) malloc(sizeof(Node));
        if(p == NULL){
            exit(0);
        }
        scanf("%d", &p->Data);
        p->Next = NULL;
        q->Next = p;
        q = q->Next;
    }

    return L;
}

void Print_List(List L){
    if(L->Next == NULL){
        printf("NULL\n");
        return;
    }
    PtrToNode p = L->Next;
    while(p){
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}
