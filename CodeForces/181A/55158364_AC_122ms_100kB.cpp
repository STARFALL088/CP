#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,s=0,c,d,r,co,st,st1;
    cin>>n>>m;
    char ch[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch[i][j];
        }
    }
    for(int i=1;i<=n;i++){
            s=0;
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='*')
            {
                c=i;
                s++;
                d=j;
            }
        }
        if(s==1){
                cout<<c<<" ";
        st=i;
        st1=d;
        }

    }
    for(int i=1;i<=n;i++){
            s=0;
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='*'&&j!=st1)
            {
              cout<<j<<endl;
            }
        }
        }



}