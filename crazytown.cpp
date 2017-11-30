#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int n;cin>>n;
	int count=0;
	while(n--){
		long long int ax,by,c;cin>>ax>>by>>c;
		if(((ax*x1+by*y1+c)>0&&(ax*x2+by*y2+c)<0)||((ax*x1+by*y1+c)<0&&(ax*x2+by*y2+c)>0))count++;
	}
	cout<<count<<"\n";
	return 0;
}