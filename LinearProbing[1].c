#include <stdio.h>
#include <stdlib.h>
int hash(int arr[], int temp){
    int i=0;
    while(arr[(temp+i*i)%10]!=-1){
        i++;
    }
    return (temp+i*i)%10;
}
void main(){
    int hashlist[10];
    int choice=1,values=0,temp;
    for(int i=0;i<10;i++){
        hashlist[i]=-1;
    }
    while(choice==1){
        printf("Enter value: ");
        scanf("%d",&temp);
        hashlist[hash(hashlist,temp)]=temp;
        values++;
        if(values>9){
            printf("The table is full: ");
            break;
        }
        printf("Continue? 1/0\n");
        scanf("%d",&choice);
    }

     for(int i=0;i<10;i++){
       printf("%d\t", hashlist[i]);
    }
    
}


