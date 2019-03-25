/*
 * @Description:  左式堆实现
 * @Author: haha_giraffe
 * @Date: 2019-03-25 18:29:10
 */
#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "../head.h"
typedef struct leftist_node* Priority_queue;
struct leftist_node
{
    int val;
    int npl;//零路径长
    Priority_queue left;
    Priority_queue right;
};

//Priority_queue initialize(void);
int FindMin(Priority_queue p);
Priority_queue Merge(Priority_queue p1,Priority_queue p2);
int IsEmpty(Priority_queue p);

#define Insert(x,p) ( p=Insert1((x),p) )

Priority_queue Insert1(int x,Priority_queue p);
Priority_queue DeleteMin1(Priority_queue p);
#endif