#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int main(){
	string s;cin>>s;
	int rem;
	memset(ans,0,sizeof(int));
	int cnt=0,hsh=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='('){ans[i]=1;cnt++;}
		else {ans[i]=-1;cnt--;}
		if(s[i]=='#'){rem=i;hsh++;}
	}
	if(cnt<0){cout<<"-1\n";return 0;}
	ans[rem]=0-(cnt+1);
	int flag=0;
	for(int i=1;i<len;i++){
		ans[i]+=ans[i-1];
		if(ans[i]<0){flag=1;break;}
	}
	if(flag||ans[0]<=0){cout<<"-1\n";return 0;}
	for(int i=0;i<hsh-1;i++){
		cout<<"1\n";
	}
	cout<<cnt+1<<"\n";
	return 0;
}