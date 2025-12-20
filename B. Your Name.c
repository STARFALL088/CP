#include<stdio.h>
int action(){
  int n;
    scanf("%d",&n);
    int a[26]={},b[26]={};
    for(int i=0;i<n;i++){
      char c;
      scanf(" %c", &c);
      a[c-'a']++;
    }
    for(int i=0;i<n;i++){
      char c;
      scanf(" %c", &c);
      b[c-'a']++;
    }
  for(int i=0;i<26;i++){
    if(a[i]!=b[i])return 0;
  }
  return 1;

}
 
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    printf("%s\n", action() ? "YES" : "NO");
  }
}
