/*
 * @Description: 用链表表示栈
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 20:18:56
 * @LastEditTime: 2019-03-16 20:58:09
 */

#include "stack_list.h"

void Stack::CreateStack(){
    ptrnode tmp=new Node();//建立一个头结点
    if(tmp==NULL){
        printf("error create\n");
    }
    tmp->next=NULL;
    head=tmp;
    return ;
}

int Stack::IsEmpty(){
    return head->next==NULL;
}

void Stack::DisposeStack(){
    
}

void Stack::MakeEmpty(){
    if(head==NULL){
        printf("error\n");
    }
    else{
        while(!IsEmpty()){
            Pop();
        }
    }
}

void Stack::Push(int x){
    ptrnode tmp=new Node(x);
    if(tmp==NULL){
        printf("error new\n");
    }
    else{
        tmp->next=head->next;
        head->next=tmp;
    }
}

void Stack::Pop(){
    if(!IsEmpty()){
        ptrnode temp=head->next;
        head->next=head->next->next;
        delete(temp);
    }
    else{
        return;
    }
}

int Stack::Top(){
    if(!IsEmpty()){
        return head->next->val;
    }
    else{
        printf("top error\n");
        return 0;
    }
}

void Stack::Print(){
    ptrnode temp=head->next;
    while(temp){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    
    Stack s;
    s.CreateStack();
    for(int i=0;i<10;i++){
        s.Push(i);
    }
    s.Print();
    s.Pop();
    s.Print();
    printf("%d\n",s.Top());
    s.MakeEmpty();
    s.Print();
    return 0;
}