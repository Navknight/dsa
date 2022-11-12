class Solution
{
public:
    map<int, int> a{{1, 1}, {2, 2}};
    int climbStairs(int n)
    {
        if (n == 1)
            return a[1];
        else if (n == 2)
            return a[2];
        else
        {
            int value = a[n];
            if (value == NULL)
            {
                value = climbStairs(n - 1) + climbStairs(n - 2);
                a[n] = value;
                return value;
            }
            else
            {
                return value;
            }
        }
    }
};