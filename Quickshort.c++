#include<iostream>
using namespace std ;

int getpivotindex(int a[] , int s , int e)
{
    int pivot = a[s];
    int cnt = 0;

    for(int i=s+1 ; i<=e ; i++)
    {
        if(a[i] <= pivot)
        {
            cnt ++ ;
        }
    }

    int PI = cnt + s ;
    swap(a[s],a[PI]); 
    
    int i = s ;
    int j = e ;

    while(i<PI && j>PI)
    {
        while(a[i]<pivot)
        {
            i++ ;
        }

        while(a[j]>pivot)
        {
            j-- ;
        }

        if(i<PI && j>PI)  //if(a[i]>pivot && a[j]<pivot)
        {
            swap(a[i],a[j]);
            i++ ;
            j-- ;
        }
    }
    
    return PI ;
}

void Quickshort(int a[] , int s , int e)
{
    if(s >= e)
    {
        return ;
    }

    int pivotindex = getpivotindex(a,s,e);

    Quickshort(a , s , pivotindex-1);
    Quickshort(a , pivotindex+1 , e);
}

int main()
{
    int a[10] = {10,100,90,80,70,85,6,1,20,89};
    int e = 10 ;
    int s = 0 ;

    Quickshort(a , s ,e-1);

    for(int i=0 ; i<e ;i++)
    {
        cout << a[i] << "  " ;
    }
    
    return 0;
}