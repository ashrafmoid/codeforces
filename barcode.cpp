#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  //use fast input output;
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  long int dot[1001];long int hash[1001];
  for(int i=0;i<1001;i++){
    dot[i]=0;hash[i]=0;
  }
  int n,m,x,y;
  cin>>n>>m>>x>>y;
//  long int dot[m+1];long int hash[m+1];
  //dot[0]=0;hash[0]=0;
  char s[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>s[i][j];
      if(s[i][j]=='.')dot[j+1]++;
      else{hash[j+1]++;}
    }
    if(i==n-1){
      for(int k=1;k<=m;k++){
        dot[k]+=dot[k-1];
        hash[k]+=hash[k-1];
      }
    }
  }
  long int ans[2][m+1];ans[0][0]=0;ans[1][0]=0;
  long int res=999999;
  for(int i=1;i<=m;i++){
    ans[0][i]=999999;ans[1][i]=999999;
    for(int  j=x;j<=y;j++){
      if(i>=j){
        ans[0][i]=min(ans[1][i-j]+dot[i]-dot[i-j],ans[0][i]);
        ans[1][i]=min(ans[0][i-j]+hash[i]-hash[i-j],ans[1][i]);
      }
    }
  }
  cout<<min(ans[1][m],ans[0][m]);
  return 0;
}
