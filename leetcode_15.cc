class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            int target=-nums[i];
            if(target<0||(i&&nums[i]==nums[i-1]))
                continue;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    do
                    {
                        j++;
                    }
                    while(j<nums.size()&&nums[j]==nums[j-1]);
                    do
                    {
                        k--;
                    }
                    while(k>=0&&nums[k]==nums[k+1]);
                    continue;
                }
                if(nums[j]+nums[k]<target)
                {   
                    do
                    {
                        j++;
                    }
                    while(j<nums.size()&&nums[j]==nums[j-1]);
                    continue;
                }
                if(nums[j]+nums[k]>target)
                {
                    do
                    {
                        k--;
                    }
                    while(k>=0&&nums[k]==nums[k+1]);
                    continue;
                }
            }
        }
        return ans;
    }
};