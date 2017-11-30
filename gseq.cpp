#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[100000];
int cache[100001];
int length[100001];
void factorize(int num,vector<int>& v){
  int prev=0;
  while(num>1){
    if(prev!=cache[num]){
      v.push_back(cache[num]);prev=cache[num];
    }
    num=num/cache[num];
  }
  return ;
}
int main(){
  for(int i=2;i<100001;i++){cache[i]=0;length[i]=0;}
  for(int i=2;i<100001;i++){
    if(cache[i]==0){
      cache[i]=i;
      for(int j=2*i;j<100001;j=j+i)cache[j]=i;
    }
  }
  vector<int>v;
  vector<int>::iterator it;
  int maxx=1;
  int n;cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    if(a[i]==1)continue;
    factorize(a[i],v);
    //int sze=v.size();
    int  len=0;
    for(it=v.begin();it!=v.end();it++){
      //length[*it]++;
      //maxx=max(maxx,length[*it]);
      len=max(len,length[*it]);
    }
    for(it=v.begin();it!=v.end();it++){
      length[*it]=len+1;
      maxx=max(maxx,length[*it]);
    }
    v.clear();
  }
  cout<<maxx<<"\n";
  return 0;
}
