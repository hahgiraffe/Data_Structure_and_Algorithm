/*
 * @Description:  平方探测法建立Hashtable
 * @Author: haha_giraffe
 * @Date: 2019-03-23 15:08:40
 */
#ifndef OPEN_ADDRESSING_HASH_H
#define OPEN_ADDRESSING_HASH_H

#include "../head.h"

typedef struct Hashtable* Hashtable_ptr;
typedef unsigned int Index;
typedef Index Position;
enum Stat{used,empty,deleted};

struct Hashnode
{
    int val;
    enum Stat info;
};

struct Hashtable
{
    int tablesize;
    Hashnode *hashlist;

};

Hashtable_ptr InitializeTable(int tablesize);
void DestroyTable(Hashtable_ptr h);
Position Find(int key,Hashtable_ptr h);
void Insert(int key,Hashtable_ptr h);
Hashtable_ptr Rehash(Hashtable_ptr h);
int Hash(int key,int tablesize);
void print_hash(Hashtable_ptr h);

#endif