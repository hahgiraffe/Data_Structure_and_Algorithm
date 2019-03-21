/*
 * @Description: AVL平衡二分查找树
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-20 23:42:59
 * @LastEditTime: 2019-03-20 23:43:58
 */
#ifndef _AVL_TREE_H
#define _AVL_TREE_H
#include "../head.h"
typedef struct Node* Position;
typedef struct Node* Avltree;
struct Node
{
    Node *left;
    Node *right;
    int height;
    int val;
};
Avltree MakeEmpty(Avltree T);
Position Find(int x,Avltree T);
Position FindMax(Avltree T);
Position FindMin(Avltree T);
Avltree Insert(int x,Avltree T);
Avltree Delete(int x,Avltree T);

static int Height(Position p);

Avltree Singlerotatewithleft(Avltree T);
Avltree Singlerotatewithright(Avltree T);
Avltree Doublerotatewithleft(Avltree T);
Avltree Doublerotatewithright(Avltree T);

void show(Avltree T,int level,vector<vector<int>> &vec)；

#endif