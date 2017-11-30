#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  int len[n];
  int j;
  for(int i=0;i<n;){
    j=i+1;
    while(j<n&&a[j]>a[j-1])j++;
      //len[i]=j-1;
      for(;i<=j-1&&i<n;i++)len[i]=j-1;
  }
  int  maxx=0;
  for(int i=0;i<n;i++){
    if((len[i]<n-2)&&(a[len[i]+2]-a[len[i]]>1))
    maxx=max(len[len[i]+2]-i+1,maxx);
    if(len[i]>0&&len[i]<n-1&&a[len[i]+1]-a[len[i]-1]>1){
      maxx=max(len[len[i]+1]-i+1,maxx);
    }
    if(len[i]-i+1<n)
    maxx=max(len[i]-i+2,maxx);
    else maxx=max(len[i]-i+1,maxx);//galti
    }
  cout<<maxx;
 //cout<<"\n"<<len[0]<<" "<<len[2];
  return 0;
}
