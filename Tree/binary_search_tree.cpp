/*
 * @Description: 二分查找树
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-19 15:31:08
 * @LastEditTime: 2019-03-21 00:19:47
 */
#include "binary_search_tree.h"

SearchTree MakeEmpty(SearchTree T){
    if(T!=NULL){
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(SearchTree T,int x){
    if(!T){
        return NULL;
    }
    if(T->value==x){
        return T;
    }else if(T->value<x){
        return Find(T->right,x);
    }else if(T->value>x){
        return Find(T->left,x);
    }
    else{
        return NULL;
    }
}

Position FindMin(SearchTree T){
    if(!T){
        return NULL;
    }
    if(T->left!=NULL){
        return FindMin(T->left);
    }
    return T;
}

Position FindMax(SearchTree T){
    if(T!=NULL){
        while(T->right!=NULL){
            T=T->right;
        }
    }
    return T;
}
//二分查找树的插入
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

//二分查找树的删除  这个是重点
SearchTree Delete(SearchTree T, int x){
    if(!T){
        printf("error\n");
        return NULL;
    }
    else if(T->value<x){
        T->right=Delete(T->right,x);
    }
    else if(T->value>x){
        T->left=Delete(T->left,x);
    }
    else if(T->left && T->right){
        //当找到要删除的节点并且该节点有两个子节点
        TreeNode *tmp=FindMin(T->right);
        T->value=tmp->value;
        T->right=Delete(T->right,T->value);
    }
    else{
        //要删除的节点只有一个子节点
        TreeNode *del=T;
        if(T->left==NULL){
            T=T->right;
        }
        else if(T->right==NULL){
            T=T->left;
        }else{
            T=NULL;
        }
        free(del);
    }
    return T;
}

void show(SearchTree T,int level,vector<vector<int>> &vec){
    //层次遍历 递归
    if(!T){
        return;
    }
    if(level>=vec.size()){
        vec.push_back({});
    }
    vec[level].push_back(T->value);
    show(T->left,level+1,vec);
    show(T->right,level+1,vec);
    return;
}

int main(){
    TreeNode *t=NULL;
    //t=MakeEmpty(t);
    vector<int> vec{12,32,65,11,55,86,2,5,46};
    for(int i=0;i<vec.size();i++){
        t=Insert(t,vec[i]);
    }
    // t=Insert(t,1);
    //t=Insert(t,3);
    vector<vector<int>> res;
    show(t,0,res);
    //cout<<res.size();
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
