
int findK(int A[],int alen,int B[],int blen,int K)
{
    assert(K<=alen+blen && K);
    if(alen == 0)return B[K-1];
    if(blen == 0) return A[K-1];
    if(K == 1)return min(A[0],B[0]);
    int subK = (K/2)*2==K?K/2:(K-1)/2;
    int asub,bsub;
    asub = min(subK,alen);
    bsub = min(subK,blen);
    if(A[asub-1] < B[bsub-1])
        return findK(A+asub,alen-asub,B,blen,K-asub);
    else return findK(A,alen,B+bsub,blen-bsub,K-bsub);
}