#include <stdio.h>
#include <stdlib.h>

<<<<<<< Updated upstream
int main()
{
 int op,opp,opep,ope,oppe,opoe,opc,opce,opcp,opcs;
 
 
=======
void mostrarportada(void);

int main(void)
{
 int op,opp,opep,ope,oppe,opoe,opc,opce,opcp,opcs;
 

>>>>>>> Stashed changes
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
             printf("3. Eliminar Persona \n");
             printf("0. Volver al menu principal\n\n");
             printf("Introduzca una opcion: "); scanf("%d",&opp);
             system("cls");
              switch(opp)
              {
              	case 1: /* Agregar Persona*/
              	   	break;
              	
              	case 2: /* Modificar Persona*/
              	    break;
               
               case 3: /* Eliminar Persona*/
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
   
} 
<<<<<<< Updated upstream
=======

/*********************************************FUNCIONES Y PROCEDIMIENTOS **************************************************/
 	
void mostrarportada(void)
{	 
	char hola[]="Sistema Nummy",nombre1[]="Jorge Leon",nombre2[]="Jose Felipe",nombre3[]="Pedro Leal",nombre4[]="Gianpiero Yorlano";
	printf("\t\t%s",hola);
	char nombre1[]="Jorge Leon",nombre2[]="Jose Felipe",nombre3[]="Pedro Leal",nombre4[]="Gianpiero Yorlano";
	printf("\t\tSistema");printf(" %c",165); printf("ummy");
	printf("\n\n\tIntegrantes del Proyecto: ");
	printf("\n\n\t%s \n\t%s \n\t%s \n\t%s\n\n",nombre1,nombre2,nombre3,nombre4);
	system("PAUSE");
}

>>>>>>> Stashed changes
