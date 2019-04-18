#include "red_black_tree.h"

  #define rb_parent(r)   ((r)->parent)
  #define rb_color(r) ((r)->color)
  #define rb_is_red(r)   ((r)->color==Color::red)
  #define rb_is_black(r)  ((r)->color==Color::black)
  #define rb_set_black(r)  do { (r)->color = Color::black; } while (0)
  #define rb_set_red(r)  do { (r)->color = Color::red; } while (0)
  #define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
  #define rb_set_color(r,c)  do { (r)->color = (c); } while (0)

static void rb_tree_left_rotation(rb_root *root,rb_node *node){
    //左旋
    rb_node *tmp=node->right;
    rb_node *pa=node->parent;
    node->right=tmp->left;
    if(tmp->left!=NULL){
        tmp->left->parent=node;
    }
    tmp->left=node;
    node->parent=tmp;
    if(pa==NULL){
        root->node=tmp;
    }
    else{
        if(pa->left==node){
            pa->left=tmp;
            tmp->parent=pa;
        }
        else{
            pa->right=tmp;
            tmp->parent=pa;
        }
    }
    
}
static void rb_tree_right_rotation(rb_root *root,rb_node *node){
    rb_node *pa=node->parent;
    rb_node *tmp=node->left;
    node->left=tmp->right;
    if(tmp->right!=NULL){
        tmp->right->parent=node;
    }
    tmp->right=node;
    tmp->parent=pa;
    node->parent=tmp;
    if(pa==NULL){
        root->node=tmp;
    }
    else{
        if(pa->left==node){
            pa->left=tmp;
        }
        else{
            pa->right=tmp;
        }
    }
}
static void rb_tree_insert(rb_root *root,rb_node *node){
    //首先按照查找树的位置放置好节点
    rb_node *tmp=root->node;
    rb_node *parent=NULL;
    while(tmp!=NULL){
        parent=tmp;
        if(tmp->val<node->val){
            tmp=tmp->right;
        }
        else{
            tmp=tmp->left;
        }
    }
    node->parent=parent;
    if(parent!=NULL){
        if(parent->val<node->val){
            parent->right=node;
        }
        else{
            parent->left=node;
        }
    }else{
        root->node=node;
    }
    node->color=Color::red;
    rb_tree_insert_fix(root,node);

}
static void rb_tree_insert_fix(rb_root *root,rb_node *node){
    //调整位置
    rb_node *parent,*grandparent;
    if(node->parent!=NULL && node->parent->color==Color::black){
        //如果父亲节点存在且为黑，则直接返回
        return;
    }
    while((parent=node->parent) && parent->color==Color::red){
        //如果父亲节点存在且为红
        grandparent=parent->parent;
        if(parent==grandparent->left){
            //父亲节点是祖父节点的左孩子
            rb_node *uncle=grandparent->right;
            //case1
            if((uncle!=NULL) && uncle->color==Color::red){
                //叔节点也为红
                uncle->color=Color::black;
                parent->color=Color::black;
                grandparent->color=Color::red;
                node=grandparent;
                continue;//继续迭代
            }
            //case2
            if(parent->right==node){
                //当前节点是父节点的右孩子
                rb_tree_left_rotation(root,parent);
                rb_node *tmp;
                tmp=parent;
                parent=node;
                node=tmp;
            }
            //case3叔叔是黑色且当前节点在左节点
            parent->color=Color::black;
            grandparent->color=Color::red;
            rb_tree_right_rotation(root,grandparent);
        }
        else{
            //父亲节点是祖父节点的右孩子
            rb_node *uncle=grandparent->left;
            //case1
            if((uncle!=NULL) && uncle->color==Color::red){
                //叔节点也为红
                uncle->color=Color::black;
                parent->color=Color::black;
                grandparent->color=Color::red;
                node=grandparent;
                continue;//继续迭代
            }
            //case2
            if(parent->left==node){
                //当前节点是父节点的左孩子
                rb_tree_right_rotation(root,parent);
                rb_node *tmp;
                tmp=parent;
                parent=node;
                node=tmp;
            }
            //case3叔叔是黑色且当前节点是右孩子
            parent->color=Color::black;
            grandparent->color=Color::red;
            rb_tree_left_rotation(root,grandparent);
        }
    }
    root->node->color=Color::black;//把根节点设为黑
}

static void rb_tree_delete(rb_root *root,rb_node *node){
/*先像一个查找树一样先删除，分为三种情况
（1）要删除的节点没有子节点（即为叶子节点），删除即可
（2）删除的节点有一个子节点，删除以后用他来代替即可
（3）删除的节点有两个子节点，则要找到后续替代的节点，用该节点的值放到要删除节点的位置，再删除替代节点
*/
    rb_node *child,*parent;
    Color color;
    if(node->left!=NULL && node->right!=NULL){
        //左右子节点都不为空
        rb_node *replace=node;
        replace=replace->right;
        while(replace->left!=NULL){
            replace=replace->left;
        }
        if(node->parent!=NULL){
            //node不为根节点
            if(node->parent->left==node){
                node->parent->left=replace;
            }else{
                node->parent->right=replace;
            }
        }
        else{
            root->node=replace;
        }
        child=replace->right;//取代节点没有左孩子，只可能有右孩子
        parent=replace->parent;
        color=replace->color;
        if(parent==node){
            parent=replace;
        }
        else{
            //child不为空
            if(child!=NULL){
                child->parent=parent;
            }
            parent->left=child;
            replace->right = node->right;
            node->right->parent=replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == Color::black)
            rb_tree_delete_fix(root, child, parent);
        free(node);
        return;
    }
    
    parent=node->parent;
    color=node->color;
    if(node->left!=NULL){
        child=node->left;
        //左节点不为空
    }else if(node->right!=NULL){
        //右节点不为空
        child=node->right;
    }
    else{
        //没有子节点
        child=NULL;
    }
    if(child!=NULL){
        child->parent=parent;
    }
    if(parent!=NULL){
        if(parent->left==node){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
    }
    else{
        root->node=child;
    }
    if(color==Color::black){
        rb_tree_delete_fix(root,child,parent);
    }
    free(node);
}
static void rb_tree_delete_fix(rb_root *root,rb_node *node,rb_node *parent){
    //删除了节点后，调整红黑树
    rb_node *other;

    while ((!node || node->color==Color::black) && node != root->node)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->color==Color::red)
            {
                // Case 1: x的兄弟w是红色的  
                rb_set_black(other);
                rb_set_red(parent);
                rb_tree_left_rotation(root, parent);
                other = parent->right;
            }
            if ((!other->left || other->left->color==Color::black) &&
                (!other->right || other->right->color==Color::black))
            {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
                rb_set_red(other);
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->right || other->right->color==Color::black)
                {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
                    rb_set_black(other->left);
                    rb_set_red(other);
                    rb_tree_right_rotation(root, other);
                    other = parent->right;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                rb_tree_left_rotation(root, parent);
                node = root->node;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (rb_is_red(other))
            {
                // Case 1: x的兄弟w是红色的  
                rb_set_black(other);
                rb_set_red(parent);
                rb_tree_right_rotation(root, parent);
                other = parent->left;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->left || rb_is_black(other->left))
                {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
                    rb_set_black(other->right);
                    rb_set_red(other);
                    rb_tree_left_rotation(root, other);
                    other = parent->left;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                rb_tree_right_rotation(root, parent);
                node = root->node;
                break;
            }
        }
    }
    if (node)
        rb_set_black(node);
}
void print_rbtree(rb_root *root){
    queue<rb_node*> q;
    rb_node* tmp=root->node;
    q.push(tmp);
    while(!q.empty()){
        rb_node *node=q.front();
        q.pop();
        printf("%d %d ",node->val,node->color);//0表示红色，1表示黑色
        if(node->left!=NULL){
            q.push(node->left);
        }
        if(node->right!=NULL){
            q.push(node->right);
        }
        
    }

}
rb_root* create_rb_tree(){
    rb_root *root=(rb_root*)malloc(sizeof(rb_root));
    root->node=NULL;
    return root;

}

int main(){
    rb_root *root=NULL;
    root=create_rb_tree();
    vector<int> vec{10, 40, 30, 60, 90, 70, 20, 50, 80};
    for(int i=0;i<vec.size();i++){
        rb_node *node=(rb_node*)malloc(sizeof(rb_node));
        node->val=vec[i];
        node->left=node->parent=node->right=NULL;
        node->color=Color::black;
        rb_tree_insert(root,node);
    }
    print_rbtree(root);
    rb_tree_delete(root,root->node->right);//删除60
    printf("\n");
    print_rbtree(root);
    rb_tree_delete(root,root->node->right->left);//删除40
    printf("\n");
    print_rbtree(root);
    printf("\n");
    return 0;
}