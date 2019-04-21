#include "k_d_tree.h"

K_d_ptr createNode(ElementType data){
    K_d_ptr node=(K_d_ptr)malloc(sizeof(K_d_node));
    if(node==NULL){
        printf("malloc error\n");
        return NULL;
    }
    node->left=node->right=NULL;
    node->data[0]=data[0];
    node->data[1]=data[1];
    return node;
}

K_d_ptr recursiveinsert(K_d_ptr kdtree,ElementType item,int level){
    if(kdtree==NULL){
        kdtree=createNode(item);
    }
    else if(item[level] < kdtree->data[level]){
        //左子树
        kdtree->left=recursiveinsert(kdtree->left,item,!level);
    }else{
        //右子树
        kdtree->right=recursiveinsert(kdtree->right,item,!level);
    }
    return kdtree;
}

K_d_ptr insertNode(K_d_ptr kdtree,ElementType item){
    return recursiveinsert(kdtree,item,0);
}

void recprintrange(ElementType low,ElementType high,K_d_ptr kdtree,int level){
    if(kdtree==NULL){
        return;
    }
    if(low[0]<=kdtree->data[0] && kdtree->data[0]<=high[0] 
    && low[1]<=kdtree->data[1] && kdtree->data[1]<=high[1])
    {
        printf("%d(%d)\n",kdtree->data[0],kdtree->data[1]);
    }
    if(kdtree->data[level]>=low[level]){
        recprintrange(low,high,kdtree->left,!level);
    }
    if(kdtree->data[level]<=high[level]){
        recprintrange(low,high,kdtree->right,!level);
    }
    return;
}

void printrange(ElementType low,ElementType high,K_d_ptr kdtree){
    recprintrange(low,high,kdtree,0);
    return;
}

int main(){

    K_d_ptr T = NULL;
	int data[2];
	data[0] = 53;
	data[1] = 14;
	T = insertNode(T, data);
	data[0] = 27;
	data[1] = 28;
	T = insertNode(T, data);
	data[0] = 30;
	data[1] = 11;
	T = insertNode(T, data);
	data[0] = 29;
	data[1] = 16;
	T = insertNode(T, data);
	data[0] = 40;
	data[1] = 26;
    T = insertNode(T, data);
	data[0] = 38;
	data[1] = 23;
    T = insertNode(T, data);
	data[0] = 31;
	data[1] = 85;
    T = insertNode(T, data);
	data[0] = 7;
	data[1] = 39;
    T = insertNode(T, data);
	data[0] = 15;
	data[1] = 61;
	T = insertNode(T, data);
	data[0] = 32;
	data[1] = 29;
	T = insertNode(T, data);
	data[0] = 67;
	data[1] = 50;
	T = insertNode(T, data);
	data[0] = 79;
	data[1] = 3;
	T = insertNode(T, data);
	data[0] = 99;
	data[1] = 90;
	T = insertNode(T, data);
	data[0] = 82;
	data[1] = 64;
	T = insertNode(T, data);
	data[0] = 73;
	data[1] = 75;
    T = insertNode(T, data);
	//PrintTree(T, 0);
	//printf("\n\n\n\n");
	int Low[2] = {15,20};
	int High[2] = {60, 60};
    printrange(Low, High , T);

}