#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Cliente{
    private:
    string cedula;
    string nombre;
    string apellido;
    string direccion;
    string email;
    string activo;
    int cantidad_vehiculos_rentados;

    public:
    void insercion();
    void borrar();
    void actualizar();
    void consulta();
};