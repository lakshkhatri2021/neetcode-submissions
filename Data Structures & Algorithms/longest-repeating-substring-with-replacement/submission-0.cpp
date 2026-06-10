class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxFreq = 0;
        unordered_map<char, int> count;

        for (right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);
            if(right - left + 1 - maxFreq > k){
                count[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
