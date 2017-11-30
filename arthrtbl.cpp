#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct node{
  int l,d;
}node;
bool cmp(node a,node b){
  if(a.l!=b.l)return a.l<b.l;
  return a.d<b.d;
}
int main(){
  //fast input output
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int minn_d=999,maxx_d=0;
  node q[100001];
  long long int sum[100001];long long int cnt[201];
  memset(cnt,0,sizeof(cnt));
  int n;cin>>n;
//  node q[n];
  for(int i=0;i<n;i++){cin>>q[i].l;}//minn_d=min(minn_d,q[i].d);maxx_d=max(maxx_d,q[i].d);}
  for(int i=0;i<n;i++){cin>>q[i].d;minn_d=min(minn_d,q[i].d);maxx_d=max(maxx_d,q[i].d);}
  sort(q,q+n,cmp);
  long long int ans=0,minn=99999999;
  //int sum[]
  sum[0]=q[0].d;
  for(int i=1;i<n;i++){
    sum[i]+=sum[i-1]+q[i].d;
  }
  for(int i=0;i<n;){
    ans=0;
    int j=i+1;
    while(j<n&&q[j].l==q[i].l){j++;}
    ans+=sum[n-1]-sum[j-1];
    if(j-i>i)minn=min(ans,minn);
    else{
      long int x=2*i-j+1;
      for(int k=minn_d;k<=maxx_d&&x>0;k++){
        if(cnt[k]>=x){ans+=x*k;x=0;}
        else{
          ans+=cnt[k]*k;x=x-cnt[k];
        }
      }
      minn=min(ans,minn);
    }
    for(int k=i;k<j;k++)cnt[q[k].d]++;
    i=j;
  }
  cout<<minn<<"\n";
  return 0;
}
