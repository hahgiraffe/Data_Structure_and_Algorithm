/*
 * @Description:  插入排序，对数组进行n-1趟排序，对于第p=1趟，到p=n-1趟，保证位置0到位置p的元素为已排序。O(n^2)
 * @Author: haha_giraffe
 * @Date: 2019-03-26 14:26:45
 */
#include "../head.h"

void Insert_sort(vector<int> &vec,int n){
    for(int i=1;i<n;i++){
        int tmp=vec[i];
        // for(int j=0;j<i;j++){
        //     if(tmp<vec[j]){
        //         int k=i-1;
        //         while(k>=j){
        //             vec[k+1]=vec[k];
        //             k--;
        //         }
        //         vec[j]=tmp;
        //         break;
        //     }
        // }
        int j;
        for(j=i;j>0 && vec[j-1]>tmp;j--){
            vec[j]=vec[j-1];
        }
        vec[j]=tmp;
    }
    return;
}

int main(){
    vector<int> vec{23,55,12,2,53,6,77,35,31,22};
    Insert_sort(vec,vec.size());
    for(auto a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}