#include<iostream>
#include<cmath>
using namespace std;

int setBit(int n){
int sum=0;
while(n!=0){
if(n&1){
sum++;

}
n=n>>1;
}
int ans=pow(2,sum)-1;
return ans;

}

int main(){
int n;
cin>>n;
cout<<setBit(n);


}
