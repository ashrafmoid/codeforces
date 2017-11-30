#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
  int n,m;long int k;
  scanf("%d%d%ld",&n,&m,&k);
  //cin>>n>>m>>k;
  long int a[n][m];int row[n];int col[m];
  for(int i=0;i<n;i++){
    row[i]=i;
    for(int j=0;j<m;j++){
      col[j]=j;
      //cin>>a[i][j];
      scanf("%ld",&a[i][j] );
    }
  }
  //for(int i=0;i<n;i++)
  char c;int x,y;int temp;
  getchar();
  for(long int i=0;i<k;i++){
  //  cin>>c>>x>>y;
  //getchar()
  scanf("%c%d%d",&c,&x,&y);
  getchar();
    if(c=='g'){
      printf("%ld\n",a[row[x-1]][col[y-1]]);
    }
  else   if(c=='r'){
      temp=row[x-1];
      row[x-1]=row[y-1];row[y-1]=temp;
      //cout<<"r\n";
    }
    else{
      temp=col[x-1];
      col[x-1]=col[y-1];
      col[y-1]=temp;
      //cout<<"c\n";
    }
  }
  return 0;
}
