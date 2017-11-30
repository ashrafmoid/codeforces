#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  //  long long int sum[5*100000 +1];
    //for(int i=0;i<=5*100000;i++)sum[i]=0;
  int n;cin>>n;
  long long int a[n];
  long long int sum[n];sum[0]=0;
  long long int tot_sum1=0,tot_sum2=0;long long int f1=0,f2=0,f3=0;
  //long long int sum[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i>0)
    sum[i]=a[i]+sum[i-1];
    else sum[i]=a[i];
  }
  tot_sum1=sum[n-1]/3;tot_sum2=(sum[n-1]/3)*2;
  if(sum[n-1]%3!=0){cout<<"0";return 0;}
/*  if(sum[n-1]==0){

}*/
long long int ans=0;
  for(int i=n-1;i>=0;i--){

    if(sum[i]==tot_sum1){f1++;ans+=f2;}
    else if(sum[i]==tot_sum2){f2++;}
    else if(sum[i]==sum[n-1]){f3++;}
  }
  if(sum[n-1]==0){
    ans=((f1-1)*(f1-2)/2);
    cout<<ans;return 0;
  }
//  cout<<tot_sum1<<" "<<tot_sum2<<"\n";
//  ans=(f1*f2*f3);
  cout<<ans;
  return 0;
}
