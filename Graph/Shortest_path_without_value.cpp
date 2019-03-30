#include "Shortest_path_without_value.h"

Graph_ptr InitGraph(){
    printf("initial graph, input node_number and edge_number\n");
    int node_number, edge_number;
    scanf("%d %d",&node_number,&edge_number);
    Graph_ptr g=new Graph();
    g->edge_number=edge_number;
    g->node_number=node_number;
    int pointa,pointb;
    printf("input edge\n");
    for(int n=0;n<edge_number;n++){
        scanf("%d %d",&pointa,&pointb);
        g->map[pointa][pointb]=1;
    }
    return g;
}

void Shortest_path(vector<bool> Is_used,vector<int> dis,Graph_ptr ptr){
    int edgenum=ptr->edge_number;
    int nodenum=ptr->node_number;
    int begin_num;
    for(int i=1;i<=nodenum;i++){
        Is_used[i]=false;
        dis[i]=-1;
    }
    //从定点三出发
    printf("int the range of 1 ~ %d,input the begin node_number:",nodenum);
    scanf("%d",&begin_num);
    dis[begin_num]=0;
    queue<int> q;
    q.push(begin_num);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        Is_used[tmp]=true;
        for(int i=1;i<=nodenum;i++){
            if(ptr->map[tmp][i]==1 && Is_used[i]==false){
                Is_used[i]=true;
                q.push(i);
                dis[i]=dis[tmp]+1;
            }
        }
    }
    for(int i=1;i<=nodenum;i++){
        printf("%d ",dis[i]);
    }
    printf("\n");
}

void DestroyGraph(Graph_ptr ptr){
    free(ptr);
}
int main(){
    Graph_ptr ptr=InitGraph();
    vector<bool> Is_used(ptr->node_number+1);
    vector<int> dis(ptr->node_number+1);
    Shortest_path(Is_used,dis,ptr);
    return 0;
}