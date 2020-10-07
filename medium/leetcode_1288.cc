//1288.remove-covered-intervals
//tag:sort, lambda
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //compare function
        auto f=[](vector<int>& a,vector<int> &b){
            if(a[0]!=b[0])
                return a[0]<b[0];
            return a[1]>b[1];
        };

        int n=intervals.size(),cnt=0;
        sort(intervals.begin(),intervals.end(),f);
        auto iter=intervals.begin();
        int x1=(*iter)[0],y1=(*iter)[1];
        iter++;

        while(iter!=intervals.end()){
            int x2=(*iter)[0],y2=(*iter)[1];
            //cout<<x1<<' '<<y1<<"  | "<<x2<<' '<<y2<<endl;
            if(x1<=x2&&y2<=y1){
                cnt++;
            }
            else
                x1=x2,y1=y2;
            iter++;
            //cout<<(*iter)[0]<<(*iter)[1]<<'\n';
        }

        return n-cnt;
    }
};
