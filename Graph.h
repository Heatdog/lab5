//
// Created by yura on 07.05.2021.
//

#ifndef LAB5_SEM2_GRAPH_H
#define LAB5_SEM2_GRAPH_H

#include "List.h"

typedef struct vertex {
    int name[2];
    int colour;
    struct vertex* pred;
    List* list;
    struct vertex* next;
}vertex;

typedef struct Graph {
    vertex* first;
    vertex* last;
}Graph;

Graph* new_graph();

int add_graph(Graph* graph, int name[]);

#endif //LAB5_SEM2_GRAPH_H
