//
// Created by yura on 10.05.2021.
//

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



const char *msgs[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show"};
const int N =sizeof(msgs) / sizeof(msgs[0]);

void dialog(Graph *graph)
{
    int rc = 0;
    while (1) {
        printf("\n-------------------\n");
        for (int i = 0; i < N; i++) {
            puts(msgs[i]);
        }
        puts("Make your choice: --> ");
        scan_int(&rc);
        switch (rc) {
            case 0:{
                return;
            }
            case 1:{
                D_Add(graph);
                break;
            }
            case 2:{
                D_Find(graph);
                break;
            }
            case 3:{
                D_Delete(graph);
                break;
            }
            default:{
                D_Show(graph);
                break;
            }
        }
    }
}


void D_Add(Graph *graph){
    int choose = 0;
    printf("What do you want to add?\n1)vertex 2)edge\nChoose-->");
    scan_int(&choose);
    if (choose == 1){
        add_vertex(graph);
    } else{
        add_edge(graph);
    }
}

void D_Show(Graph* graph){
    printf("\n------------------Graph-----------------\n");
    show_graph(graph);
}

void D_Delete(Graph* graph){
    int choose;
    printf("What do you want to delete?\n1)vertex 2)edge\nChoose-->");
    scan_int(&choose);
    if (choose == 1){
        delete_vertex(graph);
    } else{
        delete_edge(graph);
    }
}

void D_Find(Graph* graph){
    char *name = NULL;
    int **mass = NULL;
    printf("Please, enter vertex, from which you want start BFS\nEnter-->");
    name = scan_string(name);
    //BFS(graph, name, mass);
}


void scan_int(int* n) {
    int i = 0;
    do {
        i = scanf("%d", n);
        if (i != 1) {
            printf("You`re wrong! Please, try again!\n");
            scanf("%*c");
        }
    } while (i != 1);
}

char* scan_string(char* n) {
    int k = 0;
    n = (char*)malloc(100*sizeof (char ));
    do {
        k = scanf("%s", n);
        if (k != 1) {
            printf("Please, try again!\n");
        }
    } while (k != 1);
    unsigned int i = strlen(n);
    n = (char*)realloc(n, (i + 1) * sizeof(char));
    return n;
}