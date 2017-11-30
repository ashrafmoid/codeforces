#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  int n,d,l;int j=0;
  cin>>n>>d>>l;
  if(l==1){
    if(n%2==1){
      if(d!=1){cout<<"-1";return 0;}
      for(int i=0;i<n;i++)cout<<"1 ";
      return 0;
    }
    else {
      if(d!=0){cout<<"-1";return 0;}
      for(int i=0;i<n;i++)cout<<"1 ";
      return 0;
    }
  }
    int ans[n];
    if(n%2==1){
      if(d<=0){
        d=1-d;
        ans[j++]=1;
        //d=abs(d);
      //  int temp=d/(l-1);
        //if((d%(l-1) )!=0)temp++;
        if((n/2)*(l-1)<abs(d)){cout<<"-1";return 0;}
      }
      else{
        d=l-d;
        ans[j++ ]=l;
      //  int temp=int (abs(d)/(l-1));
        //if(int (abs(d))%(l-1)>0)temp++;
        if((n/2)*(l-1)<abs(d)){cout<<"-1";return 0;}
      }
    }
    if((n/2)*(l-1)<abs(d)){cout<<"-1";return 0;}
    if(d<=0){
      for(;j<n-1;j=j+2){
        int minn=min(abs(d),l-1);
          d=d+minn;
          ans[j]=1;ans[j+1]=1+minn;
        }
    }
    else{
      for(;j<n-1;j=j+2){
        int minn=min(d,l-1);
        d=d-minn;
        ans[j]=1+minn;ans[j+1]=1;
      }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}
