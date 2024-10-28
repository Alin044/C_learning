//Write a C function to delete a node pointed to by "p"     
//from single linked list  "L"

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;
node* start = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("\n Enter data : ");
    scanf("%d", &newNode -> data);
    newNode -> next = NULL;
    return newNode;
}
void createList(int n){
    node *newNode;
    node *temp;
    int i;
    for(i = 0; i < n; i++){
        if(start == NULL){
            start = getNode();
        }else{
            temp = start;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
        temp -> next = getNode();
        }
    }

}
void deleteNodePointer(node* p){
    node* temp;
    if(start == NULL || p == NULL){
        printf("\n List is Empty or pointer is NULL");
        return ;
    }else{
        if(p == start){
            start = p -> next;
            free(p);
            return ;
        }
        temp = start;
        while(temp != NULL && temp -> next != p){
            temp = temp -> next;
        }
        if(temp == NULL){
            printf("\n Node not found");
            return ;
        }
        temp -> next = p -> next;
        free(p);
    }
}
void traverse(){
    node *temp;
    temp = start;
    printf("\nThe contents of the list (left to right) are : \n");
    if(start == NULL){
        printf("\nNo nodes Exist");
    }else{
        while(temp != NULL){
            printf("%d -> \n", temp -> data);
            temp = temp -> next;
        }
    }
    printf("X");
}
node* getPointer(int point){
    node* temp;
    int i = 0;
    if(start == NULL){
        printf("\n List is Empty");
        return 0;
    }else{
        temp = start;
        while(temp != NULL && i < point){
            temp = temp -> next;
            i++;
        }
        return temp;
    }
}

int main(){
    int n;
    int point;
    node* pp;
    printf("\n Enter the number of nodes you want : ");
    scanf("%d", &n);
    createList(n);
    printf("\n Enter the node you want to delete : ");
    scanf("%d", &point);
    pp = getPointer(point-1);
    deleteNodePointer(pp);
    traverse();

    return 0;
}