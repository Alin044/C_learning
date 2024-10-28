//Write a C function to insert a node "t" befor a
//node pointed to by "X" in a single linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;
node* startX = NULL;
node* startT = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("\nEnter the value of the node : ");
    scanf("%d", &newNode -> data);
    newNode -> next = NULL;
    return newNode;
}

void createNodeList(node** head, int n){
    node* newNode;
    node* temp;
    int i = 0;
    for(i = 0; i < n; i++){
        newNode = getNode();
        if(*head == NULL){
            *head = newNode;
        }else{
            temp = *head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}

void appendTwoLists(){
    if(startT  == NULL){
        printf("The list T is empty ! ");
        return ;
    }
    if(startX == NULL){
        printf("The list X is empty ! ");
        return ;
    }
    node* temp = startX;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = startT;
    // node* temp1, *temp2;
    // temp1 = startX;
    // if(startT != NULL && startX != NULL){
    //     temp2 = startT;
    //     while(temp2 -> next != NULL){
    //         temp2 = temp2 -> next;
    //     }
    //     temp2 -> next = startX;
    // }
}
void displayList(node* head){
    node* temp = head;
    while(temp != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> next;
    }
}

int main(){
    int n;
    printf("\nEnter the number of nodes for list X : ");
    scanf("%d", &n);
    createNodeList(&startX, n);
    printf("\nEnter the number of nodes for list T : ");
    scanf("%d", &n);
    createNodeList(&startT, n);
    appendTwoLists();
    displayList(startX);

    return 0;
}