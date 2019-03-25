/*
 * @Description:  
 * @Author: haha_giraffe
 * @Date: 2019-03-25 15:54:38
 */

#include "leftist_heap.h"

int FindMin(Priority_queue p){
    return p->val;
}

void Swapchild(Priority_queue p){
    Priority_queue tmp= p->left;
    p->left=p->right;
    p->right=tmp;
}

static Priority_queue Merge1(Priority_queue p1,Priority_queue p2){
    if(p1->left==NULL){
        p1->left=p2;
    }else{
        p1->right=Merge(p1->right,p2);
        if(p1->left->npl < p1->right->npl){
            Swapchild(p1);
        }
        p1->npl=p1->right->npl+1;
    }
}

Priority_queue Merge(Priority_queue p1,Priority_queue p2){
    if(p1==NULL){
        return p2;
    }
    if(p2==NULL){
        return p1;
    }
    if(p1->val < p2->val){
        return Merge1(p1,p2);
    }
    else
    {
        Merge1(p2,p1);
    }
    
}
int IsEmpty(Priority_queue p){
    if(p==NULL){
        return 1;
    }
    return 0;
}

Priority_queue Insert1(int x,Priority_queue p){
    Priority_queue tmp;
    tmp=(Priority_queue)malloc(sizeof(struct leftist_node));
    if(tmp==NULL){
        printf("malloc error\n");
    }
    tmp->val=x;
    tmp->left=tmp->right=NULL;
    tmp->npl=0;
    p=Merge(tmp,p);
    return p;
}

Priority_queue DeleteMin1(Priority_queue p){
    Priority_queue leftheap,rightheap;
    if(IsEmpty(p)){
        printf("error\n");
        return NULL;
    }
    leftheap=p->left;
    rightheap=p->right;
    free(p);
    return Merge(leftheap,rightheap);
}
void Printtree(Priority_queue p){
    queue<Priority_queue> q;
    q.push(p);
    while(!q.empty()){
        Priority_queue tmp=q.front();
        cout<<tmp->val;
        q.pop();
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
    return;
}

int main(){
    Priority_queue p;
    Insert(10,p);
    for(int i=3;i<10;i+=2){
        Insert(i,p);
    }
    Printtree(p);
    cout<<endl;
    p=DeleteMin1(p);
    Printtree(p);
    return 0;
}