//
// Created by 86136 on 2022/10/2.
//
#include <bits/stdc++.h>
typedef int DListNodeDataType;
typedef struct DListNode{
    DListNodeDataType data;
    struct DListNode* prev;
    struct DListNode* next;
}DLNode;


    DLNode* DLNodeInit();
    void DLNodeDestroy(DLNode* pHead);
    void DLNodePrint(DLNode* pHead);
    DLNode* DLNodeFind(DLNode* pHead, DListNodeDataType x);
    void DLNodeInsert(DLNode* pos, DListNodeDataType x);
    void DLNodeDelete(DLNode* pos);
    void DLNodePushBack(DLNode* pHead, DListNodeDataType x);
    void DLNodePushFront(DLNode* pHead, DListNodeDataType x);
    void DLNodePopBack(DLNode* pHead);
    void DLNodePopFront(DLNode* pHead);
DLNode* DLNodeInit(){

    DLNode* pHead = (DLNode*)malloc(sizeof (DLNode));
    pHead->next = pHead->prev = pHead;
    return pHead;
}
void DLNodePrint(DLNode* pHead){
    assert (pHead);
    DLNode *cursor = pHead;
    while(cursor != pHead){
        std::cout << cursor->data;
        cursor = cursor->next;
    }
    std::cout << std::endl;
}

void DLNodeDestory(DLNode* pHead){
    assert(pHead);
    DLNode* cursor = pHead->next;  //哨兵节点，存的不是有效数据，所以要从下一个节点开始
    while(cursor != pHead){            //碰到哨兵说明已经遍历一遍了
        DLNode* next = cursor->next;//记录，防止cursor free后卡死
        free(cursor);
        cursor = next;
    }
    free(pHead);
    pHead = NULL;
}
DLNode* CreateNewNode(DListNodeDataType x){
    DLNode* new_node = (DLNode*) malloc(sizeof(DLNode));
    assert(new_node != NULL);
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void DLNodePushBack(DLNode* pHead,DListNodeDataType x){
    assert(pHead);
    DLNode* new_node = CreateNewNode(x);
    DLNode* tail = pHead->prev;
    tail->next = new_node;
    new_node->next = pHead;
    new_node->prev = tail;
    pHead->prev =new_node;

}
void DLNodePushFront(DLNode* pHead,DListNodeDataType x){
    assert(pHead);
    DLNode* new_node = CreateNewNode(x);
    DLNode *head = pHead->next;
    head->prev = new_node;
    pHead->next = new_node;
    new_node->prev = pHead;
    new_node->next = head;
}
void DLNodePopBack(DLNode* pHead){
    assert(pHead);
    DLNode* tail = pHead->prev;
    DLNode* tailPrev = tail->prev;
    free(tail);
    pHead->prev = tailPrev;
    tailPrev->next = pHead;
}
void DListPopFront(DLNode* pHead) {
    assert(pHead != NULL); // 防止pHead为空
    assert(pHead->next != pHead); // 防止链表为空

    //思路草图：  pHead  pHeadNext(待删目标)  pHeadNextNext
    DLNode* pHeadNext = pHead->next;
    DLNode* pHeadNextNext = pHeadNext->next;
    //链接
    pHead->next = pHeadNextNext;
    pHeadNextNext->prev = pHead;
    //释放
    free(pHeadNext);
}
DLNode* DListNodeFind(DLNode* pHead , DListNodeDataType x){
    assert(pHead);
    DLNode* cur = pHead->next;
    while(cur != pHead){
        if(cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void DListInsert(DLNode* pos , DListNodeDataType x){
    assert(pos);
    DLNode* new_node = CreateNewNode(x);
    DLNode* posPrev = pos->prev;
    posPrev->next = new_node;
    new_node->next = pos;
    new_node->prev = posPrev;
    pos->prev = new_node;
}
void DListEraser(DLNode* pos){
    assert(pos);
    DLNode* posPrev = pos->prev;
    DLNode* posNext = pos->next;
    posPrev->next = posNext;
    posNext->prev = posPrev;
    free(pos);
    pos = NULL;
}
