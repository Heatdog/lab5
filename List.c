//
// Created by yura on 10.05

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include "dialog.h"
#include <string.h>

Graph *new_matrix(Graph *graph){
    graph = (Graph*) malloc(sizeof (Graph));
    graph->list = NULL;
    graph->count = 0;
    return graph;
}

//////////////// Insertion ///////////////

void add_vertex(Graph* graph){
    Node *node = NULL;
    List *list = NULL;
    int keys[2];
    char *name = NULL;
    printf("Please, enter name of this vertex\nName-->");
    name = scan_string(name);
    printf("Please, enter coordinates of vertex\nX-->");
    scan_int(&keys[0]);
    printf("Y-->");
    scan_int(&keys[1]);
    list = check_name_coords(graph, name, keys);
    if (list != NULL){
        printf("You have already used this name or coordinates!\n");
        return;
    }
    node = new_node(node, keys, name);
    input_graph(graph, node);
}

Node *new_node(Node* node, int keys[], char *name){
    node = (Node*) malloc(sizeof (Node));
    node->next = NULL;
    node->prev = NULL;
    node->coordinates[0] = keys[0];
    node->coordinates[1] = keys[1];
    node->name = name;
    node->weight = 0;
    node->color = 0;
    return node;
}

void input_graph(Graph* graph, Node* node){
    if (graph->count == 0){
        graph->list = (List**) malloc(sizeof (List));
    } else{
        graph->list = (List**) realloc(graph->list, sizeof (List)*graph->count);
    }
    graph->list[graph->count] = (List*) malloc(sizeof (List));
    graph->list[graph->count]->head = node;
    graph->list[graph->count]->tail = node;
    graph->count++;
}


void add_edge(Graph* graph){
    char *edge_1 = NULL, *edge_2 = NULL;
    int weight;
    printf("Please, enter first edge\nEnter-->");
    edge_1 = scan_string(edge_1);
    printf("Please, enter second edge\nEnter-->");
    edge_2 = scan_string(edge_2);
    printf("Please, enter weight of edge\nEnter-->");
    scan_int(&weight);
    input_edge(graph, edge_1, edge_2, weight);
}


void input_edge(Graph* graph, char *name_1, char *name_2, int weight){
    List *vertex_1 = NULL, *vertex_2 = NULL;
    Node *node_1 = NULL, *node_2 = NULL;
    if (strcmp(name_1, name_2) == 0){
        printf("Please, try again! You entered two similar vertexes!\n");
        return;
    }
    for (int i = 0; i < graph->count; i++){
        if (strcmp(graph->list[i]->head->name, name_1) == 0){
            vertex_1 = graph->list[i];
        }
        if (strcmp(graph->list[i]->head->name, name_2) == 0){
            vertex_2 = graph->list[i];
        }
    }
    if (vertex_1 == NULL || vertex_2 == NULL){
        printf("We can`t find one of this edges!\n");
        return;
    }
    node_1 = copy_node(node_1, vertex_1->head, weight);
    node_2 = copy_node(node_2, vertex_2->head, weight);
    input_edge_in_list(vertex_1, node_2);
    input_edge_in_list(vertex_2, node_1);
}

void input_edge_in_list(List* list, Node* node){
    Node *ptr = list->tail;
    ptr->next = node;
    node->prev = ptr;
    list->tail = node;
    node->next = NULL;
}

Node *copy_node(Node* node_1, Node* node_2, int weight){
    node_1 = (Node*) malloc(sizeof (Node));
    node_1->name = (char *) calloc(strlen(node_2->name)+1, sizeof (char ));
    strcpy(node_1->name, node_2->name);
    node_1->coordinates[0] = node_2->coordinates[0];
    node_1->coordinates[1] = node_2->coordinates[1];
    node_1->next = NULL;
    node_1->prev = NULL;
    node_1->color = 0;
    node_1->weight = weight;
    return node_1;
}

/////////////// Show /////////////////////

void show_graph(Graph* graph){
    for (int i = 0; i < graph->count; i++){
        show_list(graph->list[i]);
        printf("\n");
    }
}

void show_list(List* list){
    Node *ptr = list->head;
    printf("(%s [%d:%d]): ", ptr->name, ptr->coordinates[0], ptr->coordinates[1]);
    ptr = ptr->next;
    while (ptr != NULL){
        show_node(ptr);
        ptr = ptr->next;
    }
}

void show_node(Node* node){
    printf("[(%s [%d:%d]) (%d)] ", node->name, node->coordinates[0], node->coordinates[1], node->weight);
}

/////////////// Delete /////////////////////

void delete_vertex(Graph* graph){
    char *name = NULL;
    printf("Please, enter name of this vertex\nEnter-->");
    name = scan_string(name);
    delete_vertex_key(graph, name);
}

void delete_vertex_key(Graph* graph, char *name){
    List *list = NULL, *list_ptr = NULL;
    Node *ptr = NULL;
    int i = 0;
    for (i = 0; i < graph->count; i++){
        if (strcmp(graph->list[i]->head->name, name) == 0){
            list = graph->list[i];
            break;
        }
    }
    ptr = list->head->next;
    while (ptr != NULL){
        list_ptr = find_list(graph, ptr->name);
        delete_in_list(list_ptr, name);
        ptr = ptr->next;
    }
    delete_list(list);
    graph->list[i] = graph->list[graph->count-1];
    graph->count--;
}

void delete_in_list(List* list, char *name){
    Node *ptr = NULL;
    ptr = list->head->next;
    while (ptr != NULL){
        if (strcmp(ptr->name, name) == 0){
            ptr->prev->next = ptr->next;
            if (ptr == list->tail){
                list->tail = ptr->prev;
            }
            free(ptr->name);
            free(ptr);
            return;
        }
        ptr = ptr->next;
    }
}

void delete_list(List* list){
    Node *ptr = list->head, *ptr_prev = NULL;
    while (ptr != NULL){
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev->name);
        free(ptr_prev);
    }
}


void delete_edge(Graph* graph){
    char *name_1 = NULL, *name_2 = NULL;
    printf("Please, enter first name of vertex\nEnter-->");
    name_1 = scan_string(name_1);
    printf("Please, enter second name of vertex\nEnter-->");
    name_2 = scan_string(name_2);
    delete_edge_key(graph, name_1, name_2);
}


void delete_edge_key(Graph* graph, char *name_1, char *name_2){
    List *list_1 = NULL, *list_2 = NULL;
    list_1 = find_list(graph, name_1);
    list_2 = find_list(graph, name_2);
    if (list_2 == NULL || list_1 == NULL){
        printf("We can`t find this elements!\n");
        return;
    }
    delete_in_list(list_1, name_2);
    delete_in_list(list_2, name_1);
}

/////////////// BFS ////////////////////////

List *find_list(Graph* graph, char *name){
    for (int i = 0 ; i < graph->count; i++){
        if (strcmp(graph->list[i]->head->name, name) == 0){
            return graph->list[i];
        }
    }
    return NULL;
}

List *check_name_coords(Graph* graph, char *name, int keys[]){
    for (int i = 0 ; i < graph->count; i++){
        if (strcmp(graph->list[i]->head->name, name) == 0 || (graph->list[i]->head->coordinates[0] == keys[0] &&
        graph->list[i]->head->coordinates[1] == keys[1])){
            return graph->list[i];
        }
    }
    return NULL;
}

Node *DFS(Graph* graph, char *name, char *find){
    Node *ptr = NULL, *ptr_prev = NULL, *ptr_list = NULL;
    List *list = NULL;
    List *list_find = NULL;
    list = find_list(graph, name);
    ptr = list->head;
    ptr_prev = ptr;
    ptr->color = 1;
    ptr_list = ptr->next;
    while (ptr_list != NULL){
        list_find = find_list(graph, ptr_list->name);
    }
    while (ptr != NULL){
        if (strcmp(ptr->name, find) == 0){
            return ptr;
        }
        if(ptr->color == 0){
            DFS(graph, ptr->name, find);
        }
        ptr = ptr->next;
    }
    ptr_prev->color = 2;
    return NULL;
}
