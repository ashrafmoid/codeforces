#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node{
  int c,p,indx;
}node;
typedef struct tone{
  int r,index;
}tone;
typedef struct temp{
  int order,table;
}temp;
bool cmp1(tone a,tone b){
    if(a.r!=b.r)
    return a.r>b.r;
    return a.index>b.index;
}
bool cmp2(node a,node b){
  if(a.c!=b.c)return a.c>b.c;
  return a.p>b.p;
}
int main(){
  int n;cin>>n;
  node q[n];
  for(int i=0;i<n;i++){
    cin>>q[i].c>>q[i].p;
    q[i].indx=i;
  }
  int k;cin>>k;
 tone t[k];
  for(int i=0;i<k;i++){cin>>t[i].r;t[i].index=i;}
  long int ans[n+1][k+1];
  for(int i=0;i<=n;i++)ans[i][0]=0;
  for(int i=0;i<=k;i++)ans[0][i]=0;
  sort(t,t+k,cmp1);sort(q,q+n,cmp2);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(q[i-1].c>t[j-1].r)ans[i][j]=ans[i][j-1];
      else{
        ans[i][j]=max(ans[i-1][j-1]+q[i-1].p,ans[i-1][j]);
      }
    }
  }
  //cout<<
  int prev=0,cnt=0;
  temp res[k];
  //for(int i=0;i<k;i++)cout<<t[i].r<<" ";
  //cout<<"\n";
  for(int i=n,j=k;i>0&&j>0;){
    if(q[i-1].c>t[j-1].r)j--;
    else if(q[i-1].p+ans[i-1][j-1]==ans[i][j]){
      res[cnt].order=q[i-1].indx+1;res[cnt].table=t[j-1].index+1;cnt++;i--;j--;
    }
    else i--;
  }
  cout<<cnt<<" "<<ans[n][k]<<"\n";
  for(int i=0;i<cnt;i++){
    cout<<res[i].order<<" "<<res[i].table<<"\n";
  }
  return 0;
}
