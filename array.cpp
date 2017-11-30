#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int f[100001];
  for(int i=0;i<=100000;i++)f[i]=0;
  //for(int i=0;i<100001;i++)b[i]=false;
  int n,k;cin>>n>>k;
  int left=0,right,flag=0;
  int dis_count=0;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(dis_count<k){
      if(f[a[i]]==0)dis_count++;
      if(dis_count==k)right=i+1;
      f[a[i]]++;
    }
  /*  else if(flag==0){
      right=i;flag=1;
    }*/
  }
  for(int i=0;i<right;i++){
    if(f[a[i]]>1){left++;f[a[i]]--;}
    else{break;}
  }
  if(dis_count==k)
  {cout<<(left+1)<<" "<<right;}
  else{
    cout<<"-1 -1\n";
  }
  return 0;
}
