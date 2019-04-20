/*
 * @Description:  Treap堆树
 * @Author: haha_giraffe
 * @Date: 2019-04-20 09:21:22
 */
#ifndef _TREAP_H
#define _TREAP_H
#include "../head.h"
#define MAX_PRIORITY 100
typedef int ElementType;
typedef struct treap_node* treap_ptr;
struct treap_node{
    ElementType val;
    int priority;
    treap_node *left;
    treap_node *right;    
};

int random_pri();
treap_ptr create_tree();
treap_ptr create_node(int pri,ElementType val);
treap_ptr insert_node(treap_ptr T, ElementType x);
treap_ptr delete_node(treap_ptr T, ElementType x);
void print_tree(treap_ptr T);
treap_ptr Singlerotatewithleft(treap_ptr T);
treap_ptr Singlerotatewithright(treap_ptr T);
#endif
