/*
 * @Description:  平方探测法建立Hashtable
 * @Author: haha_giraffe
 * @Date: 2019-03-23 15:00:02
 */
#include "open_addressing_hash.h"

Hashtable_ptr InitializeTable(int tablesize){
    Hashtable_ptr h;
    h=(Hashtable_ptr)malloc(sizeof(Hashtable));
    if(h==NULL){
        printf("malloc error\n");
        return NULL;
    }
    h->tablesize=tablesize;
    h->hashlist=(Hashnode*)malloc(h->tablesize*sizeof(Hashtable));
    if(h->hashlist==NULL){
        printf("malloc error\n");
        return NULL;
    }
    for(int i=0;i<h->tablesize;i++){
        h->hashlist[i].info=Stat::empty;
    }
    return h;
}
void DestroyTable(Hashtable_ptr h){
    free(h->hashlist);
    free(h);
}
Position Find(int key,Hashtable_ptr h){
    Position pos;
    int collisionnum=0;
    pos=Hash(key,h->tablesize);
    while(h->hashlist[pos].info!=Stat::empty && h->hashlist[pos].val!=key){
        pos+=2*(++collisionnum)-1;
        if(pos>=h->tablesize){
            pos-=h->tablesize;
        }
    }
    return pos;
}
void Insert(int key,Hashtable_ptr h){
    Position pos;
    pos=Find(key,h);
    if(h->hashlist[pos].info!=Stat::used){
        h->hashlist[pos].info=Stat::used;
        h->hashlist[pos].val=key;
    }
}
Hashtable_ptr Rehash(Hashtable_ptr h){
    //再散列，当填充因子大于某个数值时候，就表明该散列表不够大，
    //因此新建一个散列表其大小为原散列表的两倍，并将原散列表中的元素再放置到新散列表
    int i;
    int oldsize=h->tablesize;
    Hashnode * oldhash=h->hashlist;
    h=InitializeTable(2*oldsize);
    for(int i=0;i<oldsize;i++){
        if(oldhash[i].info==Stat::used){
            Insert(oldhash[i].val,h);
        }
    }
    free(oldhash);
    return h;
}
int Hash(int key,int tablesize){
    return key%tablesize;
}
void print_hash(Hashtable_ptr h){
    int len=h->tablesize;
    for(int i=0;i<len;i++){
        cout<<h->hashlist[i].val<<" ";
    }
}

int main(){
    Hashtable_ptr ptr=InitializeTable(30);
    for(int i=0;i<18;i++){
        Insert(i,ptr);
    }
    Insert(1,ptr);
    Insert(2,ptr);
    Insert(31,ptr);
    print_hash(ptr);
    return 0;
}