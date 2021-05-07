//
// Created by yura on 07.05.2021.
//

#include "dialog.h"

#include <stdbool.h>

static bool search_coincidence(Graph* graph, int name[]) {
    bool flag = false;
    for (vertex* ptr = graph->first; ptr != NULL && flag == false; ptr = ptr->next) {
        if (ptr->name[0] == name[0] && ptr->name[1] == name[1]) {
            flag = true;
        }
    }
    return flag;
}

int D_Add(Graph* graph) {
    puts("Input name vertex, please: ");
    int name[2];
    getInt(&name[0]);
    getInt(&name[1]);
    bool flag = search_coincidence(graph, name);
    if (flag == true) {
        puts("Duplicate name!");
        return 0;
    }

    int t = add_graph(graph, name);
    if (t == -1) {
        perror(strerror(errno));
        return -1;
    }

    puts("Select adjacent vertices\n");
    int weight;
    int i;
    int m;
    for (vertex* ptr = graph->first; ptr != NULL; ptr = ptr->next) {
        printf("x = %d, y = %d\n ", ptr->name[0], ptr->name[1]);
        puts("ptr -> new_ver: ");
        do {
            getInt(&i);
        } while (i != 1 && i != 0);
        puts("new_ver -> ptr: ");
        do {
            getInt(&m);
        } while (m != 1 && m != 0);

        if (i == 1 && m == 1 && ptr == graph->last) {
            puts("Error! Loop can be alone.");
            m = 0;
        }
        if (i == 1) {
            puts("Input weight: ");
            getInt(&weight);

            int k = add_list(ptr->list, name, weight);

            if (k == -1) {
                perror(strerror(errno));
                return -1;
            }
        }
        if (m == 1) {
            puts("Input weight: ");
            getInt(&weight);

            int k = add_list(graph->last->list, ptr->name, weight);

            if (k == -1) {
                perror(strerror(errno));
                return -1;
            }
        }
    }
    return 0;
}


int D_Find(Graph* graph) {
    puts("Input name 1: ");
    int name_1[2];

    bool flag;
    do {
        getInt(&name_1[0]);
        getInt(&name_1[1]);

        flag = search_coincidence(graph, name_1);

        if (flag == false) {
            puts("Repeat input please! This element not found.");
        }
    } while(flag != true);

    puts("Inut name 2: ");
    int name_2[2];
    do {
        getInt(&name_2[0]);
        getInt(&name_2[1]);
        flag = search_coincidence(graph, name_2);
        if (flag == false) {
            puts("Repeat input please! This element not found.");
        }
    } while (flag != true);
}