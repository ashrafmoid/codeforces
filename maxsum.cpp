#include<iostream>
#include<algorithm>
using namespace std;
/*bool cmp(long int x,long int y){
  if(x>=y)return true; ;
  return false;
}*/
/*bool cmp1(int x,int y){
   if(x>=y)return true;
   return false;
}*/
long long int read(long long int* tree,int indx){
  long long int sum=0;
    while(indx>0){
      sum+=tree[indx];indx-=(indx&-indx);
    }
    return sum;
}
void update(long long int* tree,int val,int indx,int limit){
    //tree[indx]+=val;
    while(indx<=limit){
      tree[indx]+=val;indx+=(indx&-indx);
    }
    return ;
}
int main(){
  long int n,q;
  cin>>n>>q;
  long int a[n];
  int maxx=0;long long int tree[n+1];tree[n]=0;
  for(int i=0;i<n;i++){cin>>a[i];tree[i]=0;}
    //for(int i=0;i<=maxx;i++)tree[i]=0;
  //node* s=(node*)malloc(q*sizeof(node));
  int x,y;
  for(int i=0;i<q;i++){
    cin>>x>>y;
    update(tree,1,x,n);
    update(tree,-1,y+1,n);
  }
  long long int f[n];
//node* f=(node*)malloc((n)*sizieof(node));
  for(int i=0;i<n;i++){
    f[i]=read(tree,i+1);
  //  cout<<"\nf[i]"<<f[i];
  }
  sort(f,f+n);sort(a,a+n);
  long long int ans=0;
  for(int i=n-1;i>=0;i--){
    //cout<<"\na[i]= "<<a[i];
    ans+=a[i]*f[i];
    //cout<<"\n"<<a[i]*f[i];
  }
  cout<<ans;
  return 0;
}
