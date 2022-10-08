//
// Created by 86136 on 2022/9/27.
//

#ifndef MAIN_CPP_SINGLELIST_H
#define MAIN_CPP_SINGLELIST_H

#endif //MAIN_CPP_SINGLELIST_H
#include <cwchar>
#include <bits/stdc++.h>
#ifndef UNTITLED8_SINGLELIST_H
#define UNTITLED8_SINGLELIST_H

#endif //UNTITLED8_SINGLELIST_H
#pragma once
using namespace std;
typedef int SLNodeDataType;
typedef struct SingleListNode {
    SLNodeDataType data;         //结点数据
    struct SingleListNode *next;    //指向下一个节点的指针
}SLNode;
void SListPrint(SLNode* pHead);
void SListPushBack(SLNode** pHead, SLNodeDataType x);
void SListPushFront(SLNode** ppHead, SLNodeDataType x);
//我们想实现单链表的打印，我们就需要遍历整个链表。首先创建一个结构体指针 cur 来存放 pHead ，然后通过 cur 来把整个链表走一遍。只要 cur 不为 NULL，就说明还没有走完，
// 就进入循环，循环体内打印出当前 cur->data 的内容，就实现了打印节点中的内容，随后将 cur 赋值成 cur->next ，使得 cur 指向它后面的节点。
// 当 cur 为 NULL 时说明已经走完了，则跳出循环。最后我们再打印一个 "NULL" 把链表的尾部表示出来

void SListPrint(SLNode* pHead){
    SLNode* cur = pHead;
    while(cur != NULL){
        cout << cur->data <<"->";
        cur = cur->next;
    }
    cout << NULL << endl;
}
void SListPushBack(SLNode** ppHead, SLNodeDataType x){             //尾插
    SLNode* new_node = (SLNode*)malloc(sizeof(SLNode));
    //检查是否扩容失败
    if(new_node == NULL){
        cout << "malloc failed" << endl;
        exit(-1);
    }
    //放置要传入的数据
    new_node->data = x;
    //next 默认为空
    new_node->next = NULL;
    //链表为空
    if(ppHead == NULL){
        *ppHead = new_node;     //直接插入
    }
    else{
        //找到尾结点
        SLNode* end = *ppHead;
        while (end->next != NULL){
            end = end->next;
        }
        end->next = new_node;   //插入
    }
}
//创建新节点
SLNode* CreateNewNode(SLNodeDataType x){
    //开辟空间
    SLNode* new_node = (SLNode *)malloc(sizeof(SLNode));
    //检测扩容是否成功
    if(new_node == NULL){
        cout<< "malloc failed" <<endl;
        exit(-1);
    }
    //存入节点数据
    new_node->data =x;
    //next 置空
    new_node->next = NULL;
    return new_node;
}
//头插
void SListPushFront(SLNode** ppHead,SLNodeDataType x){
    //创建新节点
    SLNode* new_node = CreateNewNode(x);
    //新节点的头指向头结点
    new_node->next = *ppHead;
    //更新头结点
    *ppHead = new_node;
}