#include <bits/stdc++.h>
#define en '\n'
#define f first
//#define s second
#define mp make_pair
#define  isz(x) int((x).size())
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sortlargetosmall(x) sort(all(x), greater<>())
#define sortsmalltolarge(x) sort(all(x), less<>())
#define fin(x) for (auto &it: x) cin >> it
#define fout(x) for (auto &it: x) cout << it << ' '; cout << en
#define cno cout << "NO" << en
#define cyes cout << "YES" << en
#define PI acos(-1.0L)
#define fac(x, col) for(auto x: col)
#define facl(x, col) for(auto &x: col)
#define forn(start, end) for(int i = 0; i < end; ++i)
#define cmo cout << -1 << en
#define ifyn(x) x ? cyes : cno
#define xout(x) cout << x << en
#define xin(x) cin >> x
#define nline cout << en


#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__
// ---- ---- ---- ---- ---- ---- DEBUG LIBRARY ---- ---- ---- ---- ---- ----
#define watch(...) debug && std::cerr << "{" << #__VA_ARGS__ << "} = " \
    << std::make_tuple(__VA_ARGS__) << std::endl

template<typename... X>
std::ostream& operator<<(std::ostream& os, const std::pair<X...>& p)
{ return os << std::make_tuple(std::get<0>(p), std::get<1>(p)); }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_each_const(const std::tuple<Tp...> &, FuncT) { }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_each_const(const std::tuple<Tp...>& t, FuncT f)
{ f(std::get<I>(t)),for_each_const<I + 1, FuncT, Tp...>(t, f); }


template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_each(std::tuple<Tp...> &, FuncT) { }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_each(std::tuple<Tp...>& t, FuncT f)
{ f(std::get<I>(t)); for_each<I + 1, FuncT, Tp...>(t, f); }

struct Printer {
    std::ostream& os; bool was{0};
    Printer(std::ostream& os_) : os(os_) { }
    template<typename X> void operator()(X x)
    { os << (was?", ":(was=1,"")) << x; }
};

template<typename... X>
std::ostream& operator<<(std::ostream& os, const std::tuple<X...>& t)
{ return os << "{", for_each_const(t, Printer(os)), os << "}"; }

template<typename Iterator>
std::ostream& print(std::ostream& os, Iterator begin, Iterator end)
{ return os << "{", std::for_each(begin,end,Printer(os)), os << "}"; }

#define OUTPUT(container) template<typename X, typename... T>           \
std::ostream& operator<<(std::ostream& os, const container<X,T...>& c)  \
{ return print(os, all(c)); }
OUTPUT(std::vector) OUTPUT(std::list) OUTPUT(std::deque)
OUTPUT(std::set) OUTPUT(std::unordered_set)
OUTPUT(std::multiset) OUTPUT(std::unordered_multiset)
OUTPUT(std::map) OUTPUT(std::multimap) OUTPUT(std::unordered_map)
#undef RANGE_OUTPUT

#define OUTPUT2(container, get, pop) template<typename X, typename... T> \
std::ostream& operator<<(std::ostream& os, container<X,T...> c) {       \
    std::vector<X> v(c.size());                                         \
    for (unsigned i = 0; i != v.size(); v[i++] = c.get(),c.pop());      \
    return os << v; }
OUTPUT2(std::queue,front,pop)
OUTPUT2(std::stack,top,pop)
OUTPUT2(std::priority_queue,top,pop)
#undef OUTPUT

const int debug = 1;
#endif // __DEBUG_HPP__

using namespace std;


using ll =  long long;
using ld  = long double;
using i64 = int64_t;
using i32 = int32_t;
using str = string;
// pairs
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
using V = vector<T>;
using vi = V<int>;
using vl = V<ll>;
using vpii = V<pii>;
using vpll = V<pll>;
using vb = V<bool>;
using vc = V<char>;
using vs = V<string>;
using vld = V<ld>;

using vvc = V<vc>;
using vvb = V<vb>;
using vvi = V<vi>;
using vvl = V<vl>;
using vvs = V<vs>;
using vvpii = V<vpii>;
using vvpll = V<vpll>;
using vvld = V<vld>;

using vvvi = V<vvi>;
using vvvl = V<vvl>;

using ull = unsigned long long;

using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

i32 main() {

    cin.tie(0); ios_base::sync_with_stdio(false);

    int nVertex, nEdges;
    cin >> nVertex >> nEdges;

    const int inf = 1e9;

    vvi vLen (nVertex + 1, vi (nVertex + 1, inf));


    for (int curVertex = 1; curVertex <= nVertex; ++curVertex) {
        vLen[curVertex][curVertex] = 0;
    }


    for (int curEdges = 0; curEdges < nEdges; ++curEdges) {
        int u, v, len;
        cin >> u >> v >> len;
        vLen[u][v] = len;
    }

    vvi vPred(nVertex + 1, vi (nVertex + 1));

    for (int i = 1; i <= nVertex; ++i) {
        for (int j = 1; j <= nVertex; ++j) {
            vPred[i][j] = j;
        }
    }
    // floyd
    for (int k = 1; k <= nVertex ; ++k)  {
        {for (int i = 1; i <= nVertex; ++i)
            { for (int j = 1; j <= nVertex ; ++j)
                if (vLen[i][k] < inf && vLen[k][j] < inf) {
                    if ( vLen[i][k] + vLen[k][j] < vLen[i][j]) {
                        vLen[i][j] = vLen[i][k] + vLen[k][j];
                        vPred[i][j] = vPred[i][k];
                    }
                }
            }
        }
    }
    // find negative loop
    for (int i = 1; i <= nVertex; ++i) {
        for (int j = 1; j <= nVertex ; ++j) {
            for (int k = 1; k <= nVertex ; ++k) {
                if (vLen[i][k] < inf && vLen[k][k] < 0 && vLen[k][j] < inf)
                    vLen[i][j] = -inf;
            }
        }
    }

    cout << "D:" << en;
    for (int i = 1; i <= nVertex; ++i) {
        for (int j = 1; j <= nVertex; ++j) {
            if (vLen[i][j] == inf) {
                cout << "INF";
            }
            else if (vLen[i][j] == -inf) {
                cout << "-INF";
            }
            else
            cout << vLen[i][j];
            cout << " ";
        }
        nline;
    }
    nline;
    cout << "T:" << en;
    for (int i = 1; i <= nVertex; ++i) {
        for (int j = 1; j <= nVertex; ++j) {
            cout << vPred[i][j] << ' ';
        }
        nline;
    }
    nline;
    string go = " -> ";
    for (int i = 1; i <=nVertex ; ++i) {
        for (int j = 1; j <=nVertex ; ++j) {
            if (i == j || vLen[i][j] == inf || vLen[i][j] == -inf) continue;
            cout << i << go;
            int u = i, v = j;
            while(vPred[u][v] != v) {
                cout << vPred[u][v] << go;
                u = vPred[u][v];
            }
            cout << j << " (" << vLen[i][j] << ')';
            nline;
        }
    }

    return 0;
}
