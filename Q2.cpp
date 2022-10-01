class Solution {
public:
    
    
    
    
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();
        string p2 = getnew_pattern(p,n);
        n = p2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        //cout<<p<<"\n";
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*'){
                dp[i][0] = dp[i-2][0];
            }else{
                dp[i][0]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1]=='*'){
                    if(i>=2){
                        dp[i][j] = dp[i-2][j];
                    }
                    
                    int t = j;
                    while(i>=2 && t>=1 && (p[i-2]==s[t-1] || p[i-2]=='.')){
                        dp[i][j] = (dp[i][j] || dp[i][t-1]);
                        t--;
                    }
                    
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
        
        
        
    }
};