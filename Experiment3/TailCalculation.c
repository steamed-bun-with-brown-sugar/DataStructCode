//
// Created by wage on 2022-10-20.
//

/*
 * 实验三  栈和队列

【开发语言及实现平台或实验环境】
Windows 操作系统， C开发环境。
【实验目的】
1、掌握基于数组的顺序栈和顺序队列实现。
2、理解栈的后进先出特性。
3、理解队列的先进先出特性。
【实验内容】
一、基于数组的顺序栈结构声明
struct Stack {
    int * Data;   // 栈空间
    int Top;      // 栈顶，为-1时表示空栈
    int MaxSize; //栈的最大容量
};

二、基于数组的循环队列结构声明
struct Queue {
    int * Data; // 动态分配存储空间
    int Front;  // 队头
    int Rear;   // 队尾
    int Size; // 队列中元素个数
    int MaxSize; // 队列最大容量
};

三、实验内容
1、栈的一种应用是检测代码中的括号是否正确匹配。例如：
代码形如{...(...)...[...]...} 为正确匹配。
代码形如{...[...]...}...} 错误，多了一个}。
代码形如{...[...}...]虽然数量正确，但次序错误。
编写程序，读入一个字符串，其中包含{}、[]、()三种括号，检查该字符串中的括号是否正确匹配。
提示：
依次读入每个字符。（1）若遇到左括号，压栈。（2）若遇到右括号，检查栈顶的左括号：若与右括号匹配，则弹出栈顶左括号；若不匹配，说明匹配错误；若栈中无内容，说明匹配错误。（3）若遇到其他符号，忽略之。
                (4）若字符串已读完，此时栈中仍有内容，说明匹配错误。


2、编写程序，输入一个后缀表达式字符串，操作符只可能有+、-、*、/四种二元运算，操作数之间用空格隔开。输出该表达式的计算结果，若表达式不正确，给出错误提示。
例如输入：123 4*5+67-
输出：430


3、编写程序，实现一个循环队列，入队几个数据，出队几个数据，然后输出队列中的剩余元素以及队头和队尾的下标，检查是否和预想一致。

 * */


#include<stdio.h>
#include<stdlib.h>
//#include <rpcndr.h>
#include <stdbool.h>

struct StackInt{
    int *Data;
    int Top;
    int MaxSize;

};
struct StackChar{

    char *Data;
    int Top;
    int MaxSize;
};


struct StackInt * StackIntCreate(int MaxSize);
void PushInt(struct StackInt *S1,int data);
//int PopInt();
//void CurrentInt(struct StackInt *S1);


struct StackChar * StackCharCreate(int MaxSize);
void PushChar(struct StackChar *S1,char data);
//char  PopChar();
void CurrentChar(struct StackChar *S1);


void SignCheck();
void TailCal();

/**********************        NULL         *****************/

int main(){

    SignCheck();
    TailCal();
}


struct StackChar * StackCharCreate(int MaxSize){

    struct StackChar* New = (struct StackChar *)malloc(sizeof(struct StackChar));
    New->MaxSize = MaxSize;
    New->Top = -1;
    New->Data=(char*)malloc(sizeof(char)*MaxSize);
    return New;
}


void PushChar(struct StackChar *S1,char data){
    if(S1->MaxSize-1==S1->Top){
        printf("\nPush failed: the stack is full!\n");
        return;
    }

    S1->Top++;
    S1->Data[S1->Top] = data;
}


char PopChar(struct StackChar *S1){
    char re = 0;

    if(S1->Top == -1){
        printf("\nPop failed: the Stack is Empty\n");
        return re;
    }

    re = S1->Data[S1->Top];
    S1->Top--;
    return re;
}
void CurrentChar(struct StackChar *S1){
    if(S1->Top==-1)
        printf("\nThe Stack is Emppty!\n");
    else
    printf("\nStack Peak:%d\t data:%c\n",S1->Top,S1->Data[S1->Top]);
}

/**********       Signtest          ******/
void SignCheck(){

    char String[50];
    for (int i = 0; i < 50; i++) {
        String[i]='\0';
    }
    gets(String);


    struct StackChar *S1 = StackCharCreate(20);
    char *ptr = String;

    while(*ptr!='\0') {
        CurrentChar(S1);

        bool halt = false;

        switch (*ptr) {

            case '(':
            case '[':
            case '{':
                PushChar(S1, *ptr);
                break;

            case ')':

                S1->Data[S1->Top] == '(' ? PopChar(S1) : (halt = true);
                break;

            case ']':

                S1->Data[S1->Top] == '[' ? PopChar(S1) : (halt = true);
                break;


            case '}':

                S1->Data[S1->Top] == '{' ? PopChar(S1) : (halt = true);
                break;

        }
        if (halt == true)break;
        ptr++;
    }




/*
        if(*ptr=='(' || *ptr=='[' || *ptr=='{'){
            PushChar(S1,*ptr);
            ptr++;
            continue;
        }

        if(*ptr==')'){

            if(S1->Data[S1->Top]=='(')
                PopChar(S1);
            else
                break;
        }
        if(*ptr==']'){

            if(S1->Data[S1->Top]=='[')
                PopChar(S1);
            else
                break;
        }
        if(*ptr=='}'){

            if(S1->Data[S1->Top]=='{')
                PopChar(S1);
            else
                break;
        }
     ptr++;
*/

    CurrentChar(S1);
    if(S1->Top == -1)
        printf("Spous Succeed!\n");

    else
        printf("Spous Failed!\n");
}

/************************************************************/
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
void CurrentInt(struct StackChar *S1){
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

    int x ,n1,n2;
    struct StackInt *S1 = StackIntCreate(10);

    while(*ptr!='\0'){

        printf("Switch : %c(switch)\n",*ptr);
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

                n2 = PopInt(S1);
                n1 = PopInt(S1);

                *ptr=='+' ? PushInt(S1,n1+n2): 0;
                *ptr=='+' ? PushInt(S1,n1+n2): 0;
                *ptr=='*' ? PushInt(S1,n1*n2): 0;
                *ptr=='/' ? PushInt(S1,n1/n2): 0;

            case ' ':
                ptr++;
                break;
        }
    }

    printf("ans== %d\n",PopInt(S1));
}








//////////////////////////////////////////////////////////
