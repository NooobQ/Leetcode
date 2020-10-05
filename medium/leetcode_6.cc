//zigzag-conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int mod=2*(numRows-1);
        string ans;
        int n=s.length();
        for(int i=0;i<=mod/2;i++){
            if(i==0||i==mod/2){
                for(int j=0;i+mod*j<n;j++)
                    ans+=s[i+mod*j];
            }
            else
            for(int j=0;i+j*mod<n;j++){
                int x1=i+j*mod,x2=(j+1)*mod-i;
                ans+=s[x1];
                if(x2<n)
                    ans+=s[x2];
            }
        }
        return ans;
    }
};
