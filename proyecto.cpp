#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Tratamiento.h"
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
void promedio_temp_provincias(struct ciudad *, struct ciudad *, struct ciudad *);
void promedio_temp_ciudad(struct ciudad *);
void ciudad_mas_calidad_provincias(struct ciudad *, struct ciudad *, struct ciudad *);
void ciudad_mas_fria_provincias(struct ciudad *,struct ciudad *, struct ciudad *);
void dia_mas_frio_provincia(struct ciudad *, struct ciudad *, struct ciudad *);
void dia_mas_calido_ciudad(struct ciudad *);
int main(int argc, char *argv[]){
	Tratamiento t;
    struct ciudad *stakptr=NULL;
    struct ciudad *new_node=NULL;
	struct ciudad *new_node2=NULL;
	struct ciudad *head_1=NULL;//CORDOBA.
	struct ciudad *head_2=NULL;//SANTA FE.
	struct ciudad *head_3=NULL;//MENDOZA.
    char op=' ',cass=' ',nombre[50];
	int id=0,valor=0,horas=0,minutos=0,dias=0,meses;
    float hum=0.0f,tempe=0.0f;
    FILE *fp;
    fp = fopen("data_set.txt","r");
    check(fp);
	printf("MENU DE OPCIONES: \n");
    while (fscanf(fp,"%d %d %s %f %f %d %d %d %d", &id,&valor,&nombre,&tempe,&hum,&horas,&minutos,&dias,&meses) != EOF){
        new_node = (struct ciudad *) malloc(sizeof(ciudad));
		new_node = (struct ciudad *) new_node;
		//---------------------------------------------------------------------------------
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
		//---------------------------------------------------------------------------------
		switch(valor){
		case 1:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_1;
			head_1 = new_node2;
			break;
		case 2:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_2;
			head_2 = new_node2;
			break;
		case 3:
			new_node2=NULL;
			new_node2 = (struct ciudad *) malloc(sizeof(ciudad));
			new_node2 = (struct ciudad *) new_node2;
			new_node2->ciudad_id=id;
			new_node2->provincia=valor;
			for(int i=0;i<50;i++){
				new_node2->nombre_ciudad[i] = nombre[i];
			}
			new_node2->clime.temp=tempe;
			new_node2->clime.humedad=hum;
			new_node2->clime.time.horas=horas;
			new_node2->clime.time.minutos=minutos;
			new_node2->clime.time.dia=dias;
			new_node2->clime.time.mes=meses;
			new_node2->next = head_3;
			head_3 = new_node2;
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
        printf("F)Dia mas frio de cada provincia.\n");
        printf("G)Dia mas calido de cada ciudad.\n");
        printf("H)Mejor provincia para cultivar pimientos.\n");//Temperatura promedio cercana a 23 C
        scanf(" %c",&cass);
        switch (cass)
        {
        case 'a':
        case 'A':
			t.cantMuestras();
            break;
        case 'b':
        case 'B':
			promedio_temp_provincias(head_1,head_2,head_3);
            break;
        case 'c':
        case 'C':
			promedio_temp_ciudad(stakptr);
            break;
        case 'd':
        case 'D':
			ciudad_mas_calidad_provincias(head_1,head_2,head_3);
            break;
        case 'e':
		case 'E':
			ciudad_mas_fria_provincias(head_1,head_2,head_3);
            break;
        case 'f':
        case 'F':
			dia_mas_frio_provincia(head_1, head_2, head_3);
            break;
        case 'g':
        case 'G':
			dia_mas_calido_ciudad(stakptr);
            break;
        case 'h':
        case 'H':
			t.promPimientos();
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
void promedio_temp_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	float suma=0.0f,promedio=0.0f,cant=0.0f;
	struct ciudad *temp=NULL;
	temp=head_1;
	while(temp!=NULL){
		cant++;
		suma=(suma+temp->clime.temp);
		temp=temp->next;
	}
	promedio=suma/cant;
	printf("PROMEDIO DE TEMPERATURAS DE CORDOBA: %f\n",promedio);
	suma=0;
	promedio=0;
	cant=0;
	temp=head_2;
	while(temp!=NULL){
		cant++;
		suma=(suma+temp->clime.temp);
		temp=temp->next;
	}
	promedio=suma/cant;
	printf("PROMEDIO DE TEMPERATURAS DE SANTA FE: %f\n",promedio);
	suma=0;
	promedio=0;
	cant=0;
	temp=head_3;
	while(temp!=NULL){
		cant++;
		suma=(suma+temp->clime.temp);
		temp=temp->next;
	}
	promedio=suma/cant;
	printf("PROMEDIO DE TEMPERATURAS DE MENDOZA: %f\n",promedio);
	suma=0;
	promedio=0;
	cant=0;
}
void promedio_temp_ciudad(struct ciudad *sp){
	float promedio=0.0f,suma=0.0f;
	int contador=0,i=0;
	struct ciudad *temp=NULL;
	temp=sp;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			printf("El promedio de %s es: %f\n",temp->nombre_ciudad,promedio);
			i=0;
			suma=0;
			contador++;
		}
		temp=temp->next;
	}
	printf("EL TOTAL DE MUESTRAS ES: %d\n",contador);
}
void ciudad_mas_calidad_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	struct ciudad *temp=NULL;
	float suma=0.0f, mayor_temp=0.0f,promedio=0.0f;
	char nombre[50];
	int i=0;
	temp=head_1;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS CALIDA DE CORDBA ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
	suma=0;
	i=0;
	mayor_temp=0;
	temp=head_2;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS CALIDA DE SANTA FE ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
	suma=0;
	i=0;
	mayor_temp=0;
	temp=head_3;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio>mayor_temp){
				mayor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS CALIDA DE MENDOZA ES: %s , con una temperatura promedio de: %f\n",nombre,mayor_temp);
}
void ciudad_mas_fria_provincias(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	struct ciudad *temp=NULL;
	float suma=0.0f,promedio=0.0f,menor_temp=100;
	char nombre[50];
	int i=0;
	temp=head_1;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio<menor_temp){
				menor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE CORDBA ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
	suma=0;
	menor_temp=100;
	temp=head_2;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio<menor_temp){
				menor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE SANTA FE ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
	suma=0;
	menor_temp=100;
	temp=head_3;
	while(temp!=NULL){
		suma=(suma+temp->clime.temp);
		i++;
		if(i==80){
			promedio=suma/80.0;
			if(promedio<menor_temp){
				menor_temp=promedio;
				for(int j=0;j<50;j++){
					nombre[j]=temp->nombre_ciudad[j];
				}
			}
			i=0;
			suma=0;
		}
		temp=temp->next;
	}
	printf("LA CIUDAD MAS FRIA DE MENDOZA ES: %s , con una temperatura promedio de: %f\n",nombre,menor_temp);
}
void dia_mas_frio_provincia(struct ciudad *head_1, struct ciudad *head_2, struct ciudad *head_3){
	struct ciudad *temp=NULL;
	float menor_temp=100;
	float menor_temp_ciudad=100;
	int dia=0;
	char nombre[50];
	temp=head_1;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;
			}
		}
		if(temp->clime.temp==menor_temp_ciudad){
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Cordoba es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
	menor_temp=100;
	menor_temp_ciudad=100;
	temp=head_2;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;
			}
		}
		if(temp->clime.temp==menor_temp_ciudad){
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Santa Fe es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
	menor_temp=100;
	menor_temp_ciudad=100;
	temp=head_3;
	while(temp!=NULL){
		if(temp->clime.temp<menor_temp){
			menor_temp=temp->clime.temp;
			if(menor_temp<menor_temp_ciudad){
				menor_temp_ciudad=menor_temp;
			}
		}
		if(temp->clime.temp==menor_temp_ciudad){
			dia=temp->clime.time.dia;
			for(int j=0;j<50;j++){
				nombre[j]=temp->nombre_ciudad[j];
			}
		}
		temp=temp->next;
	}
	printf("El dia mas frio de Mendoza es el %d, en la ciudad de %s con una temperatura de %f\n",dia,nombre,menor_temp_ciudad);
}
void dia_mas_calido_ciudad(struct ciudad *sp){
	float mayor_temp=0.0f;
	int dia=0,i=0,mes=0;
	struct ciudad *temp=NULL;
	temp=sp;
	while(temp!=NULL){
		i++;
		if(temp->clime.temp>mayor_temp){
			mayor_temp=temp->clime.temp;
			if(temp->clime.temp==mayor_temp){
				dia=temp->clime.time.dia;
				mes=temp->clime.time.mes;
			}
		}
		if(i==80){
			printf("El dia mas calido de %s es el: %d del mes %d, con una tempertura de: %f\n",temp->nombre_ciudad,dia,mes,mayor_temp);
			i=0;
			mayor_temp=0;
			dia=0;
		}
		temp=temp->next;
	}
}
