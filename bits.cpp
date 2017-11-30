#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	int repl[100],repr[100];
	long long int l,r;
	while(n--){
		cin>>l>>r;
		memset(repl,0,sizeof(repl));
		memset(repr,0,sizeof(repr));
		int lenl=0,lenr=0,one=0;
		while(l>0){
			//cout<<l%2<<"\n";
			repl[lenl++]=l%2;
			l=l>>1;
		}
		while(r>0){
			repr[lenr++]=r%2;
			if(r%2)one++;
			r=r>>1;
		}
		long long int ans=0;
		while(lenl&&lenr&&lenl==lenr&&(repl[lenl-1]==repr[lenr-1])){
			ans+=pow(2,lenl-1)*repl[lenl-1];
			if(repr[lenr-1])one--;
			lenl--;lenr--;
		}
		if(one==lenr){
			ans+=pow(2,lenr)-1;
		}
		else if(lenr){
			if(pow(2,lenr-1)-1)
			ans+=pow(2,lenr-1)-1;
			else ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}