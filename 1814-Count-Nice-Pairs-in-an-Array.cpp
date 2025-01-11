class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r*=10;
            r+=(n%10);
            n/=10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> m; 
        for(int i=0 ; i<n ;i++){
            nums[i] = (nums[i] - rev(nums[i]));   // update the same arr with its diff
        }  
        int count = 0;    
        for(int i=0 ; i<n ; i++){ 
            // in this loop we update and the count and tha map simultaneously
            if(m.find(nums[i]) != m.end()){
                count = count%1000000007;
                count = count + m[nums[i]];
                m[nums[i]]++;     
            }
            else m[nums[i]]++;
        } 
        return count%1000000007;     
        // given in the the que to return in this form.....bcoz value count can be so large.
    }
};