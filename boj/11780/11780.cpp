// https://www.acmicpc.net/problem/11780
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

#include <iostream>
using namespace std;

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

#ifndef LOCAL
#    include <bits/stdc++.h>
#    include <sys/mman.h>
#    include <sys/stat.h>
constexpr int INPUT_SZ  = 3200000;
constexpr int OUTPUT_SZ = 1 << 16;

class INPUT {
private:
    char* p;
    bool  __END_FLAG__, __GETLINE_FLAG__;

public:
    explicit operator bool() { return !__END_FLAG__; }
    INPUT() { p = (char*)mmap(0, INPUT_SZ, PROT_READ, MAP_SHARED, 0, 0); }
    bool is_blank(char c) { return c == ' ' || c == '\n'; }
    bool is_end(char c) { return c == '\0'; }
    char _readChar() { return *p++; }
    char readChar() {
        char ret = _readChar();
        while (is_blank(ret)) {
            ret = _readChar();
        }
        return ret;
    }
    template<typename T>
    T readInt() {
        T    ret  = 0;
        char cur  = _readChar();
        bool flag = 0;
        while (is_blank(cur)) {
            cur = _readChar();
        }
        if (cur == '-') {
            flag = 1, cur = _readChar();
        }
        while (!is_blank(cur) && !is_end(cur)) {
            ret = 10 * ret + cur - '0', cur = _readChar();
        }
        if (is_end(cur)) {
            __END_FLAG__ = 1;
        }
        return flag ? -ret : ret;
    }
    string readString() {
        string ret;
        char   cur = _readChar();
        while (is_blank(cur)) {
            cur = _readChar();
        }
        while (!is_blank(cur) && !is_end(cur)) {
            ret.push_back(cur), cur = _readChar();
        }
        if (is_end(cur)) {
            __END_FLAG__ = 1;
        }
        return ret;
    }
    double readDouble() {
        string ret = readString();
        return stod(ret);
    }
    string getline() {
        string ret;
        char   cur = _readChar();
        while (cur != '\n' && !is_end(cur)) {
            ret.push_back(cur), cur = _readChar();
        }
        if (__GETLINE_FLAG__) {
            __END_FLAG__ = 1;
        }
        if (is_end(cur)) {
            __GETLINE_FLAG__ = 1;
        }
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) {
        s = in.getline();
        return in;
    }
} _in;

class OUTPUT {
private:
    char write_buf[OUTPUT_SZ];
    int  write_idx;

public:
    ~OUTPUT() { bflush(); }
    void bflush() {
        fwrite(write_buf, sizeof(char), write_idx, stdout);
        write_idx = 0;
    }
    void writeChar(char c) {
        if (write_idx == OUTPUT_SZ) {
            bflush();
        }
        write_buf[write_idx++] = c;
    }
    template<typename T>
    int getSize(T n) {
        int ret = 1;
        if (n < 0) {
            n = -n;
        }
        while (n >= 10) {
            ret++, n /= 10;
        }
        return ret;
    }
    template<typename T>
    void writeInt(T n) {
        int sz = getSize(n);
        if (write_idx + sz >= OUTPUT_SZ) {
            bflush();
        }
        if (n < 0) {
            write_buf[write_idx++] = '-', n = -n;
        }
        for (int i = sz - 1; i >= 0; i--) {
            write_buf[write_idx + i] = n % 10 + '0', n /= 10;
        }
        write_idx += sz;
    }
    void writeString(string s) {
        for (auto& c: s) {
            writeChar(c);
        }
    }
    void writeDouble(double d) { writeString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>>(INPUT& in, char& i) {
    i = in.readChar();
    return in;
}
INPUT& operator>>(INPUT& in, string& i) {
    i = in.readString();
    return in;
}
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
INPUT& operator>>(INPUT& in, T& i) {
    i = in.readInt<T>();
    return in;
}
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
INPUT& operator>>(INPUT& in, T& i) {
    i = in.readDouble();
    return in;
}
OUTPUT& operator<<(OUTPUT& out, char i) {
    out.writeChar(i);
    return out;
}
OUTPUT& operator<<(OUTPUT& out, string i) {
    out.writeString(i);
    return out;
}
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
OUTPUT& operator<<(OUTPUT& out, T i) {
    out.writeInt<T>(i);
    return out;
}
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
OUTPUT& operator<<(OUTPUT& out, T i) {
    out.writeDouble(i);
    return out;
}

/* macros */
#    define cin     _in
#    define cout    _out
#    define istream INPUT
#    define ostream OUTPUT
#endif

#define fastio 1
//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main() {
    fastio;

    //   logic
    int n, m;
    cin >> n >> m;

    vector<vector<ll>>  dist(n + 1, vector<ll>(n + 1, __MAX));
    vector<vector<int>> succsessor(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (dist[a][b] > c) {
            dist[a][b]       = c;
            succsessor[a][b] = b;
        }
    }

    for (int i = 1; i <= n; ++i) {
        dist[i][i]       = 0;
        succsessor[i][i] = 0;
    }

    // -----

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i][k] == __MAX) {
                continue;
            }

            for (int j = 1; j <= n; ++j) {
                if (dist[k][j] == __MAX) {
                    continue;
                }

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j]       = dist[i][k] + dist[k][j];
                    succsessor[i][j] = succsessor[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == __MAX) {
                cout << "0\n";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == __MAX || i == j) {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int         cur = i;

            path.push_back(cur);

            while (cur != j) {
                cur = succsessor[cur][j];
                path.push_back(cur);
            }

            cout << path.size() << " ";

            for (const auto& e: path) {
                cout << e << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
