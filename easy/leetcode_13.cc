class Solution {
public:
    int romanToInt(string s) {
        int ans=0;

        for(int i=0;i<s.length();i++){
            char ch=s[i];

            switch(ch){
                case 'I':
                    if(i+1<s.length() && 
                    (s[i+1]=='V'||s[i+1]=='X')){
                        ans+=(s[i+1]=='V')?4:9;
                        i++;
                        break;
                    }
                    ans+=1;break;
                case 'V':
                    ans+=5;break;
                case 'X':
                    if(i+1<s.length() && 
                    (s[i+1]=='L'||s[i+1]=='C')){
                        ans+=(s[i+1]=='L')?40:90;
                        i++;
                        break;
                    }
                    ans+=10;break;
                case 'L':
                    ans+=50;break;
                case 'C':
                    if(i+1<s.length() && 
                    (s[i+1]=='D'||s[i+1]=='M')){
                        ans+=(s[i+1]=='D')?400:900;
                        i++;
                        break;
                    }
                    ans+=100;break;
                case 'D':
                    ans+=500;break;
                case 'M':
                    ans+=1000;break;
            }
        }

        return ans;
    }
};


class Solution2 {
public:
    int romanToInt(string s) {
        static int mp[256];
        mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;
        mp['C']=100;mp['D']=500;mp['M']=1000;
        int ans=0;
        int pre=1000;
        for(const char &ch:s){
            ans+=mp[ch];
            if(pre<mp[ch])
                ans-=2*pre;
            pre=mp[ch];
        }
        
        return ans;
    }
};
