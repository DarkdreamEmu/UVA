#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#define max 500000000
using namespace std;

char s1[max];
char s2[max];

int convertBinaryToDecimal(char s[])
{
    stringstream ss(s);
    long long int n;
    ss>>n;
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int gcd(long long int a,long long int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main()
{
    int t,d=1;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        long long int r=convertBinaryToDecimal(s1);
        long long int r1=convertBinaryToDecimal(s2);
        long long int result=gcd(r,r1);
        if(result>1)
        {
            printf("Pair #%d: All you need is love!\n",d);

        }
        else
        {
            printf("Pair #%d: Love is not all you need!\n",d);
        }
        d++;
    }
    return 0;
}
