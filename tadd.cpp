#include<iostream>
#include<algorithm>
using namespace std;
/*bool cmp(long long int a,long long int b){
  return a<b;
}*/
int main(){
  int n;long long int k;
  cin>>n>>k;
  long long int a[n];long long int res[n];res[0]=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
  /*  if(i>0)
    res[i]=a[i]+res[i-1];
    else{res[i]=a[i];}
    cout<<"res="<<res[i]<<" ";*/
  }
  //cout<<"\n";
  sort(a,a+n);
  res[0]=a[0];
  int len=1,be=0;long long int nmbr=a[0];
  for(int i=1;i<n;i++){
    res[i]=a[i]+res[i-1];
      if(be>0){
        if((i-be)*a[i]-res[i-1]+res[be-1]<=k&&len<i-be+1){
          len=i-be+1;nmbr=a[i];
        }
        else be++;
      }
      else if((i-be)*a[i]-res[i-1]<=k&&len<i-be+1){
        len=i-be+1;nmbr=a[i];//cout<<((i-be)*a[i]-res[i])<<"\n";
      }
        //else{be++;cout<<"else1\n";}
      //}
      //else  if(i*a[i]-res[i-1]<=k&&len<i+1){
        //    len=i+1;nmbr=a[i];cout<<"if2\n";
          //}
  else {be++;}//cout<<"YES\n";}
    //cout<<"len="<<len<<" ,nmbr="<<nmbr<<" ,index="<<i<<endl;
  }
  cout<<len<<" "<<nmbr;
  return 0;
}
