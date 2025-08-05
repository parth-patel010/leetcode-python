// Problem 3: Longest Substring Without Repeating Characters

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> lastSeen(128, -1);
            int maxLength = 0;
            int windowStart = 0;
            for (int current = 0; current < s.size(); ++current){
                char ch = s[current];
                if (lastSeen[ch] >= windowStart) {
                    windowStart = lastSeen[ch] + 1;
                }
                lastSeen[ch] = current;
                int currentWindowLength = current - windowStart + 1;
                if (currentWindowLength > maxLength) {
                    maxLength = currentWindowLength;
                }
            }
    
            return maxLength;
        }
    };
    