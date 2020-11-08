#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Personas { /*Registro*/
	long ci;
	char na[20],cn[15],dip[40];
	int  fn;
	};
	
/* Funciones*/
void AgregarP(struct Personas *pers);
int ValidarPN(struct Personas *pers);
//int ValidarPS(struct Personas *pers);
void ConsultarP(struct Personas *pers);
void ModificarP(struct Personas *pers);
void EliminarP(struct Personas *pers);


int main()
{
	struct Personas per;
	int op;
	
	do
	{     //Menu principal
	 
     printf("\t Menu \n\n");
     printf("1. Agregar\n");
     printf("2. modificar\n");
     printf("3. consultar\n");
     printf("4. Eliminar\n");
     printf("0. Salir\n");
     scanf("%d",&op);
     system("cls");
     
     switch(op){
     	 
     	 case 1: 
     	      printf("Introduzca los siguientes datos\n para agregar a una persona\n\n");
     	      AgregarP(&per);
     	      ValidarPN(&per);
     	    //  ValidarPS(&per);
     	     
     	      system("cls");
     	      
     	 break;
     	 
     	 case 2:
     	 	printf("Modifique sus datos a su parecer (la cedula no se modifica)");
     	 	ModificarP(&per);
         break;
         
         case 3:
         	printf("Los datos de la persona introducidas son: \n\n");
         	ConsultarP(&per);
          	system("cls");
        break;
        
        case 4:
             EliminarP(&per);
           
             system("cls");
        break;
        
        case 0:
        break;
     	
	 }
   	  
   	
   	  
   }while(op!=0);
   
   return(0);
   system("pause");
   	  
}  /*Fin main*/

void AgregarP(struct Personas *pers)  /*Funcion agregar Persona*/
{
	
	printf("Cedula: ");
	scanf("%d",&pers->ci);
	printf("\nNombre y Apellido: ");
	fflush(stdin);
	fgets(pers->na,20,stdin);
    printf("\nFecha de nacimiento (yyyymmdd).  \nEscribir entre: A"); printf("%c",164); printf("o (1900-2100)");
    printf("| Mes(01-12) | Dia(01-31): ");
    scanf("%d",&pers->fn);
    printf("\nCiudad de nacimiento: ");
	fflush(stdin);
	gets(pers->cn);
	printf("\nDireccion: ");
	fflush(stdin);
	gets(pers->dip);
  
}

int ValidarPN(struct Personas *pers)
{
   int x= pers->ci, y=pers->fn, fn1,fn2,fn3,fn4,cont;
   
   
    if((scanf("%d",&x)!=1) && (scanf("%d",&y)!=1))
   {
   	return 0;
	   }
    else
    {
     
	 for(cont=0; cont>=6 && cont<=8; cont++)
	 {
	 	y/=10;
	 
	 if(cont>=6 && cont<=8)
	 {
	 	fn1=pers->fn/10000; //yyyy
	 	fn2=pers->fn%10000;
	 	fn3=fn2/100; //mm
	 	fn4=fn2%100; //dd
	 	
	 	if((fn1>=1900||fn1<=2100) && (fn3>=1||fn3<=12) &&(fn4>=1||fn4<=31))
	 	{
	 		return 1;
	    }
	 }	
	}  	
	}

	  return 1;

}

/*int ValidarPS(struct Personas *pers)
{
  int i;
  
   for(i=1; pers->na; i++)
   {
   	if(isalpha(pers->na[i])==0 && pers->na!=32)
   	{
   		return 0;
	   }
   }
 return 1;
}*/


void ConsultarP(struct Personas *pers)  /*Funcion consultar Persona*/
{
	int cons,ci1;
	char na1[20];
	
	printf("%c",168); printf("Como desea hacer la consulta?\n\n");
	printf("1. Cedula\n");
	printf("2. Nombre\n\n");
	printf("Introduzca opcion: ");
	
	scanf("%d",&cons);
	system("cls");
	
	switch(cons)
	{
		case 1:
		do
		{
		  printf("escriba la cedula correspondiente\n");
		  printf("CI: ");
		  scanf("%d",&ci1);
		  system("cls");
		  
		  if (ci1 == pers->ci)
		  {
		  	printf("\n\nLa persona solicitada por CI: %d",ci1);
		  	printf("\n Cedula: %d",pers->ci);
		  	printf("\nNombre: %s",pers->na);
		  	printf("\nFecha de Nacimiento: %d",pers->fn);
		  	printf("\nCiudad de nacimiento: %s",pers->cn);
		  	printf("\nDireccion: %s",pers->dip);
		  	printf("\n\n");
		  	
		  	system("pause");
		  }
		  else
		  {
		  	printf("\n\nLa cedula introducida no coincide con alguna del sistema");
		  	printf("\nPor favor vuelva a introducirla\n\n");
		  }
	  }while(ci1!=pers->ci);
	 
	  system("pause");
	  break;
	
	case 2:
		do
		{
		  printf("escriba el nombre correspondiente\n");
		  printf("Nombre: ");
		  fflush(stdin);
		  gets(na1);
		  strcmp(na1,pers->na);
		  system("cls");
		 
		  if (strcmp(na1,pers->na)==0)
		  {
		  	printf("\n\nLa persona solicitada por nombre: %s",na1);
		  	printf("\n Cedula: %d",pers->ci);
		  	printf("\nNombre: %s",pers->na);
		  	printf("\nFecha de Nacimiento: %d",pers->fn);
		  	printf("\nCiudad de nacimiento: %s",pers->cn);
		  	printf("\nDireccion: %s",pers->dip);
		  	printf("\n\n");
		  	
		  	system("pause");
		  }
		  else
		  {
		  	printf("\n\nEL nombre introducido no coincide con alguno del sistema");
		  	printf("\nPor favor vuelva a introducirlo\n\n");
		  }
	    }while(na1!=pers->na);
	  
	  system("pause");
    break;
    }
} /*Fin ConsultarP*/

void ModificarP(struct Personas *pers) /*Funcion modificar Persona*/
{
	printf("Introducira los mismos datos de ser requerido y cambiar el que desee\n\n");
	printf("Nombre y apellido: ");
	fflush(stdin);
	gets(pers->na);
	printf("\nFecha de nacimiento (yyyymmdd): ");
	scanf("%d",&pers->fn);
	printf("\nCiudad de nacimiento: ");
	fflush(stdin);
	gets(pers->cn);
	printf("\nDireccion: ");
	fflush(stdin);
	gets(pers->dip);
	
	
} /*Fin modificar Persona*/

void EliminarP(struct Personas *pers) /*Funcion eliminar Persona*/
{
   printf("Se eliminaran los datos de la persona en el sistema");
   pers->ci=' ';
   memset(pers->na,' ',20);
   pers->fn=' ';
   memset(pers->cn,' ',15);
   memset(pers->dip,' ',40);
   printf("Cargando...");
   system("pause");
} /*Fin eliminar Persona*/
 
