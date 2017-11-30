#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct node{
  int l,r;
  long long int d;
}node;
long long int f[100005];
long long int b[100005];
int main(){
      ios_base::sync_with_stdio(false);cin.tie(NULL);
  memset(f,0,sizeof(f));
  memset(b,0,sizeof(b));
  int n,m,k;cin>>n>>m>>k;
  long long int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  node q[m];
  for(int i=0;i<m;i++){
    cin>>q[i].l>>q[i].r>>q[i].d;
  }
  int x,y;
  for(int i=0;i<k;i++){
    cin>>x>>y;
    f[x-1]++;f[y]--;
  }
  for(int i=1;i<=m;i++){
    f[i]+=f[i-1];
  }
  for(int i=0;i<m;i++){
    b[q[i].l-1]+=f[i]*q[i].d;b[q[i].r]-=f[i]*q[i].d;
  }
  for(int i=0;i<n;i++){
    if(i>0)b[i]+=b[i-1];
    a[i]+=b[i];
    cout<<a[i]<<" ";
  }
  cout<<"\n";return 0;
}
