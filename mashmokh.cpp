#include<bits/stdc++.h>
using namespace std;
int main(){
	long int n,k;
	cin>>n>>k;
	long int a,b;
	if(n==1&&k>0){cout<<"-1";return 0;}
	if(n==1&&k==0){cout<<"1";return 0;}
	if(k-n/2<0){cout<<"-1";return 0;}
	a=k-(n/2-1);b=2*a;
	long int x=1;
	for(int i=0;i<n/2-1;i++){
		//if(x==a||x==b){x++;}
		while(x==a||x==b||x+1==a||x+1==b)x++;
		cout<<x<<" "<<x+1<<" ";
		x+=2;
	}
	while(x==a||x==b||x+1==a||x+1==b)x++;
	//if(x==a||x==b)x++		;
	if(n%2==1){cout<<a<<" "<<b<<" "<<x+1;}
	else cout<<a<<" "<<b;
	return 0;	
}