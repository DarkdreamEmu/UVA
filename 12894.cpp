#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int xo,yo,x1,y1,c1,c2,r;
        cin>>xo>>yo>>x1>>y1>>c1>>c2>>r;
        int l=x1-xo;
        int w=y1-yo;
        int dx = c1-xo, dy= c2-yo;
        if (l == r * 5 && w * 10 == l * 6 && dy * 2 == w && 20 * dx == l * 9)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
