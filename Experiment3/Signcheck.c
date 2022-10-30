////
//// Created by wage on 2022-10-22.
////
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//struct StackChar{
//
//    char *Data;
//    int Top;
//    int MaxSize;
//};
//
//struct StackChar * StackCharCreate(int MaxSize){
//
//    struct StackChar* New = (struct StackChar *)malloc(sizeof(struct StackChar));
//    New->MaxSize = MaxSize;
//    New->Top = -1;
//    New->Data=(char*)malloc(sizeof(char)*MaxSize);
//    return New;
//}
//
//
//void PushChar(struct StackChar *S1,char data){
//    if(S1->MaxSize-1==S1->Top){
//        printf("\nPush failed: the stack is full!\n");
//        return;
//    }
//
//    S1->Top++;
//    S1->Data[S1->Top] = data;
//}
//
//
//char PopChar(struct StackChar *S1){
//    char re = 0;
//
//    if(S1->Top == -1){
//        printf("\nPop failed: the Stack is Empty\n");
//        return re;
//    }
//
//    re = S1->Data[S1->Top];
//    S1->Top--;
//    return re;
//}
//void CurrentChar(struct StackChar *S1){
//    if(S1->Top==-1)
//        printf("\nThe Stack is Emppty!\n");
//    else
//        printf("\nStack Peak:%d\t data:%c\n",S1->Top,S1->Data[S1->Top]);
//}
//
//
//void SignCheck() {
//
//    char String[50];
//    for (int i = 0; i < 50; i++) {
//        String[i] = '\0';
//    }
//    gets(String);
//
//    struct StackChar *S1 = StackCharCreate(20);
//    char *ptr = String;
//
//    while (*ptr != '\0') {
//
//        bool halt = false;
//        switch (*ptr) {
//            case '(':
//            case '[':
//            case '{':
//                PushChar(S1, *ptr);
//                break;
//            case ')':
//                S1->Data[S1->Top] == '(' ? PopChar(S1) : (halt = true);
//                break;
//            case ']':
//                S1->Data[S1->Top] == '[' ? PopChar(S1) : (halt = true);
//                break;
//            case '}':
//                S1->Data[S1->Top] == '{' ? PopChar(S1) : (halt = true);
//                break;
//
//        }
//        if (halt == true){
//        S1->Top = 0;  //匹配刚好多出 } ] ) 时，S1->Top为-1，故添加这句以解决此问题
//        break;
//        }
//        ptr++;
//    }
//
//    if(S1->Top == -1)
//        printf("Spous Succeed!\n");
//    else
//        printf("Spous Failed!\n");
//}
//
//
//int main(){
//
//    SignCheck();
//}
//


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct StackChar{
    char *Data;
    int Top;
    int MaxSize;
};

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


void SignCheck() {
    char String[50];
    for (int i = 0; i < 50; i++) {
        String[i] = '\0';
    }
    gets(String);
    struct StackChar *S1 = StackCharCreate(20);
    char *ptr = String;
    while (*ptr != '\0') {
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
        if (halt == true){
//匹配刚好多出 } ] ) 时，S1->Top也为-1，故添加下句以解决此问题
            S1->Top = -2;
            break;
        }
        ptr++;
    }
    if(S1->Top == -1)
        printf("Spous Succeed!\n");
    else
        printf("Spous Failed!\n");
}
int main(){
    SignCheck();
}
