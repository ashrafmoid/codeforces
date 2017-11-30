#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
  /*pre computation of prime numbers*/
  int limit=(int)sqrt((long double) 1000000000) ;
  int* fa=(int*)malloc((limit+1)*sizeof(int));
  int* fb=(int*)malloc((limit+1)*sizeof(int));
  //int fa[limit+1],fb[limit+1];
  vector<int>primes;
  bool* prm=(bool*)malloc((limit+1)*sizeof(bool));
  //bool prm[limit+1];
  for(int i=2;i<=limit;i++){prm[i]=true;fa[i]=0;fb[i]=0;}
  for(int i=2;i<=limit;i++){
    if(prm[i]==true){
      primes.push_back(i);
      int j=2*i;
      while(j<=limit){
        prm[j]=false;j=j+i;
      }
    }
  }
  free(prm);
  int len=primes.size();
  long int a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"0";return 0;
  }
  long int ovrl=(max(a,b)/2);
  int roota,rootb;
  roota=(int)sqrt((long double)a);rootb=(int)sqrt((long double)b);
  int index=0;
//  for(int i=2;i<=limit;i++)fa[i]=0;
  //for(int i=2;i<=rootb;i++)fb[i]=0;
  while(a>1&&index<len&&primes[index]<=limit){
    while(a%primes[index]==0){
      a=a/primes[index];
      fa[primes[index]]++;
    }
    index++;
  }
  /*if(a>1){
    fa[a]=1;
  }*/
  index=0;
  while(b>1&&index<len&&primes[index]<=limit){
    while(b%primes[index]==0){
      b=b/primes[index];
      fb[primes[index]]++;
    }
    index++;
  }
  /*if(b>1){
    fb[b]=1;
  }*/
  int flag=0;
  long int ans=0;//int minroot=min(roota,rootb);
  int maxx,minn;long int i;
  for(i=2;i<=limit&&i<=ovrl;i++){
    //if()
    maxx=max(fa[i],fb[i]);minn=min(fa[i],fb[i]);
    if(i>5){
      if(maxx>0&&minn==0){flag=1;break;}
      else{
        ans+=maxx-minn;
      }
    }
    else ans+=maxx-minn;
  }
/*  while(i<=roota){
    if(fa[i]!=0){
      flag=1;break;
    }
    i++;
  }
  while(i<=rootb){
    if(fb[i]!=0){
      flag=1;break;
    }
    i++;
  }
  if((fa[a]||fb[b])&&(a>5||b>5)){
    flag=1;
  }*/
  if(flag||ans==0){
    cout<<"-1";
  }
  else{
    cout<<ans;
  }
  return 0;
}
