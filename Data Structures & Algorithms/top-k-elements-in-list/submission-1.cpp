class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> seen;
        vector<pair<int,int>> sorted;
        for(int i = 0;i < nums.size(); i++){
            seen[nums[i]]++;
        }
        for(auto& j : seen){
            sorted.push_back({j.first, j.second});
        }
        sort(sorted.begin(), sorted.end(), [](auto& a, auto& b){
    return a.second > b.second;
});
vector<int> result;

for(int i = 0 ; i < k ; i++){
    result.push_back(sorted[i].first);
}
return result;
}
};
