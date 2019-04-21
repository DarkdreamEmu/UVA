#include<stdio.h>
#include<math.h>

int main()
{
    double vit,volume;
    int l,f;
    while(1)
    {
       scanf("%d %d",&l,&f);
       if(l==0&& f==0)
            break;
       vit=sqrt(l*f*2.0);
       volume=(vit*3600.0)/(2.0*l);
       printf("%0.8lf %0.8lf\n",vit,volume);
       }

       return 0;
}
