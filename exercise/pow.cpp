/*
 * @Description: pow
 * @Author: haha_giraffe
 * @LastEditors: Please set LastEditors
 * @Date: 2019-03-16 12:18:18
 * @LastEditTime: 2019-03-16 12:27:58
 */
#include "../head.h"

int Pow(int x,int n){
    if(n==1){
        return x;
    }
    if(n==0){
        return 1;
    }
    if(n%2==0){
        //偶数
        return Pow(x*x,n/2);
    }
    else{
        //奇数
        return Pow(x*x,n/2)*x;
    }
}

int main(){
    int res=Pow(3,5);
    cout<<res;
    return res;
}