void MakeNext(int* P,int M,int* Next){
    Next[0] = -1;
    int i = 0, j = -1;
    while(i<M){
        if(j==-1||P[i]==P[j]){
            i++,j++;
            if(P[i]!=P[j])Next[i] = j;
            else Next[i] = Next[j];
        }
        else j = Next[j];
    }
}
int KMP(int* T,int N,int* P,int M)
{
    MakeNext(P,M,Next);
    int i=0,j=0;
    while(i<N&&j<M){
        if(T[i]==P[j]||j==-1)i++,j++;
        else j = Next[j];
    }
    if(j==M)return i-M;
    else return -2;
}
