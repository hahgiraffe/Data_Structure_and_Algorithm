/*
 * @Description:  希尔排序 最差为O(n^2),根据不同的增量序列有不同的时间复杂度
 * @Author: haha_giraffe
 * @Date: 2019-03-26 14:54:28
 */
#include "../head.h"

void shell_sort(vector<int> &vec,int n){
    int inc,i,j;
    for(inc=n/2;inc>0;inc=inc/2){
        for(i=inc;i<n;i++){
            int tmp=vec[i];
            for(j=i;j>=inc;j=j-inc){
                if(tmp<vec[j-inc]){
                    vec[j]=vec[j-inc];
                }
                else{
                    break;
                }
            }
            vec[j]=tmp;
        }
    }
}

int main(){
    vector<int> vec{23,55,12,2,53,6,77,35,31,22};
    shell_sort(vec,vec.size());
    for(auto a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}