#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Personas { /*Registro Personas*/
	long ci;
	char na[20],cn[15],dip[40];
	int  fn;
	};
	
/* Funciones Personas*/
void AgregarP(struct Personas *pers);
void ValidarP(struct Personas *pers);
void ConsultarP(struct Personas *pers);
void ModificarP(struct Personas *pers);
void EliminarP(struct Personas *pers);

int main()
{
 int op,opp,opep,ope,oppe,opoe,opc,opce,opcp,opcs;
 struct Personas per;

 
 do
 {
/* Menu Principal */
	system("cls");
    printf("\t Sistema %cummy  \n\n",165);
    printf("\t Menu Principal \n\n");
    printf("1. PERSONAS \n");
    printf("2. EMPRESAS \n");
    printf("3. ORDENES DE ENVIO \n");
    printf("4. CONSULTAS \n");
    printf("0. SALIR \n");
   	printf("\n Introduzca una opcion: "); scanf("%d",&op);
   	system("cls");
  
    switch(op)
	{
       
        case 1: /* Menu Personas*/
         do
		 {   system("cls");
             printf("\t Bienvenido al Menu de Personas \n\n");
             printf("Que desea realizar?\n\n");
             printf("1. Agregar Personas \n");
             printf("2. Modificar Persona \n");
             printf("3. Consultar Persona \n");
             printf("4.. Eliminar Persona\n");
             printf("0. Volver al menu\n\n");
             printf("Introduzca una opcion: "); scanf("%d",&opp);
             system("cls");
              switch(opp)
              {
              	case 1: /* Agregar Persona*/
              	  printf("Introduzca los siguientes datos\n para agregar a una persona\n\n");
     	          AgregarP(&per);
     	      
     	          system("cls");
              	break;
              	
              	case 2: /* Modificar Persona*/
              	  	printf("Modifique sus datos a su parecer (la cedula no se modifica)");
     	 	        ModificarP(&per);
              	    break;
               
               case 3: /* Consultar Persona*/
                    printf("Los datos de la persona introducidas son: \n\n");
         	ConsultarP(&per);
          	system("cls");
                    break;
                    
                case 4: /*Eliminar persona*/
                   EliminarP(&per);
           
             system("cls");
                break;
                
               case 0:
               		break;
               		
               default:
               	   printf("Opcion incorrecta debe introducir un numero entre 0 y 4. Intente nuevamente.\n");
               	   system("PAUSE");
               	   break;
			  }
   		 }while(opp!=0);
        break;
        
        case 2: /* Menu Empresas*/
	        do
	        {
	             system("cls");
	 			 printf("\t Bienvenido al Menu de Empresas y Productos \n\n"); printf("%c",168); 
				 printf("Donde desea entrar? \n\n");
				 printf("1. Menu Empresas \n");
				 printf("2. Menu Productos \n");  
				 printf("0. Volver al menu principal\n\n");
				 printf("Introduzca una opcion: ");	 scanf("%d",&opep);
				 system("cls");
				 switch(opep)
				 {
				 	case 1: /* Empresa*/
				 		do
				 		{
					 	   system("cls");	
					 	   printf("Bienvenido al Menu de Empresas \n\n"); printf("%c",168);
						   printf("Que desea hacer? \n\n");
						   printf("1. Agregar empresa \n");
						   printf("2. Modificar empresa \n");
						   printf("3. Consultar empresa \n");
						   printf("4. Eliminar empresa \n");
						   printf("0. Volver al menu de Empresas\n\n");
						   printf("Introduzca una opcion: "); scanf("%d",&ope);
						   system("cls");
						   switch(ope)
						   {
						   	case 1: /* Agregar Empresa*/
						   		break;
			
						   	case 2: /* Modificar Empresa*/
						   	   	break;
						   	
						   	case 3: /* Consuultar Empresa*/
						   	   	break;
						   	
						   	case 4: /* Eliminar Empresa*/
						   	  	break;
						   	
						   	case 0:
						   		break;
						   	
						   	default:
						   		printf("Opcion incorrecta debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
						   		system("PAUSE");
						   		break;	
						   }
					    }while(ope!=0);
					 	break;
				 	
				 	case 2: /* Menu Productos*/
					 	do
					 	{
					 	   system("cls");
					 	   printf("Bienvenido al Menu de Productos\n\n"); printf("%c",168);
					 	   printf("Que desea hacer? \n\n");
					 	   printf("1. Agregar producto \n");
					 	   printf("2. Modificar producto \n");
					 	   printf("3. Consultar producto \n");
					 	   printf("4. Eliminar producto \n");
					 	   printf("0. Volver al menu principal \n\n");
					 	   printf("Introduzca una opcion: "); scanf("%d",&oppe);
					 	   
					 	   system("cls");
					 	   switch(oppe)
					 	   {
					 	   	 case 1: /* Agregar producto*/
					 	   	    break;
					 	   	 
					 	   	 case 2: /* Modificar producto*/
					 	   	    break;
			
					 	   	 case 3: /* Consultar producto*/
					 	   	  	break;
					 	   	 
					 	   	 case 4: /*Eliminar producto*/
					 	   	    break;
					 	   	    
					 	   	 case 0:
					 	   	 	break;
					 	   	 
					 	   	 default:
					 	   	 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
					 	   	 	system("PAUSE");
        						break;
					       }
					    }while(oppe!=0);   
					 	break;
					
					case 0:
						break;
					 }	 
		    }while(opep!=0);
	        break;
        
        case 3: /* Menu Ordenes de envio*/
	        do
	        {
	        	 system("cls");
	             printf("\t Bienvenido al Menu Ordenes de envio \n\n"); printf("%c",168);
	             printf("Que desea hacer? \n\n");
	             printf("1. Solicitar envio \n");
	             printf("2. Modificar envio \n");
	             printf("3. Consultar envio \n");
	             printf("4. Cierre de envio \n");
	             printf("5. Eliminar envio \n");
	             printf("0. Volver al menu principal \n\n");
	             printf("Introduzca una opcion: "); scanf("%d",&opoe);
	             system("cls");
	             switch(opoe)
	             {
	               case 1: /*solicito de envio*/ 
				   		break;
				   
				   case 2: /*modificar envio*/
				   	    break;
				   
				   case 3: /* Consultar envio*/
				        break;
				   
				   case 4: /* cierre de envio*/	
				   	    break;
				   
				   case 5: /* eliminar envio*/
				        break;
				    
				   case 0:
				   		break;
				
				   default:
					 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
					 	system("PAUSE");
        				break;
				 }
	                  
	        }while(opoe!=0);
	        break;
        
        case 4: /* Menu Consultas*/
	        do
	        {
	          system("cls");
	          printf("\t Bienvenido al Menu de Consultas \n\n"); printf("%c",168);
	          printf("Que desea consultar? \n\n");
	          printf("1. Empresas\n");
	          printf("2. Personas\n");
	          printf("3. Sistema\n");
	          printf("0. Volver al menu principal\n\n");
	          printf("Introduzca una opcion: "); scanf("%d",&opc);
	          system("cls");
	          switch(opc)
	          {
	          	case 1: /*consulta de empresa*/
		          	do
		          	{
		          	   system("cls");
		          	   printf("Bienvenido al Menu Consulta de Empresas\n\n"); printf("%c",168);
		          	   printf("Que desea ver?\n\n");
		          	   printf("1. Movimiento del sistema\n");
		          	   printf("2. Movimiento de empresa\n");
		          	   printf("3. Movimiento de cliente\n");
		          	   printf("4. Notoriedad en clientes\n");
		          	   printf("5. Notoriedad en empresas\n");
		          	   printf("0. Volver al menu\n\n");
		          	   printf("Introduzca una opcion: "); scanf("%d",&opce);
		          	   system("cls");
		          	   switch(opce)
		          	   {
		          	   	 case 1: /*Movimiento del sistema*/
		          	   	 	break;
		          	   	 
		          	   	 case 2: /*Movimiento de empresa*/
		          	   	    break;
		          	   	 
		          	   	 case 3: /* movimiento del cliente*/
		          	   	    break;
		          	   	 
		          	   	 case 4: /*notoriedad cliente*/
		          	   	    break;
		          	   	 
		          	   	 case 5: /*notoriedad empresa*/
		          	   	    break;
		          	   	    
		          	   	 case 0:
		          	   	 	break;
		          	   	 
		          	   	 default:
		          	   	 	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	   	 	system("PAUSE");
		          	   	 	break;
					   }
		            }while(opce!=0);
		           	break;
	          	
	          	case 2: /* Consulta de persona*/
		          	do
		          	{
		          	   system("cls");
		          	   printf("Bienvenido al Menu Consulta de Personas\n\n"); printf("%c",168);
		          	   printf("Que desea ver?\n\n");
		          	   printf("1. Persona en general\n");
		          	   printf("2. Persona y empresa\n");
		          	   printf("0. Volver al menu\n\n");
		          	   printf("Introduzca una opcion: "); scanf("%d",&opcp);
		          	   system("cls");
		          	   switch(opcp)
		          	   {
		          	   	case 1: /*Persona general*/
		          	   	  	break;
		          	   	
		          	   	case 2: /*Persona y empresa*/
		          	   	   	break;
		          	    	
		          	    default:
		          	    	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	    	system("PAUSE");
		          	    	break;
						 }
		            }while(opcp!=0);
		          	break;
          	
	          	case 3: /* consulta de sistema*/
		          	do
		          	{
		              system("cls");
		          	  printf("\t Bienvenido al Menu Consulta del Sistema\n\n"); printf("%c",168);
		          	  printf("Que desea ver?\n\n");
		          	  printf("1. Ingreso por empresa\n");
		          	  printf("2. Producto vendido por empresa\n");
		          	  printf("3. Compra por persona\n");
		          	  printf("4. Producto comprado por persona\n");
		          	  printf("5. Nro de facturas\n");
		          	  printf("0. Volver al menu\n\n");
		          	  printf("Introduzca una opcion: "); scanf("%d",&opcs);
		          	  
		          	  system("cls");
		          	  switch(opcs)
		          	  {
		          	  	case 1: /*ingreso empresa*/
		          	  	  	break;
		          	  	
		          	  	case 2: /* Producto vendido por empresa*/
		          	  	  	break;
		          	  	
		          	  	case 3: /*Compra por persona*/
		          	  	  	break;
		          	  	
		          	  	case 4: /*producto comprado por persona*/
		          	  	  	break;
		          	  	
		          	  	case 5: /*nro de facturas*/
		          	  	  	break;
		          	  		
		          	  	default:
		          	  		printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		          	  		system("PAUSE");
		          	  		break;
					  }
		          	  
		           }while(opcs!=0);
		          	break;
		        
		        case 0:
		        	break;
		          	
		        default:
		        	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
		        	system("PAUSE");
		        	break;
				  }
		        }while(opc!=0);
		        break; 
		
		case 0:
			break;   
        
        default:
        	printf("Opcion incorrecta, debe introducir un numero entre 0 y 4. Intente nuevamente.\n\n");
        	system("PAUSE");
        	break;
	}
 } while(op!=0);
   
   system("pause");
   return(0);
   
} //Fin del main


void AgregarP(struct Personas *pers)  /*Funcion agregar Persona*/
{
	
	printf("Cedula: ");
	scanf("%d",&pers->ci);
	printf("\nNombre y Apellido: ");
	fflush(stdin);
    gets(pers->na);
    printf("\nFecha de nacimiento (yyyymmdd).  \nEscribir entre: A"); printf("%c",164); printf("o (1900-2100)");
    printf("| Mes(01-12) | Dia(01-31): ");
    scanf("%d",&pers->fn);
    printf("\nCiudad de nacimiento: ");
	fflush(stdin);
	gets(pers->cn);
	printf("\nDireccion: ");
	fflush(stdin);
	gets(pers->dip);
  
} //Fin void agregarP


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
        
