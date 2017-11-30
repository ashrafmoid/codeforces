#include<iostream>
#include<algorithm>
using namespace std;
long long int r=1000000007;
long long int getpart(long long int* cache,int num,int limit){
  if(num==0)return 1;
  if(cache[num]!=0)return (cache[num]%r);
  long long int sum=0;
  for(int i=min(limit,num);i>=1;i--){
    //if(i<=num)
    sum=(sum+getpart(cache,num-i,limit)%r);
  }
  cache[num]=sum%r;
  return (sum%r);
}
long long int getpart(long long int* cache,int num,long long int* smaller,bool b){
  //if(num==0)return 1;
  if(b==false)
  return ((cache[num]-smaller[num])%r);
  return (cache[num]%r);
  /*long long int sum=0;
  for(int i=min(num,limit);i>0;i--){
    if(i<check)
    sum+=getpart(cache,num-i,limit,false,check);
    else{
      sum+=getpart(cache,num-i,limit,true,check);
    }
  }
  //cache[num]=sum;
  return sum;*/
}
int main(){
  long long int cache[101];
  long long int smaller[101];
  for(int i=0;i<101;i++){cache[i]=0;smaller[i]=0;}
  cache[1]=1;cache[0]=1;
  int n,k,d;
  cin>>n>>k>>d;
  getpart(cache,n,k);//to fill the cache
  if(d>1){smaller[1]=1;smaller[0]=1;getpart(smaller,n,d-1);}
  /* now call the same function but overloaded repeatedly to get ans*/
  long long int ans=0;
  /*cout<<"see cache values:\n";
  for(int i=0;i<=n;i++){
    cout<<cache[i]<<" ";
  }*/
  //cout<<endl;
  for(int i=1;i<=k&&i<=n;i++){
    if(i<d)
      ans=(ans+getpart(cache,n-i,smaller,false)%r);
      else ans=(ans+getpart(cache,n-i,smaller,true)%r);
      ans=ans%r;
  }
  cout<<ans%r;/*this part of program results in time limit exceeding*/
  //optimize this part
  //cout<<"cache n is:"<<cache[n];
  return 0;
}
