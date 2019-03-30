/*
 * @Description:  单源无权图上，最短路径，BFS用队列
 * @Author: haha_giraffe
 * @Date: 2019-03-30 18:19:15
 */
#ifndef _SHORTEST_PATH_WITHOUT_VALUE_H
#define _SHORTEST_PATH_WITHOUT_VALUE_H
#include "../head.h"
#define MAX_NODE_NUM 100
typedef struct Graph* Graph_ptr;
struct Graph{
    int map[MAX_NODE_NUM][MAX_NODE_NUM];
    int node_number;
    int edge_number;
};
Graph_ptr InitGraph();
void Shortest_path(vector<bool>,vector<int>,Graph_ptr);
void DestroyGraph(Graph_ptr ptr);
#endif