//834.sum-of-distances-in-tree
//tag:DFS BFS DP
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if(N==1)
            return {0};
        if(edges.empty())
            return {};
        int root=edges[0][0];
        vector<int> ans(N);
        vector<bool> vis(N,false);
        vector<int> nums(N);//total num of TreeNode;
        vector<vector<int>> mapping(N);
        //map edge and node
        for(auto foo:edges){
            int x=foo[0],y=foo[1];
            mapping[x].push_back(y);
            mapping[y].push_back(x);
        }
        
        //DFS
        dfs(root,vis,nums,mapping);
        //for(auto foo:nums)
            //cout<<foo<<endl;
        
        //traverse with status
        for(int i=0;i<N;i++)
            ans[root]+=nums[i],vis[i]=false;
        ans[root]-=N;

        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int cur=q.front(),next;q.pop();
            vis[cur]=true;
            for(int i=0;i<mapping[cur].size();i++){
                next=mapping[cur][i];
                if(!vis[next]){
                    //cout<<"BFS("<<next<<")\n";
                    q.push(next);
                    ans[next]=ans[cur]+N-2*nums[next];
                }
            }
        }

        return ans;
    }
    int dfs(int cur,vector<bool> &vis,vector<int> &nums,vector<vector<int>> &mapping){
        //漏了个'&'TLE了两遍哈哈哈哈哈哈哈哈哈哈哈哈哈臭傻逼
        //cout<<"dfs("<<cur<<")\n";
        int tmp=0;
        vis[cur]=true;
        for(int i=0;i<mapping[cur].size();i++){
            int next=mapping[cur][i];
            if(!vis[next])
                tmp+=dfs(next,vis,nums,mapping);
        }
        return nums[cur]=tmp+1;
    }
};
