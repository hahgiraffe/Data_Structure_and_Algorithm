/*
 * @Description: 伸展树（自底向上）
 * @Author: haha_giraffe
 * @Date: 2019-03-21 15:07:59
 */
#ifndef _SPLAY_TREE_H
#define _SPLAY_TREE_H
#include "../head.h"
typedef struct Node* Splay_tree;
typedef struct Node* Position;
//结点中有指向父节点的指针
struct Node
{
    int val;
    Splay_tree left;
    Splay_tree right;
    Splay_tree parent;    
};


Splay_tree MakeEmpty(Splay_tree T);
Position Find(int x,Splay_tree T);
Position FindMax(Splay_tree T);
//Position FindMin(Splay_tree T);
Splay_tree Insert(int x,Splay_tree T);
Splay_tree Delete(int x,Splay_tree T);
Splay_tree Singlerotatewithleft(Splay_tree T);
Splay_tree Singlerotatewithright(Splay_tree T);
Splay_tree Doublerotatewithleft(Splay_tree T);
Splay_tree Doublerotatewithright(Splay_tree T);
void show(Splay_tree T,int level,vector<vector<int>> &vec);
void get_show(Splay_tree root);
Splay_tree Splay(Splay_tree tmp,Splay_tree T);
Position searchvalue(int x,Splay_tree T);
#endif