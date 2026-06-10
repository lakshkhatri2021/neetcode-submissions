class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> forS1;
        unordered_map<char, int> forS2;

        for (int right = 0; right < s1.size(); right++) {
            forS1[s1[right]]++;
        }
        for (int right = 0; right < s1.size(); right++) {
            forS2[s2[right]]++;
        }

        if (forS1 == forS2) return true;

        for (int right = s1.size(); right < s2.size(); right++) {
            forS2[s2[right]]++;
            forS2[s2[right - s1.size()]]--;
            if (forS2[s2[right - s1.size()]] == 0) forS2.erase(s2[right - s1.size()]);
            if (forS1 == forS2) return true;
        }

        return false;
    }
};