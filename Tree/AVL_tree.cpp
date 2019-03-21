/*
 * @Description: AVL平衡二分查找树
 * @Author: haha_giraffe
 * @LastEditors: your name
 * @Date: 2019-03-20 23:42:59
 * @LastEditTime: 2019-03-20 23:43:26
 */
#include "AVL_tree.h"
//前面四个和二分查找树一样
Avltree MakeEmpty(Avltree T)
{
    if(T==NULL){
        return NULL;
    }
    else{
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(int x,Avltree T){
    if(T==NULL){
        return NULL;
    }
    if(x<T->val) 
    {
        Find(x,T->left);
    }
    else if(x>T->val){
        Find(x,T->right);
    }
    else{
        return T;
    }
}

Position FindMax(Avltree T){
    if(T==NULL){
        return NULL;
    }
    if(T->right==NULL){
        return T;
    }
    else{
        FindMax(T->right);
    }
}

Position FindMin(Avltree T){
    if(T!=NULL){
        while(T->left!=NULL){
            T=T->left;
        }
    }
    return T;
}

static int Height(Position p){
    if(p==NULL){
        return -1;
    }
    else{
        return p->height;
    }
}

Avltree Insert(int x,Avltree T){//递归实现
    if(T==NULL){
        //插入一个节点并调整AVL树
        T=(Avltree)malloc(sizeof(struct Node));
        if(T==NULL){
            printf("malloc error\n");
        }
        else{
            T->val=x;
            T->left=T->right=NULL;
            T->height=0;
        }
    }
    else if(x<T->val)
    {
        T->left=Insert(x,T->left);
        if(Height(T->left)-Height(T->right)==2){
            if(x<T->left->val){
                //在左孩子的左子树，单选
                T=Singlerotatewithleft(T);
            }else{
                //在左孩子的右子树，双旋
                T=Doublerotatewithleft(T);
            }
        }
    }
    else{
        T->right=Insert(x,T->right);
        if(Height(T->right)-Height(T->left)==2){
            if(x>T->right->val){
                //在右孩子的右子树，单旋
                T=Singlerotatewithright(T);
            }else{
                //在右孩子的左子树，双旋
                T=Doublerotatewithright(T);
            }
        }
    }
    T->height=max(Height(T->left),Height(T->right))+1;
    return T;
}

Avltree Singlerotatewithleft(Avltree T){
    Position k;
    k=T->left;
    T->left=k->right;
    k->right=T;
    T->height=max(Height(T->left),Height(T->right))+1;
    k->height=max(Height(k->left),Height(k->right))+1;
    return k;
}
Avltree Singlerotatewithright(Avltree T){
    Position k;
    k=T->right;
    T->right=k->left;
    k->left=T;
    T->height=max(Height(T->left),Height(T->right))+1;
    k->height=max(Height(k->left),Height(k->right))+1;
    return k;
}
Avltree Doublerotatewithleft(Avltree T){
    T->left=Singlerotatewithright(T->left);
    return Singlerotatewithleft(T);
}

Avltree Doublerotatewithright(Avltree T){
    T->right=Singlerotatewithleft(T->right);
    return Singlerotatewithright(T);
}

Avltree Delete(int x,Avltree T){
    if(T==NULL){
        return NULL;
    }
    else{
        if(x==T->val){
            //当找到这个节点时候，判断该节点有两个孩子还是一个孩子
            if(T->left && T->right){
                //当两个孩子都存在的时候，则取该节点的右子树中最小的一个作为替代节点
                T->val=FindMin(T->right)->val;
                T->right=Delete(T->val,T->right);
                T->height=max(Height(T->left),Height(T->right));
                if(Height(T->left)-Height(T->right)==2){//此时应减少左子树的高度
                    if(Height(T->left->left) >= Height(T->left->right))//左子树左节点的高度大于左子树右节点的高度
						T=Singlerotatewithleft(T);
                    else
                        T=Doublerotatewithleft(T);
                }
            }
            else
            {
                Avltree tmp=T;
                if(T->left){
                    T=T->left;
                    free(tmp);
                }else{
                    T=T->right;
                    free(tmp);
                }
            }
        }
        else if(x<T->val){
            T->left=Delete(x,T->left);
            T->height=max(Height(T->left),Height(T->right));
            if(Height(T->right)-Height(T->left)==2){
                if(Height(T->right->right) >= Height(T->right->left))
					T=Singlerotatewithright(T);
                else
                    T=Doublerotatewithright(T);
            }
        }
        else{
            T->right=Delete(x,T->right);
            T->height=max(Height(T->left),Height(T->right));
            if(Height(T->left)-Height(T->right)==2){
                if(Height(T->left->left) >= Height(T->left->right))
					T=Singlerotatewithleft(T);
                else
                    T=Doublerotatewithleft(T);
            }
        }
    }
    return T;
    
}

void show(Avltree T,int level,vector<vector<int>> &vec){
    //层次遍历 递归
    if(!T){
        return;
    }
    if(level>=vec.size()){
        vec.push_back({});
    }
    vec[level].push_back(T->val);
    show(T->left,level+1,vec);
    show(T->right,level+1,vec);
    return;
}

int main()
{
    Node* root=NULL;
    vector<int> vec{3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    for(int i=0;i<vec.size();i++){
        root=Insert(vec[i],root);
    }
    vector< vector<int>> res;
    show(root,0,res);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    res.clear();
    cout<<endl;
    root=Delete(13,root);
    show(root,0,res);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}