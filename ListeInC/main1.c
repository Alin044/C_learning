#include <stdio.h>
#include <stdlib.h>

struct slinkList{
    int data;
    struct slinkList *next;
};
typedef struct slinkList node; 
node* start = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("\nEnter the data of type int : ");
    scanf("%d", &newNode-> data);
    newNode -> next = NULL;
    return newNode; 
}
void createList(int n){
    int i;
    node *newNode;
    node *temp;
    for(i = 0; i < n; i++){
        newNode = getNode();
        if(start ==  NULL){
            start = newNode;
        }else{
            temp = start;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
}
int countnode(node* start){
    if(start == NULL){
        return 0;
    }else{
        return (1 + countnode(start -> next));
    }
}

void insert_at_begin(){
    node *newNode;
    newNode = getNode();
    if(start == NULL){
        start = newNode;
    }else{
        newNode -> next = start;
        start = newNode;
    }
}
void insert_at_end(){
    node *newNode;
    node *temp;
    newNode = getNode();
    if(start == NULL){
        start = newNode;
    }else{
        temp = start;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void insert_at_mid(){
    node *newNode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newNode = getNode();
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if(pos > 1 && pos < nodectr + 1){
        temp = prev = start;
        while(ctr < pos){
            prev = temp;
            temp = temp -> next;
            ctr++;
        }
        prev -> next = newNode;
        newNode -> next = temp;
    }else {
        printf("position %d is not a middle position ", pos);
    }
}
void delete_at_beg(){
    node* temp;
    if(start == NULL){
        printf("\nNo nodes Exist");
        return ;
    }else{
        temp = start;
        start = start -> next;
        free(temp);
        printf("\nFirst node deleted");
    }
}
void delete_at_end(){
    node *temp, *prev;
    if(start == NULL){
        printf("\nNo nodes Exist");
        return ;
    }else{
        temp = start;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
        printf("\nLast node deleted");
    }
}
void delete_at_mid(){
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    if(start == NULL){
        printf("\nNo nodes Exist");
        return ;
    }else{
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if(pos > 1 && pos < nodectr + 1){
            temp = prev = start;
            while(ctr < pos){
                prev = temp;
                temp = temp -> next;
                ctr++;
            }
            prev -> next = temp -> next;
            free(temp);
            printf("\nMiddle node deleted");
        }else{
            printf("\nInvalid position !");
        }
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

void rev_Traverse(node * start){
    if(start == NULL){
        return;
    }else{
        rev_Traverse(start -> next);
        printf("%d -> ", start -> data);
    }
}
int menu(){
    int opt;
    printf("\n1.  Create List");
    printf("\n2.  Insert Node at the begining");
    printf("\n3.  Insert Node at the end");
    printf("\n4.  Insert Node at the middle");
    printf("\n5.  Delete Node at the begining");
    printf("\n6.  Delete Node at the end");
    printf("\n7.  Delete Node at the middle");
    printf("\n8.  Traverse the list (left to right)");
    printf("\n9.  Traverse the list (right to left)");
    printf("\n10. Count Nodes");
    printf("\n11. Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &opt);
    return opt;
}

int main(){
    int opt, n;
    while(1){
        opt = menu();
        switch(opt){
            case 1:
                if(start == NULL){
                    printf("\nNumber of nodes you want to create : ");
                    scanf("%d", &n);
                    createList(n);  
                }else{
                    printf("\nThe list is already created");
                }
                break;
            case 2: 
                insert_at_begin();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                insert_at_mid();
                break;
            case 5:
                delete_at_beg();
                break;
            case 6: 
                delete_at_end();
                break;
            case 7: 
                delete_at_mid();
                break;
            case 8:
                traverse();
                break;
            case 9:
                rev_Traverse(start);
                break;
            case 10:
                printf("\nTotal number of nodes are : %d", countnode(start));
                break;
            case 11:
                exit(0);
        }

    }
    return 0;   
}