/*
 * @Description:  SkipList跳表实现
 * @Author: haha_giraffe
 * @Date: 2019-04-19 12:23:13
 */
#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include "../head.h"
#define MAX_LEVEL 10
struct Node{
    int key;
    int value;
    struct Node* array[1];//指针数组,便于结构体存储不同数量的指针
};

struct SkipList{
    int level;
    Node *head;
};

Node* createNode(int level,int key ,int value);//创建一个跳表节点
SkipList* createList();//创建跳表
int randomlevel();//随机生成level值
bool insert_list(SkipList* sl,int key ,int value);//插入跳表一个节点
bool delete_list(SkipList* sl,int key);//删除跳表中一个节点
int find_list(SkipList* sl,int key);//跳表查找
void printsl(SkipList* sl);//打印跳表
#endif