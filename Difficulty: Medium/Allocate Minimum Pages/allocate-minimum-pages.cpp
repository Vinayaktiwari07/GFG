class Solution {
  public:
    bool isPossibleSolution(vector<int> &arr, int n, int k, int sol){
        int pageSum = 0;
        int count = 1;
        for(int i=0; i<n;i++){
            if(arr[i] > sol){
                return false;
            }
            if(pageSum + arr[i] > sol){
                count++;
                pageSum = arr[i];
                if(count > k){
                    return false;
                }
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k>n) return -1;
        
        int start = 0;
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossibleSolution(arr, n, k, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
        
    }
};