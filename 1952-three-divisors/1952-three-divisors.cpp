class Solution {
public:
    bool isThree(int n) {
        if(n == 1) return false;
        return int(sqrt(n)) * int(sqrt(n)) == n && is_prime(sqrt(n));
        
    }
    bool is_prime(int x){
        for(int i = 2; i < x/2 + 1; i++){
            if(x % i == 0) return false;
        }
        return true;
    }
};