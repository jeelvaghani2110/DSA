#include<iostream>
using namespace std ;

class node
{
        int data ;
        node* next ;
        friend class implement ;

    public:
        node(int d)
        {
            this->data = d ;
            this->next = NULL ;
        }
} ;

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
            node* temp = first ;
            node* nn = new node(d) ;

            if(first == NULL)
            {
                first = nn ;
                first->next = nn ;
            }

            else
            {
                while(temp->next!=first)
                {
                    temp = temp->next ;
                }

                temp->next = nn ;
                nn->next = first ;
            }
        }

        void insertHead(int d)
        {
            node* temp = first ;
            node* nn = new node(d) ;

            if(first == NULL)
            {
                first = nn ;
                first->next = nn ;
            }

            else
            {
                while(temp->next != first)
                {
                    temp = temp->next ;
                }

                nn->next = first ;
                temp->next = nn ;
                first = nn ;
            }
        }

        void insertAfter(int x , int d)
        {
            node* temp = first ;
            node* nn = new node(d) ;

            if(first == NULL)
            {
                first = nn ;
                first->next = nn ;
            }

            else
            {
                while(temp->data != x)
                {
                    temp = temp->next ;
                }

                nn->next = temp->next ;
                temp->next =nn ;
            }
        }

         void insertBefore(int x , int d)
        {
            node* temp = first ;
            node* nn = new node(d) ;

            if(first == NULL)
            {
                first = nn ;
                first->next = nn ;
            }

            else
            {
                while(temp->next->data != x)
                {
                    temp = temp->next ;
                }

                nn->next = temp->next ;
                temp->next = nn ;
            }
        }

        void remove(int d)
        {
            node* temp = first ;
            
            if(temp->data == d)
            {
                while(temp->next!=first)
                {
                    temp = temp->next ;
                }
                
                temp->next = first->next ;
                first = first->next ;
            }
            
            else
            {
                while(temp->next->data != d)
                {
                    temp = temp->next ;
                }
    
                temp->next = temp->next->next ;
            }
        }
        
        void removeTail(int d)
        {
            node* temp = first ;
             
            while(temp->data != d)
            {
                temp = temp->next ;
            }
                
                
            if(temp->next == first)
            {
               temp->next = first->next ;
               first = first -> next ;
               return ;
            }
            
            temp->next = temp->next->next ;
            
        }

        void print()
        {
            node* temp = first ;

            do
            {
                cout << temp->data << "  " ;
                temp = temp->next ;
            }
            while (temp != first);

            cout << endl ; 
        }
} ;

int main()
{
    implement i1 , i2 ;
    i1.insertTail(10);
    i1.insertTail(20);
    i1.insertTail(30);
    i1.insertTail(40);
    i1.insertHead(50);
    i1.insertAfter(20,25);
    i1.insertBefore(25,35);
    i1.print();
   // i1.remove(50);
    i1.removeTail(40);
    i1.print();
}