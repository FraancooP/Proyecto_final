class Tratamiento
{
private:
	int ciudad_id;
	int provincia_id;
	char nombre_ciudad[50];
	float temperaturas;
	float humedades;
	int hora;
	int minutos;
	int dias;
	int mes;
public:
    Tratamiento();//CONSTRUCTOR
    ~Tratamiento();//DESTRUCTOR
	void cantMuestras();
	void promPimientos();
};
Tratamiento::Tratamiento()
{
}
Tratamiento::~Tratamiento()
{
}
void Tratamiento::cantMuestras(){
	int contador_cordoba=0,contador_santa_fe=0,contador_mendoza=0;
	FILE *fp=NULL;
	fp=fopen("./data_set.txt","r");
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
		exit(1);
	}
	while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &ciudad_id,&provincia_id,&nombre_ciudad,&temperaturas,&humedades,&hora,&minutos,&dias,&mes) != EOF){
		if(provincia_id==1){
			contador_cordoba++;
		}else if(provincia_id==2){
			contador_santa_fe++;
		}else if(provincia_id==3){
			contador_mendoza++;
		}
	}
	fclose(fp);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN CORDOBA: %d\n",contador_cordoba);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN SANTA FE: %d\n",contador_santa_fe);
	printf("CANTIDAD DE TEMPERATURAS REGISTRADAS EN MENDOZA: %d\n",contador_mendoza);
}
void Tratamiento::promPimientos(){
	int contador_cordoba=0,contador_santa_fe=0,contador_mendoza=0;
	float promedio_cordoba=0.0f,promedio_santa_fe=0.0f,promedio_mendoza=0.0f,suma_1=0.0f,suma_2=0.0f,suma_3=0.0f;
	float promedios[3]={0};
	float mayor_promedio=0.0f;
	FILE *fp=NULL;
	fp=fopen("./data_set.txt","r");
	if(fp==NULL){
		printf("Imposible abrir el archivo.\n");
		exit(1);
	}
	while(fscanf(fp,"%d %d %s %f %f %d %d %d %d", &ciudad_id,&provincia_id,&nombre_ciudad,&temperaturas,&humedades,&hora,&minutos,&dias,&mes) != EOF){
		if(provincia_id==1){
			contador_cordoba++;
			suma_1=suma_1+temperaturas;
		}else if(provincia_id==2){
			contador_santa_fe++;
			suma_2=suma_2+temperaturas;
		}else if(provincia_id==3){
			contador_mendoza++;
			suma_3=suma_3+temperaturas;
		}
	}
	fclose(fp);
	promedio_cordoba=suma_1/contador_cordoba;
	promedio_santa_fe=suma_2/contador_santa_fe;
	promedio_mendoza=suma_3/contador_mendoza;
	promedios[0]=promedio_cordoba;
	promedios[1]=promedio_santa_fe;
	promedios[2]=promedio_mendoza;
	for(int i=0;i<3;i++){
		if(promedios[i]>mayor_promedio){
			mayor_promedio=promedios[i];
		}
	}
	if(mayor_promedio==promedio_cordoba){
		printf("La temperatura promedio mas cercana a 23 es %f de la provincia de Cordoba.\n",mayor_promedio);
	}else if(mayor_promedio==promedio_santa_fe){
		printf("La temperatura promedio mas cercana a 23 es %f de la provincia de Santa Fe\n",mayor_promedio);
	}else if(mayor_promedio==promedio_mendoza){
		printf("La temperatura promedio mas cercana a 23 es de %f de la provincia de Mendoza\n",mayor_promedio);
	}
}
