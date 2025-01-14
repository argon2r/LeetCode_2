class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> setA, setB;
        vector<int> ans;

        for(int i=0 ; i<n ; i++){
            setA.insert(A[i]);
            setB.insert(B[i]);

            int count = 0;
            for(int ele : setA){
                if(setB.count(ele)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;

    }
};