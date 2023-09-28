#include <iostream>
const int TAM=100;
using namespace std;

//***************************Definicion de la clase Alumno*************************
//**********************************************************************************
class Alumno
{
private:
    string Nombre;
    string Carrera;
    int TotalMaterias;
    float Promedio;
public:
    Alumno();
    void operator=(Alumno& x);
    Alumno(string N,string C, int TM,float Prm);
    friend std::ostream& operator<<( std::ostream&, Alumno&);
    friend std::istream& operator>>( std::istream&, Alumno&);
    bool operator ==(Alumno& elem);
};
//***************************************************************************************



//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Cola
{
private:
    Alumno datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Alumno& elem, int pos);
public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    void enqueue(Alumno& elem);
    Alumno& dequeue();
    int BusquedaLineal(Alumno& elem);

};
//*************************************************************************************

Alumno::Alumno()
{
    Nombre="";
    Carrera="";
    TotalMaterias = 0;
    Promedio = 0;
}

Alumno::Alumno(string N,string C, int TM,float Prm): Nombre(N),Carrera(C),TotalMaterias(TM), Promedio(Prm) {}
void Alumno::operator=(Alumno& x)
{
    Nombre=x.Nombre;
    Carrera = x.Carrera;
    TotalMaterias=x.TotalMaterias;
    Promedio=x.Promedio;
}

std::ostream& operator<<( std::ostream& o, Alumno& p)
{
    o<<"Nombre: "<<p.Nombre<<"\nCarrera: "<<p.Carrera<<"\nTotal de Materias: "<<p.TotalMaterias<<"\nPromedio: "<<p.Promedio<<endl;
    return o;
}
std::istream& operator>>( std::istream& o, Alumno& p)
{
    std::cout<<"\n Inserta nombre: ";
    getline (o,p.Nombre);
    std::cout<<"\n Inserta Carrera: ";
    getline (o,p.Carrera);
    std::cout<<"\n Inserta Total de Materias: ";
    o>>p.TotalMaterias;
    std::cout<<"\n Inserta Promedio: ";
    o>>p.Promedio;
    return o;
}



bool Cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(Alumno& elem)
{
    inserta(elem,0);
}

Alumno& Cola::dequeue()
{
    ult--;
    return datos[ult+1];
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Cola::inserta(Alumno& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}

int main()
{
    Cola MiCola;
    Alumno a,b;

    int opc=0;
    do
    {
        cout<<"1. Dar de alta a un alumno\n";
        cout<<"2. Elaborar una constancia\n: ";
        cin>>opc;
        cin.ignore();
        switch(opc)
        {
        case 1:
            cout<<"Ingresa los datos del Alumno.\n";

            cin>>a;
            MiCola.enqueue(a);
            break;

        case 2:
            if(!MiCola.vacia())
            {
                a = MiCola.dequeue();
                cout<<a;
            }else{
                cout<<"Cola vacia.\n";
            }

            break;

        }
    }
    while(opc!=3);
    return 0;
}

