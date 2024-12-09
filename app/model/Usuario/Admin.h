#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

class Admin{
    public:
    void vehiculos_admin();
    void repuestos_admin();
    void clientes_admin();
    void copia_seguridad();
};