class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> dude;
        unordered_map<char, int> curr;
        
        for(int i = 0; i < s1.size(); i++){
            dude[s1[i]]++;
        }

        for(int j = 0 ; j < s1.size(); j++){
            curr[s2[j]]++;
        }

        if(dude == curr) return true;

        for(int k = s1.size(); k < s2.size(); k++){
            curr[s2[k]]++;
            curr[s2[k - s1.size()]] --;

            if(curr[s2[k - s1.size()]] == 0) curr.erase(s2[k - s1.size()]);

            if(dude == curr) return true;
        }

        return false;
        
    }
};
