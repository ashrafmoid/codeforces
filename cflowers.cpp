#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  long int r,g,b;
  cin>>r>>g>>b;
  int rem_r,rem_g,rem_b;
  rem_r=r%3;rem_g=g%3;rem_b=b%3;
  long int ans=0;
  int temp=1;
  if((rem_r==2||rem_r==0)&&(rem_g==2||rem_g==0)&&(rem_b==2||rem_b==0)){
    if(rem_r==2&&rem_g==2&&rem_b==2)temp=2;
    else if(rem_r==0&&rem_g==0&&rem_b==0) temp=0;
    else temp=1;
  }
  ans+=r/3+g/3+b/3+temp;
  cout<<ans;
  return 0;
}
