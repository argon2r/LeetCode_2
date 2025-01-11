class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , int> m;     // MAP created find the occur. of the Key
        for(int i =0 ;i<n ; i++){
            m[arr[i]]++;
        } 
        unordered_set<int> s;  // SET to store occurence and compare
        for(auto x : m ){
            int freq = x.second;
            if(s.find(freq) != s.end()) return false;
            else s.insert(freq);
        }   
        return true;   
    }
};