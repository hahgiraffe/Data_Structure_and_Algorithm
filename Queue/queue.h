/*
 * @Description: 队列的数组实现
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-18 10:36:47
 * @LastEditTime: 2019-03-18 11:41:03
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "../head.h"

typedef struct Queue_data* Queue_data_ptr;
struct Queue_data
{
    int capacity;
    int front;
    int rear;
    int size;
    int array[];
};

class Queue
{
public:
    int IsEmpty();
    int IsFull();
    void Enqueue(int x);
    void Dequeue();
    int Front();
    void CreateQueue();
    void MakeEmpty();
    void Print();
private:
    Queue_data_ptr q;
};




#endif

