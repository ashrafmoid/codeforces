#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	vector< pair<char,pair<int,int> > > v[10];
	//vector<pair<char,int > > v[5];
	for(int i=0;i<4;i++){
		int cst;char a,b,x,y;
		cin>>a>>b>>x>>y>>cst;
		v[(x-'A')].push_back(make_pair(a,make_pair(y-'A',cst)));
		if(b=='B'){
			v[(y-'A')].push_back(make_pair(a,make_pair(x-'A',cst)));
		}
		cout<<a<<" "<<cst<<" "<<b<<" "<<x<<" "<<y;
		//v[i].push_back(make_pair(a,cst));
	}
	for(int i=0;i<5;i++){
		//for(int )
		if(v[i].size()!=0)
		cout<<v[i][1].second.second<<" "<<v[i][1].second.first<<" "<<i<<"\n";
	}
	return 0;
}
// just mofify this for git
