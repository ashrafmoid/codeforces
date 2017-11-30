#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
 int main(){
   long int ans=0;
   int n,p;
   cin>>n>>p;
  // string s;
  char s[n];
   cin>>s ;
   //int len=s.size();
   int mid=n/2;
   int temp;
  // int bef_mid[len/2],aft_mid[len/2];
  vector<int>bef_mid;
  vector<int>aft_mid;
   for(int i=0, j=n-1;i<j;){
     if(s[i]!=s[j]){
       //calculate minimum of upper and lower arrow keys
       //cout<<(s[i]-97+122-s[j]+1)<<"\n";
       int a=min(s[i],s[j]);int b=max(s[j],s[i]);//cout<<a<<" "<<b<<"\n";
       //cout<<s[i]<<" "<<s[j];
      // cout<<(a-b)<<"\n";
       temp=min((26+a-b),abs(a-b));//modify this
      //cout<<temp<<" \n";
       ans+=temp;
       //cout<<ans<<"\n";
       bef_mid.push_back(i+1);
       aft_mid.push_back(j+1);
     }
     i++;j--;
   }
   int len1=aft_mid.size();int len2=bef_mid.size();
   int temp1=0,temp2=0,minn=0,maxx=0;
   if(p>=mid&&len1>0){
     temp1=abs(aft_mid[len1-1]-p);//cout<<"temp1 "<<temp1<<"\n";
     temp2=abs(aft_mid[0]-p);//cout<<"temp2"<<temp2<<"\n";
     //cout<<min(temp1,temp2)<<"\n";
     if(temp1>=temp2){minn=temp2;maxx=temp1;}
     else{minn=temp1;maxx=temp2;}
     //cout<<"min="<<minn<<"max="<<maxx<<"\n";
     if(p>aft_mid[len1-1]&&p<aft_mid[0]){
     ans+=2*minn+maxx;}
     else {ans=ans+maxx;}
     //cout<<ans<<"\n";
   }
   else if(len2>0){
    temp1=abs(bef_mid[len2-1]-p);
     temp2=abs(bef_mid[0]-p);
     if(temp1>=temp2){minn=temp2;maxx=temp1;}
     else{minn=temp1;maxx=temp2;}
     if(p<bef_mid[len2-1]&&p>bef_mid[0])
     ans+=2*minn+maxx;
     else
     ans+=maxx;
     //cout<<ans<<"\n";
   }
   cout<<ans;
   return 0;
 }
