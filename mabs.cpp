#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  long int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long int sum[n-k+1];
  long long int temp=0;
  for(int i=0;i<n-k+1;i++)sum[i]=0;
  int prev;
  for(int i=0;i<n;i++){
    if(i+1<k)temp+=a[i];
    else if(i+1==k){
      temp+=a[i];
      sum[i+1-k]=temp;prev=0;
    //  cout<<"sum="<<sum[i+1-k];
    }
    else {
      temp=temp+a[i]-a[prev];prev++;
      sum[i+1-k]=temp;//cout<<"sum="<<sum[i+1-k]<<" ";
    }
  }
  int maxx[n];long long int max_val=0;prev=n-k;
  for(int i=n-k;i>=0;i--){
    if(sum[i]>=max_val){
      maxx[prev]=i;max_val=sum[i];prev--;
    }
    else{
      maxx[prev]=maxx[prev+1];prev--;
    }
    //cout<<"\nmaxx="<<maxx[i]<<" ";
  }
  max_val=0;
  int start=-1,end=-1;
  for(int i=0;i<=n-2*k;i++){
    if(sum[i]+sum[maxx[i+k]]>max_val){
      start=i;end=maxx[i+k];max_val=sum[i]+sum[maxx[i+k]];
    }
  }
  cout<<(start+1)<<" "<<(end+1)<<endl;
  return 0;
}
