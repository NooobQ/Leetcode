class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(i<j)
        {
            ans=max(min(height[i],height[j])*(j-i),ans);
            if(height[i]>height[j])
            {
                int tmp=j-1;
                while(tmp>=0&&height[tmp]<=height[j])
                    tmp--;
                j=tmp;
                continue;
            }
            else
            {
                int tmp=i+1;
                while(tmp<height.size()&&height[tmp]<=height[i])
                    tmp++;
                i=tmp;
                continue;
            }
        }
        return ans;
    }
};
