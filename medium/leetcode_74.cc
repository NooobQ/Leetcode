//Search-a-2d-matrix
//binary_search
//edge_condition attention:lowest number and highest number
//bug point:lowest number ,and trying to access the value of end iterator
//---------
//两次二分查找算法，第一次二分得到的数（纵向）需要处理。
//边界条件处理：比数组内最小的数还小，最大的数还大的数，开头与结尾
//只测试了大的数没测试小的数导致vector访问越界
//注意越界问题
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()||matrix[0].empty())
            return false;
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(matrix[mid][0]>target)
                r=mid;
            else
                l=mid+1;
        }
        
        //cout<<"test:l=\t"<<l<<endl;    
        if(l!=n&&matrix[l][0]==target)
            return true;
        if(l>0)
            l--;

        auto p=lower_bound(matrix[l].begin(),matrix[l].end(),target);
        //cout<<"test:p=\t"<<*p<<endl;
        if(p!=matrix[l].end())
            return *p==target;
        else
            return false;
    }
};
