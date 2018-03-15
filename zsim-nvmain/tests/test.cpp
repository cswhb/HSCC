#include<stdio.h>
int main(){
    int a[10000];
    int i=0;
    for(i=0;i<10000;i++){
        a[i]=i;
    }
    for(i=0;i<10000;i++)printf("%d\n",a[i]);
    return 0;
}
