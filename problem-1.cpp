// https://leetcode.com/problems/ugly-number-ii/description/
// Time Complexity: O(n) 
// Space Complexity: O(n)

class Solution {
    public:
        int nthUglyNumber(int n) {
            int p2=0, p3=0, p5=0;
            int n2=2, n3=3, n5=5;
            vector<int> ans(n,0);
            ans[0] = 1;
            for(int i=1; i<n; i++){
                int minVal = min(n2, min(n3,n5));
                ans[i] = minVal;
                if(minVal == n2){
                    p2++;
                    n2 = 2*ans[p2];
                }
                if(minVal == n3){
                    p3++;
                    n3 = 3*ans[p3];
                }
                if(minVal == n5){
                    p5++;
                    n5 = 5*ans[p5];
                }
            }
            return ans[n-1];
        }
    };