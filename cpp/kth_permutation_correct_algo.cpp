class Solution {
public:

    int factoria(int x)
    {
        if (x < 0)
        {
            return -1;
        }
        if (x == 0)
        {
            return 1;
        }
        return x*factoria(x - 1);
    }
    
    string kMinusOneThPerm(string s, int k)
    {
        if (k == 0)
        {
            return s;
        }
        int fact = factoria(s.length() - 1);
        int firstCharPos = k / fact;
        int subOrderK = k % fact;
        
        return s[firstCharPos] + kMinusOneThPerm(s.substr(0, firstCharPos)
            + s.substr(firstCharPos + 1), subOrderK);
    }
    
    string getPermutation(int n, int k) {
        if (k < 1)
        {
            return "";
        }
        string ns = "";
        for (int i = 0; i < n; ++i)
        {
            ns += to_string(i + 1);
        }
        if (k == 1)
        {
            return ns;
        }
        return kMinusOneThPerm(ns, k - 1);
    }
};