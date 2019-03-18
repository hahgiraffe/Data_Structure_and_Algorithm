#include "queue.h"

void Queue::CreateQueue(){
    q->front=1;
    q->rear=0;
    q->size=0;
    q->capacity=10;
    q->array[q->capacity]={0};
    // for(int i=0;i<q->capacity;i++){
    //     q->array[i]=0;
    // }
}

int Queue::IsEmpty(){
    return q->size==0;
}

int Queue::IsFull(){
    return (q->size==q->capacity);
}

void Queue::Enqueue(int x){
    if(IsFull()){
        printf("full\n");
    }
    else{
        q->size++;
        q->rear=(q->rear+1)%(q->capacity);
        q->array[q->rear]=x;
    }
}


void Queue::Dequeue(){
    if(IsEmpty()){
        printf("empty\n");
    }
    else{
        q->size--;
        q->array[q->front]=0;
        q->front=(q->front+1)%(q->capacity);
    }
}

int Queue::Front(){
    return q->array[q->front];
}

void Queue::MakeEmpty(){
    q->size=0;
    while(q->rear!=q->front){
        q->array[q->front]=0;
        q->front=(q->front+1)%q->capacity;
    }
    q->array[q->front]=0;
}

void Queue::Print(){//打印方向相反
    int tmp=q->front;
    while(q->rear!=tmp){
        cout<<q->array[tmp]<<" ";
        tmp=(tmp+1)%q->capacity;
    }
    cout<<q->array[tmp]<<endl;
}
int main(){
    Queue queue;
    queue.CreateQueue();
    queue.Enqueue(7);
    for(int i=0;i<7;i++){
        queue.Enqueue(i);
    }
    queue.Print();
    queue.Dequeue();
    queue.Dequeue();
    queue.Print();
    cout<<queue.Front();
    return 0;
}