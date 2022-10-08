#include <bits/stdc++.h>
typedef int QueueDataType;
typedef struct QueueNode{
    QueueDataType data;
    QueueNode* next;
}QueueNode;
typedef struct Queue{
    QueueNode* pHead;
    QueueNode* pTail;
}Queue;


void QueueInit(Queue* pQ);                  //队列初始化
void QueueDestroy(Queue* pQ);               //销毁队列
bool QueueIsEmpty(Queue* pQ);               //判断队列是否为空
void QueuePush(Queue* pQ, QueueDataType x); //入队
void QueuePop(Queue* pQ);                   //出队
QueueDataType QueueFront(Queue* pQ);        //返回队头数据
QueueDataType QueueBack(Queue* pQ);         //返回队尾数据
int QueueSize(Queue* pQ);                   //求队列大小

void QueueInit(Queue* pQ){
    assert(pQ);
    pQ->pHead = pQ->pTail = NULL;
}
void QueueDestroy(Queue* pQ){
    assert(pQ);
    QueueNode* cur = pQ->pHead;
    while(cur != NULL){
        QueueNode* curNext = cur->next;
        free(cur);
        cur = curNext;
    }

    pQ->pHead = pQ->pTail = NULL;
}
bool QueueIsEmpty(Queue* pQ){
    assert (pQ);
    //if(pQ->pHead == NULL)return true;
    //else return false;
    return pQ->pHead == NULL;
}
void QueuePush(Queue* pQ, QueueDataType x){
    assert(pQ);
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));
    assert(new_node);
    if(pQ->pHead == NULL){
        pQ->pHead = pQ->pTail = NULL;
    }
    else{
        pQ->pTail->next = new_node;   // plant new node
        pQ->pTail = new_node;        // update tail node
    }
}
void QueuePop(Queue* pQ){
    assert(pQ);
    assert(QueueIsEmpty(pQ));
    QueueNode* headNext = pQ->pHead->next;
    free(pQ->pHead);
    pQ->pHead = headNext;
    if(pQ->pHead == NULL)
        pQ->pTail = NULL;
}

QueueDataType QueueFront(Queue* pQ){
    assert(pQ);
    assert(QueueIsEmpty(pQ));
    return pQ->pHead->data;
}

QueueDataType QueueBack(Queue* pQ) {
    assert(pQ);                            //防止传入的pQ为空
    assert(!QueueIsEmpty(pQ));             //防止队列为空

    return pQ->pTail->data;
}

int QueueSize(Queue* pQ){
    assert(pQ);
    assert(QueueIsEmpty(pQ));
    int count = 0;
    QueueNode* cur = pQ->pHead;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}