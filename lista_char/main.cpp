#include <iostream>

using namespace std;

class nodo
{
public:
    char dato;
    nodo *sig;
    nodo()
    {
        dato=0;
        sig==NULL;
    }
    nodo(char carac)
    {
        dato=carac;
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
    void inicializar(char c)
    {
        h=new nodo(c);
    }

    void inst_h(char c)
    {
        nodo *nuevo=new nodo(c);
        if(h==NULL)
        {
            inicializar(c);
        }
        else
        {
            nuevo->sig=h;
            h=nuevo;
        }
    }

    void inst_fin(char c)
    {
        nodo *nuevo=new nodo(c),*it=h;
        if(h==NULL)
            inicializar(c);
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

    int inst_pos(char c,int p)
    {
        nodo *ant=NULL,*it=h,*nuevo=new nodo(c);
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
            return 1;
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

    int eliminar(char car)
    {
        nodo *it=h;
        if(it->dato==car)
        {
            h=h->sig;
            delete it;
            return 1;
        }
        if(h->sig!=NULL)
        {
            nodo *ant;
            while(it->sig!=NULL&&it->dato!=car)
            {
                ant=it;
                it=it->sig;
            }
            if(it->dato==car)
            {
                if(it->sig!=NULL)
                {
                    ant->sig=it->sig;
                    delete it;
                    return 1;
                }
                if(it->sig==NULL)
                {
                    ant->sig=NULL;
                    delete it;
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
return 1;
    }

    int ant(char d)
    {
        nodo *ant=new nodo(),*it=h;
        while(it->dato!=d)
        {
            ant=it;
            it=it->sig;

        }
        if((ant->dato==NULL)||(h->dato==NULL))
        {
            cout<<" no hay anterior "<<endl;
            return 0;
        }
        cout<<"el anterior es "<<ant->dato<<endl;

    }
    int sig(char d)
    {
        nodo *it=h;
        if(h==NULL||h->sig==NULL)
            {cout<<"no ha proximo"<<endl;return 0;}

        while(it->dato!=d)
        {
            it=it->sig;
        }
        if(it->sig==NULL)
            {cout<<"no ha proximo"<<endl;return 0;}

        cout<<" el sig es "<<it->sig->dato<<endl;
    }
};

int main()
{
    int opc,num;
    char x='#';
    lista lis;
    lis.inst_fin('a');
    lis.inst_fin('b');

    while(opc!=9)
    {
    cout<<"1 insertar inicio\t2 insertar final\t3 insertar posicion\t4 eliminar\t5 ver\t6 anterior\t7 siguiente\n";
    cin>>opc;
    switch(opc)
    {
    case 1:
        cout<<"caracter a insertar"<<endl;cin>>x;
        lis.inst_h(x);
        break;
    case 2:
        cout<<"caracter a insertar"<<endl;cin>>x;
        lis.inst_fin(x);
        break;
    case 3:
        cout<<"caracter a insertar"<<endl;cin>>x;cout<<endl;
        cout<<"en que posicion lo insertaras"<<endl;
        cin>>num;
        lis.inst_pos(x,num);
        break;
    case 4:
        cout<<"que caracter morira??"<<endl;
        cin>>x;
        lis.eliminar(x);
        break;
    case 5:
        lis.ver();
        break;
    case 6:
        cout<<"anterior de cual"<<endl;cin>>x;
        lis.ant(x);
        break;
    case 7:
        cout<<"siguiente de cual"<<endl;cin>>x;
        lis.sig(x);
        break;
}
    }
}

