//Leetcode-39-combination_sum
//search & backtrace
//just dfs & backtrace (many parameter ver 1.0)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> List;
        dfs(List, candidates, ans, 0, target, 0);
        return ans;
    }
    void dfs(vector<int> &List, vector<int> &candidates, vector<vector<int>> &ans, int index, int &target, int tmp){
        

        if(tmp>=target){
            
            if(tmp==target){
                //for(auto foo:List)
                //    cout<<foo<<'\t';
                //cout<<'\n';
                ans.push_back(List);
            }
            return;
        }

        for(int i=index;i<candidates.size();i++){
            List.push_back(candidates[i]);
            dfs(List, candidates, ans, i, target, tmp + candidates[i]);
            List.pop_back();
        }
    }
};
