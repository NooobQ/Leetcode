//344.reverse-string
class Solution {
public:
    void reverseString(vector<char>& s) {
        int x=0,y=s.size()-1;
        while(x<y)
            swap(s[x++],s[y--]);
    }
};
