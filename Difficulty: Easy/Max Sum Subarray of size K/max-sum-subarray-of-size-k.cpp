class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int sum = 0;
        // first window
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        int maxi = sum;

        // remaining windows
        for(int i = k; i < n; i++) {
            sum += arr[i];        // add next element
            sum -= arr[i - k];    // remove previous element
            maxi = max(maxi, sum);
        }

        return maxi;
        
    }
};