// https://leetcode.com/problems/longest-palindromic-substring/description/
// Time Complexity: O(n^2) 
// Space Complexity: O(n^2)
// DP

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.length();
            vector<vector<bool>> dp(n, vector<bool> (n, false));
            for(int i=0; i<n; i++){
                dp[i][i] = true;
            }
            int start = 0; int maxlen = 1;
            for(int len=2; len<=n; len++){
                for(int i=0; i<=n-len; i++){
                    int j = i + len - 1;
                    if(s[j] == s[i]){
                        if(dp[i+1][j-1] || len == 2) {
                            dp[i][j] = true;
                            if(len > maxlen){
                                start = i; 
                                maxlen = len;
                            }
                        }
                    } 
                }
            }
            return s.substr(start, maxlen);
        }
    };

// Time Complexity: O(n^2) 
// Space Complexity: O(1)

    class Solution {
        public:
            void helper(string &s, int left, int right, int n, int &start, int &maxlen){
                while(left >= 0 && right <= n && (s[left] == s[right])){
                    left--;
                    right++;
                }
                int len = right - left - 1;
                if(len > maxlen){
                    maxlen = len;
                    start = left+1;
                }
            }
            string longestPalindrome(string s) {
                int n = s.length();
                int start = 0; int maxlen=0;
                for(int i=0; i<n; i++){
                    // odd length
                    helper(s, i, i, n, start, maxlen);
        
                    // even length
                    helper(s, i, i+1, n, start, maxlen);
                }
                return s.substr(start, maxlen);
            }
        };