#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOMBREFICHERO "Membrana Texsa PVC negro arriba.txt"
#define MAXLINEA 1024

/* http://www.cplusplus.com/reference */

int main(){
	FILE* fid;
	char linea[MAXLINEA];
	int i,seccionDatos;
	
	int mes,dia,anio,hora,min,alpha;
	float radon,error,temp,hum,tilt;
	
	/*Abrimos el fichero de entrada*/
	fid=fopen(NOMBREFICHERO,"r");
	/*Leemos lineas mientras la funcion fgets no devuelva NULL*/
	/* http://www.cplusplus.com/reference/cstdio/fgets/ */
	seccionDatos=0;
	
	while(fgets(linea,MAXLINEA,fid)>0){
		
		if(seccionDatos){
			/*Time	Radon	Error	Temp.	Hum.	Tilt	Alpha Counts*/
			/*11/7/2012 14:35	14	100	19.5	49	249	1*/
			sscanf(linea,"%d/%d/%d %d:%d %f %f %f %f %f %d",&mes,&dia,&anio,&hora,&min,&radon,&error,&temp,&hum,&tilt,&alpha);
			printf("mes:%d dia:%d anio:%d hora:%d min:%d radon:%g error:%g temp:%g hum:%g til:%g count:%d\n",mes,dia,anio,hora,min,radon,error,temp,hum,tilt,alpha);
		}else { 
			/* Buscamos la linea que empiece por  Time*/
			if(strncmp(linea,"Time",strlen("Time"))==0){
				/* La siguiente linea "debe" ser las unidades*/
				fgets(linea,MAXLINEA,fid);
				/* y a parir de ahora leemos lineas de datos */
				seccionDatos=1;				
			}else if (strncmp(linea,"RESULTS",strlen("RESULTS"))==0){
				/* seccion de resultados*/
				
				
				
				
				
			}else{
				printf("ignorando: %s", linea);
			}
		}
	}
	/*Cerramos el fichero de entrada*/
	fclose(fid);
	/*y salimos del programa*/
	return 0;
}

