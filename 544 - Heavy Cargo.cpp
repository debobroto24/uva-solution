#include<bits/stdc++.h>
int dp[205][205];
using  namespace std;
int main(){
    int n,e,i,j,k,f=0,cost;
    string s,t;
    map<string,int>mp;
    while(cin>>n>>e,n!=0){
          int c=1;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                if(i==j)
                    dp[i][j]=0;
                else dp[i][j]=-1;
            }
        while(e--){
            cin>>s>>t>>cost;
            if(mp[s]==0)mp[s]=c++;
            if(mp[t]==0)mp[t]=c++;
            dp[mp[s]][mp[t]]=cost;
            dp[mp[t]][mp[s]]=cost;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    dp[i][j]=max(dp[i][j],min(dp[i][k],dp[k][j]));

        cin>>s>>t;
        int fff=mp[s],ggg=mp[t];
        cout<<"Scenario #"<<++f<<endl;
        cout<<dp[fff][ggg]<<" tons"<<endl<<endl;
        mp.clear();
    }
return 0;
}

/*

4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruheo
0 0





4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0




*/
