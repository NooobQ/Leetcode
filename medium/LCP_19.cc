//LCP 19
//tag:DP
//TO-DO: code-review in English
class Solution {
public:
    int minimumOperations(string leaves) {
        int len=leaves.length();
        vector<int> dp[len];
        for(int i=0;i<len;i++)
            dp[i].resize(3);

        dp[0][0]=(leaves[0]!='r');
        dp[0][1]=dp[0][2]=dp[1][2]=INT_MAX/2;
        for(int i=1;i<len;i++){
            bool flag=(leaves[i]=='r');
            //flag ---> s[i]-> red leave
            dp[i][0]=dp[i-1][0]+!flag;
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+flag;
            dp[i][2]=min(dp[i-1][1],dp[i-1][2])+!flag;
            //cout<<dp[i][0]<<'\t'<<dp[i][1]<<'\t'<<dp[i][2]<<endl;
        }

        return dp[len-1][2];
    }
};
