#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef signed long long int64;
int main(){
  //use fast input output
  long int k;char c[1000000];
  long long int ans=0;int len=0;
  int f[1000000];int counts=0;f[0]=0;
  //cin>>k;
  scanf("%ld",&k);
  getchar();
  for(int i=0;i<1000000;i++){
    //c[i]=getchar_unlocked();
    scanf("%c",&c[i]);
    //len++;
    if(c[i]=='\n'||c[i]==' ')break;
    if(c[i]=='1'){f[counts]=i;counts++;}
    //if(c[i]=='\n'||c[i]==' ')break;
    len++;
  }
  if(k==0&&counts>0){
    for(int i=0;i<counts;i++){
      if(i>0)
      ans+=((int64(f[i]-f[i-1]-1))*(f[i]-f[i-1]))/2;
      else{
        ans+=((int64(f[i]))*(f[i]+1))/2;
      }
    }
    ans+=((int64(len-f[counts-1]-1))*(len-f[counts-1]))/2;
  }
  else if(k==0&&counts==0){
    ans=((int64 (len))*(len+1))/2;
  }
  else if(k<=counts){
          int j=0;
        for(int i=k-1;i<counts;i++){
          if(i<counts-1){
            if(j==0)
            {ans+=f[j]+1+(int64 (f[i+1]-f[i]-1))*(f[j]+1);j++;}
            else{
              ans+=f[j]-f[j-1]+(int64(f[i+1]-f[i]-1))*(f[j]-f[j-1]);j++;
            }
          }
          else {
            if(j==0)
            {ans+=f[j]+1+(int64 (len-f[i]-1))*(f[j]+1);j++;}
            else{
              ans+=f[j]-f[j-1]+(int64 (len-f[i]-1))*(f[j]-f[j-1]);j++;
            }
            //ans+=f[j]-f[j-1];j++;
          }
          /*else{
            if(j>0){
            ans+=f[j]-f[j-1]+(len-f[i]-1)*(f[j]-f[j-1]);}
            else{
                ans+=f[j]+(len-f[i]-1)*f[j];
            }
          }*/
      //   printf("ans=%lld ",ans);
        }
  }
  //cout<<ans;
  printf("%lld",ans);
//  printf("\n%s\n",c);x
  return 0;
}
