#include <iostream>
#include <string>

using namespace std;

int main() {
	string s,ans="";
	cin >> s;
	//s="#"+s;
	int cnt=1;
	int n=s.size();
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			ans.push_back(s[i-1]);
			ans+=to_string(cnt);
			cnt=1;
		}
		else cnt++;
	}
	ans.push_back(s.back());
	ans+=to_string(cnt);
	if(ans.size()<=s.size())cout<<ans<<endl;
	else cout<<s<<endl;
	return 0;
}
