/*
 * @Description:  分离链接法建立hashtable
 * @Author: haha_giraffe
 * @Date: 2019-03-23 13:34:08
 */


#include "separate_chaining_hash.h"

Hashtable_ptr InitializeTable(int tablesize){
    Hashtable_ptr h;
    h=(Hashtable_ptr)malloc(sizeof(Hashtable));
    if(h==NULL){
        printf("malloc error\n");
        return NULL;
    }
    h->tablesize=tablesize;//这里可以设定为下一个素数
    h->Thelist=(List*)malloc(sizeof(Position)*h->tablesize);//Thelist指向一个指针数组（一个数组，里面存放着都是指针，指针指向ListNode节点）
    if(h->Thelist==NULL){
        printf("malloc error\n");
        return NULL;
    }
    for(int i=0;i<h->tablesize;i++){
        h->Thelist[i]=(Position)malloc(sizeof(struct ListNode));//这个头节点初始化
        if(h->Thelist[i]==NULL){
            printf("malloc error\n");
            return NULL;
        }
        else{
            h->Thelist[i]->next=NULL;
        }
    }
    return h;
}
void DestroyTable(Hashtable_ptr h){
    List l;
    for(int i=0;i< h->tablesize;i++){
        l=h->Thelist[i];
        Position tmp=l;
        while(tmp!=NULL){
            Position tmp2=tmp->next;
            free(tmp);
            tmp=tmp2;
        }
        
    }
    return;
}
Position Find(int key,Hashtable_ptr h){
    Position p;
    List l;
    l=h->Thelist[Hash(key,h->tablesize)];
    p=l->next;
    while(p!=NULL && p->val!=key){
        p=p->next;
    }
    return p;
}
void Insert(int key,Hashtable_ptr h){
    Position pos;
    List l;
    Position newnode;
    pos=Find(key,h);
    if(pos==NULL){
        newnode=(Position)malloc(sizeof(ListNode));
        if(newnode==NULL){
            printf("malloc error\n");
            return ;
        }
        else{
            l=h->Thelist[Hash(key,h->tablesize)];
            newnode->next=l->next;//头插入
            newnode->val=key;
            l->next=newnode;
        }
    }
    //如果hash表中已经存在，则不用插入  
}

int Hash(int key,int tablesize){
    if(tablesize==0){
        printf("tablesize error\n");
        return NULL;
    }
    return key%tablesize;//最简单的散列函数
}
int main(){
    Hashtable_ptr ptr=InitializeTable(10);
    for(int i=0;i<15;i++){
        Insert(i,ptr);
    }
    Position p=Find(11,ptr);
    cout<<p->val<<"  "<<p->next->val;
    return 0;
}