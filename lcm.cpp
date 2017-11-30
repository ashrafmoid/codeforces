#include<bits/stdc++.h>
using namespace std;
long long int hcf(long long int a,long long int b){
	if(a%b==0)return b;
	return hcf(b,a%b);
}
int main(){
	long long int n;
	cin>>n;
	if(n==1){cout<<"1\n";return 0;}
	if(n==2){cout<<"2\n";return 0;}
	//clock_t en;
	//clock_t be=clock(); 
	long long int ans1=n*(n-1);
	long long int ans2=(n-2)*(n-1);
	long long int temp=max(ans1,ans2);
	long long int gd;
	for(long long int i=n-2;i>=2;i--){
		temp=max(temp,ans1*(i/hcf(ans1,i)));
		temp=max(temp,ans2*(i/hcf(ans2,i)));
	}
	cout<<temp<<"\n";
	//en=clock();
	//cout<<double(en-be)/CLOCKS_PER_SEC;
	return 0;
}