#include<stdio.h>
#include<string.h>
#include<ctype.h>
// EDA KEMON OJ CPP KOI -_-
int main() {

    char s[1010];
    scanf("%s",&s);
    int p[10]={0};
    for(int i=0;i<strlen(s);i++) {
    char a=s[i];
        if(a<='9'&&a>='0') p[a-'0']++;
    }
    for(int i=0;i<10;i++) printf("%d ",p[i]);
}