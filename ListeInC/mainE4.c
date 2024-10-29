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
void createNode(int n){
    int i;
    node* newNode;
    node* temp;
    for(i = 0; i < n; i++){
        newNode = getNode();
        temp = start;
        if(start == NULL){
            start = newNode;
        }else{
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}
int count42(){
    node* temp;
    int ctr = 0;
    if(start == NULL){
        printf("\n List is empty");
        return 0;
    }
    temp = start;
    while(temp != NULL){
        if(temp -> data == 42){
            ctr++;
        }
        temp = temp -> next;
    }
    return ctr; 
}

int main(){
    int n;
    printf("\n Enter the number of nodes : ");
    scanf("%d", &n);
    createNode(n);
    printf("\n Number of 42's in the list : %d", count42());

    return 0;
}