//
// Created by yura on 07.05.2021.
//

#include "Tree.h"

Tree* new_tree() {
    Tree* pTree = NULL;
    pTree = (struct Tree*)malloc(sizeof (struct Tree));
    return pTree;
}

Node* new_node() {
    Node* pNode = NULL;
    pNode = (struct Node*)malloc(sizeof (struct Node));
    return pNode;
}

int insert_tree(Node* parent, int name[]) {
    if (parent == NULL) {
        parent = new_node();
        parent->name[0] = name[0];
        parent->name[1] = name[1];
        return 0;
    }
    Node* pBuf = parent;
    while (pBuf != NULL) {
    }
}