//
// Created by wage on 2022-10-20.
//
//、编写程序，实现一个循环队列，入队几个数据，出队几个数据，然后输出队列中的剩余元素以及队头和队尾的下标，检查是否和预想一致。

#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int * Data; // 动态分配存储空间
    int Front;  // 队头
    int Rear;   // 队尾
    int Size; // 队列中元素个数
    int MaxSize; // 队列最大容量
};


struct Queue * QueueCreate(int MaxSize){

    struct Queue *New = (struct Queue*)malloc(sizeof(struct Queue));
    New->MaxSize = MaxSize;
    New->Data = (int*) malloc(sizeof(int)*MaxSize);
    New->Size =0;
    New->Front = 0;
    New->Rear = -1;
}

void EnQueue(struct Queue *Q,int data){
    if(Q->Size==Q->MaxSize){
        printf("EnQueue Failed: the queue is full!\n");
        return;
    }
    Q->Size++;
    Q->Rear == Q->MaxSize-1? Q->Rear=1 : ++Q->Rear;
    Q->Data[Q->Rear] = data;
}

int  OutQueue(struct Queue *Q){
    if(Q->Size == 0){
        printf("OutQueue failed: the Queue is Empty!\n");
        return -1;
    }
    Q->Size--;
    int data =Q->Data[Q->Front];
    Q->Front == Q->MaxSize-1 ? Q->Front=0 : Q->Front++;
    return  data;
}


void PrintQueue(struct Queue *Q){
    printf("Current Queue elements as follows:\n");
    int Index = Q->Front;
    for(int i = Q->Size; i > 0; i--){
        printf("%d\t",Q->Data[Index]);
        Index = Index == Q->MaxSize-1 ? 0 : Index + 1 ;
    }
    printf("\nCurrent RearIndex is : %d  \nCurrent FrontIndex is : %d\n",Q->Rear,Q->Front);
}


 int main(){

    struct Queue *Q = QueueCreate(10);
    EnQueue(Q,100);
    EnQueue(Q,200);
    EnQueue(Q,300);
    EnQueue(Q,400);
    EnQueue(Q,500);
    OutQueue(Q);
    OutQueue(Q);

    PrintQueue(Q);
 }


