class Solution {
public:
    using pii=pair<int,int>;
    int trap(vector<int>& height) {//单调栈
        stack<int> st;
        int tmp=0,d=0;
        int ans=0;
        for(auto foo:height){
            if(st.empty()){
                st.push(foo);
            }
            else{
                if(foo>=st.top()){
                    tmp+=d*st.top();
                    ans+=tmp;
                    st.push(foo);
                    tmp=0;d=0;
                }else{
                    tmp-=foo;
                    d++;
                }
            }
        }
        while(!st.empty())
            st.pop();
        tmp=0;d=0;
        for(auto foo=height.rbegin();foo!=height.rend();foo++){
            if(st.empty()){
                st.push(*foo);
            }
            else{
                if(*foo>st.top()){
                    tmp+=d*st.top();
                    std::cout<<tmp<<'\n';
                    ans+=tmp;
                    st.push(*foo);
                    tmp=0;d=0;
                }else{
                    tmp-=*foo;
                    d++;
                }
            }
        }
        return ans;
    }
};
