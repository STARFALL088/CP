#include<stdio.h>
int main(){
  char s[20];
  int t;
  scanf("%d",&t);
  while(t--){
    for(int i=0;i<3;i++){
      scanf("%s",s);
      printf("%c",s[0]);
    }
    puts(" ");
  }
}  
