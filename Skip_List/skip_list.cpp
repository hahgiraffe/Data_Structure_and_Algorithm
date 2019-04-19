#include "skip_list.h"

Node* createNode(int level,int key ,int value){
    Node* newnode=(Node*)malloc(sizeof(Node)+level*sizeof(Node*));
    newnode->key=key;
    newnode->value=value;
    return newnode;
}
SkipList* createList(){
    SkipList* sl=(SkipList*)malloc(sizeof(SkipList));
    sl->level=0;
    sl->head=createNode(MAX_LEVEL-1,0,0);
    for(int i=0;i<MAX_LEVEL;i++){
        sl->head->array[i]=NULL;//头结点的每个指针都初始化为空
    }
    return sl;
}
int randomlevel(){
    //插入元素时候，占有层数随机生成
    int k=1;
    while(rand()%2){//相当于每次都是1/2几率
        k++;
    }
    k=(k<MAX_LEVEL)?k:MAX_LEVEL;
    return k;
}
bool insert_list(SkipList* sl,int key ,int value){
    //首先查找到待插入的位置，然后随机一个层数level，最后从高层往下插入
    Node* update[MAX_LEVEL];
    Node *p,*q=NULL;
    p=sl->head;
    int k=sl->level;
    for(int i=k-1;i>=0;i--){
        while((q=p->array[i]) && q->key<key){
            //q指向i层下一个节点，比较两个节点的key值
            p=q;
        }
        update[i]=p;
    }
    if(q && q->key==key){//不能插入相同的key值
        return false;
    }
    k=randomlevel();//产生一个随机值k层
    if(k>sl->level){
        for(int i=sl->level;i<k;i++){
            update[i]=sl->head;
        }
        sl->level=k;
    }
    q=createNode(k,key,value);
    for(int i=0;i<k;i++){
        q->array[i]=update[i]->array[i];
        update[i]->array[i]=q;
    }
    return true;
}
bool delete_list(SkipList* sl,int key){
    Node* update[MAX_LEVEL];
    Node *p,*q=NULL;
    p=sl->head;
    int k=sl->level;
    for(int i=k-1;i>=0;i--){
        while((q=p->array[i]) && q->key<key){
            //q指向i层下一个节点，比较两个节点的key值
            p=q;
        }
        update[i]=p;
    }
    if(q && q->key==key){
        for(int i=0;i<sl->level;i++){
            if(update[i]->array[i]==q){
                update[i]->array[i]=q->array[i];
            }
        }
        free(q);
        //考虑如果删除的是最高层的节点，则要更新整个跳表的level值
        for(int i=sl->level-1;i>=0;i--){
            if(sl->head->array[i]==NULL){
                sl->level--;
            }
        }
        return true;
    }
    else{
        return false;
    }
    
}
int find_list(SkipList* sl,int key){
    Node *p,*q;
    p=sl->head;
    int k=sl->level;//从最高层往下查看
    for(int i=k-1;i>=0;i--){
        while((q=p->array[i]) && q->key<=key){
            if(q->key==key){
                return q->value;
            }
            p=q;
        }
    }
    return NULL;
}
void printsl(SkipList* sl){
    Node* p,*q;
    int k=sl->level;
    for(int i=k-1;i>=0;i--){
        p=sl->head;
        while(q=p->array[i]){
            printf("%d(%d)->",p->key,p->value);
            p=q;
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    SkipList *sl=createList();
    for(int i=1;i<=10;i++){
        insert_list(sl,i,i*i);
    }
    printsl(sl);
    //printf("%d\n",find_list(sl,4));
    delete_list(sl,1);
    printsl(sl);
    return 0;
}