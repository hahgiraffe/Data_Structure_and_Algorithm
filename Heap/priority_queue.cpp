/*
 * @Description:  优先队列创建小顶堆（数组实现）
 * @Author: haha_giraffe
 * @Date: 2019-03-25 13:09:44
 */
#include "priority_queue.h"

Priority_queue Initialize(int max){
    Priority_queue p;
    p=(Priority_queue)malloc(sizeof(struct HeapStruct));
    if(p==NULL){
        printf("malloc error\n");
        return NULL;
    }
    p->size=0;
    p->capacity=max;
    p->val=(int*)malloc((max+1)*sizeof(int));
    if(p==NULL){
        printf("malloc error\n");
        return NULL;
    }
    p->val[0]=0;//val[0]存储最小的值
    return p;
}
void Destroy(Priority_queue p){
    free(p->val);
    free(p);
}
void MakeEmpty(Priority_queue p){
    p->size=0;
    free(p->val);
    p->val=(int*)malloc(p->capacity*sizeof(int));
    if(p==NULL){
        printf("malloc error\n");
        return;
    }
    return ;
}
void Insert(Priority_queue p,int x){//注意要把val[0]的位置空出来
    int i;
    if(IsFull(p)){
        printf("full\n");
        return;
    }
    for(i=++p->size;p->val[i/2]>x;i=i/2){//上滤过程，插入的节点先放到完全二叉树最尾部，然后一步一步与父节点置换
        p->val[i]=p->val[i/2];
    }
    p->val[i]=x;
    return;
}
int DeleteMin(Priority_queue p){
    int min,last,i,child;
    if(IsEmpty(p)){
        printf("empty\n");
        return p->val[0];
    }
    min=p->val[1];
    last=p->val[p->size--];
    for(i=1;i*2<=p->size;i=child){//下滤过程，因为不能保证每个节点都有两个子节点，所以先要检测左孩子是否存在，
        child=i*2;
        if(child != p->size && p->val[child+1]<p->val[child]){//这里就是为了找到左右子节点中较小的那个
            child++;
        }
        if(last>p->val[child]){
            p->val[i]=p->val[child];
        }
        else{
            break;
        }
    }
    p->val[i]=last;
    return min;
}

int FindMin(Priority_queue p){
    if(IsEmpty(p)){
        printf("empty\n");
        return -1;
    }
    return p->val[1];
}

int IsEmpty(Priority_queue p){
    if(p->size==0){
        return 1;
    }
    return 0;
}
int IsFull(Priority_queue p){
    if(p->size==p->capacity){
        return 1;
    }
    return 0;
}

void Show(Priority_queue p){
    for(int i=1;i<=p->size;i++){
        printf("%d ",p->val[i]);
    }
    cout<<endl;
}

int main(){
    Priority_queue p = Initialize(15);
    Insert(p,30);
    Insert(p,25);
    Insert(p,14);
    Insert(p,3);
    Insert(p,356);
    Insert(p,32);
    Show(p);
    DeleteMin(p);
    Show(p);
}