/*
 * @Description:  分离链接法建立hashtable
 * @Author: haha_giraffe
 * @Date: 2019-03-23 13:39:50
 */
#ifndef SEPARATE_CHAINING_HASH_H
#define SEPARATE_CHAINING_HASH_H

#include "../head.h"
struct ListNode;
typedef struct ListNode* Position;
struct Hashtable;
typedef struct Hashtable* Hashtable_ptr;
typedef Position List;

typedef struct ListNode
{
    int val;
    Position next;
};

typedef struct Hashtable
{
    int tablesize;
    List *Thelist;//Thelist是ListNode指针的指针
};

Hashtable_ptr InitializeTable(int tablesize);
void DestroyTable(Hashtable_ptr h);
Position Find(int key,Hashtable_ptr h);
void Insert(int key,Hashtable_ptr h);
int Hash(int key,int tablesize);





#endif