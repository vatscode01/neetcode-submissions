class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size(); 
        long long p1=1,p2=1,res=INT_MIN;
        for(int i=0; i<n; i++){
            p1 *= a[i];
            p2 *= a[i];
            res = max(res, max(p1,p2));

            if(p2 == 0){p1=1; p2=1;}
            else{
                if(p1 > p2)
                    swap(p1,p2);
                if(p2 < 0)
                    p2 = 1;
            }
        }
        return res;
    }
};
