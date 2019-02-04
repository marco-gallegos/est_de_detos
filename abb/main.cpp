#include <iostream>
#include<string>

using namespace std;

class nodo
{
public:
    string word;
    nodo *izq;
    nodo *der;

    nodo(): izq(NULL),der(NULL){}
    nodo(string a): word(a),izq(NULL),der(NULL){}

};

class abb
{
public:
    nodo *raiz;
    abb():raiz(new nodo()){}

    bool vacio()
    {
        return raiz==NULL;
    }

    bool es_hoja(nodo *a)
    {
        if(a->der==NULL&&a->izq==NULL)
            return 1;
        else
            return 0;
    }

    int inst(string nw)
    {
        if(raiz->word=="\0"||raiz==NULL||vacio())
        {
            raiz=new nodo(nw);
            return 1;
        }
        nodo *it=raiz,*ant;
        while(it!=NULL)
        {
            if(nw[0]>it->word[0])
            {
                if(it->der==NULL)
                {
                    it->der=new nodo(nw);
                    return 1;
                }
                it=it->der;
            }

            if(nw[0]<it->word[0])
            {
                if(it->izq==NULL)
                {
                    it->izq=new nodo(nw);
                    return 1;
                }
                it=it->izq;
            }

        }


    }

    bool elim(string kill)
    {
        nodo *it=raiz,*ant=NULL,*aux=NULL;
        string change;
        while(it!=NULL)
        {

            if(it->word==kill)
            {
                if(es_hoja(it))
                {
                    if(ant==NULL)
                    {
                        delete it;
                        it=new nodo();
                        return 1;
                    }
                    //es hoja y si hay anterior
                    if(ant->der==it)
                    {
                        delete ant->der;
                        ant->der=NULL;
                    }
                    else
                    {

                        ant->izq=NULL;
                    }
                    return 1;
                }
                else//es la palabra no es hoja y no nos importa si hay anterior ya que solo cambiaremos su valor
                {
                    aux=it;
                    if(it->der)//mas a la izquierda de la rama derecha
                    {
                        aux=aux->der;
                        while(aux->izq!=NULL)
                        {
                            aux=aux->izq;
                        }
                    }
                    else//mas a la derecha de su rama izq;
                    {
                        aux=aux->izq;
                        while(aux->der!=NULL)
                        {
                            aux=aux->der;
                        }
                    }
                    //intercambio y dejamos el dato en una hoja
                    change=it->word;
                    it->word=aux->word;
                    aux->word=change;
                    it=aux;
                }
            }
            else//seguimos iterando aun no lo encontramos
            {
                if(kill[0]<it->word[0])
                {
                    ant=it;
                    it=it->izq;
                }
                else
                    if(kill[0]>it->word[0])
                    {
                        ant=it;
                        it=it->der;
                    }

            }
        }
        cout<<"no shi pudio"<<endl;
    }

    void preorden(nodo *act)
    {
        if(act!=NULL)
        {
            cout<<act->word<<" ";
            preorden(act->izq);
            preorden(act->der);
        }

    }
    void inorden(nodo *act)
    {
        if(act!=NULL)
        {
            inorden(act->izq);
            cout<<act->word<<" ";
            inorden(act->der);
        }
    }
    void postorden(nodo *act)
    {
        if(act!=NULL)
        {
            postorden(act->izq);
            postorden(act->der);
            cout<<act->word<<" ";
        }
    }


    string parte_de(string comp)
    {
        nodo *it=raiz;
        while(it!=NULL&&it->word!=comp)
        {
            if(comp[0]>it->word[0])
            {
                it=it->der;
            }
            else
            {
                it=it->izq;
            }

        }
        if(it->word==comp)
            cout<<it->word<<" si existe en el arbol"<<endl;
        else
            cout<<"no shi pudio"<<endl;
    }

};


int main()
{
    abb arbbin;

    arbbin.inst("cash");
    arbbin.inst("bash");
    arbbin.inst("ash");
    arbbin.inst("est");


//    arbbin.preorden(arbbin.raiz);
    arbbin.elim("ash");
    cout<<endl;
    int x=0;
    bool preguntar=1;
    string help;
    while(1)
    {
        cout<<" 1ins 2del 3ver 4primero 5vacio 6 buscar "<<endl;cin>>x;
        switch(x)
        {
            case 1:
               // cin.ignore(10000,'\n');
                cout<<"palabra"<<endl;
                cin>>help;
                arbbin.inst(help);
                break;
            case 2:
                //cin.ignore(10000,'\n');
                cout<<"palabra"<<endl;
                cin>>help;
                arbbin.elim(help);
                break;
            case 3:
                while(preguntar)
                {
                    cout<<" 1pre 2in 3post ";cin>>x;
                    switch(x)
                    {
                    case 1:
                        arbbin.preorden(arbbin.raiz);
                        preguntar=0;
                        break;
                    case 2:
                        arbbin.inorden(arbbin.raiz);
                        preguntar=0;
                        break;
                    case 3:
                        arbbin.postorden(arbbin.raiz);
                        preguntar=0;
                        break;
                    }
                }
                break;
            case 4:
                cout<<arbbin.raiz->word<<endl;
                break;
            case 5:
                cout<<arbbin.vacio()<<endl;
                break;
            case 6:
                //cin.ignore(10000,'\n');
                cout<<"palabra"<<endl;
                cin>>help;
                arbbin.parte_de(help);
                break;

        }

    }




}
