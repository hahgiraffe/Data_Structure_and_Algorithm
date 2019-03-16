/*
 * @Description: max_subsequence_sum
 * 最大子序列和，基本思路最优的方法是O(n)
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 10:18:18
 * @LastEditTime: 2019-03-16 12:44:07
 */

#include "../head.h"

int max_subsequence_sum(vector<int> tmp){
    int size=tmp.size();
    int max=0,sum=0;
    for(int i=0;i<size;i++){
        sum+=tmp[i];
        if(sum>max){
            max=sum;
        }else if(sum<0){
            sum=0;
        }
        else{
            continue;
        }
    }
    
    return max;
}

int main(){
    vector<int> vec{4,-3,5,-2,-1,2,6,-2};
    int result=max_subsequence_sum(vec);
    cout<<"the result is "<<result<<endl;
    return 0;
}