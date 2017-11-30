  #include<iostream>
  #include<algorithm>
  #include<cmath>
  using namespace std;
  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int ans[5001];
    for(int i=0;i<5001;i++)ans[i]=0;
    //int a[2*100000][2*100000]
    long int n;cin>>n;
    long int a[n];
    for(long int i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
      //ans[a[i]]+=1+ans[a[i]-1];
      ans[a[i]]++;
    }
    long int f[5001];f[0]=0;
    for(int i=1;i<=5000;i++){
      f[i]=f[i-1]+ans[i];
      //cout<<f[i]<<"\n";
    }
  //  long int be=0;en=n-1;
  //int ans[5001];
  //for(int i=0;i<5001;i++)ans[i]=0;
  long int res=0;
  int limit;
  if(a[n-1]%2==0)limit=a[n-1]/2 -1;
  else limit=a[n-1]/2;
  for(int i=a[0];i<=limit;i++){
    res+=min(f[i]-f[i-1],n-f[2*i]);
  }
    cout<<res;
    return 0;
  }
