/*
 * @Description: 用链表表示栈
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 20:19:30
 * @LastEditTime: 2019-03-16 20:51:24
 */

#ifndef STACK_LIST_H
#define STACK_LIST_H
#include "../head.h"
typedef struct Node* ptrnode;

struct Node {
    int val;
    Node *next;
    Node():val(0),next(NULL){ }
    Node(int x):val(x),next(NULL){ }
};

class Stack{
public:
    int IsEmpty();
    void CreateStack();
    void DisposeStack();
    void MakeEmpty();
    void Push(int x);
    void Pop();
    int Top();
    void Print();
public:
    ptrnode head;//头结点
};

#endif