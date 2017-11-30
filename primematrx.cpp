#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long int getans(int* dummy,int len,vector<int>& prime){
  long int ans=0;int j=0;
  for(int i=0;i<len;i++){
    //int j=0;
    while(dummy[i]>prime[j]){
      j++;
    }
    ans+=prime[j]-dummy[i];
  }
  return ans;
}
int main(){
  vector<int> prime;
  bool* b=(bool*)malloc(100020*sizeof(bool));
  for(int i=0;i<100020;i++)b[i]=true;
  for(int i=2;i<100020;i++){
      if(b[i]==true){
        prime.push_back(i);
        int temp=i;
        while(temp<100020){
          b[temp]=false;temp=temp+i;
        }
      }
  }
  free(b);
  int n,m;cin>>n>>m;
  int matrx[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cin>>matrx[i][j];
  }
  int dummyrow[m];int dummycol[n];
//  long int row,col;
  long int minn=9999999;
  for(int i=0;i<n;i++){
  //  row=0;
    for(int j=0;j<m;j++)
      dummyrow[j]=matrx[i][j];
    sort(dummyrow,dummyrow+m);
    minn=min(minn,getans(dummyrow,m,prime));
  }
  for(int i=0;i<m;i++){
  //  row=0;
    for(int j=0;j<n;j++)
      dummycol[j]=matrx[j][i];
    sort(dummycol,dummycol+n);
    minn=min(minn,getans(dummycol,n,prime));
  }
  cout<<minn;
  return 0;
}
