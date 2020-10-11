//66.plus-one
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto foo=digits.rbegin();
        int flag=false,cnt=0;
        while(foo!=digits.rend()){
            *foo+=1;
            if(*foo<10)
                return digits;
            *foo=0;
            foo++;
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};
