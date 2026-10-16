class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string a,b,odd,even;
        for(int i=0; i<s.size()-1; i++){
            //Odd
            a = func(s,i,i);
            //Even
            b = func(s,i,i+1);
            if(odd.size()<a.size()) odd = a;
            if(even.size()<b.size())    even = b;
        }
        return (odd.size() > even.size()) ? odd : even; 
    }

    string func(string s, int i, int j){
        // if(i<0 || j>=s.size())  return 0;
        while(i>=0 && j<s.size() && s[i]==s[j]) {
            i--; j++;
        }
        return s.substr(i+1, j-i-1);
    }
};
