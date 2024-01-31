class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int mid;

        while(s<=e){
            mid = s + (e-s)/2;
            if(arr[mid] == target) return true;

            if(arr[s] == arr[mid] && arr[mid] == arr[e]){
                s = s + 1;
                e = e - 1;
                continue;
            }


            if(arr[s] <= arr[mid]){
                if(arr[s] <= target && target < arr[mid]){
                    e = mid -1;
                }else s = mid + 1;
            }else{
                if(arr[e] >= target && target > arr[mid]){
                   s = mid + 1;
                }else e = mid -1;
            }
        }


        return false;

    }
};