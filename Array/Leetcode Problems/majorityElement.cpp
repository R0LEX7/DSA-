class Solution {
    public:
        int majorityElement(vector<int>& nums) {
           int n = nums.size();
           int elem , cnt1 = 0 , cnt2 = 0 ;

           for(int i =0 ; i<n; i++){
               if(!cnt1){
                   elem = nums[i];
                   cnt1 = 1;
               }else if(elem == nums[i]){
                   cnt1++;
               }else {
                   cnt1--;
               }
           }

           for(int i =0 ; i< n ; i++){
               if(elem == nums[i]) cnt2++;
           }

           return cnt2 > n/2 ? elem : -1;
        }
    };