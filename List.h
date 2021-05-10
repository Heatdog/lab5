//
// Created by yura on 10.05.2021.
//

#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H


typedef struct node_{
    int coordinates[2];
    char *name;
    int weight;
    int color;
    struct node_* next;
    struct node_* prev;
}Node;

typedef struct list_{
    Node *head;
    Node *tail;
}List;

typedef struct graph_{
    List **list;
    int count;
}Graph;


Graph *new_matrix(Graph*);
//////////////// Insertion ///////////////
void add_edge(Graph *);
Node *new_node(Node*, int[], char *);
void input_graph(Graph*, Node*);
void add_vertex(Graph*);
void input_edge(Graph*, char *, char *, int);
void input_edge_in_list(List*, Node*);
Node *copy_node(Node*, Node*, int);
List *check_name_coords(Graph*, char *, int []);
/////////////// Show /////////////////////
void show_graph(Graph*);
void show_list(List*);
void show_node(Node*);
/////////////// Delete /////////////////////
void delete_vertex(Graph*);
void delete_vertex_key(Graph*, char *);
void delete_in_list(List*, char *);
void delete_list(List*);
void delete_edge(Graph*);
void delete_edge_key(Graph*, char *, char *);
/////////////// BFS ////////////////////////
List *find_list(Graph*, char *);
//void BFS(Graph*, char *, int**);



#endif //GRAPH_LIST_H
