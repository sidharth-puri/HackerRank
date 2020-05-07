int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,max,x;
        scanf("%d",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        max=0;
        for(int i=0;i<n;i++)
        {  
            x=20*a[i]-10*b[i];
            if(x>max)
                max=x;
        }
        printf("%d \n",max);
    }

    return 0;
}
