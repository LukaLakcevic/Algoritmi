#include <stdio.h>
#include <stdlib.h>


//Linked list:
//------------------------------------------------------------------------------------------------------------
typedef struct node{

    int e;
    struct node* next;
}node;

void add_node(int e, node** head){

    node* new_node = (node*)malloc(sizeof(node));
    new_node->e = e;
    new_node->next = *head;

    *head = new_node;
}

void print_node(node* head){

    printf("<");
    while(head){
        printf("%d ", head->e);
        head = head->next;
    }
    printf("\b>\n");
}

//Graph:
//---------------------------------------------------------------------------------------------------------

typedef struct graph{

    int n;
    node** nodes;
}graph;

graph* initialize(int n){

    graph* g = (graph*)malloc(sizeof(graph));
    g->n = n;
    g->nodes = (node**)malloc(n*sizeof(graph));

    for(int i = 0; i < n; i++)
        g->nodes[i] = NULL;

    return g;
}

void add_edge(int start, int finish, graph* g){

    add_node(start, &g->nodes[finish]);
    add_node(finish, &g->nodes[start]);
}

void print_graph(graph* g){

    for(int i = 0; i < g->n; i++)
        print_node(g->nodes[i]);
}

void dfs(int start, graph* g){

    int visited[g->n];
    int stack[g->n];
    int top = -1;

    for(int i = 0; i < g->n; i++)
        visited[i] = 0;

    visited[start] = 1;
    stack[++top] = start;

    while(top != -1){
        printf("%d ", stack[top--]);
        for(node* i = g->nodes[start]; i != NULL; i = i->next)
            if(visited[i->e] != 1){
                stack[++top] = i->e;
                visited[i->e] = 1;
            }                
    }
    
    printf("\n");
    
}

void bfs(int start, graph* g){

    int visited[g->n];
    int queue[g->n];
    int front = 0, rear = 0;

    for(int i = 0; i < g->n; i++){
        visited[i] = 0;
        queue[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    while(front != rear){
        printf("%d ", queue[front]);
        for(node* i = g->nodes[front++]; i != NULL; i = i->next)
            if(visited[i->e] != 1){
                queue[rear++] = i->e;
                visited[i->e] = 1;
            }
    }
    
    printf("\n"); 
}

int main(int argc, char* argv[]){

    graph* g = initialize(6);

    add_edge(0, 1, g);
    add_edge(0, 2, g);
    add_edge(1, 2, g);
    add_edge(0, 3, g);

    add_edge(4, 5, g);

    print_graph(g);
    
    dfs(0, g);    
    bfs(0, g);
    
    return 0;
}
