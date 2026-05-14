class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(int i = 0 ; i < strs.size(); i++){
            encoded += to_string(strs[i].length()) + "#" + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.length()){
    int j = s.find("#", i);
    int len = stoi(s.substr(i, j - i));
    decoded.push_back(s.substr(j + 1, len));
    i = j + 1 + len;
}
        return decoded;
    }
};
