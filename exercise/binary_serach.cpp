/*
 * @Description: binary_search
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 10:41:44
 * @LastEditTime: 2019-03-16 11:03:56
 */
#include "../head.h"

bool binary_search(vector<int> vec, int target){
    bool result=false;
    int left=0,right=vec.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(vec[mid]<target){
            left=mid+1;
        }
        else if(vec[mid]>target){
            right=mid-1;
        }else{
            result=true;
            break;
        }
    }
    return result;
}

int main(){
    vector<int> vec{1,3,5,6,7,8};
    int tar=4;
    //int tar=7;
    bool result=false;
    result=binary_search(vec,tar);
    cout<<result;
    return 0;
}
