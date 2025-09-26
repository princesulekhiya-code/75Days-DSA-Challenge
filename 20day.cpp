// 509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

// 50. Pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result *= x;
            x *= x;
            exp /= 2;
        }
        return result;
    }
};

// 1071. Greatest Common Divisor of Strings
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
