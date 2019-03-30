#include "Dijkstra.h"

Graph_ptr InitGraph(){
    printf("initial graph, input node_number and edge_number\n");
    int node_number, edge_number;
    scanf("%d %d",&node_number,&edge_number);
    Graph_ptr g=new Graph();
    g->edge_number=edge_number;
    g->node_number=node_number;
    int pointa,pointb,value;
    printf("input edge\n");
    for(int n=0;n<edge_number;n++){
        scanf("%d %d %d",&pointa,&pointb,&value);
        g->map[pointa][pointb]=value;
    }
    return g;
}

void Dijkstra(vector<bool> Is_used,vector<int> dis,Graph_ptr ptr){
    int edgenum=ptr->edge_number;
    int nodenum=ptr->node_number;
    int begin_num;
    for(int i=1;i<=nodenum;i++){
        Is_used[i]=false;
        dis[i]=__INT_MAX__;
    }
    printf("int the range of 1 ~ %d,input the begin node_number:",nodenum);
    scanf("%d",&begin_num);
    dis[begin_num]=0;
    queue<int> q;
    q.push(begin_num);
    Is_used[begin_num]=true;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=1;i<=nodenum;i++){
            if(ptr->map[tmp][i]!=0 && Is_used[i]==false){
                q.push(i);
                Is_used[i]=true;
            }
            if(ptr->map[tmp][i]!=0 && dis[tmp]+ptr->map[tmp][i]<dis[i]){
                dis[i]=dis[tmp]+ptr->map[tmp][i];
            }
        }
    }
    for(int i=1;i<=nodenum;i++){
        printf("%d ",dis[i]);
    }
}

void DestroyGraph(Graph_ptr ptr){
    free(ptr);
}
int main(){
    Graph_ptr ptr=InitGraph();
    vector<bool> Is_used(ptr->node_number+1);
    vector<int> dis(ptr->node_number+1);
    Dijkstra(Is_used,dis,ptr);
    DestroyGraph(ptr);
    return 0;
}