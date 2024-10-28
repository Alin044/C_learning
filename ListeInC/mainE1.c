#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;

node* L = NULL;
node* R1 = NULL;
node* R2 = NULL;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void appendNode(node** head, int data){
    node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void displayList(node* head){
    node* temp = head;
    while(temp != NULL){
            printf("%d -> ", temp -> data);
            temp = temp -> next;
    }
    printf("NULL\n");
}
void splitList(node* head){
    int i = 0;
    node* temp = head;
    while(temp != NULL){
        if(i % 2 == 0){
            appendNode(&R2, temp -> data);
        }else{
            appendNode(&R1, temp -> data);
        }
        temp = temp -> next;
        i++;
    }
}

int main(){
    int n, data;
    int i;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter data for node %d ", i + 1);
        scanf("%d", &data);
        appendNode(&L, data);   
    }

    printf("Original list L : ");
    displayList(L);

    splitList(L);

    printf("List R1 : ");
    displayList(R1);

    printf("List R2 : ");
    displayList(R2);
    
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct slinkList{
//     int data;
//     struct slinkList *next;
// };

// typedef struct slinkList node;
// node* start1 = NULL;
// node* start2 = NULL;

// node* getNode(){
//     node* newNode;
//     newNode = (node*)malloc(sizeof(node));
//     printf("\n Enter the data of type int : ");
//     scanf("%d", &newNode-> data);
//     newNode -> next = NULL;
//     return newNode;
// }
// void createList(int n){
//     int i;
//     node* newNode;
//     node* temp;
//     for(i = 0; i < n; i++){
//         newNode = getNode();
//         if(start1 == NULL){
//             start1 = newNode;
//         }else{
            
//             temp = start1;
//             while(temp -> next != NULL){
//                 temp = temp -> next;
//             }
//             temp -> next = newNode;
//         }
//     }
// }
// int countListNodes(node* start){
//     if(start1 == NULL){
//         printf("\n List is empty");
//         return 0;
//     }
//     else{
//         return(1 + countListNodes(start -> next));
//     }
// }
// void separateList(){
//     node* temp1 = start1;
//     node* temp2 = NULL;
//     node* prev = NULL;
//     int i = 0;
//     while(temp1 != NULL){
//         if(i % 2 == 0){
//             if(start2 == NULL){
//                 start2 = temp1;
//                 temp2 = start2;
//             }else{
//                 temp2 -> next = temp1;
//                 temp2 = temp2 -> next;
//             }
//             if(prev != NULL){
//                 prev -> next = temp1 -> next;
//             }
//         }else{
//             prev = temp1;
//         }
//         temp1 = temp1 -> next;
//         i++;
//     }
// }
// void separateListl(){
//     node* temp1 = start1;
//     node* temp2 = NULL;
//     node* prev = NULL;
//     node* next = temp1 -> next;
//     int i = 1;
//     while(temp1 != NULL){
//         if(i % 2 == 0){
//             if(start2 == NULL){
//                 start2 = temp1;
//                 temp2 = start2;
//             }else{
//                 temp2 -> next = temp1;
//                 temp2 = temp2 -> next;
//             }
//             if(prev != NULL){
//                 prev -> next = next;
//             }
//             temp2 -> next = NULL;
//         }else{
//             prev = temp1;
//         }
//         temp1 = next;
//         i++;
//     }
// }
// void displayLists(){
//     int ctr1, ctr2;
//     int i;
//     node* temp1 = start1;
//     node* temp2 = start2;
//     ctr1 = countListNodes(start1);
//     ctr2 = countListNodes(start2);
//     printf("The first list is : ");
//     if(start1 == NULL || start2 == NULL){
//         printf("\n List is empty");
//         return;
//     }else{
//         for(i = 0; i < ctr1; i++){
//             printf("%d -> ", temp1->data);
//             temp1 = temp1 -> next;
//         }
//         printf("X\n");
//         printf("The second list is : ");
//         for(i = 0; i < ctr1; i++){
//             printf("%d -> ", temp1->data);
//             temp1 = temp1 -> next;
//         }
//         printf("X\n");
//     }
// }


// int main(){
//     int n;
//     printf("\nEnter the number of nodes : ");
//     scanf("%d", &n);
//     createList(n);
//     separateList();
//     displayLists();
//     return 0;
// }