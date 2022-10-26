#include <iostream>
using namespace std;
struct dias
{
    int dia;
    int mes;
    int horas;
    int minutos;
};

struct clima
{
    float temp;
    float humedad;
    struct dias time;
};

struct ciudad
{
    struct ciudad *next;
    struct clima c;
    int ciudad_id;
    char nombre_ciudad[50];
};

int main(int argc, char *argv[]){
    struct ciudad p;





    return 0;
}