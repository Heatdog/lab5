//
// Created by yura on 07.05.2021.
//

#ifndef LAB5_SEM2_LIST_H
#define LAB5_SEM2_LIST_H

#include "Func.h"

typedef struct Item {
    int name[2];
    int weight;
    struct Item* next;
}Item;

typedef struct List {
    Item* head;
    Item* tail;
}List;

List* new_list();

int add_list(List* list, int name[], int weight);
int pop_queue(List* list);

#endif //LAB5_SEM2_LIST_H
