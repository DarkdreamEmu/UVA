#include <stdio.h>


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int L,R,S;
        scanf("%d %d %d",&L,&R,&S);
        int A[100010],B[100010],C[100010],ALL[100010];
        int X1=0,X2=0,Y1=0,Y2=0,Z1=0,Z2=0;
        int ind=0,num,i;
        int take[101001];
        for(i=0; i<=100011; i++){
            A[i]=0,B[i]=0,C[i]=0,ALL[i]=0;
        }
        for(i=0; i<L; i++){
            scanf("%d",&num);
            A[num]=1;
            if(!ALL[num]){ALL[num]=1;take[ind++]=num;};
        }
        for(i=0; i<R; i++){
            scanf("%d",&num);
            B[num]=1;
            if(!ALL[num]){ALL[num]=1;take[ind++]=num;};
        }
        for(i=0; i<S; i++){
            scanf("%d",&num);
            C[num]=1;
            if(!ALL[num]){ALL[num]=1;take[ind++]=num;};
        }
        for(i=0; i<ind; i++){
            num=take[i];
            if(A[num]&&(!B[num]&&!C[num]))X1++;
            if(!A[num]&&(B[num]&&C[num]))X2++;
            if(B[num]&&(!A[num]&&!C[num]))Y1++;
            if(!B[num]&&(A[num]&&C[num]))Y2++;
            if(C[num]&&(!B[num]&&!A[num]))Z1++;
            if(!C[num]&&(B[num]&&A[num]))Z2++;
        }
        printf("Case #%d:\n",cs++);
        printf("%d %d\n",X1,X2);
        printf("%d %d\n",Y1,Y2);
        printf("%d %d\n",Z1,Z2);
    }
    return 0;
}
