//200.number-of-islands
//tag:traverse
class Solution {
public:
    pair<int,int> dirs[4]={{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n);
        for(int i=0;i<n;i++)
            vis[i].resize(m,0);

        auto check=[&](int x,int y){
            return x>=0 && y>=0 &&
                    x<n && y<m && grid[x][y]=='1';
        };

        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==0)
                    q.push({i,j}),ans++;

                while(!q.empty()){
                    int curx=q.front().first,cury=q.front().second;
                    q.pop();
                    if(vis[curx][cury])
                        continue;
                    vis[curx][cury]=1;
                    //cout<<"test:|||"<<curx<<'|'<<cury<<endl;
                    for(auto dir:dirs){
                        int fx=curx+dir.first,fy=cury+dir.second;
                        if(check(fx,fy)&&!vis[fx][fy])
                            q.push({fx,fy});
                    }
                }
            }
        return ans;
    }
};
