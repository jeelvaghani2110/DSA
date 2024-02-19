#include<iostream>
using namespace std;

void merge(int a[] , int s , int e)
{
    int mid = (s+e)/2 ;
    int len1 = mid-s+1 ;
    int len2 = e-mid ;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainarrayindex = s ;
    for(int i=0 ; i<len1 ; i++)
    {
        first[i] = a[mainarrayindex];
        mainarrayindex++;
    }

    mainarrayindex = mid+1 ;
    for(int i=0 ; i<len2 ; i++)
    {
        second[i] = a[mainarrayindex];
        mainarrayindex++;
    }

    int index1=0 , index2=0 ;
    mainarrayindex = s ;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]>second[index2])
        {
            a[mainarrayindex] = second[index2];
            mainarrayindex++;
            index2 ++ ;
        }

        else
        {
            a[mainarrayindex] = first[index1];
            mainarrayindex++ ;
            index1 ++ ;
        }
    } 

    while(index1 < len1)
    {
        a[mainarrayindex] = first[index1];
        index1 ++ ;
        mainarrayindex ;
    }

    while(index2 < len2)
    {
        a[mainarrayindex] = second[index2];
        index2 ++ ;
        mainarrayindex++ ;
    }
}

void mergesort(int a[] , int s , int e)
{
    if(s >= e)
    {
        return ;
    }

    int mid = (s+e)/2 ;

    mergesort(a , s , mid) ;
    mergesort(a , mid+1 , e) ;

    merge(a,s,e);
}

int main()
{
    int a[10] = {10,8,74,99,65,23,78,105,85,0};
    int e = 10 ;
    int s = 0 ;

    mergesort(a , s , e-1);

    for(int i=0 ; i<e ; i++)
    {
        cout << a[i] << "  " ;
    }

    return 0 ;
}