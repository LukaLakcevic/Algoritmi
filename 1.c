#include <stdio.h>

typedef struct node{

    int e;
    struct node* next;
}node;

node* create(int e, node* head){

    node* newNode = (node*)malloc(sizeof(node));
    
    newNode->e = e;
    newNode->next = head;

    return newNode;
}

void addNode(int e, node** head){

    *head = create(e, *head);
}

void print_List(node* head){

    printf("<");
    while(head){
        printf("%d ", head->e);
        head = head->next;
    }
}

typedef struct Graph{

    int n;
    node** array;
}Graph;

Graph* createG(int n){

    Graph* g = (Graph*)malloc(sizeof(Graph));

    g->n = n;
    g->array = (node**)malloc(sizeof(node));

    for(int i = 0; i < n; i++)
        g->array[i] = NULL;

    return g;
}

void addEdge(Graph* g, int e1, int e2){

    addNode(e1, g->array[e2]);
    addNode(e2, g->array[e1]);
}

void dfs(Graph* g, int start, int visited[]){


    visited[start] = 1;
    printf("%d ", start);

    for(node* i = g->array[start]; i != NULL; i = i->next)
        if(!visited[i]])
            dfs(g, i->e, visited);
}















