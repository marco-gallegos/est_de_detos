#include<iostream>
using namespace std;
void qs(int lista[],int limite_izq,int limite_der)
{
    int izq=limite_izq;
    int der=limite_der;
    int pivote=lista[(izq+der)/2];
    int temp;

    do
    {
        while((lista[izq]<pivote)&&(izq<limite_der))
        {
            izq++;
        }
        while((lista[der]>pivote)&&(der>limite_izq))
        {
            der--;
        }
        if(izq<=der)
        {
            temp=lista[der];
            lista[der]=lista[izq];
            lista[izq]=temp;
            izq++;
            der--;
        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}
}

int main()
{
    int a[]={10,2,4,6,12,1};
    int der=sizeof(a)/sizeof(int);
    qs(a,0,der);

    for(int i=0;i<=der;i++)
    {
        cout<<a[i]<<endl;
    }

}
