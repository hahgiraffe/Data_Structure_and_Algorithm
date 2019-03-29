#include "../union_find.h"

void Initialize(ufset s){
    int i;
    for(i=numset;i>0;i--){
        s[i]=0;
    }
}
void SetUnion(ufset s,settype root1,settype root2){
    s[root2]=root1;
}
settype Find(elementtype x,ufset s){
    if(s[x]<=0){
        return x;
    }
    else 
        return s[x]=Find(s[x],s);
}