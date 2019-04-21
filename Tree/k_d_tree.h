/*
 * @Description:  2-d树的构建与范围查找
 * @Author: haha_giraffe
 * @Date: 2019-04-21 08:52:09
 */
#ifndef K_D_TREE_H
#define K_D_TREE_H
#include "../head.h"
typedef int ElementType[2];
typedef struct K_d_node* K_d_ptr;
struct K_d_node{
    ElementType data;
    K_d_ptr left;
    K_d_ptr right;
};

K_d_ptr createNode(int *data);
K_d_ptr insertNode(K_d_ptr kdtree,ElementType item);
void printrange(ElementType low,ElementType high,K_d_ptr kdtree);

#endif