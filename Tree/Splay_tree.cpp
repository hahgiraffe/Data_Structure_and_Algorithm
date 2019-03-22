/*
 * @Description: 伸展树的实现
 * @Author: haha_giraffe
 * @Date: 2019-03-21 15:20:15
 */
#include "Splay_tree.h"

//非递归创建结点并插入
Splay_tree Insert(int x,Splay_tree T){
    if(T==NULL){
        //如果是空树则直接创建结点
        T=(Splay_tree)malloc(sizeof(Node));
        if(T==NULL){
            cout<<"malloc error\n";
        }
        T->left=T->right=T->parent=NULL;
        T->val=x;
    }
    else{
        Splay_tree tmp_father=T;
        Splay_tree tmp=T;
        while(tmp){
            if(x<tmp->val){
                tmp_father=tmp;
                tmp=tmp->left;
            }
            else if(x>tmp->val){
                tmp_father=tmp;
                tmp=tmp->right;
            }
            else{
                cout<<"not equal\n";
            }
        }
        if(tmp==NULL){
            tmp=(Splay_tree)malloc(sizeof(Node));
            if(tmp==NULL){
                cout<<"malloc error\n";
            }
            tmp->left=tmp->right=NULL;
            tmp->parent=tmp_father;
            tmp->val=x;
            if(x<tmp_father->val){
                tmp_father->left=tmp;
            }else{
                tmp_father->right=tmp;
            }
        }
        //插入了结点，接下来要进行旋转
        T=Splay(tmp,T);
        
    }
    return T;
}

Splay_tree Delete(int x,Splay_tree T){
    if(T==NULL){
        return NULL;
    }
    T=Find(x,T);
    if(x==T->val){
        //此时将根节点删除
        if(T->left && T->right){
            Position tmp;
            Position ltmp=T->left;
            Position rtmp=T->right;
            ltmp->parent=rtmp->parent=NULL;
            free(T);
            ltmp=FindMax(ltmp);
            ltmp->right=rtmp;
            rtmp->parent=ltmp;
            return ltmp;
        }
        else if(T->left){
            Position ltmp=T->left;
            ltmp->parent=NULL;
            free(T);
            return ltmp;
        }
        else{
            Position rtmp=T->right;
            rtmp->parent=NULL;
            free(T);
            return rtmp;
        }
    }
    else{
        cerr<<"find error\n";
        return T;
    }
}

//旋转，两种方式，zig-zag和zig-zig
Splay_tree Splay(Splay_tree tmp,Splay_tree T){
    Position parent,Grandparent;
    parent=tmp->parent;
    //printf("k");
    while(parent!=NULL){
        Grandparent=parent->parent;
        if(tmp==parent->left){
            if(Grandparent!=NULL){
                if(Grandparent->left==parent){
                    //zig-zig，,该节点是父节点的左子树，父节点是祖父结点的左子树
                    //注意以下两个顺序是不能换的
                    Singlerotatewithright(Grandparent);
                    Singlerotatewithright(parent);
                }else{
                    //zig-zag,该节点是父节点的左子树，父节点是祖父结点的右子树
                    Doublerotatewithright(Grandparent);
                }
            }else{
                //grandparent==NULL
                Singlerotatewithright(parent);
            }
        }else{
            if(Grandparent!=NULL){
                if(Grandparent->left==parent){
                    //zig-zag，,该节点是父节点的右子树，父节点是祖父结点的左子树
                    Doublerotatewithleft(Grandparent);
                }else{
                    //zig-zig,该节点是父节点的右子树，父节点是祖父结点的右子树
                    Singlerotatewithleft(Grandparent);
                    Singlerotatewithleft(parent);
                }
            }else{
                //grandparent==NULL
                Singlerotatewithleft(parent);
            }
        }
        parent=tmp->parent;
    }
    return tmp;
}

Position Find(int x,Splay_tree T){
    if(T==NULL){
        return NULL;
    }
    Position p=searchvalue(x,T);
    if(p==T){
        return p;
    }else
    {
        return Splay(p,T);
    }
    
}
Position searchvalue(int x,Splay_tree T){
    if(x==T->val){
        return T;
    }else if(x<T->val && T->left){
        return searchvalue(x,T->left);
    }
    else if(x>T->val && T->right){
        return searchvalue(x,T->right);
    }
}
Position FindMax(Splay_tree T){
    if(T==NULL) return NULL;
    Position p=T;
    while(p->right!=NULL){
        p=p->right;
    }
    return Splay(p,T);
}

Splay_tree Singlerotatewithleft(Splay_tree T){
    //该节点向左边移动
    Splay_tree pa=T->parent;
    Splay_tree tmp=T->right;
    tmp->parent=pa;
    if(tmp->left!=NULL){
        tmp->left->parent=T;
    }
    T->right=tmp->left;

    tmp->left=T;
    T->parent=tmp;
    if(pa){
        if(pa->left==T){
            pa->left=tmp;
        }
        else if(pa->right==T){
            pa->right=tmp;
        }
    }
    return tmp;
}
Splay_tree Singlerotatewithright(Splay_tree T){
    //该节点向右边移动;
    Splay_tree tmp=T->left;
    Splay_tree pa=T->parent;
    tmp->parent=pa;
    if(tmp->right!=NULL){
        tmp->right->parent=T;
    }
    T->left=tmp->right;
    T->parent=tmp;
    tmp->right=T;
    if(pa){
        if(pa->left==T){
            pa->left=tmp;
        }
        else{
            pa->right=tmp;
        }
    }
    return tmp;
}
Splay_tree Doublerotatewithleft(Splay_tree T){
    Singlerotatewithleft(T->left);
    return Singlerotatewithright(T);

}
Splay_tree Doublerotatewithright(Splay_tree T){
    Singlerotatewithright(T->right);
    return Singlerotatewithleft(T);
}

void show(Splay_tree T,int level,vector<vector<int>> &vec){
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

void get_show(Splay_tree root){
    vector<vector<int>> res;
    show(root,0,res);
    //cout<<res.size();
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    Splay_tree root=NULL;
    for(int i=1;i<8;i++){
        root=Insert(i,root);
    }
    get_show(root);
    root=Find(1,root);
    get_show(root);
    root=Delete(3,root);
    get_show(root);
    return 0;

}


