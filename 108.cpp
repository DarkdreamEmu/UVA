#include <bits/stdc++.h>
using namespace std;

int maxSumSubMatrix (int mat[][100], int rows, int columns )
{
    int L=0,R=0,
        maxCurrentSum=0, maxSum=0,
        left=0,right=0,up=0,down=0;  // sub matrix indexes

    for(L=0 ; L < columns ; L++ )
    {
        // temp Array A
        int A[rows];
        for (int i=0 ; i< rows ; i++)
            A[i]=0;

        for(R=L ; R < columns ; R++ )
        {

            // Add mat[][R] in A[]
            for (int i=0 ; i < rows ; i++)
                A[i] = A[i] + mat[i][R];

            // find max. sum sub array
            int temp=0,maxEnd, maxStart, currentStart;
            maxCurrentSum = 0;

            for(int j=0; j<rows ; j++)
            {
                temp  = temp + A[j];
                if(temp < 0)
                {
                    temp=0;
                    currentStart=j+1;
                }

                if(temp > maxCurrentSum)
                {
                    maxCurrentSum=temp;
                    maxEnd=j;
                    maxStart=currentStart;
                }
            }

            if (maxCurrentSum > maxSum)
            {
                maxSum = maxCurrentSum;
                left=L;
                right=R;
                up=maxStart;
                down=maxEnd;
            }
        }
    }
    return maxSum;
}

int main()
{
    int n;
    int matrix[100][100];
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        int ans=maxSumSubMatrix(matrix,n,n);
        if(ans>0)
        {
             printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
