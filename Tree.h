//
// Created by yura on 07.05.2021.
//

#ifndef LAB5_SEM2_TREE_H
#define LAB5_SEM2_TREE_H

#include "Func.h"

typedef struct Node {
    int name[2];
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Tree {
    Node* parent;
}Tree;

Tree* new_tree();

#endif //LAB5_SEM2_TREE_H
