
const int K = 26;
struct Vertext
{
    int next[K];
    bool leaf = false;
    Vertext()
    {
        memset(next, -1, sizeof next);
    }
};
vector<Vertext> trie(1);
void addString(string x)
{
    int index = 0;
    for(char c: x)
    {
        if (!~trie[index].next[c - 'a'])
        {
            trie[index].next[c-'a'] = trie.size();
            trie.push_back(Vertext());
        }
        index = trie[index].next[c - 'a'];
    }
    trie[index].leaf = 1;
}
int addToLastSting(char c, int index = 0)
{
    if (!~trie[index].next[c - 'a'])
    {
        trie[index].next[c-'a'] = trie.size();
        trie.push_back(Vertext());
    }
    index = trie[index].next[c - 'a'];
    trie[index].leaf = 1;
    return index;
}