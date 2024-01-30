class Solution {
private :
    int findIndex(vector<vector<int>>& arr ,int n , int m , int col){
        int maxi = -1;
        int index = -1;

        for(int i =0; i<n ; i++){
            if(arr[i][col] > maxi){
                maxi = arr[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int s = 0 , e = m-1;

        while(s<=e){
            int mid = s + (e-s)/2;

            int maxRowIndex = findIndex(arr , n , m , mid);

            int left =  mid - 1 >= 0 ? arr[maxRowIndex][mid-1] : -1;
            int right = mid + 1 < m ? arr[maxRowIndex][mid+1] : -1;

            if(arr[maxRowIndex][mid] > left && arr[maxRowIndex][mid] > right){
                return {maxRowIndex , mid};
            }else if(arr[maxRowIndex][mid] < left) e = mid - 1;
            else s = mid + 1;

        }

        return {-1 , -1};
    }
};