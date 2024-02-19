//sorted linklist

#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;
    friend class implement;

    public:
        node(int d)
        {
            this -> data = d ;
            this -> next = NULL ;
        }
};

class implement
{
    node* first ;

    public:
        implement()
        {
            first = NULL ;
        }

        void insertTail(int d)
        {
            node* nn = new node(d);

            if(first==NULL)
            {
                first = nn ;
            }

            else
            {
                node* temp = first ;

                while(temp->next != NULL)
                {
                    temp = temp->next ;
                }

                temp->next = nn ;
            }
        }

        void duplicate()
        {
            node* temp = first ;

            while(temp != NULL)
            {
                if((temp->next!=NULL) && temp->data == temp->next->data)
                {
                    temp->next = temp->next->next ;
                }

                else
                {
                    temp = temp->next ;
                }
            }
        }

        void print()
        {
            node* temp = first ;

            while(temp != NULL)
            {
                cout << temp->data << "  " ;
                temp = temp->next ; 
            }

            cout << endl ;
        }
};

int main()
{
    implement i1 , i2 , i3 ;
    i1.insertTail(10); 
    i1.insertTail(20);
    i1.insertTail(20);
    i1.insertTail(20);
    i1.insertTail(20);
    i1.insertTail(20);
    i1.insertTail(30); 
    i1.insertTail(40);
    i1.duplicate();
    i1.print();
}