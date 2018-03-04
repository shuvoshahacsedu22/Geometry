#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define mx 1000005


ll area(ll x1,ll yy,ll x2,ll y2,ll x3,ll y3)
{

    ll temp=0;
    temp = (x1*y2+x2*y3+x3*yy)-(yy*x2+y2*x3+y3*x1);
    return temp;
}
double dis(ll a,ll b,ll c,ll d)
{

    return sqrt( (a-c)*(a-c) +  (b-d)*(b-d) );
}



bool online(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4)
{

    double ac,cb,ab;

    ac=dis(x1,y1,x3,y3);
    cb=dis(x3,y3,x2,y2);
    ab=dis(x1,y1,x2,y2);
    if(abs(ac+cb-ab)<=0.000001) return true;


    ac=dis(x1,y1,x4,y4);
    cb=dis(x4,y4,x2,y2);
    ab=dis(x1,y1,x2,y2);
    if(abs(ac+cb-ab)<=0.000001) return true;



    ac=dis(x3,y3,x1,y1);
    cb=dis(x1,y1,x4,y4);
    ab=dis(x3,y3,x4,y4);
    if(abs(ac+cb-ab)<=0.000001) return true;


    ac=dis(x3,y3,x2,y2);
    cb=dis(x2,y2,x4,y4);
    ab=dis(x3,y3,x4,y4);
    if(abs(ac+cb-ab)<=0.000001) return true;

    return false;
}

bool onSegment(ll x1,ll y1,ll x2,ll y2, ll x3,ll y3,ll x4,ll y4)
{

    ll A1=area(x1,y1,x2,y2,x3,y3);
    ll A2=area(x1,y1,x2,y2,x4,y4);

    ll B1=area(x3,y3,x4,y4,x1,y1);
    ll B2=area(x3,y3,x4,y4,x2,y2);

    if(A1==0 || A2==0 || B1==0 || B2==0)
    {

        if( online(x1,y1,x2,y2,x3,y3,x4,y4) )return true;
        return false;
    }
    else
    {

        if(A1*A2 > 0  || B1*B2 > 0) return false;
        else return true;

    }

}

int main()
{

    ll tc,x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>tc;

    while(tc--)
    {

        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if( onSegment(x1,y1,x2,y2,x3,y3,x4,y4) ) cout<<1<<endl;
        else cout<<0<<endl;

    }

    return 0;
}
