class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()<4)
            return {};
        
        sort(nums.begin(),nums.end());
        vector< vector<int> > ans;
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int x=target-nums[i]-nums[j];
                int a=j+1,b=nums.size()-1;
                while(a<b)
                {
                    if(nums[a]+nums[b]==x)
                    {
                        ans.push_back({nums[i],nums[j],nums[a],nums[b]});
                        do
                        {
                            a++;
                        }
                        while(a<nums.size()&&nums[a]==nums[a-1]);
                        do
                        {
                            b--;
                        }
                        while(b>=0&&nums[b]==nums[b+1]);
                        continue;
                    }
                    if(nums[a]+nums[b]>x)
                        b--;
                    if(nums[a]+nums[b]<x)
                        a++;
                }
            }
        }
        return ans;
    }
};
