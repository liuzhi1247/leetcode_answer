LC121 -->   dp[i][0] = max(dp[i-1][0], -prices[i]);
            只能买卖一次
LC122 -->   dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            买卖次数无限制
LC123 -->   dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            只能买卖两次
LC188 -->   dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
            dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            只能买卖k次
LC309 -->   dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[2]);
            dp[2] = dp[0] + prices[i];
            含有冷冻期
LC714 -->   dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);
            含有手续费

