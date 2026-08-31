class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> arr(128,false); // can be used 256 ans 128 aslo
            int longest = 0;
            int i = 0,j = 0;
            while(j < s.length()) {
                // 3ms runtime due to O(n*k)
                // while(j < s.length() && !arr[s[j]]) {
                //     arr[s[j]] = 1;
                //     j++;
                // }
                // // cout << i << " : " << j << " | ";
                // longest = max(longest,j-i);
                // if(arr[s[j]]) {
                //     arr[s[i]] = 0;
                //     i++;
                // }
    
                // O(n)
                if(!arr[s[j]]) {
                    arr[s[j]] = 1;
                    longest = max(longest, j - i + 1);
                    j++;
                } else {
                    arr[s[i]] = 0;
                    i++;
                }
            }
    
    
            return longest;
        }
    };