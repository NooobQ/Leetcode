//90.subset-ii
//tag:backtracking
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(nums.begin(),nums.end());
        backtrace(-1,nums,list,ans);
        return ans;
    }
    //backtrace: doSomething--put into list--backtrace--put out of list--dosomethingelse
    void backtrace(int pos,vector<int> &nums,
            vector<int> &list,vector<vector<int>> &ans){
        
        ans.push_back(list);
        for(int i=pos+1;i<nums.size();i++){
            if(i>pos+1&&nums[i]==nums[i-1])    
                continue;
            list.push_back(nums[i]);
            backtrace(i,nums,list,ans);
            list.pop_back();
        }
    }
};
