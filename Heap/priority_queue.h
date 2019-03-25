/*
 * @Description:  优先队列创建小顶堆（数组实现）
 * @Author: haha_giraffe
 * @Date: 2019-03-25 13:09:32
 */
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "../head.h"

typedef struct HeapStruct* Priority_queue;
Priority_queue Initialize(int max);
void Destroy(Priority_queue p);
void MakeEmpty(Priority_queue p);
void Insert(Priority_queue p,int x);
int DeleteMin(Priority_queue p);
int FindMin(Priority_queue p);
int IsEmpty(Priority_queue p);
int IsFull(Priority_queue p);
void Show(Priority_queue p);

struct HeapStruct
{
    int capacity;
    int size;
    int *val;
};


#endif

