class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        string res;
        int resLen = INT_MAX;
        int resLeft = left;

        int have = 0;

        for (int i = 0; i < t.size(); i++) {
            tFreq[t[i]]++;
        }
        int need = tFreq.size();
        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;
            if (tFreq.count(s[right]) && tFreq[s[right]] == window[s[right]]) {
                have++;
            }
            while (have == need) {
                int currLen = right - left + 1;
                if (currLen < resLen) {
                    resLen = currLen;
                    resLeft = left;
                }
                window[s[left]]--;
                if (tFreq.count(s[left]) && window[s[left]] < tFreq[s[left]]) {
                    have--;
                }

                left++;
            }
        }
        if (resLen == INT_MAX) {
            return "";
        } else {
            return s.substr(resLeft, resLen);
        }
    }
};
