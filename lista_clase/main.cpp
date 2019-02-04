#include <iostream>

using namespace std;

class nodo
{
public:
    int dato;
    nodo *sig;
    nodo(int num)
    {
        dato=num;
        sig=NULL;
    }
};

class lista
{
public:
    nodo *h;
    lista()
    {
        h=NULL;
    }
    void inicializar(int n)
    {
        h=new nodo(n);
    }

    void inst_h(int n)
    {
        nodo *nuevo=new nodo(n);
        if(h==NULL)
        {
            inicializar(n);
        }
        else
        {
            nuevo->sig=h;
            h=nuevo;
        }
    }

    void inst_fin(int n)
    {
        nodo *nuevo=new nodo(n),*it=h;
        if(h==NULL)
            inicializar(n);
        else
        {
            while(it!=NULL)
            {
                if(it->sig==NULL)
                    break;
                else
                    it=it->sig;
            }
            it->sig=nuevo;
        }

    }

    int inst_pos(int n,int p)
    {
        nodo *ant=NULL,*it=h,*nuevo=new nodo(n);
        if(p<0)
            cout<<"invalido"<<endl;
        for(int i=1;i<p;i++)
            {
                if(it->sig==NULL)
                {
                    cout<<"posicion no existe"<<endl;
                    return 0;
                }
                if(it->sig!=NULL)
                {
                    ant=it;
                    it=it->sig;
                }
            }

            nuevo->sig=it;
            ant->sig=nuevo;

    }

    void ver()
    {
        nodo *it=h;
        while(it!=NULL)
        {
            cout<<it->dato<<endl;
            it=it->sig;
        }
    }

    int eliminar(int dat)
    {
        nodo *aux=h;
        if(aux->dato==dat)
        {
            h=h->sig;
            delete aux;
            return 1;
        }
        if(h->sig!=NULL)
        {
            nodo *ant;
            while(aux->sig!=NULL&&aux->dato!=dat)
            {
                ant=aux;
                aux=aux->sig;
            }
            if(aux->dato==dat)
            {
                if(aux->sig!=NULL)
                {
                    ant->sig=aux->sig;
                    delete aux;
                    return 1;
                }
                if(aux->sig==NULL)
                {
                    ant->sig=NULL;
                    delete aux;
                    return 1;
                }
            }
            else
            {
                cout<<"no existe"<<endl;
            }

        }
        else
        {
            cout<<"lista vacia "<<endl;
        }

    }

};

int main()
{
    int opc,num;
    lista lis;
    lis.inst_h(9);
    lis.inst_h(22);
    lis.inst_h(33);
    while(opc!=9)
    {
    cout<<"1 insertar inicio\t2 insertar final\t3 insertar posicion\t4 eliminar\t5 ver\n";
    cin>>opc;
    switch(opc)
    {
    case 1:
        lis.inst_h(22);
        break;
    case 2:
        lis.inst_fin(9);
        break;
    case 3:
        cout<<"en que posicion lo insertaras"<<endl;
        cin>>num;
        lis.inst_pos(69,num);
        break;
    case 4:
        cout<<"que numero morira??"<<endl;
        cin>>num;
        lis.eliminar(num);
        break;
    case 5:
        lis.ver();
        break;
}
    }
}

