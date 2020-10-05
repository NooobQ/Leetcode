//27.remove-element
//vector index out of bound WARNNING!
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int x=0,y=n-1;

        while(x<=y){
            while(x<nums.size()&&nums[x]!=val)
                x++;
            if(x>y)
                break;
            swap(nums[x],nums[y]);
            while(y<nums.size()&&nums[y]==val){
                nums.pop_back();
                y--;
            }
        }
        return nums.size();

    }
};
