class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        long long common = min(need1, need2);
        long long extra1 = need1 - common;
        long long extra2 = need2 - common;

        // For common items, choose between one bundle and two separate items.
        long long commonCost = min(1LL * costBoth,
                                   1LL * cost1 + cost2);

        // For extra items, a bundle can still be useful because the unused item
        // is allowed, so compare the bundle price with the separate price.
        long long extra1Cost = min(1LL * cost1, 1LL * costBoth);
        long long extra2Cost = min(1LL * cost2, 1LL * costBoth);

        return common * commonCost
             + extra1 * extra1Cost
             + extra2 * extra2Cost;
    }
};