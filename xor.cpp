#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  long int lena,lenb;
  lena=a.length();
  lenb=b.length();
  if(lena!=lenb){
    cout<<"NO";return 0;
  }
  int flag=0;
  //int bk=0,f=0;
  long int za=0,zb=0;
    for(int i=lena-1;i>=0;i--){
      if(a[i]-48==0)za++;
      if(b[i]-48==0)zb++;
    }
    if(za==lena&&zb!=lena){
      cout<<"NO";return 0;
    }
    if(zb==lena&&za!=lena){
      cout<<"NO";return 0;
    }
    else cout<<"YES";
  return 0;
}
