#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
#define eps 1e-8
#define LL long long
#define mod 1000000007
#define mxn 50005
int n, m, T, t, cnt;
struct Team {
    string name;
    int solve, penalty;
    int ac_time[26];
    int submit_forzen[26]; 
    int submit_final[26];  
    int submit_valid[26];  
    bool ok_forzen[26];    
    bool ok_final[26];    
    int last[26];
    vector<int> pending;
    void init( string s ) {
        name = s;
        solve = penalty = 0;
        memset(submit_forzen, 0, m * 4);
        memset(submit_final, 0, m * 4);
        memset(submit_valid, 0, m * 4);
        memset(ok_forzen, 0, m);
        memset(ok_final, 0, m);
        memset(last, 0, m * 4);
        pending.clear();
    }
    bool operator < (const Team &b) const {
        if( solve > b.solve ) return true;
        if( solve < b.solve ) return false;
        if( penalty < b.penalty ) return true;
        if( penalty > b.penalty ) return false;
        for( int j = solve - 1; j >= 0; --j ) {
            if( last[j] < b.last[j] )
                return true;
            else if( last[j] > b.last[j] )
                return false;
        }
        return name > b.name;
    }
    void add( int id, int tim, int tp ) {
        if( ok_forzen[id] ) return ;
        if( ok_final[id] ) {
            if( tim < t ) return ;
            ++submit_final[id];
            return ;
        }
        if( tp == 0 ) {
            if( tim < t ) {
                ok_forzen[id] = true;
                ac_time[id] = tim;
                penalty += ac_time[id] + submit_valid[id] * 20;
                int j = solve++;
                last[j] = tim;
                while( j > 0 && last[j] < last[j-1] )
                    swap(last[j], last[j-1]), --j;
            }
            else {
                ok_final[id] = true;
                ac_time[id] = tim;
                ++submit_final[id];
            }
        }
        else if( tp == 1 ) {
            if( tim < t ) {
                ++submit_forzen[id];
                ++submit_valid[id];
            }
            else {
                ++submit_final[id];
                ++submit_valid[id];
            }
        }
        else {
            if( tim < t ) return ;
            else {
                ++submit_final[id];
            }
        }
    }
    void relax() {
        int id = pending.back();
        if( ok_final[id] ) {
            penalty += ac_time[id] + submit_valid[id] * 20;
            int j = solve++;
            last[j] = ac_time[id];
            while( j > 0 && last[j] < last[j-1] )
                swap(last[j], last[j-1]), --j;
        }
        pending.pop_back();
    }
    void forzen() {
        for( int i = m - 1; i >= 0; --i )
            if( submit_final[i] )
                pending.push_back(i);
    }
}p[mxn];
struct Submit {
    int team_id, problem_id, submit_time;
    int tp; //0: Yes    1: No    2: Errors
    bool operator < (const Submit &b) const {
        return submit_time < b.submit_time || submit_time == b.submit_time && tp > b.tp;
    }
}Sub[mxn];
struct Index {
    int id;
    Index(){}
    Index(int id):id(id) {}
    bool operator < (const Index &b) const {
        return p[id] < p[b.id];
    }
}idx[mxn];
map<string, int> mp;
set<Index> st;
void Forzen() {
    st.clear();
    for( int i = 1; i <= cnt; ++i )
        st.insert(Index(i));
    int rank = 0;
    for( set<Index>::iterator it = st.begin(); it != st.end(); ++it ) {
        Team &k = p[it->id];
        printf( "%s %d %d %d", k.name.c_str(), ++rank, k.solve, k.penalty );
        for( int i = 0; i < m; ++i ) {
            if( k.ok_forzen[i] ) {
                if( k.submit_valid[i] == 0 )
                    printf( " +" );
                else printf( " +%d", k.submit_valid[i] );
            }
            else if( k.submit_final[i] ) {
                if( k.submit_forzen[i] == 0 )
                    printf( " 0/%d", k.submit_final[i] );
                else printf( " -%d/%d", k.submit_forzen[i], k.submit_final[i] );
            }
            else if( k.submit_forzen[i] )
                printf( " -%d", k.submit_forzen[i] );
            else printf( " ." );
        }
        puts( "" );
    }
}
void Update() {
    for( int i = 1; i <= cnt; ++i )
        p[i].forzen();
    while( st.size() ) {
        set<Index>::iterator it = st.end();
        --it;
        Team &k = p[it->id];
        Index nxt = Index(it->id);
        st.erase(it);
        if( k.pending.size() == 0 ) continue;
        k.relax();
        set<Index>::iterator fit = st.upper_bound(nxt);
        if( fit != st.end() ) {
            printf( "%s %s %d %d\n", k.name.c_str(), p[fit->id].name.c_str(), k.solve, k.penalty );
        }
        st.insert(fit, nxt);
    }
}
void Final() {
    for( int i = 1; i <= cnt; ++i ) idx[i].id = i;
    sort(idx + 1, idx + cnt + 1);
    for( int j = 1; j <= cnt; ++j ) {
        Team &k = p[idx[j].id];
        printf( "%s %d %d %d", k.name.c_str(), j, k.solve, k.penalty );
        for( int i = 0; i < m; ++i ) {
            if( k.ok_forzen[i] || k.ok_final[i] ) {
                if( k.submit_valid[i] == 0 )
                    printf( " +" );
                else printf( " +%d", k.submit_valid[i] );
            }
            else if( k.submit_valid[i] )
                printf( " -%d", k.submit_valid[i] );
            else printf( " ." );
        }
        puts( "" );
    }
}
int cal( char c ) {
    if( c == 'Y' ) return 0;
    if( c == 'N' ) return 1;
    return 2;
}
int main()
{
    int tes, cas = 0, cur_time;
    char sname[50], pro[10], ret[10];
    scanf( "%d", &tes );
    while( tes-- ) {
        cnt = 0; mp.clear();
        scanf( "%d%d%d%d", &n, &m, &T, &t );
        for( int i = 0; i < n; ++i ) {
            scanf( "%s%s%d%s", sname, pro, &cur_time, ret );
            string s = sname;
            if( !mp.count(s) ) {
                mp[s] = ++cnt;
                p[cnt].init(s);
                Sub[i].team_id = cnt;
            }
            else Sub[i].team_id = mp[s];
            Sub[i].problem_id = pro[0] - 'A';
            Sub[i].submit_time = cur_time;
            Sub[i].tp = cal(ret[0]);
        }
        sort(Sub, Sub + n);
        for( int i = 0; i < n; ++i )
            p[Sub[i].team_id].add(Sub[i].problem_id, Sub[i].submit_time, Sub[i].tp);
        printf( "Case #%d:\n", ++cas );
        Forzen();
        Update();
        Final();
    }
    return 0;
}
