#include <iostream>
#include<cstdlib>

using namespace std;

class nodo
{
public:
    char dato;
    nodo *sig;

    nodo()
    {
        dato='\0';
        sig=NULL;
    }
    nodo(char d)
    {
        dato=d;
        sig=NULL;
    }
};

class cola
{
public:
    nodo *h,*ultimo;

    cola()
    {
        h=new nodo();
        ultimo=new nodo();

    }

    int push(char d)
    {
        nodo *nuevo=new nodo(d);
        if(h->dato==NULL)
          {
              h=nuevo;
              ultimo=h;
              return 1;
          }
          nodo *it=h;
          while(it->sig!=NULL)
          {
              it=it->sig;
          }
          ultimo=nuevo;
          it->sig=ultimo;


    }

    int pop()
    {
        if(h->dato==NULL)
        {
            return 1;
        }
        if(ultimo==h)
        {
            delete h;
            h=new nodo();
            return 1;
        }
        nodo *x=h;
        h=h->sig;
        delete x;

    }

    int ver()
    {
        nodo *it=h;
        while(it->sig!=NULL)
        {

            cout<<it->dato<<endl;
            it=it->sig;
            break;

        }
      /*  if(ultimo->dato!=NULL)
        {
            cout<<ultimo->dato<<endl;

        }*/
    }

    bool primero()
    {
        if(h->dato!=NULL)
        {
            cout<<h->dato<<endl;
            return 1;

        }
        cout<<"no hay cola"<<endl;
        return 0;
    }

    bool ultim()
    {
        if(ultimo->dato!=NULL)
        {
            cout<<ultimo->dato<<endl;
            return 1;
        }
        cout<<"no hay cola"<<endl;
        return 0;
    }

    bool vacia()
    {
        if(h->dato==NULL)
        {
            cout<<"vacia"<<endl;
            return 1;
        }
        cout<<"no vacia"<<endl;
        return 0;
    }

    bool tam()
    {
        if(h->dato==NULL)
        {
            cout<<"0"<<endl;
        }
        int x=1;
        nodo *it=h;
        while(it->sig!=NULL)
        {
            x++;
            it=it->sig;
        }
        cout<<x<<endl;
    }

};

int main()
{
    cola c;
    int x=0;
    char z;
    do
    {
        cout<<" 1 ins  2del 3ver 4vacia  5tamaño  6 ultimo"<<endl;cin>>x;
        switch(x)
        {
        case 1:
            cout<<"que letra"<<endl;cin>>z;
            c.push(z);
            break;
        case 2:
            c.pop();
            break;
        case 3:
            c.ver();
            break;
        case 4:
            c.vacia();
            break;
        case 5:
            c.tam();
            break;
        case 6:
            c.ultim();
            break;
        }
    }while(x!=9);
}
