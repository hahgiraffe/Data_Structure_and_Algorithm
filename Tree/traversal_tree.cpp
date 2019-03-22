/*
 * @Description: 二叉树的前序遍历、中序遍历、后序遍历、层次遍历的递归和非递归实现
 * @Author: haha_giraffe
 * @Date: 2019-03-21 21:41:38
 */
#include "../head.h"
#include "./binary_search_tree.h"
//前序递归
void preorder_recursion(TreeNode *t){
    if(t==NULL){
        return;
    }
    cout<<t->value;
    preorder_recursion(t->left);
    preorder_recursion(t->right);
    return;
}
//中序递归
void inorder_recursion(TreeNode *t){
    if(t==NULL){
        return;
    }
    preorder_recursion(t->left);
    cout<<t->value;
    preorder_recursion(t->right);
    return;
}
//后序递归
void postorder_recursion(TreeNode *t){
    if(t==NULL){
        return;
    }
    preorder_recursion(t->left);
    preorder_recursion(t->right);
    cout<<t->value;
    return;
}
//前序非递归

void preorder_nonrecursion(TreeNode *root){
    stack<TreeNode*> s1;
    if(root==NULL){
        return ;
    }
    TreeNode *t=root;
    s1.push(t);
    while(!s1.empty()){
        TreeNode *tmp=s1.top();
        s1.pop();
        cout<<tmp->value<<" ";
        if(tmp->right!=NULL){
            s1.push(tmp->right);
        }
        if(tmp->left!=NULL){
            s1.push(tmp->left);
        }
        
    }
    return;
}
//中序非递归
void inorder_nonrecursion(TreeNode *root){
    if(root==NULL){
        return;
    }
    // stack<TreeNode *> s;
    // TreeNode *t=root;
    // while(!s.empty() || t){
    //     while(t){
    //         s.push(t);
    //         t=t->left;
    //     }
    //     if(t==NULL){
    //         t=s.top();
    //         s.pop();
    //         cout<<t->value<<" ";
    //         t=t->right;
    //     }
    // }
    // return ;
    stack<TreeNode *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            cout << root->value << " ";
            s.pop();
            root = root->right;
        }
    }
}
//后序非递归，使用一个栈（还有一种方法使用两个栈，后序遍历为根右左的翻转！！）
void postorder_nonrecursion(TreeNode *root){
    if(root==NULL){
        return;
    }
    TreeNode *tmp=root;
    TreeNode *last=NULL;
    stack<TreeNode*> s;
    while(tmp){
        s.push(tmp);
        tmp=tmp->left;
    }
    while(!s.empty()){

        tmp=s.top();
        s.pop();
        if(tmp->right==NULL || tmp->right==last){
            cout<<tmp->value<<" ";
            last=tmp;
        }
        else{
            s.push(tmp);
            tmp=tmp->right;
            while(tmp){
                s.push(tmp);
                tmp=tmp->left;
            }
        }
        
    }
}
//层次非递归,利用队列进行层次遍历
void level_nonrecursion(TreeNode *root){
    queue<TreeNode *> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        TreeNode *tmp=q.front();
        q.pop();
        cout<<tmp->value<<" ";
        if(tmp->left!=NULL){
            q.push(tmp->left);
        }
        if(tmp->right!=NULL){
            q.push(tmp->right);
        }
    }
    return;
}

SearchTree Insert(SearchTree T,int x){
    if(T==NULL){
        //创建
        //T=new TreeNode(x);
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        if(T==NULL){
            printf("error");
        }else{
            T->value=x;
            T->left=T->right=NULL;
        }
    }
    else if(x<T->value){
        T->left=Insert(T->left,x);
    }
    else if(x>=T->value){
        T->right=Insert(T->right,x);
    }
    return T;
}

int main(){
    TreeNode *t=NULL;
    //t=MakeEmpty(t);
    vector<int> vec{12,32,65,11,55,86,2,5,46};
    for(int i=0;i<vec.size();i++){
        t=Insert(t,vec[i]);
    }
    preorder_nonrecursion(t);
    cout<<endl;
    inorder_nonrecursion(t);
    cout<<endl;
    postorder_nonrecursion(t);
    cout<<endl;
    level_nonrecursion(t);
    return 0;
}