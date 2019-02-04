#include<iostream>
using namespace std;

class nodo
{
public:
    int dato;
    nodo *sig;
    nodo()
    {
        sig=NULL;
    }
    nodo(int num)
    {
        dato=num;
        sig=NULL;
    }
    ~nodo()
    {
        delete sig;
    }
};

class lista
{
public:
nodo *h;

lista()
{
    h=new nodo();
}
~lista()
{
    delete h;
}

void insertar(int d)
{
    nodo *tmp=new nodo(d);

    if(h->sig==NULL)
    {
        h=tmp;
    }
    else
    {
        tmp->sig=h;
        h=tmp;
    }

}

void insertar_final(int num)
{
    nodo *tmp=new nodo(num);
    nodo *aux=h;
    if(h==NULL)
    {
        h=tmp;
    }
    else
    {
        while(aux!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=tmp;
    }
    delete tmp;
}


void mostrar(void)
{
    nodo *tmp=h;
    while(tmp != NULL)
    {
        cout<<tmp->dato<<endl;
        tmp=tmp->sig;
    }
}

};

int main()
{
    lista l;
    l.insertar(1);
    l.insertar(2);
    l.mostrar();


}
// insertar posi
// eliminar
