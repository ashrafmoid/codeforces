#include<iostream>
#include<algorithm>
using namespace std;
/*typedef struct node{
  int day,fruits;
}node;*/
int main(){
  long int f[3002];
  for(int i=0;i<=3001;i++)f[i]=0;
  long int n,v;
  cin>>n>>v;
  int maxx=0;
  //node* q=(node*)malloc(n*sizeof(node));
  int day,fruits;
  for(int i=0;i<n;i++){
    cin>>day>>fruits;
    maxx=max(day,maxx);
    f[day]+=fruits;
  }
  int prev=0;long int ans=0;int temp=0,temp1=0;
  for(int i=1;i<=maxx+1;i++){
    temp=min(v,f[prev]);ans+=temp;
    f[prev]=f[prev]-temp;
    if(f[i]>0){
      temp1=min(v-temp,f[i]);
      f[i]=f[i]-temp1;ans+=temp1;
    }
    prev++;
  }
  cout<<ans<<endl;
}
