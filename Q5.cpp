class Solution {
public:
    
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        int i=0;
        
        
        
       // cout<<p<<" "<<m<<"\n";
        bool arr[n+1][m+1];
        memset(arr,false,sizeof(arr));
        arr[0][0]=true;
        i =1;
        while(i<m && p[i-1]=='*'){
            arr[0][i]=true;
            i++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    if(arr[i-1][j-1]){
                        arr[i][j]=true;
                    }else{
                        arr[i][j]=false;
                    }
                }else if(p[j-1]=='*'){
                    if(arr[i-1][j-1] || arr[i-1][j] || arr[i][j-1]){
                        arr[i][j]=true;
                    }else{
                        arr[i][j]=false;
                    }
                }
            }
        }
        return arr[n][m];
    }
};