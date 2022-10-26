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
    char op=' ',cass=' ';
    struct ciudad p;










    
    do
    {
        printf("Elija una de las siguintes opciones.\n");
        printf("A)Total de temperaturas almacenadas por provincia.\n");
        printf("B)Temperatura promedio de cada provincia.\n");
        printf("C)Temperautra promedio de cada ciudad.\n");
        printf("D)Ciudad mas calida de todas las provincias.\n");
        printf("E)Ciudad mas fria de cada provincia.\n");
        printf("F)Dia mas calido de cada princida.\n");
        printf("G)Dia mas frio de cada provincia.\n");
        printf("H)Mejor provincia para cultivar pimientos.\n");//Temperatura promedio cercana a 23 C
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
            break;
        case 'b':
        case 'B':
            break;
        case 'c':
        case 'C':
            break;
        case 'd':
        case 'D':
            break;
        case 'e':
        case 'E':
            break;
        case 'f':
        case 'F':
            break;
        case 'g':
        case 'G':
            break;
        case 'h':
        case 'H':
            break;
        default:
        printf("No se eligio ninunga opcion propuesta.\n");
            break;
        }
        printf("Desea continuar?S/N");
        scanf(" %c",&op);
    } while (op=='s' && 'S');
    






    return 0;
}