#include<bits/stdc++.h>
using namespace std;
long long int hi=3000000000,lo=0;
int main(){
	long long int n,m;cin>>n>>m;
	if(n<m){cout<<n<<"\n";return 0;}
	long long int mid;
	while(hi>lo){
		mid=lo+(hi-lo)/2;
		if(mid*(mid+1)>=2*(n-m)){
			hi=mid;
			if(mid*(mid+1)==2*(n-m))break;
		}
		else lo=mid+1;
		//cout<<mid<<"\n";
	}
	cout<<hi+m<<"\n";
	return 0;
}