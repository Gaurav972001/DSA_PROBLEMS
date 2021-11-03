class Trie
{
public:
    bool is_word = false;
    Trie *children[26] = {NULL};
};
class Solution
{
private:
    Trie *root = NULL;
    int dp[301];
    void insert(string &s)
    {
        Trie *temp = root;
        for (auto &i : s)
        {
            int k = i - 'a';
            if (temp->children[k] == NULL)
            {
                temp->children[k] = new Trie;
            }
            temp = temp->children[k];
        }
        temp->is_word = true;
    }

    bool search(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!(temp->children[s[i] - 'a']))
            {
                return false;
            }
            temp = temp->children[s[i] - 'a'];
        }
        if (temp != NULL && temp->is_word)
            return true;
        return false;
    }
    bool helper(string s, int pos)
    {
        if (pos == s.size())
            return true;
        if (dp[pos] != -1)
            return dp[pos];

        string t = "";
        for (int i = pos; i < s.size(); ++i)
            if (search(s.substr(pos, i - pos + 1)) and helper(s, i + 1))
                return dp[pos] = true;
        return dp[pos] = false;
    }

public:
    bool wordBreak(string s, vector<string> &words)
    {
        root = new Trie;
        for (auto &s : words)
            insert(s);
        memset(dp, -1, sizeof dp);
        return helper(s, 0);
    }
};