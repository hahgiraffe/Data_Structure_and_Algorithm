/*
 * @Description:  Dijkstra算法，计算单源有权图最短路径算法,BFS队列
 * @Author: haha_giraffe
 * @Date: 2019-03-30 19:32:43
 */
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include "../head.h"
#define MAX_NODE_NUM 100
typedef struct Graph* Graph_ptr;
struct Graph{
    int map[MAX_NODE_NUM][MAX_NODE_NUM];
    int node_number;
    int edge_number;
};
Graph_ptr InitGraph();
void Dijkstra(vector<bool>,vector<int>,Graph_ptr);
void DestroyGraph(Graph_ptr ptr);

#endif