//序列1，-1，2，-3，4，-5，6，-7中，最长递增子序列长度为4，可以是1，2，4，6，也可以是-1，2，4，6。
//solution:DP
int LIS(int * arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > lis)
                {
                    lis = dp[i];
                }
            }
        }
    }
    return lis;
}