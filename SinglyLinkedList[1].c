#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert_beg(struct node* head, int data){if(head!=NULL){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head->next;
    head->next=newnode;
}}
void ins_end(struct node* head, int data){if(head!=NULL){
struct node* newnode;
newnode = (struct node*)malloc(sizeof(struct node));
while(head->next!=NULL){
    head=head->next;

}
head->next=newnode;
newnode->next=NULL;
newnode->data=data;

}
}
void ins_after(struct node* head, int data, int af){
    struct node* new;
    new= (struct node*)malloc(sizeof(struct node));
    while(head->next!=NULL && head->data!=af){
        head=head->next;
    }
    
    new->data=data;
    new->next=head->next;
    head->next=new;}
void ins_bef(struct node* head, int data, int af){
    struct node* new;
    new= (struct node*)malloc(sizeof(struct node));
    while(head->next!=NULL && head->next->data!=af){
        head=head->next;
    }
    
    new->data=data;
    new->next=head->next;
    head->next=new;}
void del(struct node* head, int data){
    if(head!=NULL){
        while(head->next->data!=data){
            if(head->next!=NULL){
                head=head->next;
            }else{printf("Not found");break;}

        }
        head->next=head->next->next;
    }else{printf("Underflow!");}
}

void disp(struct node* ptr){
    struct node* head=ptr;
    if(head->next!=NULL){
        while(head->next!=NULL){
            printf("%d\t",head->next->data);
            head=head->next;
        }
    }else{printf("underflow");}
}
void size_list(struct node* head){
    if(head==NULL){printf("List not found");}else{
        int i=0;
        while(head!=NULL){i++;
            head=head->next;
        }
        printf("%d",i-1);
    }
}
void del_start(struct node* head){
    if(head!=NULL){
        head->next=head->next->next;
    }
}
void del_end(struct node* head){
    if(head!=NULL){if(head->next!=NULL){
        while(head->next->next!=NULL){
            head=head->next;
        }
        head->next=head->next->next;
    }else{head->next=NULL;}}
}
void update_node(struct node* head,int data,int data2){if(head!=NULL){
    while(head->data!=data){
        if(head->next!=NULL){
        head=head->next;}else{printf("Not found");break;}
    }
    head->data=data2;
    
}}
int main(){
    struct node* head;
    head= (struct node*)malloc(sizeof(struct node));
    int data, af;

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    insert_beg(head, data);

    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    ins_end(head, data);

    printf("Enter data to insert after: ");
    scanf("%d", &data);
    printf("Enter the value after which to insert: ");
    scanf("%d", &af);
    ins_after(head, data, af);

    printf("Enter data to insert before: ");
    scanf("%d", &data);
    printf("Enter the value before which to insert: ");
    scanf("%d", &af);
    ins_bef(head, data, af);

    disp(head);
    printf("\n");

    int oldData, newData;
    printf("Enter the data to update: ");
    scanf("%d", &oldData);
    printf("Enter the new data: ");
    scanf("%d", &newData);
    update_node(head, oldData, newData);

    disp(head);
return 0;}