  #include<iostream>
  #include<stdio.h>
  #include<algorithm>
  using namespace std;
  typedef struct node{
    //char clr1,clr2;
    long long int ans[3][3];
    //for(int i=0;i<3;i++){
      //for(int j=0;j<3;j++)ans[i][j]=0;
    //}
    int indx;
  }node;
  node *a;
  long long int getans(int pre1,int pre2,int indx,int n){
   if(indx>1&&a[indx].ans[pre1][pre2]!=0){
       return a[indx].ans[pre1][pre2];
      }
    if(indx>=n){
        if(pre1==2)
        return 0;
        return 1;
      }
    if(pre1==0){
      a[indx].ans[pre1][pre2]=(getans(2,0,indx+1,n)+getans(1,0,indx+1,n));
      return a[indx].ans[pre1][pre2];
    }
    if(pre1==2){
      if(pre2==0){
        a[indx].ans[pre1][pre2]=(getans(1,2,indx+1,n));
        return a[indx].ans[pre1][pre2];
      }
      else if(pre2==1){
        a[indx].ans[pre1][pre2]=(getans(0,2,indx+1,n));
        return a[indx].ans[pre1][pre2];
      }
    //  else return 0;
    }
    a[indx].ans[pre1][pre2]=(getans(0,1,indx+1,n)+getans(2,1,indx+1,n));
    return a[indx].ans[pre1][pre2];
  }
  int main(){
    int n;cin>>n;
    a=(node*)malloc((n+1)*sizeof(node));
    for(int i=0;i<n+1;i++){
      for(int j=0;j<3;j++){
        for(int k=0;k<3;k++)a[i].ans[j][k]=0;
      }
    }
  //long long int a[3][n+1];
  //for(int i=0;i<3;i++){
    //for(int j=0;j<=n;j++)a[i][j]=0;
  //}
    //int ans1,ans2;
    //printf("the ans is:w");
  //  ans1=getans('w','o',1,n);
    //printf("")
    printf("the ans is:%lld",(getans(0,-1,1,n)+getans(1,-1,1,n)));
  }
