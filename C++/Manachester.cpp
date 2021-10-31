//O(N)
//eg aababa , pal_array is 1 1 2 3 2 1, 
//basically ceil(length of pal/2) keeping i as center of palindrome
vector<int> pal_array(string s)
{
    int n = s.size();
    s = "@" + s + "$";
    vector<int> len(n + 1);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        len[i] = min(r - i, len[l + (r - i)]);
        while (s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if (i + len[i] > r)
        {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(begin(len));
    return len;
}

//longest palindrome in O(N)
void solve() {

    string s;
    cin >> s;
    string s2 = "#";
    rep(i, 0, s.size())s2.pb(s[i]), s2 += "#";
    vi arr = pal_array(s2);
    int mxe = 0, mxep;
    rep(i, 0, arr.size())if (arr[i] > mxe)mxe = arr[i], mxep = i;

    string ans = s2.substr(mxep - mxe + 1, 2 * mxe - 1);
    for (char c : ans)if (c != '#')cout << c;

}