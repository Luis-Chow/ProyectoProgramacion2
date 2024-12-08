#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;

class Admin{
    public:
    void vehiculos_admin();
    void repuestos_admin();
    void clientes_admin();
    void crearCopiaSeguridad_admin();
};

class Manager{
    public:
    void vehiculos_manager();
    void repuestos_manager();
    void clientes_manager();
};

class Empleado{
    public:
    void vehiculos_empleados();
    void repuestos_empleados();
    void clientes_empleados();
};
