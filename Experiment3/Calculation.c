//
// Created by wage on 2022-10-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackInt{
    int *Data;
    int Top;
    int MaxSize;

};

struct StackInt * StackIntCreate(int MaxSize){

    struct StackInt* New = (struct StackInt *)malloc(sizeof(struct StackInt));
    New->MaxSize = MaxSize;
    New->Top = -1;
    New->Data=(int*)malloc(sizeof(int)*MaxSize);
    return New;
}


void PushInt(struct StackInt *S1,int data){
    if(S1->MaxSize-1==S1->Top){
        printf("\nPush failed: the stack is full!\n");
        return;
    }
    S1->Top++;
    S1->Data[S1->Top] = data;
}

int  PopInt(struct StackInt *S1){

    int re = 0;
    if(S1->Top == -1){
        printf("\nPop failed: the Stack is Empty\n");
        return re;
    }

    re = S1->Data[S1->Top];
    S1->Top--;
    return re;

}
void CurrentInt(struct StackInt *S1){
    if(S1->Top==-1)
        printf("\nThe Stack is Emppty!\n");
    else
        printf("\nStack Peak:%d\t data:%d\n",S1->Top,S1->Data[S1->Top]);
}



void TailCal(){

    printf("Input the Formula: ");
    char String[50];
    gets(String);
    char *ptr =  String;

    bool Error = false;
    int x ,n1,n2;
    struct StackInt *S1 = StackIntCreate(10);

    while(*ptr!='\0' && Error==false){

        switch (*ptr) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':

                x = *ptr - 48 ;
                ptr++;
                while(*ptr!='+'&& *ptr!='-' && *ptr!='*' && *ptr!='/' && *ptr!=' '){
                    x = x*10 + *ptr-48;
                    ptr++;
                }
                PushInt(S1,x);
                break;

            case '+':
            case '-':
            case '*':
            case '/':

                if(S1->Top==0){
                    Error = true;
                    break;
                }
                n2 = PopInt(S1);
                n1 = PopInt(S1);

                *ptr=='+' ? PushInt(S1,n1+n2): 0;
                *ptr=='+' ? PushInt(S1,n1+n2): 0;
                *ptr=='*' ? PushInt(S1,n1*n2): 0;
                *ptr=='/' ? PushInt(S1,n1/n2): 0;

            case ' ':
                ptr++;
                break;

            default:  //必须存在避免输入非法字符
                Error = true;
        }

    }

    Error == true ? printf("Wrong Formula: Please check your formula!\n") : printf("ans = %d\n",PopInt(S1));
}

int main(){
    TailCal();
}