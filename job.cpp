#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){
  int n,m,k;
  long long int r=-100000000000;
  cin>>n>>m>>k;
  long int* a=(long int*)malloc(n*sizeof(long int));
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long int cache[n];int start=0;long long int temp=0;
  for(int i=0;i<n;i++){
    if(i+1==m){cache[i]=temp+a[i];//cout<<cache[i]<<endl;
    }
    else if(i+1>m){
      cache[i]=cache[i-1]+a[i]-a[start];start++;
    //  cout<<cache[i]<<"\n";
    }
    else {
      temp+=a[i];cache[i]=0;
    }
  }
  long long int sum[n+1][k+1];
  for(int i=0;i<=n;i++)sum[i][0]=0;
  for(int i=1;i<=k;i++)sum[0][i]=r;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(i/m>=j){
        sum[i][j]=max(sum[i-1][j],sum[i-m][j-1]+cache[i-1]);
      }
      else sum[i][j]=r;
    }
  }
  cout<<sum[n][k]<<endl;
  return 0;
}
