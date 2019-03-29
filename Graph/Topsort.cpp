#include "Topsort.h"
#include <queue>
//有向图初始化
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
void PrintGraph(Graph_ptr ptr){
    for(int i=1;i<=ptr->node_number;i++){
        for(int j=1;j<=ptr->node_number;j++){
            if(ptr->map[i][j]==1){
                printf("%d -> %d\n",i,j);
            }
        }
    }
}

void Topsort(Graph_ptr ptr,vector<int> &arr,vector<int> &res){
    queue<int> q;
    initial_arr(arr,ptr);
    for(int i=1;i<=ptr->node_number;i++){
        if(arr[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int loc=q.front();
        q.pop();
        res.push_back(loc);
        for(int i=1;i<=ptr->node_number;i++){
            if(ptr->map[loc][i]==1){
                arr[i]--;
                if(arr[i]==0){
                    q.push(i);
                }
            }
        }
    }
}

void initial_arr(vector<int> &arr,Graph_ptr ptr){
    for(int i=1;i<=ptr->node_number;i++){
        int num=0;
        for(int j=1;j<=ptr->node_number;j++){
            if(ptr->map[j][i]==1){
                num++;
            }
        }
        arr[i]=num;
    }
}
int main(){
    Graph_ptr g=InitGraph();
    vector<int> arr(g->node_number);//记录每个顶点的入度
    vector<int> res;
    Topsort(g,arr,res);
    for(auto a:res){
        printf("%d ",a);
    }
    printf("\n");
    //PrintGraph(g);
}