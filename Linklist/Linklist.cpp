/*
 * @Description: 单向链表实现与测试
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 13:19:00
 * @LastEditTime: 2019-03-16 16:14:09
 */
#include "Linklist.h"

Linklist::~Linklist(){
    DeleteList();
}
//如果链表为空则返回true
int Linklist::isEmpyt(){
    List l=head;
    return l->next==NULL;
}
//如果Position为链表最后一个结点则返回true
int Linklist::isLast(Position p){
    return p->next==NULL;
}
//链表查找，如果找到则返回第一个值所对应的位置，否则为空
Position Linklist::Find(int x){
    List tmp=head;
    while(tmp!=NULL){
        if(x==tmp->val){
            break;
        }
        tmp=tmp->next;
    }
    return tmp;
}
//在链表l中，插入结点x到p所指向的位置的后方
void Linklist::Insert(int x,Position p){
    Node *newnode=new Node(x);
    newnode->next=p->next;
    p->next=newnode;
}
//找到值为x的前一个位置
Position Linklist::FindPrevious(int x){
    List tmp=head;
    while(tmp->next!=NULL && tmp->next->val != x){
        tmp=tmp->next;
    }
    return tmp;
}
//删除x结点
void Linklist::Delete(Position p){
    List l=head;
    while(l->next!=p){
        l=l->next;
    }
    if(p->next==NULL){
        l->next=NULL;
        delete p;
    }
    else{
        l->next=p->next;
        delete p;
    }
}
//删除整个链表
void Linklist::DeleteList(){
    List tmp=head->next;
    head->next=NULL;
    List tmp2;
    while(tmp!=NULL){
        tmp2=tmp->next;
        delete tmp;//注意delete以后就不能用tmp->next，因为其没有指向任何一个对象
        tmp=tmp2;
    }
}
//把整个链表置空
List Linklist::MakeEmpty(){
    List l=head;
    List tmp=l->next;
    while(tmp){
        tmp->val=0;
        tmp=tmp->next;
    }
    return l;
}
//构造函数
Linklist::Linklist(vector<int> vec){
    List l=new Node(0);
    List tmp=l;
    for(int i=0;i<vec.size();i++){
        List newnode=new Node(vec[i]);
        tmp->next=newnode;
        tmp=tmp->next;
    }
    tmp->next=NULL;
    head=l;
}
//打印链表
void Linklist::PrintList(){
    List l=head;
    while(l){
        cout<<l->val<<" ";
        l=l->next;
    }
    cout<<endl;
}

int main(){
    vector<int> vec{2,7,4,9,6};
    Linklist *ll=new Linklist(vec);
    // cout<<ll->head->val<<" "<<ll->head->next->val;
    // ll->PrintList();
    // ll->Delete(ll->head->next->next);
    // ll->PrintList();
    // cout<<ll->Find(9)->val;
    // ll->Insert(100,ll->head->next->next);
    // ll->PrintList();
    delete ll;
    return 0;
}