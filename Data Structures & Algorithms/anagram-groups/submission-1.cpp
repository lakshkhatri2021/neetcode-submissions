class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> finding;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            finding[sorted].push_back(strs[i]);
        }

        for(auto& i : finding){
            result.push_back(i.second);
        }

        return result;
    }
};
