vector<int> prefixFunction(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j && s[j] != s[i])
            j = pi[j-1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}