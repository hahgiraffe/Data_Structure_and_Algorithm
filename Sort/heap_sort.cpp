/*
 * @Description:  堆排序 O(nlogn) 这样可以避免使用额外的空间
 * @Author: haha_giraffe
 * @Date: 2019-03-26 15:58:42
 */
#include "../head.h"
#define leftchild(i) (2*(i)+1)
void PerDown(vector<int> &vec,int begin,int number){
    //begin是数组下标，从这个元素和其儿子，number代表堆中元素的个数
    int child,tmp;
    for(tmp=vec[begin];leftchild(begin)<number;begin=child){
        child=leftchild(begin);
        if(child!=number-1 && vec[child+1]>vec[child]){
            child++;//选择右孩子
        }
        if(tmp<vec[child]){
            vec[begin]=vec[child];
        }
        else{
            break;
        }
    }
    vec[begin]=tmp;
}

void heap_sort(vector<int> &vec,int n)
{
    //要生成一个递增的数组，先建立一个大根堆，至上而下,从最后一个节点的父节点开始，往上遍历
    for(int i=n/2;i>=0;i--){
        PerDown(vec,i,n);
    }
    for(int i=n-1;i>0;i--){
        swap(vec[0],vec[i]);//相当于把大根堆中最大值，放在数组最后
        PerDown(vec,0,i);
    }
}

int main(){
    vector<int> vec{23,55,12,2,53,6,77,35,31,22};
    heap_sort(vec,vec.size());
    for(auto a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}