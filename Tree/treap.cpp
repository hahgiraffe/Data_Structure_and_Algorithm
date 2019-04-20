#include "treap.h"
int random_pri(){
    int k=rand() % MAX_PRIORITY;
    //printf("%d ",k);
    return k;
}
treap_ptr create_tree(){
    treap_ptr head=(treap_ptr)malloc(sizeof(treap_node));
    if(head==NULL){
        printf("malloc error\n");
        return NULL;
    }
    head->left=head->right=NULL;
    return head;
}
treap_ptr create_node(int pri,ElementType val){
    treap_ptr node=(treap_ptr)malloc(sizeof(treap_node));
    if(node==NULL){
        printf("malloc error\n");
        return NULL;
    }
    node->left=node->right=NULL;
    node->priority=pri;
    node->val=val;
    return node;
}
treap_ptr insert_node(treap_ptr T, ElementType x){
    if(T==NULL){
        int pri=random_pri();
        T=create_node(pri,x);
    }
    else if(x<T->val){
        T->left=insert_node(T->left,x);
        if(T->left->priority<T->priority){
            T=Singlerotatewithleft(T);
        }
    }
    else if(x>T->val){
        T->right=insert_node(T->right,x);
        if(T->right->priority<T->priority){
            T=Singlerotatewithright(T);
        }
    }
    return T;
}
treap_ptr delete_node(treap_ptr T, ElementType x){
    if(T!=NULL){
        if(x<T->val){
            T->left=delete_node(T->left,x);
        }
        else if(x>T->val){
            T->right=delete_node(T->right,x);
        }
        else
        {
            if(T->left==NULL){
                T=T->right;
            }else if(T->right==NULL)
            {
                T=T->left;
            }
            else{
                //左右子节点都不为空
                if(T->left->priority<T->right->priority){
                    T=Singlerotatewithleft(T);
                    delete_node(T->right,x);
                }
                else{
                    T=Singlerotatewithright(T);
                    delete_node(T->left,x);
                }
            }
        }
        
    }
    return T;
}
void recursive(treap_ptr T,int level,vector<vector<pair<int,int>>> &res){
    if(T==NULL){
        return;
    }
    if(level>=res.size()){
        res.push_back(vector<pair<int,int>> ());
    }
    res[level].push_back(pair<int,int> (T->val,T->priority) );
    recursive(T->left,level+1,res);
    recursive(T->right,level+1,res);
    return;
}
void print_tree(treap_ptr T){
    vector<vector<pair<int,int>>> res;
    recursive(T,0,res);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            printf("%d(%d) ",res[i][j].first,res[i][j].second);
        }
        printf("\n");
    }
}

treap_ptr Singlerotatewithleft(treap_ptr T){
    treap_ptr k;
    k=T->left;
    T->left=k->right;
    k->right=T;
    return k;
}
treap_ptr Singlerotatewithright(treap_ptr T){
    treap_ptr k;
    k=T->right;
    T->right=k->left;
    k->left=T;
    return k;
}


int main(){
    treap_ptr treap;
    for(int i=1;i<=10;i++){
        treap=insert_node(treap,i);
    }
    print_tree(treap);
    printf("\n");
    treap=delete_node(treap,10);
    print_tree(treap);
}