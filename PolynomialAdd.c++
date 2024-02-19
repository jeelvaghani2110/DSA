#include<iostream>
#include<vector>
using namespace std ;

class poly
{
    public:
        int coof ;
        int expo ;
};

int add(poly a[50] , poly b[50] , poly c[50] , int k1 , int k2)
{
    int i,j,k;
    i=0,j=0,k=0;
    int t3=0;

    while(i<k1 && j<k2)
    {
        if(a[i].expo == b[j].expo)
        {
            c[k].expo = a[i].expo ;
            c[k].coof = a[i].coof + b[j].coof ;
            i++ ;
            j++ ;
            k++ ;
        }

        else if(a[i].expo > b[j].expo)
        {
            c[k].expo = a[i].expo ;
            c[k].coof = a[i].coof ;
            i++ ;
            k++ ;
        }

        else if(a[i].expo < b[j].expo)
        {
            c[k].expo = b[j].expo ;
            c[k].coof = b[j].coof ;
            j++ ;
            k++ ;
        }
    }

    while(i<k1)
    {
        c[k].expo = a[i].expo ;
        c[k].coof = a[i].coof ;
        i++ ;
        k++ ;
    }
    
    while(j<k2)
    {
        c[k].expo = b[j].expo ;
        c[k].coof = b[j].coof ;
        j++ ;
        k++ ;
    }
    t3=k;

    return t3;
}

int main()
{
    poly a[50] , b[50] , c[50] ;
    int k1=0 , k2=0 ;

    cout << "How Many Elements In Poly-1 and poly-2 :" << endl ;
    cin >> k1 >> k2 ;
    
    cout << "Enter First Polynomial :" << endl ;
    for(int i=0 ; i<k1 ; i++)
    {
        cin >> a[i].coof ;
        cout << "x^" ;
        cin >> a[i].expo ;
        cout << "+" ;
    }

    cout << "Enter Second Polynomial :" << endl ;
    for(int i=0 ; i<k2 ; i++)
    {
        cin >> b[i].coof ;
        cout << "x^" ;
        cin >> b[i].expo ;
        cout << "+" ;                                       
    }

    int total=add(a,b,c,k1,k2) ;

    cout << "Answer Of Polynomial Addition is : " ;
    for(int i=0 ; i<total ; i++)
    {
        cout << c[i].coof << "x^" << c[i].expo << "+" ;
    }

    return 0 ;
}