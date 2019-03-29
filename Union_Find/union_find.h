/*
 * @Description:  并查集实现
 * @Author: haha_giraffe
 * @Date: 2019-03-29 12:44:18
 */
#ifndef _UNION_FIND_H
#define _UNION_FIND_H
#include "../head.h"
#define numset 100

typedef int ufset[numset+1];
typedef int settype;
typedef int elementtype;

void Initialize(ufset s);
void SetUnion(ufset s,settype root1,settype root2);
settype Find(elementtype x,ufset s);

#endif