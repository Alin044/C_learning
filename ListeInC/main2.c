#include <stdio.h>
#include <stdlib.h>

struct dlinkList{
    int data;
    struct dlinkList *left;
    struct dlinkList *right;
};

typedef struct dlinkList node;
node* start = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    printf("\nEnter the data of type int : ");
    scanf("%d", &newNode-> data);
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
int countnode(node* start){
    if(start == NULL){
        return 0;
    }else{
        return (1 + countnode(start -> right));
    }
}
void createList(int n){
    int i;
    node* newNode;
    node* temp;
    for(i = 0; i < n; i++){
        newNode = getNode();
        if(start == NULL){
            start = newNode;
        }else{
            temp = start;
            while(temp -> right != NULL){
                temp = temp -> right;
            }
            temp -> right = newNode;
            newNode -> left = temp;
        }
    }
}

void insert_at_beg(){
    node* newNode;
    newNode = getNode();
    if(start == NULL){
        start = newNode;
    }else{
        newNode -> right = start;
        start -> left = newNode;
        start = newNode;
    }
}
void insert_at_end(){
    node* newNode, *temp;
    newNode = getNode();
    if(start == NULL){
        start = newNode;
    }else{
        temp = start;
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        temp -> right = newNode;
        newNode -> left = temp;
    }
}

void insert_at_mid(){
    node* newNode, *temp, *prev;
    int pos, nodectr, ctr =  1;
    newNode = getNode();
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if(pos > 1 && pos < nodectr + 1){
        temp = start;
        prev = NULL;
        while(ctr < pos){
            prev = temp;
            temp = temp -> right;
            ctr++;  
        }
        prev -> right = newNode;
        newNode -> left = prev;
        newNode -> right = temp;
        if(temp != NULL){
            temp -> left = newNode;    
        }else{
            printf("\nPosition %d is not a middle position ", pos);
        }   
    }
}
void delete_at_beg(){
    node* temp;
    if(start == NULL){
        printf("\nList is empty");
        return ;
    }else{
        temp = start;
        start = start -> right;
        if(start -> right != NULL){
            start -> left = NULL;
        }
        free(temp);
    }
}

void delete_at_end(){
    node* temp, *prev;
    if(start == NULL){
        printf("\nList is empty");
        return ;
    }else{
        temp = start;
        if(temp -> right == NULL){
            start = NULL;
            free(temp);
            return;
        }
        while(temp -> right != NULL){
            prev = temp;
            temp = temp -> right;
        }
        prev -> right = NULL;
        free(temp);
    }
}
void delete_at_mid(){
    node* temp, *prev;
    int ctr = 1, pos, nodectr;
    if(start == NULL){
        printf("\nList is empty");
        return ;
    }else{
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if(pos > 1 && pos < nodectr + 1){
            temp = start;
            ctr = 1;
            while(ctr < pos){
                prev = temp;
                temp = temp -> right;
                ctr++;
            }
            prev -> right = temp -> right;
            temp -> right -> left = temp -> left;
            free(temp);
            printf("\nMiddle node deleted");
        }
    }
}
void traverse(){
    node* temp;
    if(start == NULL){
        printf("\nList is empty");
        return ;
    }else{
        temp = start;
        while(temp != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> right;
        }
    }
}
void rev_traverse(){
    node* temp;
    if(start == NULL){
        printf("\nList is empty");
        return ;
    }else{
        temp = start;
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        while(temp != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> left;
        }
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
                printf("\nEnter number of nodes : ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                insert_at_beg();
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
                rev_traverse();
                break;
            case 10:
                printf("\nNumber of nodes are %d", countnode(start));
                break;
            case 11:
                exit(0);
        }
    }
    return 0;
}
































