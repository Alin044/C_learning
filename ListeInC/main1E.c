#include <stdio.h>
#include <stdlib.h>

struct slinkList{
    int data;
    struct slinkList *next;
};

typedef struct slinkList node;
node* start1 = NULL;
node* start2 = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("\n Enter the data of type int : ");
    scanf("%d", &newNode-> data);
    newNode -> next = NULL;
    return newNode;
}
void createList(int n){
    int i;
    node* newNode;
    node* temp;
    for(i = 0; i < n; i++){
        newNode = getNode();
        if(start1 == NULL){
            start1 = newNode;
        }else{
            
            temp = start1;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}
int countListNodes(node* start){
    if(start1 == NULL){
        printf("\n List is empty");
        return 0;
    }
    else{
        return(1 + countListNodes(start -> next));
    }
}
void separateList(){
    node* temp1, *temp2;
    int i;
    int ctr = countListNodes(start1);
    temp1 = start1;
    temp2 = start2;
    node* opt;

    if(start1 == NULL){
        printf("\n List is empty");
        return ;
    }else{
        for(i = 0; i < ctr; i+=2){
            if(temp1 -> next != NULL){
                temp2 = (node*)malloc(sizeof(node));
                temp2 = temp1 -> next;
                temp2 = temp2 -> next;
                opt = temp1 -> next;
                free(opt);
                temp1 -> next = temp1 -> next ->next;
                temp1 = temp1 -> next;
            }
        }
    }
}
void displayLists(){
    int ctr1, ctr2;
    int i;
    node* temp1 = start1;
    node* temp2 = start2;
    ctr1 = countListNodes(start1);
    ctr2 = countListNodes(start2);
    printf("The first list is : ");
    if(start1 == NULL || start2 == NULL){
        printf("\n List is empty");
        return;
    }else{
        for(i = 0; i < ctr1; i++){
            printf("%d -> ", temp1->data);
            temp1 = temp1 -> next;
        }
        printf("X\n");
        printf("The second list is : ");
        for(i = 0; i < ctr1; i++){
            printf("%d -> ", temp1->data);
            temp1 = temp1 -> next;
        }
        printf("X\n");
    }
}


int main(){
    int n;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    createList(n);
    separateList();
    displayLists();
    return 0;
}