int climbStairs(int n) {
    if (n == 0 || n == 1)
        return 1;

    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;  // DP: ways(n) = ways(n-1) + ways(n-2)
        a = b;
        b = c;
    }
    return b;
}