//201.bitwise-and-of-numbers-range
//tag:bit prefix
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int p=31;
        int ans=0;
        while(p>=0){
            int x=1<<p;
            if((m&x)!=(n&x))
                break;
            ans+=m&x;
            p--;
        }
        return ans;
    }
};
