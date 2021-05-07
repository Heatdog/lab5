//
// Created by yura on 07.05.2021.
//

#include "Graph.h"

#include <stdbool.h>

vertex* new_vertex() {
    vertex* pVertex = NULL;
    pVertex = (struct vertex*)malloc(sizeof (struct vertex));
    pVertex->list = new_list();
    if (pVertex->list == NULL) {
        return NULL;
    }
    return pVertex;
}

Graph* new_graph() {
    Graph* pGraph = NULL;
    pGraph = (struct Graph*)malloc(sizeof (struct Graph));
    return pGraph;
}

int add_graph(Graph* graph, int name[]) {
    vertex* new_el = new_vertex();
    if (new_el == NULL) {
        return -1;
    }
    new_el->name[0] = name[0];
    new_el->name[1] = name[1];
    if (graph->first == NULL) {
        graph->first = new_el;
        graph->last = new_el;
    } else {
        graph->last->next = new_el;
        graph->last = graph->last->next;
    }
    return 0;
}

int graph_initialization(Graph* graph, vertex* ptr_1, vertex* Q) {
    vertex* pBuf = graph->first;
    while (pBuf != NULL) {
        pBuf->colour = 1;
        pBuf->pred = NULL;
    }
    ptr_1->colour = 0;
    Q[0] = ptr_1[0];

    return 0;
}

int find_graph(List* list, vertex* Q) {
    int tail = 1;
    for (int i = 0; i < tail; i++) {
        vertex* u = &Q[i];
        for (Item* ptr = u->list->head; ptr != NULL; ptr = ptr->next) {
        }
    }
}