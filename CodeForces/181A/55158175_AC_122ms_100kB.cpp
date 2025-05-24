#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,s=0,st;
    cin>>n>>m;
    char ch[n+12][m+12];
    for(int i=1;i<=n;i++){
            s=0;
        for(int j=1;j<=m;j++){
            cin>>ch[i][j];
            if(ch[i][j]=='*')
            {
                s++;
            }
        }
        if(s==1){
                st=i;

        }
    }
cout<<st<<" ";
    for(int j=1;j<=m;j++){
            s=0;
        for(int i=1;i<=n;i++)
        {
            if(ch[i][j]=='*')
            {
             s++;
            }
        }
        if(s==1)
        {
            cout<<j<<endl;

        }
        }



}
