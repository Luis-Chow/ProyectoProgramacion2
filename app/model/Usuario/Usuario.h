#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include "../controller/ClientesController.cpp"
#include "../controller/VehiculosController.cpp"
#include "../controller/RepuestosController.cpp"
using namespace std;

class Admin{
    public:
    void vehiculos();
    void repuestos();
    void clientes();
    void crearCopiaSeguridad();
};

class Manager{
    public:
    void vehiculos();
    void repuestos();
    void clientes();
};

class Empleado{
    public:
    void vehiculos();
    void repuestos();
    void clientes();
};
