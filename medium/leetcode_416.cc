//416.partition-equal-subset-sum
//tag:dp 0-1pack
//pack use volume as index
//can be rewrite using dp[10050] 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto foo:nums)
            sum+=foo;
        if(n<2||sum%2)
            return false;
        sum/=2;

        bool dp[205][10005];
        memset(dp,0,sizeof(dp));

        dp[0][0]=true;
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(dp[i-1][j]){
                    dp[i][j]=true;
                    int tmp=(j+nums[i]<=sum?j+nums[i]:0);
                    if(tmp==sum)
                        return true;
                    dp[i][tmp]=true;
                }
            }
        }

        //test:
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=sum;j++)
        //         cout<<dp[i][j]<<'\t';
        //     cout<<endl;
        // }

        return dp[n-1][sum];
    }
};
