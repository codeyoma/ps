#include <string>
#include <vector>

using namespace std;

vector<int> make_table(const string& pattern) {
    vector<int> table(pattern.size(), 0);
    int         j = 0;

    for (int i = 1; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(const string& s, const string& pattern) {
    vector<int> table        = make_table(pattern);
    int         s_size       = s.size();
    int         pattern_size = pattern.size();
    int         j            = 0;

    for (int i = 0; i < s_size; ++i) {
        while (j > 0 && s[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (s[i] == pattern[j]) {
            if (j == pattern_size - 1) {
                j = table[j];
                // i - pattern_size 에서 매칭
                // or i - j
            } else {
                ++j;
            }
        }
    }
}