#include <stdio.h>
int main(void){
<<<<<<< Updated upstream
	
=======
	int op;
	/*Interfaz*/
	do{
		printf ("1.- Acceder a Personas\n");
		printf ("2.- Acceder a Empresas y Productos\n");
		printf ("3.- Acceder a Ordenes de Envio\n");
		printf ("4.- Acceder a Consultas\n\n\n");
		printf ("0.- Salir"); 
		
		scanf ("%d", &op);  /*Imprimir opciones*/
		switch(op){
			case 1:
			//Codigo//
			 printf ("%10s","Personas"); 
			 printf ("\t 1.-Agregar Persona");
			 printf ("\t 2.-Modificar Persona");
			 printf	("\t 3.-Consultar Cedula");
			 printf ("\t 4.-Consultar Nombre");
			 printf ("\t 5.-Eliminar Persona");
			 printf ("\t 6.-Volver al menu pricnicpal");
		     scanf ("%d", &opp);
		     switch(opp){
		     	case 1:
		     		do{
		     			system
					 }
			 }
			case 2:
			/*Codigo*/
			printf("1.-Agregar empresa \n");
			printf("2.-Modificar empresa \n");
			printf("3.-Consultar empresa \n");
			printf("4.-Eliminar empresa \n\n");
			printf("0.-Volver a menu inicial");
				do{
					system("CLS");
					printf("MENU EMPRESAS Y PRODUCTOS\n");
					printf("1.-Entrar a Menu Empresas\n");
					printf("2.-Entrar a Menu Productos\n\n");
					printf("0.-Salir\n");
					scanf("%d",&opeyp);
					switch(opeyp){
						case 1:
							do{
								system("CLS");
								printf("\tMENU EMPRESAS\n")
								printf("1.-Agregar empresa\n");
								printf("2.-Modificar empresa\n");
								printf("3.-Consultar empresa\n");
								printf("4.-Eliminar empresa\n");
								printf("0.-Volver a menu inicial\n");
								scanf("%d",&ope);
							}while(ope!=0);
							break;
						case 2:
							do{
								system("CLS");
								printf("\tMENU PRODUCTOS\n")
								printf("1.-Agregar producto\n");
								printf("2.-Modificar producto\n");
								printf("3.-Consultar producto\n");
								printf("4.-Eliminar producto \n");
								printf("0.-Volver a menu inicial\n");
								scanf("%d",&ope);
							break;
						case 0:
							break;
						default:
							break;
					}
					}while(op != 0);
			case 3:
				/*Codigo*/
			case 4:
				/*Codigo*/
			default:
				/*Codigo*/
		}
	}while(op!=0);
>>>>>>> Stashed changes
	return 0;
}
