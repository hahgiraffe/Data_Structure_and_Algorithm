/*
 * @Description: 单向链表头文件
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 13:06:22
 * @LastEditTime: 2019-03-16 16:06:06
 */

#ifndef LINKLIST_H
#define LINKLIST_H
#include "../head.h"

typedef struct Node* List;
typedef Node* Position;
struct Node
{
    int val;
    Node *next;
    Node (int v):val(v),next(NULL){ }
};

class Linklist
{
public:
    List head;
public:
    ~Linklist();
    Linklist(vector<int> vec);
    List MakeEmpty();
    int isEmpyt();
    int isLast(Position p);
    Position Find(int x);
    void Delete(Position p);
    Position FindPrevious(int x);
    void Insert(int x,Position p);
    void DeleteList();
    void PrintList();
    //Position Head(List l);
    //Position First(List l);
    //Position Advance(Position p);
    //int Retrieve(Position p);
};


#endif