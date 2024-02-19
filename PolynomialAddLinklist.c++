#include<iostream>
using namespace std;

class poly
{
        int expo ;
        int coof ;
        poly* next ;
        friend class implement ;

    public:
        poly(int c,int e)
        {
            this->coof = c ;
            this->expo = e ;
            this->next = NULL ;
        }

};

class implement
{
        poly* first ;

    public:
        implement()
        {
            first = NULL ;
        }

    void insert(int c,int e)
    {
        poly* nn = new poly(c,e);
        poly* temp = first ;

        if(first == NULL)
        {
            first = nn ;
        }

        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next ;
            }

            temp->next = nn ;
        }
    }

    void display()
    {
        poly* temp = first ;

        while(temp != NULL)
        {
            cout << temp->coof << "x^" << temp->expo << "+ " ;
            temp = temp->next ;
        }

        cout << endl ;
    }

    void Addpoly(implement* i1 , implement* i2 , int k1, int k2)
    {
        poly* temp1 = i1->first ;
        poly* temp2 = i2->first ;
        int i=0 , j =0 ;
        
        while(i<k1 && j<k2)
        {
            if(temp1->expo == temp2->expo)
            {
                insert((temp1->coof+temp2->coof) , temp1->expo) ;
                temp1 = temp1->next ;
                temp2 = temp2->next ;
                i++ ;
                j++ ;
            }

            else if(temp1->expo > temp2->expo)
            {
                insert(temp1->coof , temp1->expo) ;
                temp1 = temp1->next ;
                i++ ;
            }

            else if(temp1->expo < temp2->expo)
            {
                insert(temp2->coof , temp2->expo) ;
                temp2 = temp2->next ;
                j++ ;
            }
        }

        while(i < k1)
        {
            insert(temp1->coof , temp1->expo) ;
            temp1 = temp1->next ;
            i++ ;
        }

        while(j < k2)
        {
            insert(temp2->coof , temp2->expo) ;
            temp2 = temp2->next ;
            j++ ;
        }

        display();
    }
};

int main()
{
    implement i1 , i2 , i3 ;
    int k1 , k2 ;
    int c , e ;

    cout << "How Many Element Insert In Poly-1 and poly-2 : " << endl ;
    cin >> k1 >> k2 ;

    cout << "Enter Polynomial-1 :" << endl ;
    for(int i=0 ; i<k1 ;i++)
    {
        cout << "Enter Poly-1 Expo and Coof :  ";
        cin >> c >> e ;
        i1.insert(c,e);
    }

    cout << "Enter Polynomial-2 :" << endl ;
    for(int i=0 ; i<k2 ;i++)
    {
        cout << "Enter Poly-2 Expo and Coof :  ";
        cin >> c >> e ;
        i2.insert(c,e);
    }

    i3.Addpoly(&i1,&i2,k1,k2);

    return 0 ;
}