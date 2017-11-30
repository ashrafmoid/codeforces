#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef struct node{
  long int l,r;
  long int index;
}node;
int s;
bool cmp(node a,node b){
  if((a.l/s)!=b.l/s)return (a.l/s<b.l/s);
  return a.r<b.r;
}
int main(){
  //fast input output
  //precompute primes
  int j;
  bool* b=(bool*)malloc(10000001*sizeof(bool));
  int trc=0;
  long int* ans=(long int*)malloc(50001*sizeof(long int));
  for(int i=0;i<10000001;i++)b[i]=false;
  vector<int >primes;
  for(int i=2;i<10000001;){
    if(b[i]==false){
      continue;
    }
    else{
      b[i]=true;primes.push_back(i);
    }
    j=2*i;
    while(j<10000001&&b[i]==true){
      b[j]=true;j=j+i;
    }
    if(i==2)i++;
    else i=i+2;
  }
  int len=primes.size();
  long int* a=(long int*)malloc(1000000*sizeof(long int));
  node* q=(node*)malloc(50000*sizeof(node));
  int* f=(int*)malloc(10000001*sizeof(int));
  long int n;
  long int maxx=0;
  cin>>n;
  s=sqrt(n);
  for(long int i=0;i<n;i++){cin>>a[i];maxx=max(maxx,a[i]);}
  int m;cin>>m;
  for(int i=0;i<m;i++){cin>>q[i].l>>q[i].r;q[i].index=i;}
  sort(q,q+m,cmp);
  for(int i=0;i<len&&primes[i]<=maxx;i++){
    int cnt=0;
    for(long int k=0;k<n;k++){
        if(a[k]%primes[i]==0)cnt++;
    }
    f[primes[i]]=cnt;
  }
  int strt=0,end=0;
  long int prev=0;
  for(int i=0;i<m;i++){
    while(end<q[i].r){
      if(b[end]==true){
        prev+=f[end];
      }
      end++;
    }
    if(end==q[i].r&&b[end]==true)prev+=f[end];
    while(end>q[i].r){
      if(b[end]==true){
        prev-=f[end];
      }
      end--;
    }
    if(strt>q[i].l)strt--;
    while(strt<q[i].l){
      if(b[strt]==true)prev-=f[strt];
      strt++;
    }
    while(strt>=q[i].l){
      if(b[strt]==true)prev+=f[strt];
    }
    ans[q[i].index]=prev;
  }
  for(int i=0;i<m;i++){
    cout<<ans[i]<<"\n";
  }
  return 0;
}
