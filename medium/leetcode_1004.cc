//1004.max-consecutive-ones-iii
//tag:slide windows
class Solution {
public:
    //count on '0' and using binary_search
    int longestOnes(vector<int>& A, int K) {
        vector<int> zero(A.size());
        vector<int> list;
        if(A[0]==1)
            list.push_back(0);
        for(int i=0;i<A.size();i++){
            zero[i]=(A[i]==0)+(i>0?zero[i-1]:0);
            if(i>0&&A[i]==1&&A[i-1]==0)
                list.push_back(i);
        }

        // for(auto foo:zero)
        //     cout<<foo<<'\t';
        // cout<<endl;
        
        int ans=0;
        for(auto foo:list){
            auto p=lower_bound(zero.begin(),zero.end(),K+zero[foo]);
            int tmp=0;
            if(p!=zero.end()){
                int tmp=*p;
                while(p!=zero.end()&&*p==tmp)
                    p++;
            }

            tmp=(p-zero.begin())-foo;

            if(p==zero.end()){
                tmp+=K+zero[foo]-zero.back();
            }

            ans=max(ans,tmp);
        }
        if(ans>A.size())
            ans=A.size();
        return ans;
    }
};
class Solution2 {
public:
    int longestOnes(vector<int>& A, int K) {
        int l=0,r=0;
        int n=A.size(),cnt=0,ans=0;
        while(r!=n){
            while(r!=n&&A[r]==1)
                r++;
            if(r!=n&&cnt<K&&A[r]==0){
                r++,cnt++;continue;
            }
            //cout<<l<<'\t'<<r<<'\t'<<cnt<<endl;
            ans=max(ans,r-l);
            if(A[l]==0)
                cnt--;
            l++;
        }
        if(r==n)
            ans=max(ans,n-l);
        return ans;
    }
};
