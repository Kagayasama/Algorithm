//
// Created by 86136 on 2022/9/10.
//
#include <cassert>
#include"SeqList.h"
void SeqListInit(SL* ps)
{
    ps-> a = NULL;
    ps-> capacity = ps -> size = 0;
}
void SeqListCheckCapacity(SL *psl)
{
    assert(psl);
    psl->capacity *= 2;
    psl ->a =(SLDataType*)realloc(psl->a,sizeof(SLDataType)*psl->capacity);
    assert(psl->a !=NULL);
}
void SeqListPushBack(SL* psl,SLDataType x)
{
    assert(psl) ;
    //judge whether capacity is full
    if(psl->size >= psl->capacity){
        if(psl->capacity == 0) psl->capacity = 4;
        psl->capacity *= 2;
        psl->a =(SLDataType*)realloc(psl->a,sizeof(SLDataType)* psl->capacity) ;
        if(psl->a == NULL){
            cout << "capacity enlarge fail" ;
            exit(-1);
        }
        psl->a[psl->size]=x ;
        psl->size++ ;
    }
}
void SeqListPopBack(SL* psl,SLDataType x)
{
    SeqListCheckCapacity(psl);
    int end = psl->size-1;
    while(end >= 0){
        psl -> a[end+1] = psl -> a[end];
        end--;
    }
}
void SeqListPushFront(SL *psl,SLDataType x){
    SeqListCheckCapacity(psl);
    int end = psl->size-1;
    while(end >= 0) {
        psl->a[end + 1] = psl->a[end];
        psl->a[0] = x;
        psl->size++;
    }
}
void SeqListPopFront(SL *psl,SLDataType x){
    assert(psl->size>0);
    int begin = 1;
    while (begin < psl->size){
        psl->a[begin-1] = psl->a[begin];
        begin++;
    }
}
int SeqListFind(SL *psl,SLDataType x){
    for(int i =0;i < psl->size;i++){
        if(psl->a[i]==x)
            return i;
    }
    return -1;
}
void SeqListInsert(SL *psl,int pos,SLDataType x){
    assert(pos >= 0 && pos <= psl->size);
    SeqListCheckCapacity(psl);
    int end = psl->size-1;
    while(end >= pos){
        psl->a[end+1] = psl->a[end];
        end--;
    }
    psl->a[pos]=x;
    psl->size++;
}
void SeqListEraser(SL* psl, int pos){
    assert(pos >=0 && pos <= psl->size);
    int begin = pos+1;
    while(begin <= psl->size){
        psl->a[begin-1] = psl->a[begin];
        begin++;
    }
    psl->size--;
}
/* 打印 */
void SeqListPrint(SL* psl) {
    int i = 0;
    for (i = 0; i < psl->size; i++) {
        printf("%d ", psl->a[i]);
    }
    printf("\n");
}

