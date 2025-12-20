#include<stdio.h>
#include <stdlib.h>
int cmp(const void *x, const void *y) {
    long a = *(long *)x;
    long b = *(long *)y;
    if(a < b) return 1;  
    else if(a > b) return -1;
    else return 0;
}
int main(){
  long n,k;
  scanf("%ld%ld",&n,&k);
  long int a[n],b[n],c[n];
  for(int i=0;i<n;i++)scanf("%ld",&a[i]);
  for(int i=0;i<n;i++)scanf("%ld",&b[i]);
  for(int i=0;i<n;i++)c[i]=b[i]-a[i];
  qsort(c,n,sizeof(long),cmp); 
  long mx=0,add=0;
  for(int i=0;i<k;i++){
    mx+=c[i];
  }
  printf("%ld",mx);
}

