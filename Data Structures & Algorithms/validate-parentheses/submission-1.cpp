class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> friends = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (friends.count(s[i])) {
                if (st.empty() || st.top() != friends[s[i]]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
