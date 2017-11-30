#include<bits/stdc++.h>
using namespace std;
char a[100005];
int ans[100005];
int main(){
	memset(ans,0,sizeof(int));
	string s;
	cin>>s;
	int i=0;
	int len=s.size();
	for(int j=0;j<len;j++){
		a[i]=s[j];
		if(a[i]==')'&&i>0){
			if(i-1>=0&&a[i-1]=='('){
				i--;
			}
			else if(i-1>=0&&a[i-1]=='#'){
				if(i-2>=0&&a[i-2]=='('){
					a[i-2]='#';i--;			}
			}
		}
		else i++;
	}
	while(i>=1&&a[i-1]==')'){	
		if(i-2>=0&&a[i-2]=='(')i=i-2;
		else if(i-3>=0&&a[i-2]=='#'&&a[i-3]=='('){
			a[i-3]='#';i=i-2;
		}
		else break;
	}
	int cnt=0,hsh=0;
	for(int j=0;j<i;j++){
		if(a[j]=='(')cnt++;
		if(a[j]==')')cnt--;
		if(a[j]=='#')hsh++;
	}
	if(a[0]==')'||a[0]=='#'||a[i-1]=='('||cnt<hsh){cout<<"-1\n";return 0;}
	for(int j=0;j<hsh-1;j++)cout<<"1\n";
	cout<<cnt-hsh+1<<"\n";
	return 0;
} 