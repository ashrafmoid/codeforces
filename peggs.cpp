#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  /*int** a=(int**)malloc(n*sizeof(int*));
  for(int i=0;i<n;i++){
    a[i]=(int*)malloc(2*sizeof(int));
  }*/
  int a[n],g[n];
  for(int i=0;i<n;i++){
    cin>>a[i]>>g[i];
  }
  char ans[n];
  //long long int sa=0,sg=0;
  int dif=0;//dif=sa-sg
  for(int i=0;i<n;i++){
      if(a[i]+dif>500){
        ans[i]='G';dif=dif-g[i];
      }
      else{
        ans[i]='A';dif=dif+a[i];
      }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i];
  }
  return 0;
}
