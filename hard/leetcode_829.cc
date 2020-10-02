//829.consecutive-numbers-sum
//tag:Math
//When N is odd, N/k > k/2, for example N=3, k=3, if 3/3 = 3/2 -> 3=0+1+2 -> illegal
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int i=1;i<floor(sqrt(2*N+1));i++){
            if(check(N,i))
                ans++;
        }
        return ans;
    }
    inline bool check(int N,int k){
        if(k%2)
            return N%k==0;
        return (int)(N/k)*k+k/2==N;
    }
};
