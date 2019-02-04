#include <iostream>
#include<cstdlib>

using namespace std;

class nodo
{
public:
    int dato;
    nodo *sig;
    nodo(int d)
    {
        dato=d;
        sig=NULL;
    }
    nodo()
    {
        dato=0;
        sig=NULL;
    }
};


class pila
{
public:
    nodo *h;
    pila()
    {
        h=new nodo();
    }


    int push(int d)
    {
        if(h->dato==NULL)
           {
              h=new nodo(d);
              return 0;
           }

        nodo *aux=h;
        while(aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=new nodo(d);

    }

    int pop()
    {
        nodo *aux=h,*ant;
        if(h->sig==NULL)
        {
            delete h;
            return 0;
        }
        while(aux->sig!=NULL)
        {
                ant=aux;
                aux=aux->sig;

        }
        ant->sig=NULL;
        delete aux;

    }

    int ver()
    {
        if(h->dato==NULL)
            return 1;
        nodo *aux=h;
        while(aux!=NULL)
        {
            cout<<aux->dato<<endl;
            aux=aux->sig;
        }
    }

    bool pila_vacia()
    {
        if(h->dato==NULL)
        {
            return 1;
        }
        return 0;
    }

    int limpiar_pila()
    {
        while(h->dato!=NULL)
        {
            nodo *aux=h,*ant;
        if(h==NULL)
        {
            return 1;
        }
        if(h->sig==NULL)
        {
            delete h;
            return 0;
        }
        while(aux->sig!=NULL)
        {
                ant=aux;
                aux=aux->sig;

        }
        ant->sig=NULL;
        delete aux;
        }

    }

    bool tam()
    {
        if(pila_vacia())
        {
            cout<<"0"<<endl;
            return 0;
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
    pila pil;
    int x=0;
    int o;
    pil.push(69);
  /*  while(x<4)
    {
        srand(time(NULL));
        pil.push(rand()%10);
       // system("sleep 1");
        x++;
    }
    */
    do
    {
        cout<<" 1ins  2del 3ver 4vacia 5tamaño"<<endl;cin>>x;
        switch(x)
        {
        case 1:
            cout<<"numero ";cin>>o;
            pil.push(o);
            break;
        case 2:
            pil.pop();
            break;
        case 3:
            pil.ver();
            break;
        case 4:
            if(pil.pila_vacia())
                cout<<"vacia "<<endl;

            else
                cout<<"no vacia "<<endl;
            break;
        case 5:
            pil.tam();
            break;
        case 6:
            pil.limpiar_pila();
            break;

        }
    }while(x!=9);
}
