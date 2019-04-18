/*
 * @Description:  红黑树实现
 * @Author: haha_giraffe
 * @Date: 2019-04-17 18:55:31
 */
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include "../head.h"
enum Color { red , black};
typedef struct rb_node* node_ptr;
typedef struct rb_node{
    rb_node *left;
    rb_node *right;
    rb_node *parent;
    int val;
    Color color;
};
typedef struct rb_root{
    node_ptr node;
};
static void rb_tree_left_rotation(rb_root *root,rb_node *node);//左旋
static void rb_tree_right_rotation(rb_root *root,rb_node *node);//右旋
static void rb_tree_insert(rb_root *root,rb_node *node);//插入
static void rb_tree_insert_fix(rb_root *root,rb_node *node);//插入后修正红黑树
static void rb_tree_delete(rb_root *root,rb_node *node);//删除
static void rb_tree_delete_fix(rb_root *root,rb_node *node,rb_node *parent);//删除后修正红黑树
void print_rbtree(rb_root *root);
rb_root* create_rb_tree();
#endif
