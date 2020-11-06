
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**//*/*/
struct Empresa{
	int codigo,tipo;
	char nombre[20],direccion[40],telefono[12];
	struct Producto *p;
};

int validarnumeros(char *p){
	do{
		if (*p<'0' or *p>'9')
			return 0;
	}while(*++p);
	return 1;
}

int validarstring(char *p){
	do{
		char charstr = tolower(*p);
		if(charstr<'a' || charstr>'z' && charstr!=32)
			return 0;
	}while(*++p);
	return 1;
}


int main(void){
	int prueba,ope,i=0;
	printf("Escoja el numero 1: ");
	scanf("%i",&prueba);
	switch (prueba){
		case 1:
	do{
	 			   printf("\n\nBienvenido al menu de empresas \n\n"); printf("%c",168);
				   printf("Que desea hacer? \n");
				   printf("1. Agregar empresa \n");
				   printf("2. Modificar empresa \n");
				   printf("3. Consultar empresa \n");
				   printf("4. Eliminar empresa \n");
				   printf("0. Volver al menu \n\n");
				   printf("Introduzca una opcion: "); scanf("%d",&ope);
				   system("cls");
				   switch(ope)
				   {
				   	case 1: /* Agregar Empresa */
				   	struct Empresa pro1;
				   	do{
						printf("Codigo de empresa(0-9999): \n");
						scanf("%i",&pro1.codigo);
						system("cls");
						if(pro1.codigo<=0 || pro1.codigo>9999){
							printf("Introduzca un numero entre 1 y 9999.\n\n");
							system("PAUSE");
						}
						system("cls");
					}while(pro1.codigo<=0 || pro1.codigo>9999);
					fflush(stdin);
					do{
						printf("Nombre de empresa: \n");
						gets(pro1.nombre);
						system("cls");
						if(!(validarstring(pro1.nombre))){
							printf("Validar string retorna: %d\n\n",validarstring(pro1.nombre));
							printf("Introduzca una cadena de caracteres. Intente nuevamente\n\n");
							system("PAUSE");
						}	
						system("cls");
					}while(!validarstring(pro1.nombre));
					do{
					printf("Tipo de empresa \n");
					printf("Opciones: (1)Comida (2)Alimentos (3)General \n");
					scanf("%i",&pro1.tipo);
					if (pro1.tipo != 1 && pro1.tipo != 2 && pro1.tipo != 3){
						printf("No selecciono bien la empresa. Vuelva a intentarlo\n\n");
						system("PAUSE");
					}
					system("cls");
					}while (pro1.tipo != 1 && pro1.tipo != 2 && pro1.tipo != 3);
					fflush(stdin);	
					do{
					printf("Telefono de la empresa: \n");
					gets(pro1.telefono);
					if(!(validarnumeros(pro1.telefono))){
						printf("El telefono debe estar compuesto solo de numeros.\n\n");
						system("PAUSE");
					}					
					system("cls");
					}while(!(validarnumeros(pro1.telefono)));
					fflush(stdin);
					printf("Direccion de la empresa: \n");
					gets(pro1.direccion);
					system("cls");
				   	
				   	break;
				   	
				   	case 2: /* Modificar Empresa*/
				   	
				   	break;
				   	
				   	case 3: /* Consultar Empresa*/
				   	printf("El codigo de la empresa es: %i",pro1.codigo);
					printf("\nEl nombre de la empresa es: %s",pro1.nombre);
					if (pro1.tipo == 1){
						printf("\nEl tipo de empresa es de Comida");
					}
					else if (pro1.tipo == 2){
						printf("\nEl tipo de empresa es de Alimentos");
					}
					else if (pro1.tipo == 3){
						printf("\nEl tipo de empresa es General");
					}
					printf("\nEl telefono de la empresa es: %s",pro1.telefono);
					printf("\nLa direccion de la empresa es: %s",pro1.direccion);
				   	break;
				   	
				   	case 4: /* Eliminar Empresa*/
				   	
				   	break;
				   	
				   	case 0: /* Vuelve al menu*/
				   	break;
				   	
				   	default:
				   		printf("Opcion introducida incorrecta");
				   	break;
				   	
				   }
			    }while(ope!=0);
			 	break;
			}
	return 0;
	}


