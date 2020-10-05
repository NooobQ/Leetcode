class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        int n=nums.size();
        nums.push_back(INT_MIN);

        //time:O(n^3)
        for(int i=0;i<n-3;i++){
            //erase repetive case
            if(i&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int Target = target - nums[i] - nums[j];
                int x = j+1,y=n-1;

                while(x<y){
                    //traverse in time:O(n)
                    //double pointer meet
                    int sum = nums[x]+nums[y];
                    if(sum==Target){
                        ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                        do{
                            x++;
                        }while(nums[x]==nums[x-1]);
                        continue;
                    }
                    if(sum<Target)
                        x++;
                    else
                        y--;
                }
            }
        }
        return ans;
    }
};
