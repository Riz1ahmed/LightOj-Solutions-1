/*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/
 
#include<bits/stdc++.h>
 
#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
 
typedef long long ll;
typedef unsigned long long llu;
 
using namespace std;
 
 
template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);
 
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
 
template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}
 
template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}
 
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
 
 
template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}
 
/******* ! Code start from here ! *******/
 
 
vector<pair<int,int> >lst[30];
int cnt[30][2]; 
int mark[1003];
string kp[1004];
stack<pair<int,int> >st1,st2;
int c,d,n;

void clear_all(){	
    fill(lst,lst+30,vector<pair<int,int> >() );
    reset(mark,0); 
    reset(cnt,0);
    c=0,d=0;

    while(!st1.empty())
    	st1.pop();

    while(!st2.empty())
    	st2.pop();
}

void input(){
    in(n);	 
    for(int i=0;i<n;i++)
    {
        cin>>kp[i];
    }

}
 
void dfs(int nod,int id)
{ 
    for(int j=0;j<sz(lst[nod]);j++)
    {

    	pair<int,int>i=lst[nod][j];
        if(!mark[i.S])
        {
            mark[i.S]=1;

            st1.push(mp(nod,id) );
 
            dfs(i.F,i.S);
            return;
        }
    }

    st2.push(mp(nod,id) );

    if(!st1.empty() ){
    	pair<int,int> cr=st1.top();
    	st1.pop();
    	dfs(cr.F,cr.S);

    }


}
 
int main()
{
//     std::ios_base::sync_with_stdio(false);
//  freopen ( "in.txt", "r", stdin );   freopen ( "out.txt", "w", stdout );
    #ifdef kimbbakar
       
     
    #endif
 
    int t,tcase=1;
 
    in(t);
    string s;
 
    while(t--)
    {
 		clear_all();
 		input();

 
        int idx=0;
        for(int i=0;i<n;i++)
        {
            idx=kp[i][0]-'a';
            cnt[kp[i][0]-'a'][0]++;
            cnt[kp[i][sz(kp[i])-1 ]-'a'][1]++;

           lst[kp[i][0] -'a' ].pb(mp(kp[i][sz(kp[i])-1 ]-'a',i ) );
 
        }
 
        bool ok=true;
 
        for(int i=0;i<26 && ok;i++)
        {
            if( cnt[i][0] -cnt[i][1]==1 )
            {
                idx=i;
                c++;
            }
            else if( cnt[i][1] -cnt[i][0]==1 )
            {
                d++;
            }
            else if(cnt[i][1] -cnt[i][0]>1 || cnt[i][0] -cnt[i][1]>1)
            	ok=false;
 
             //  pf("%d %d %c\n",cnt[i][0] ,cnt[i][1],i+'a');
 
            if(c>1 || d>1)
                ok=false;
        } //what_is(ok)
 
        pf("Case %d: ",tcase++);
 
        if(!ok)
            pf("No\n");
        else
        {
            dfs(idx,-1);

            if(sz(st2)-1!=n){
            	pf("No\n");
            	continue;
            }


            pf("Yes\n");
 			
 			st2.pop();
            while(!st2.empty() ){
            	cout<<kp[st2.top().S ];
            	st2.pop();

            	if(sz(st2))
            		pf(" ");
            }
            pf("\n");
        }
    }
 
 
    return 0;
}
 
 