class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 2) return 1;
        int prev = 1, cur = 1, temp = 0;
        n -= 3;
        while (n--) {
            temp = cur;
            cur += prev;
            prev = temp;
        }
        return cur;
    }
    
    int findMinFibonacciNumbers(int k) {
        int i = 1, output = 0;
        while (k > 3) {
            while (fib(i) <= k) i++;
            k -= fib(i - 1);
            i = 1;
            output++;
        }
        
        if (k > 0) output++;
        return output;
    }
};
