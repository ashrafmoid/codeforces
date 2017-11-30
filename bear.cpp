#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   int* visit=(int*)malloc(10000001*sizeof(visit));
   memset(visit,0,sizeof(visit));
  long int* f=(long int*)malloc(10000001*sizeof(long int));
  memset(f,0,sizeof(f));
  int n;cin>>n;
  long int* temp=(long int*)malloc(10000001*sizeof(long int));
  memset(temp,0,sizeof(long int));
  //int a[n];
  long int x;long int maxx=0;
  //for(int i)
  for(int i=0;i<n;i++){
    cin>>x;temp[x]++;
    maxx=max(maxx,x);
  }
  for(int i=2;i<=maxx;i++){
    if(visit[i]==0){
      int j=i;
      while(j<=maxx){
        visit[j]=1;f[i]+=temp[j];j=j+i;
      }
    }
  }
  for(int i=2;i<maxx+1;i++){
    //if(i<20)
  //  cout<<"f[i]="<<f[i]<<"\n";
    f[i]=f[i]+f[i-1];
  }
  int m;cin>>m;
  long int l,r;
  for(int i=0;i<m;i++){
    cin>>l>>r;
      if(l>maxx){cout<<"0\n";continue;}
    if(r>maxx)r=maxx;
    cout<<f[r]-f[l-1]<<"\n";
  }
  return 0;
}
