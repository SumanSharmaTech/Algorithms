//computes the longest prefix length for every i, which is equal to suffix of s[0...i] 
// ie finds largest L which gives s.substr(0,L) = s.substr(i-L+1,L) for each i;
//for each i, checks previous longest prefix ie p[i-1]
//then tries to extend it by 1, if not check for smaller prefix ie pi[pi[i-1]]
//try till it becomes possible to extend or the longest prefix becomes zero.
//O(n)
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int>freq_of_pref(string s) {
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    //pi contains only longest pref,
    //so it may be possible that the inside the longest pref there would be smaller ones
    for (int i = n - 1; i > 0; i--)
        ans[pi[i - 1]] += ans[i];
    //we didnt count pref itself, so add 1
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}

//A state is determined by pi and state changes when a character is added
//automaton computes all the possible transition from a given pi
//speeds up, s+#+t processes as pi value will be bound by s and automaton based on s will have every possible transition
//hence can compute every pi of s+#+t easily.
//O(26*|S|)
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i - 1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

//overflow assumed to be okay
//if not ok then only those periods which are factor the size of string are peoper periods

void all_possible_periods() {
    
    vi pref = prefix_function(s);
    int p = pref.back();
    //smallest |x|, if s = x+x+x....
    int period = s.size() - p;
    while (p != 0) {

        int k = period;
        cout << k << " ";
        p = pref[p - 1];
        period = s.size() - p;
    }
    cout << s.size();
}