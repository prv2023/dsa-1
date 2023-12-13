#include <stdio.h>
#include <stdlib.h>
int isOpening(char ch){
    return ch=='[' || ch == '{' || ch =='(';
}
int isClosing(char ch){
     return ch==']' || ch == '}' || ch==')';
}
int isMatch(char ch, char ch2){
    return (ch=='['&& ch2==']')||(ch=='{'&& ch2=='}')||(ch=='('&& ch2==')');
}
int isBalanced(char exp[]){
    char stack[100];
    int top=-1;
    for(int i=0;exp[i]!='\0';i++){
        if(isOpening(exp[i])){
            top++;stack[top]=exp[i];
        }else if(isClosing(exp[i])){if(top!=-1){
            if(isMatch(stack[top],exp[i])){
                top--;
                
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }}
    
    return top==-1;
}

int main(){
    int maxsize=100;
    char expression[maxsize];
    printf("Enter an expression");
    fgets(expression,maxsize, stdin);
    if(isBalanced(expression)){
        printf("Balacned");
    }else{
        printf("Not balanced");
    }

}