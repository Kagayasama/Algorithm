/*
 * Created as note and tips by Kagaya for studying
 *
 *栈是一种特殊的线性表，它只允许在固定的一端进行插入和删除元素的操作。
 *
 *进行数据插入的删除和操作的一端，称为 栈顶 。另一端则称为 栈底 。
 *
 *栈中的元素遵守后进先出的原则，即 LIFO原则（Last In First Out）
 *
 *压栈：栈的插入操作叫做 进栈 / 压栈 / 入栈 ，入数据在栈顶。
 *出栈：栈的删除操作叫做出栈。出数据也在栈顶。
 */
#include <iostream>
#include <bits/stdc++.h>
typedef int StackDataType;
typedef struct Stack{
    StackDataType* array;   //array in stack
    int capacity;
    int top;
}stack;
/*
 *This is a static Stack and it might cause a waste of memory, so we choose dynamic stack to store data
 *
typedef char StackDataType;
#define N 10

typedef struct Stack {
	StackDataType _array[N];  //数组
	int _top;                 //栈顶
} Stack;
 */

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
bool StackIsEmpty(Stack* pst);
void StackPush(Stack* pst, StackDataType x);
void StackPop(Stack* pst);
StackDataType StackTop(Stack* pst);
int StackSize(Stack* pst);


void StackInit(Stack* pst){
    assert(pst);
    pst->array = NULL;
    pst->top = pst->capacity = 0;
}
void StackDestory(Stack* pst){
    assert(pst);
    free(pst);
    pst->array = NULL;
    pst->capacity = pst->top = 0;
}
bool StackIsEmpty(Stack*pst){
    assert(pst);
    if(pst->top == 0) return true;
    else  return false;
}
void StackPush(Stack* pst , StackDataType x){
    assert(pst);
    if(pst->capacity == pst->top){
        int new_capacity = pst->capacity; //for capacity expansion
        if(pst->capacity == 0){
            new_capacity = 4;
        }
        new_capacity *= 2;
        StackDataType* tmp_arr = (StackDataType*)realloc(pst->array ,sizeof(StackDataType)*new_capacity );
        assert (tmp_arr);
        pst->array = tmp_arr;
        pst->capacity = new_capacity;
    }
    pst->array[pst->top] = x;
    pst->top++;
}

void StackPop(Stack* pst){
    assert(pst);
    assert(!StackIsEmpty(pst));
    pst->top--;

}
StackDataType StackTop(Stack* pst){
    assert(pst);
    assert(!StackIsEmpty(pst));
    return pst->array[pst->top-1];
}

int StackSize(Stack* pst) {
    assert(pst);

    return pst->top;
}