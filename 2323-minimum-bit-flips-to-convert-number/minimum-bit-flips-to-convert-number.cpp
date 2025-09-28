class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long x=start^goal;

        long long count=0;

        while(x>0)
        {
            if(x&1) count++;

            x=x>>1;
        }

        return count;
    }
};