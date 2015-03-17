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
	int dimsize;
	int mes,dia,anio,hora,min,alpha;
	float radon,error,temp,hum,tilt;
	
	/*DECLARATION OF NETCDF VARIABLES*/
	int  stat;  /* return status */
    int  ncid;  /* netCDF id */

    /* dimension ids */
    int time_dim;
    /* dimension lengths */
    size_t time_len = dimsize;
    /* variable ids */
    int Radon_id;
    int Error_id;
    int Temp_id;
    int Hum_id;
    int Tilt_id;
    int AlphaCounts_id;
    /* rank (number of dimensions) for each variable */
#   define RANK_data 1
    /* variable shapes */
    int Radon_dims[RANK_data];
    int Error_dims[RANK_data];
    int Temp_dims[RANK_data];
    int Hum_dims[RANK_data];
    int Tilt_dims[RANK_data];
    int AlphaCounts_dims[RANK_data];

	/* DEFINE MODE */
    stat = nc_create("RadonMembrana.nc", NC_CLOBBER, &ncid);
    check_err(stat,__LINE__,__FILE__);

    /* define dimensions */
    stat = nc_def_dim(ncid, "time", time_len, &time_dim);
    check_err(stat,__LINE__,__FILE__);

    /* define variables */
    Radon_dims[0] = time_dim;
    stat = nc_def_var(ncid, "Radon", NC_INT, RANK_data, Radon_dims, &Radon_id);
    check_err(stat,__LINE__,__FILE__);
    Error_dims[0] = time_dim;
    stat = nc_def_var(ncid, "Error", NC_INT, RANK_data, Error_dims, &Error_id);
    check_err(stat,__LINE__,__FILE__);
    Temp_dims[0] = time_dim;
    stat = nc_def_var(ncid, "Temp", NC_INT, RANK_data, Temp_dims, &Temp_id);
    check_err(stat,__LINE__,__FILE__);
    Hum_dims[0] = time_dim;
    stat = nc_def_var(ncid, "Hum", NC_INT, RANK_data, Hum_dims, &Hum_id);
    check_err(stat,__LINE__,__FILE__);
    Tilt_dims[0] = time_dim;
    stat = nc_def_var(ncid, "Tilt", NC_INT, RANK_data, Tilt_dims, &Tilt_id);
    check_err(stat,__LINE__,__FILE__);
    AlphaCounts_dims[0] = time_dim;
    stat = nc_def_var(ncid, "AlphaCounts", NC_INT, RANK_data, AlphaCounts_dims, &AlphaCounts_id);
    check_err(stat,__LINE__,__FILE__);

    /* leave define mode */
    stat = nc_enddef (ncid);
    check_err(stat,__LINE__,__FILE__);

	
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
			//printf("mes:%d dia:%d anio:%d hora:%d min:%d radon:%g error:%g temp:%g hum:%g til:%g count:%d\n",mes,dia,anio,hora,min,radon,error,temp,hum,tilt,alpha);
		}else { 
			// Sacamos numero de registros, longitud de variables
			if(strncmp(linea,"Data Records",strlen("Data Records"))==0){
				sscanf(linea,"Data Records %d",&dimsize);
				/* dimension lengths */
    			size_t time_len = dimsize;
				//printf("%d",dimsize);
			/* Buscamos la linea que empiece por  Time*/
			}else if(strncmp(linea,"Time",strlen("Time"))==0){
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
	/*y el nc*/
	stat = nc_close(ncid);
    check_err(stat,__LINE__,__FILE__);
	/*y salimos del programa*/
	return 0;
}

