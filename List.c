//
// Created by yura on 07.05.2021.
//

#include "List.h"

List* new_list() {
    List* pList = NULL;
    pList = (struct List*)malloc(sizeof (struct List));
    return pList;
}

Item* new_item() {
    Item* pItem = NULL;
    pItem = (struct Item*)malloc(sizeof (struct Item));
    return pItem;
}

int add_list(List* list, int name[], int weight) {
    Item* new_el = new_item();
    if (new_el == NULL) {
        return -1;
    }
    new_el->name[0] = name[0];
    new_el->name[1] = name[1];
    new_el->weight = weight;
    if (list->head == NULL) {
        list->head = new_el;
        list->tail = new_el;
    } else {
        list->tail->next = new_el;
        list->tail = list->tail->next;
    }
    return 0;
}

int pop_queue(List* list) {
    if (list->head == NULL) {
        return 1;
    }
    list->head = list->head->next;
    return 0;
}