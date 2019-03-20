/*
 * @Description: 二分查找树
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-19 15:31:15
 * @LastEditTime: 2019-03-19 16:44:48
 */
#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_
#include "../head.h"

typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

struct TreeNode{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):value(x),left(NULL),right(NULL){ }
};

SearchTree MakeEmpty(SearchTree T);
Position Find(SearchTree T,int x);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(SearchTree T,int x);
SearchTree Delete(SearchTree T, int x);
//int Retrieve(Position p);
void show(SearchTree T,int &level,vector<vector<int>> vec);

#endif