/*
 * @Description:  归并排序,O(nlogn)，需要线性附加内存空间O(n)
 * @Author: haha_giraffe
 * @Date: 2019-03-26 16:36:38
 */
#include "../head.h"

void merge(vector<int> &vec,vector<int> &tmp,int left,int right,int end){
    //把vec[left]-vec[right-1]和vec[right]-vec[end]合并到tmp
    int i=left,j=right;
    int k=i;
    while(i<=right-1 && j<=end){
        if(vec[i]>vec[j]){
            tmp[k]=vec[j];
            j++;
        }
        else{
            tmp[k]=vec[i];
            i++;
        }
        k++;
    }
    while(i<=right-1){
        tmp[k++]=vec[i++];
    }
    while(j<=end){
        tmp[k++]=vec[j++];
    }
    int num=left;
    while(num<=end){
        vec[num]=tmp[num];
        num++;
    }
}

void msort(vector<int> &vec,vector<int> &tmp,int left,int right){
    int middle;
    if(left<right){
        middle=(left+right)/2;
        msort(vec,tmp,left,middle);
        msort(vec,tmp,middle+1,right);
        merge(vec,tmp,left,middle+1,right);
    }
}
void merge_sort(vector<int> &vec,int n){
    vector<int> tmp(n);
    msort(vec,tmp,0,n-1);
}

int main(){
    vector<int> vec{23,55,12,2,53,6,77,35,31,22};
    merge_sort(vec,vec.size());
    for(auto a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
