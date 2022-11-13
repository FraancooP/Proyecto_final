#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tratamiento.h"
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
	struct ciudad *head_1=NULL;//CORDOBA.
	struct ciudad *head_2=NULL;//SANTA FE.
	struct ciudad *head_3=NULL;//MENDOZA.
    char op=' ',cass=' ',nombre[50];
	int id,valor,horas,minutos,dias,meses,i=0;
    float hum=0.0f,tempe=0.0f,promedio_cordoba=0.0f,promedio_santa_fe=0.0f,promedio_mendoza=0.0f,suma=0.0f;
	float total_cba=0.0f, total_santa_fe=0.0f,total_mendoza=0.0f,promedio_ciudad=0.0f;
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
		switch(valor){
		case 1:
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
			new_node->next = head_1;
			head_1 = new_node;
			break;
		case 2:
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
			new_node->next = head_2;
			head_2 = new_node;
			break;
		case 3:
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
			new_node->next = head_3;
			head_3 = new_node;
			break;
		}
    }
    fclose(fp);
    do
    {
        printf("Elija una de las siguintes opciones.\n");
        printf("A)Total de temperaturas almacenadas por provincia.\n");
        printf("B)Temperatura promedio de cada provincia.\n");
        printf("C)Temperautra promedio de cada ciudad.\n");
        printf("D)Ciudad mas calida de todas las provincias.\n");
        printf("E)Ciudad mas fria de cada provincia.\n");
        printf("F)Dia mas calido de cada provincida.\n");
        printf("G)Dia mas frio de cada provincia.\n");
        printf("H)Mejor provincia para cultivar pimientos.\n");//Temperatura promedio cercana a 23 C
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
			temp=head_1;
			while(temp!=NULL){
					total_cba++;
				temp=temp->next;
			}
			printf("TEMPERATURAS ALMACENADAS EN CORDOBA: %.0f\n",total_cba);
			temp=head_2;
			while(temp!=NULL){
					total_santa_fe++;
				temp=temp->next;
			}
			printf("TEMPERATURAS ALMACENADAS EN SANTA FE: %.0f\n",total_santa_fe);
			temp=head_3;
			while(temp!=NULL){
				total_mendoza++;
				temp=temp->next;
			}
			printf("TEMPERATURAS ALMACENADAS EN MENDOZA: %.0f\n",total_mendoza);
            break;
        case 'b':
        case 'B':
			temp=head_1;
			while(temp!=NULL){
				suma=(suma+temp->clime.temp);
				temp=temp->next;
			}
			promedio_cordoba=suma/total_cba;
			printf("PROMEDIO DE TEMPERATURAS DE CORDOBA: %f\n",promedio_cordoba);
			suma=0;
			temp=head_2;
			while(temp!=NULL){
				suma=(suma+temp->clime.temp);
				temp=temp->next;
			}
			promedio_cordoba=suma/total_santa_fe;
			printf("PROMEDIO DE TEMPERATURAS DE SANTA FE: %f\n",promedio_cordoba);
			suma=0;
			temp=head_3;
			while(temp!=NULL){
				suma=(suma+temp->clime.temp);
				temp=temp->next;
			}
			promedio_cordoba=suma/total_mendoza;
			printf("PROMEDIO DE TEMPERATURAS DE MENDOZA: %f\n",promedio_cordoba);
			suma=0;
            break;
        case 'c':
        case 'C':
			for(int i=0;i<100;i++){
				temp=stakptr;
				while(temp!=NULL){
					if(temp->ciudad_id==i){
						suma=(suma+temp->clime.temp);
					}
					temp=temp->next;
				}
				promedio_ciudad=suma/80.0;
					temp=stakptr;
					if(temp->ciudad_id==i){
						while(temp!=NULL){
							for(int j=0;j<1;j++){
								printf("PROMEDIO DE %s\n",temp->nombre_ciudad);
							}
							temp=temp->next;
						}
					}
				i++;
			}
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
