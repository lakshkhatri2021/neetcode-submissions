class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        unordered_set<char> seen;
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            if (!seen.count(s[r])) {
                seen.insert(s[r]);
            } else {
                while (seen.count(s[r])) {
                    seen.erase(s[l]);
                    l++;
                }
            }
            seen.insert(s[r]);
            length = max(length, r - l + 1);
            r++;
        }
        return length;
    }
};
