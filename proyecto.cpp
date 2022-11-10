#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
    struct clima clime;
    int ciudad_id;
	int provincia;
    char nombre_ciudad[50];
};
void check(FILE *fp);
int main(int argc, char *argv[]){
    struct ciudad *stakptr=NULL;
    struct ciudad *new_node=NULL;
    struct ciudad *temp=NULL;
    char op=' ',cass=' ',nombre[50];
	int id,valor,horas,minutos,dias,meses;
	float prom=0.0f,suma=0.0f;
	int cant=0,count=7;
    float hum=0.0f,tempe=0.0f;
    FILE *fp;
    fp = fopen("data_set.txt","r");
    check(fp);
	printf("MUESTRAS: \n");
    while (fscanf(fp,"%d %d %s %f %f %d %d %d %d", &id,&valor,&nombre,&tempe,&hum,&horas,&minutos,&dias,&meses) != EOF){
        new_node = (struct ciudad *) malloc(sizeof(ciudad));
		new_node = (struct ciudad *) new_node;
		if(new_node == NULL) {
			cout<<"No hay memoria disponible"<<endl;
			exit(0);
		}
        new_node->ciudad_id=id;
        new_node->provincia=valor;
		for(int i=0;i<50;i++){
			new_node->nombre_ciudad[i] = nombre[i];
		}
        new_node->clime.temp=tempe;
        new_node->clime.humedad=hum;
        new_node->clime.time.horas=horas;
        new_node->clime.time.minutos=minutos;
        new_node->clime.time.dia=dias;
        new_node->clime.time.mes=meses;
		new_node->next = stakptr;
		stakptr = new_node;
    }
    fclose(fp);
	cout<<"Estructura cargada"<<endl;
	    fclose(fp);
		temp=stakptr;
        
            while(temp!=NULL){
			if (temp->ciudad_id==76){
			printf("%d\t%d\t%s\t%f\t%f\t%d\t%d\t%d\t%d\n",temp->ciudad_id,temp->provincia,temp->nombre_ciudad,temp->clime.temp,temp->clime.humedad,temp->clime.time.horas,temp->clime.time.minutos,temp->clime.time.dia,temp->clime.time.mes);
			cant++;
			if(cant<count){
			suma=(suma+temp->clime.temp);
			}
			}
			temp=temp->next;
		}
			prom=suma/count;
			printf("CANTIDAD: %d\n",cant);
			printf("Promedio: %f\n",prom);
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
    fclose(fp);
    return 0;
}
void check(FILE *fp){
    if (fp==NULL)
    {
        printf("Imposible abrir el archivo.\n");
        exit(1);
    }
}
