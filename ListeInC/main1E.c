#include <stdio.h>
#include <stdlib.h>

struct slinkList{
    int data;
    struct slinkList *next;
};

typedef struct slinklist node;
node* start1 = NULL;
node* start2 = NULL;

node* getNode(){
    node* newNode;
    newNode = (node*)malloc(sizeof(node));
    
}