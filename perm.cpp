#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  bool b[100001];
  for(int i=0;i<100001;i++)b[i]=false;
  int n,k;
  cin>>n>>k;
  vector<int> g1;vector<int> g2;
  for(int i=1;i<=n;i++){
    if(k>0){
    g1.push_back(2*i-1);k--;
    b[2*i-1]=true;
  }
  else{
    g1.push_back(2*i);b[2*i]=true;
  }
  }
  for(int i=1;i<=2*n;i++){
      if(b[i]==false)g2.push_back(i);
  }
  for(int i=0;i<n;i++){
    cout<<g1[i]<<" "<<g2[i]<<" ";
  }
  return 0;
}
