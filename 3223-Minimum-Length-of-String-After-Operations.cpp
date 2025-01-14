class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char ,int> m;
        int n  = s.size();
        for(int i=0; i<n ; i++){
            m[s[i]]++;            
        }    
        // map is formed
        for(int i=1 ; i<n ; i++){
            if(m[s[i]]<3) continue;
            else m[s[i]] = m[s[i]] -2;
        }
        int sum = 0;
        for (auto x : m){
            sum += x.second; 
        }
        return sum;
    }
};