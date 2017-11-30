#include<iostream>
#include<algorithm>
using namespace std;
void assgn_color(char* c,int indx,int limit,int k){
  if(indx-1>=0){
    if(indx+1<=limit){
      for(int i=0;i<k;i++){
        if(c[indx-1]!=(65+i)&&c[indx+1]!=(65+i)){c[indx]=char(65+i);break;}
      }
    }
    else {
      for(int i=0;i<k;i++){
        if(c[indx-1]!=(65+i)){c[indx]=char(65+i);break;}
      }
    }
  }
  else {
    for(int i=0;i<k;i++){
      if(c[indx+1]!=(65+i)){
        c[indx]=char(65+i);break;
      }
    }
  }
  return ;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n,k;
  cin>>n>>k;
  char c[n];
  cin>>c;
  long int count,j,i;
  long int ans=0;long int count1=0,count2=0;
  if(k==2){
    char c1[n+1],c2[n+1];
    for(int i=0;i<n;i++){
      if(i%2==0){
        if(c[i]!=65)count1++;
          else count2++;
        c1[i]=char(65);
      //  if(c[i]!=66)count2++;
        c2[i]=char(66);
      }
      else {
        if(c[i]!=66)count1++;
          else count2++;
        c1[i]=char(66);
      //  if(c[i]!=65)count2++;
        c2[i]=char(65);
      }
    }
    c1[n]='\0';c2[n]='\0';
    if(count1>count2){
      cout<<count2<<" \n"<<c2;
    }
    else{
      cout<<count1<<"\n"<<c1;
    }
    return 0;
  }
  for(i=0;i<n;){
    count=1;j=i+1;
    if(c[i]==c[j]&&i>0){
      count++;j++;
     assgn_color(c,j-1,n-1,k);
      while(j<n&&c[i]==c[j]){
        j++;count++;
        if(count%2==0)
        assgn_color(c,j-1,n-1,k);
      }
      ans+=count/2;
      /*for(int x=j-1;x>=i;x=x-2){
        assgn_color(c,x,n-1,k);
      }*/
    }
    else if(c[i]==c[j]){
      count++;j++;
     //assgn_color(c,j-2,n-1,k);
      while(j<n&&c[i]==c[j]){
          j++;count++;
      //    if(count%2==0)
        //  assgn_color(c,j-2,n-1,k);
        }
        ans+=count/2;
        for(int x=j-2;x>=i;x=x-2)assgn_color(c,x,n-1,k);
      }
    i=j;
  }
  cout<<ans<<"\n"<<c;
  return 0;
}
