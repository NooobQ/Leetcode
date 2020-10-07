class Solution {
public:
    void sortColors(vector<int>& nums) {
        //2-loop
        int n=nums.size();
        int head=-1,tail=n;
        auto f=[&](int x){
            do{
                head++;
            }while(head<n&&nums[head]!=x);
            do{
                tail--;
            }while(tail>=0&&nums[tail]==x);
        };
        auto g=[&](int x){
            f(x);
            while(head<tail){
                swap(nums[head],nums[tail]);
                f(x);
            }
        };

        g(2);
        
        tail=-1;
        swap(head,tail);
        g(1);
    }
};

//1-loop,2-swap
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p0=0,p1=0;
        for(int i=0;i<n;++i){
            if(nums[i]==1){
                swap(nums[i],nums[p1]);
                ++p1;
            }
            else{
                if(nums[i]==0){
                    swap(nums[i],nums[p0]);
                    if(p0<p1)
                        swap(nums[p1],nums[i]);
                    ++p0;++p1;
                }
            }
        }
    }
};
