/*
 * @Description:  拓扑排序
 * @Author: haha_giraffe
 * @Date: 2019-03-29 14:24:59
 */
#ifndef _TOPSORT_H
#define _TOPSORT_H
#include "../head.h"
#define MAX_NODE_NUM 100

typedef struct Graph* Graph_ptr;
struct Graph{
    int map[MAX_NODE_NUM][MAX_NODE_NUM];
    int node_number;
    int edge_number;
};
Graph_ptr InitGraph();
void PrintGraph(Graph_ptr );
void Topsort(Graph_ptr ptr,vector<int> &arr,vector<int> &res);
void initial_arr(vector<int> &arr,Graph_ptr ptr);
#endif