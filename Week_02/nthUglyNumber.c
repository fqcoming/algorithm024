
// 1是丑数,除1之外正整数中只包含质因数2,3,5且至少包含其中一个质因数的正整数是丑数

int min(int a, int b, int c){
    int min = a;
    if(b<min) min = b;
    if(c<min) min = c;
    return min;
}

int nthUglyNumber(int n){
    int *dp = (int *)malloc(sizeof(int)*n);
    memset(dp, 0, sizeof(int)*n);
    dp[0] = 1;

    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    int i;
    for(i=1; i<n; i++){
        dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5);
        if(dp[i]==dp[i2]*2) i2++;
        if(dp[i]==dp[i3]*3) i3++;
        if(dp[i]==dp[i5]*5) i5++;
    }
    return dp[n-1];
}