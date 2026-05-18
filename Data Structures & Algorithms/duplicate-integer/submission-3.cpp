class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        for(int  i= 0 ; i < n-1  ; i++){
            if(arr[i] == arr[i+1]){
                return true;
            }
        }
        return false;
    }
};