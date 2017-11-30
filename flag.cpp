#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int dance[m][3];
  for(int i=0;i<m;i++){
    for(int j=0;j<3;j++)
      cin>>dance[i][j];
  }
  int f[n+1];
  for(int i=0;i<=n;i++){
    f[i]=0;
  }
  int val=0,nxtval=0;
  for(int i=0;i<m;i++){
    val=0;nxtval=0;
    if(f[dance[i][0]]!=0){
      val=f[dance[i][0]];
    }
    else if(f[dance[i][1]]!=0){
      val=f[dance[i][1]];
    }
    else if(f[dance[i][2]]!=0){
      val=f[dance[i][2]];
    }
    if(!f[dance[i][0]]){
      if(1!=val){f[dance[i][0]]=1;nxtval=1;}
      else if(2!=val){f[dance[i][0]]=2;nxtval=2;}
      else {f[dance[i][0]]=3;nxtval=3;}
    }
    if(val==0){
      val=nxtval;
    }
    if(!f[dance[i][1]]){
      if(1!=val&&nxtval!=1){f[dance[i][1]]=1;nxtval=1;}
      else if(2!=val&&nxtval!=2){f[dance[i][1]]=2;nxtval=2;}
      else {f[dance[i][1]]=3;nxtval=3;}
    }
    if(!f[dance[i][2]]){
      if(1!=val&&nxtval!=1){f[dance[i][2]]=1;nxtval=1;}
      else if(2!=val&&nxtval!=2){f[dance[i][2]]=2;nxtval=2;}
      else {f[dance[i][2]]=3;nxtval=3;}
    }
    //cout<<f[dance[i][0]]<<" "<<f[dance[i][1]]<<" "<<f[dance[i][2]]<<" ";
  }
  for(int i=1;i<=n;i++){
    cout<<f[i]<<" ";
  }
  return 0;
}
