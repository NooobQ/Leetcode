//Leetcode-40-combination_sum_ii
//search & backtrace
//just dfs & backtrace with some change
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> List;
        dfs(List, candidates, ans, 0, target, 0);
        return ans;
    }
    void dfs(vector<int> &List, vector<int> &candidates, vector<vector<int>> &ans, int index, int &target, int tmp){
        if(tmp>=target){
            if(tmp==target){
                ans.push_back(List);
            }
            return;
        }

        int len=List.size();
        for(int i=index;i<candidates.size();i++){
            if(i && i!=index && candidates[i]==candidates[i-1])
                continue;
            List.push_back(candidates[i]);
            dfs(List, candidates, ans, i + 1, target, tmp + candidates[i]);
            List.pop_back();
        }
    }
};
