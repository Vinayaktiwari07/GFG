class Solution {
  public:
    int powMod(int x, int n, int M) {
        long long int ans = 1;
        while(n>0){
            if(n & 1){
                ans = (ans * x) % M;
            }
            x = (1LL * x * x) % M;
            n >>= 1;
        }
        return ans % M;
        
    }
};