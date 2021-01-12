//Sum of elements between k1'th and k2'th smallest elements,, implemented using heaps

long long kthSmallest(long long arr[],long long n,long long k)
{
    priority_queue<long long>q1;
    for(long long i=0;i<n;i++)
    {
        q1.push(arr[i]);
        if(q1.size()>k)
        q1.pop();
    }
    return q1.top();
}

long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
{
    // Your code goes here
    long long sum=0,k2small=LONG_MAX,k1small=LONG_MIN;
    if(k1>k2)
    return sum;
    if(k1<n)
    k1small=kthSmallest(a,n,k1);
    if(k2<n)
    k2small=kthSmallest(a,n,k2);
    
    for(long long i=0;i<n;i++)
    {
        if(a[i]>=k1small && a[i]<=k2small)
        sum+=a[i];
    }    
    sum=sum-k1small-k2small;
    return sum;
}
