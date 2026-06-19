class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        unordered_set<char> seen;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            if (!seen.count(s[right])) {
                seen.insert(s[right]);  
            } else {
                while (seen.count(s[right])) {
                    seen.erase(s[left]);
                    left++;
                }
            }
            seen.insert(s[right]);
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};
