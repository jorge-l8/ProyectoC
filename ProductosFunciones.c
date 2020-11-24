#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Producto /*Registro Producto*/
	{
		int cod;
		char *descripcion;
		int ppu;
		int activo;
	};
	
struct Empresa /*Registro Empresas*/
	{
		int codigo;
		int tipo;
		char *nombre; 
		char *direccion;
		char *telefono;
		struct ListaProductos *p;
	};
	
struct ListaEmpresas /*Lista de Empresas*/
	{
		struct Empresa *emp;
		struct ListaEmpresas *prox;
	};

struct ListaPersonas /*Lista de Personas*/
	{
		struct Personas *pers;
		struct ListaPersonas *prox;
	};

/***************************************Funciones auxiliares**************************************/

int validarnumeros(char *p)
{
	char *aux = p;
	do{
		if (*aux<'0' || *aux>'9')
			return 0;
	}while(*++aux);
	return 1;
};

int validarstring(char *p)
{
	char *aux = p;
	do{
		char charstr = *aux;
		if(!(isalpha(charstr)) && charstr!= 32){
			return 0;
		}	
	}while(*++aux);
	return 1;
};

int validaralphanum(char *p)
{
	char *aux = p;
	do{
		char charstr = *aux;
		if(!(isalnum(charstr)) && charstr != 32){
			return 0;
		}
	}while(*++aux);
	return 1;
}

void eliminarnl(char s1[])
{
  if (strlen(s1) >0 && s1[strlen(s1)-1] == '\n')
    s1[strlen(s1)-1] = '\0';
};



/***********************************Fin funciones auxiliares*************************************/


/*Funciones usadas en main*/

//funciones productos
struct Empresa *buscarempresacod(struct ListaEmpresas *pemp);
void mostrarproducto(struct Empresa *pi);
void agregarproducto(struct Empresa *p);
void modificarproducto(struct Empresa *pemp);
void eliminarproducto(struct Empresa *pi);

//funciones empresas
void agregarempresa(struct ListaEmpresas **pemp);
void modificarempresa(struct ListaEmpresas *pemp);
void consultarempresa(struct ListaEmpresas *pemp);
void eliminarempresa(struct ListaEmpresas **pemp);

/*************************************************************PROGRAMA PRINCIPAL**********************************************************/
	
int main(void){
	/*Punteros a las lista de empresas y lista de personas*/
	struct ListaEmpresas *pemp = NULL;
	struct ListaPersonas *ppers = NULL;	
	
	int oppe = 0, ope = 0, opeyp = 0;
	
	/*puntero a la empresa que el usuario elija*/
	struct Empresa *prod = NULL; 
	int inprod;
	
	/*Menu empresas*/
	do{
		printf("\n\tMenu Empresas y Productos");
		printf("\n\n\t1. Menu Empresas");
		printf("\n\t2. Menu Productos");
		printf("\n\t0. Salir");
		printf("\n\n\tOpcion: ");
		scanf("%d", &opeyp);
		switch(opeyp){
			
		 case 1: /* Menu Empresas*/
				do{
				   system("CLS");
	 			   printf("\n\n\tBienvenido al Menu de Empresas \n\n\t"); printf("%c",168);
				   printf("Que desea hacer? \n");
				   printf("\t1. Agregar empresa \n");
				   printf("\t2. Modificar empresa \n");
				   printf("\t3. Consultar empresa \n");
				   printf("\t4. Eliminar empresa \n");
				   printf("\t0. Volver al Menu Empresas y Productos\n\n");
				   printf("\tOpcion: "); scanf("%d",&ope);
				   system("cls");
				   switch(ope)
				   {
				   	case 1: /* Agregar Empresa */
				   		agregarempresa(&pemp);
			   			break;
			   	
				   	case 2: /* Modificar Empresa*/
						modificarempresa(pemp);
				   		break;
				   	
				   	case 3: /* Consultar Empresa*/
						consultarempresa(pemp);
						break;
				   	
				   	case 4: /* Eliminar Empresa*/
				   		eliminarempresa(&pemp);
				   		break;
				   	
				   	case 0: /* 
					   Vuelve al menu*/
				   		break;
				   	
				   	default:
				   		printf("\n\n\tIntroduzca un numero entero entre 0 y 4. Intente nuevamente.\n\n\t");
				   		break;
				   }
				   system("CLS");
		    }while(ope);
			break;
		
		case 2: /*Menu Productos*/
			inprod = 0;
		 	do{
					 system("cls");
					if( !(inprod) && !(prod=buscarempresacod(pemp))){
						printf("No se encontro una empresa en el sistema con el codigo introducido. Agregue dicha empresa o intente nuevamente.\n\n\t");
						system("PAUSE");
						break;
					}
				   inprod = 1;
				   printf("\n\t\t%s\n",prod->nombre);
			 	   printf("\n\tBienvenido al Menu de Productos\n\n\t"); printf("%c",168);
			 	   printf("Que desea hacer? \n\n");
			 	   printf("\t1. Agregar producto \n");
			 	   printf("\t2. Modificar producto \n");
			 	   printf("\t3. Consultar producto \n");
			 	   printf("\t4. Eliminar producto \n");
			 	   printf("\t0. Volver al Menu Empresas y Productos\n\n");
			 	   printf("\tOpcion: "); 
				   scanf("%d",&oppe);
			 	   
			 	   system("cls");
			 	   switch(oppe)
			 	   {
			 	   	 case 1: /* Agregar producto*/
						agregarproducto(prod);
			 	   	    break;
			 	   	 
			 	   	 case 2: /* Modificar producto*/
			 	   	 	modificarproducto(prod);
						break;
			
			 	   	 case 3: /* Consultar producto*/
						mostrarproducto(prod);
						break;
			 	   	 
			 	   	 case 4: /*Eliminar producto*/
			 	   	    eliminarproducto(prod);
			 	   		break;
			 	   	    
			 	   	 case 0:
			 	   	 	break;
			 	   	
			 	   	 default:
			 	   	 	break;
			 	   }
			 	   	system("CLS");
		 	}while(oppe);
		
		}
		system("CLS");
	}while(opeyp);

	return 0;
};


/****************************************************MENU DE EMPRESAS*************************************************/

/************************************FUNCIONES AGREGAR EMPRESA********************************************/
int leercodigoemp(void)
{
	int cod;
	do{
		printf("\n\tIntroduzca el codigo de la empresa : ");
		fflush(stdin);
		if(scanf("%d",&cod)!=1 || cod <= 0 ){
			printf("\n\tIntroduzca un numero positivo mayor a 0. Intente nuevamente.\n\n\t");
		}
		else{
			//WARNING: No se ha validado si hay otra empresa con el mismo codigo
				return cod;
			}
		system("PAUSE");
		system("CLS");
	}while(1);	
};

char *leernombreemp(void)
{
	static char nombre[20];
	//char *returnptr = (char*) malloc(20 + 1);
	char *returnptr = NULL;
	do{
		printf("\n\tIntroduzca el nombre de la empresa: ");
		fflush(stdin);
		fgets(nombre, 20, stdin);
		eliminarnl(nombre);
		if(!(validarstring(nombre))){
			printf("\n\n\tERROR. Debe introducir una cadena que solo contenga caracteres alfabeticos. Intente nuevamente\n\n");
		}
		else{
			//strcpy(returnptr,nombre);
			returnptr = nombre;
			return returnptr;
			//return strdup(&nombre[0]);
		}	
		system("PAUSE");
		system("CLS");
	}while(1);
};

int leertipoemp(void)
{
	int tipo = 0;
	do{
		printf("\n\tTipo de empresa \n");
		printf("\n\tOpciones: (1)Comida (2)Alimentos (3)General \n\n");
		printf("\n\tOpcion: ");
		fflush(stdin);
		scanf("%d",&tipo);
		if (tipo != 1 && tipo != 2 && tipo != 3){
			printf("\n\tEl numero seleccionado '%d' no se encuentra dentro de las opciones. Intente nuevamante\n\n\t", tipo);
		}
		else{
			return tipo;
		}
		system("PAUSE");
		system("CLS");
	}while (1);
};

char *leertelfemp(void)
{
	char static telefono[12];
	//char *returnptr = (char*) malloc(12 + 1);
	char *returnptr = NULL;
	do{
		printf("\n\tTelefono de la empresa: ");
		fflush(stdin);
		fgets(telefono, 12, stdin);
		eliminarnl(telefono);
		if(!(validarnumeros(telefono))){
			printf("\n\tEl telefono debe estar compuesto solo de numeros. Intente nuevamente.\n\n\t");
		}
		else{
			//strcpy(returnptr,telefono);
			returnptr = telefono;
			return returnptr;
			//return strdup(&telefono[0]);
		}
		system("PAUSE");					
		system("CLS");
	}while(1);
};

char *leerdireccionemp(void)
{
	char static direccion[40];
	//char *returnptr = (char*) malloc(40);
	char *returnptr = NULL;
	do{
		printf("\n\tIntroduzca la direccion de la empresa: ");
		fflush(stdin);
		fgets(direccion, 40, stdin);
		eliminarnl(direccion);
		if(!(validaralphanum(direccion))){
			printf("\n\tLa direccion solo puede contener caracteres alfanumericos. Intente nuevamente.\n\n\t");
		}
		else{
			//strcpy(returnptr,direccion);
			returnptr = direccion;
			return returnptr;
			//return strdup(&direccion[0]);
		}
		system("PAUSE");
		system("CLS");
	}while(1);
};

/**********************************FIN FUNCIONES AGREGAR EMPRESA******************************/

/*Funcion que agrega una empresa a la lista ListaEmpresas publica*/
void agregarempresa(struct ListaEmpresas **pemp)
{
	int codigo, tipo;
	char *nombre, *tlf, *direccion ;
	
	/*leer codigo*/ 
	
	// WARNING: Falta permitir al usuario salir si introduce un codigo repetido
	codigo = leercodigoemp();
	system("CLS");

	/*leer nombre*/
	nombre = leernombreemp();
	system("CLS");
	
	/*leer tipo*/
	tipo = leertipoemp();
	system("CLS");
	
	/*leer telefono*/
	tlf = leertelfemp();
	system("CLS");
	
	/*leerdireccion*/
	direccion = leerdireccionemp();
	system("CLS");
		
	struct ListaEmpresas *newemp = (struct ListaEmpresas*) malloc(sizeof(struct ListaEmpresas));
	newemp->emp = (struct Empresa*) malloc(sizeof(struct Empresa));
	newemp->emp->codigo = codigo;
	newemp->emp->nombre = (char*) malloc(sizeof(char)*12);
	strcpy(newemp->emp->nombre,nombre);
	newemp->emp->tipo = tipo;
	newemp->emp->telefono = (char*) malloc(sizeof(char)*20);
	strcpy(newemp->emp->telefono,tlf);
	newemp->emp->direccion = (char*) malloc(sizeof(char)*40);
	strcpy(newemp->emp->direccion,direccion);	
	newemp->prox = *pemp;
	*pemp = newemp;
	
	/*puntero a la lista de productos*/
	newemp->emp->p = NULL;
	return;
};


/*Rutina para modificar algun renglon de una empresa existente en el sistema*/
void modificarempresa(struct ListaEmpresas *pemp)
{
	struct Empresa *auxemp = NULL;
	int op;
	if((auxemp = buscarempresacod(pemp))){
		do{
			printf("\n\t\t%c",168); printf("Que desea modificar?: \n\n");
			printf("\t1. Codigo \n");
			printf("\t2. Nombre\n");
			printf("\t3. Tipo\n");
			printf("\t4. Telefono\n");   
			printf("\t5. Direccion\n");
			printf("\t0. Volver al Menu Empresas \n\n");
			printf("\tIntroduzca una opcion: "); scanf("%d",&op);
			system("cls");
			switch(op){	
				case 1: 
					auxemp->codigo = leercodigoemp();
					printf("\n\n\tCodigo modificado exitosamente\n\n\t");
					break;   		
			   	
			   	case 2:
					strcpy(auxemp->nombre, leernombreemp());
					printf("\n\n\tNombre modificado exitosamente\n\n\t");
					break;
					
				case 3:
					auxemp->tipo = leertipoemp();
					printf("\n\n\tTipo modificado exitosamente\n\n\t");
					break;
		
				case 4:
					strcpy(auxemp->telefono,leertelfemp());
					printf("\n\n\tTelefono modificado exitosamente\n\n\t");
					break;
					
				case 5:
					strcpy(auxemp->direccion,leerdireccionemp());
					printf("\n\n\tDireccion modificada exitosamente\n\n\t");
					break;
				
				case 0:
					break;
				
				default:
					printf("\n\tERROR. Por favor introduzca un numero entero entre 0 y 5. Intente nuevamente.\n\t");
					break;			
			}
			system("PAUSE");
			system("CLS");
		}while(op);
	}
	else{
		printf("\n\n\tNo se encontro ninguna empresa en el sistema con el codigo introducido. Intente nuevamente.\n\t");
		system("PAUSE");
		system("CLS");
		return;
	}
};

/*Rutina que muestra los componentes de una determinada empresa*/
void mostrarempresa(struct Empresa *empresa)
{
	struct Empresa *aux = empresa;
	char nomcpy[20];
	strcpy(nomcpy, aux->nombre);
	strupr(nomcpy);
	printf("\n\t\t%s\t\t\n",nomcpy);
	printf("\n\tCodigo: %d", aux->codigo);
	printf("\n\tNombre: %s",aux->nombre);
	switch(aux->tipo){
		case 1:
			printf("\n\tTipo: Comidas");
			break;
		
		case 2:
			printf("\n\tTipo: Alimentos");
			break;
			
		case 3:
			printf("\n\tTipo: General");
			break;
		
	}
	printf("\n\tTelefono: %s",aux->telefono);
	printf("\n\tDireccion: %s\n\n\t",aux->direccion);
	system("PAUSE");
	system("CLS");
	return; 
};

/*Rutina para mostrar todos los renglones de una determinada empresas en el sistema*/
void consultarempresa(struct ListaEmpresas *pemp)
{
	struct Empresa *buscarempresanom(struct ListaEmpresas *pemp);
	struct ListaEmpresas *aux1 = pemp;
	struct Empresa *actemp = NULL;
	int op;
	do{
		printf("\n\t%c",168);printf("Como desea buscar la empresa a consultar?\n\n");
		printf("\t1. Por Codigo.\n");
		printf("\t2. Por Nombre.\n\n");
		printf("\tOpcion: ");
		fflush(stdin);
		scanf("%d", &op);
		switch(op){
			case 1:
				if(actemp = buscarempresacod(aux1)){
					//mostrarempresa(aux1->prox->emp);
					mostrarempresa(actemp);
				}
				else{
					printf("\n\n\tEl codigo de la empresa que introdujo no se encuentra en el sistema. Intente nuevamente\n\n\t");
					system("PAUSE");
				}
				break;
			
			case 2:
				if((actemp = buscarempresanom(aux1))){
					mostrarempresa(actemp);
				}
				else{
					printf("\n\n\tEl nombre de la empresa que introdujo no se encuentra en el sistema. Intente nuevamente\n\n\t");
					system("PAUSE");
				}
				break;
		}
		system("CLS");	
	}while(op != 1 && op != 2);
};

void eliminare(struct ListaEmpresas **pemp, struct Empresa *emp)
{
	struct ListaEmpresas *aux = *pemp;
	int codigo = emp->codigo; 
	if (aux){ /*asegurarse que la lista no sea vacia*/
		if(aux->emp->codigo == codigo){
			(*pemp) = (*pemp)->prox;
			free(aux);
		}
		else{
			while ((aux->prox)&& (aux->prox->emp->codigo != codigo))
				aux = aux->prox;
			if (aux->prox){
				struct ListaEmpresas *aux2 = aux->prox;
				aux->prox = aux->prox->prox;
				free(aux2);
			}
	}
	}
};

/*Rutina para eliminar una empresa del sistema*/
void eliminarempresa(struct ListaEmpresas **pemp)
{
	struct ListaEmpresas *aux = *pemp;
	struct Empresa *emp;
	if((emp = buscarempresacod(aux))){
		eliminare(&*pemp, emp);
		printf("\n\n\tEmpresa eliminada exitosamente. \n\n\t");
	}
	else{
		printf("\n\n\tEl codigo de la empresa no se encuentra registrado en la empresa. Agreguela o intente nuevamente\n\n\t");
	}
	system("PAUSE");
	system("CLS");
};



/************************************************FIN MENU DE EMPRESAS***************************************************/


/****************************************************MENU DE PRODUCTOS*************************************************/

struct ListaProductos /*Lista de Productos*/
	{
		struct Producto *prod;
		struct ListaProductos *prox;
	};



/**************RUTINA MADRE DE MENU PRODUCTOS y EMPRESAS *************/

struct Empresa *buscarempresacod(struct ListaEmpresas *pemp)
{
	struct ListaEmpresas *aux = pemp;
	int cemp = leercodigoemp();
	struct Empresa *returnptr = (struct Empresa*) malloc(sizeof(struct Empresa));
	while(aux){
		if (aux->emp->codigo == cemp){
			printf("\n\n\tSelecciono la empresa '%s'.", aux->emp->nombre);
			printf("\n\tCargando...");
			sleep(1);
			system("CLS");
			returnptr = aux->emp;
			return returnptr;
		}
		aux = aux->prox;
	}
	free(returnptr);
	return NULL;
};

struct Empresa *buscarempresanom(struct ListaEmpresas *pemp)
{
	struct ListaEmpresas *aux = pemp;
	char *nomemp = leernombreemp();
	struct Empresa *returnptr = (struct Empresa*) malloc(sizeof(struct Empresa));
	while(aux){
		if (!(strcmp(nomemp, aux->emp->nombre))){
			printf("\n\n\tSelecciono la empresa '%s'.", aux->emp->nombre);
			printf("\n\tCargando...");
			sleep(1);
			system("CLS");
			returnptr = aux->emp;
			return returnptr;
		}
		aux = aux->prox;
	}
	free(returnptr);
	return NULL;	
}

/***********FIN RUTINA MADRE MENU PRODUCTOS************/

/****** FUNCIONES AGREGAR PRODUCTO ******/
int leercodigoprod(void)
{
	int cprod;	
	do{
		printf("\n\n\tIntroduzca el codigo del producto: ");
		fflush(stdin);
		if (scanf("%d", &cprod)!=1 || cprod<=0){
   	 		printf("\n\n\tEl codigo del producto debe ser numerico (mayor que 0).\n\n\t");
			system("PAUSE");
			system("CLS"); 
			 }
		else{
			return cprod;
		}
	}while(1);
};

char *leerdescripcionprod(void)
{
	char static desc[20];
	char *returnptr = NULL;
	do{
   	 	printf("\n\n\tIntroduzca una breve descripcion del mismo (no mayor a 20 caracteres): ");
   	 	fflush(stdin);
		fgets(desc, 20, stdin);
   	 	eliminarnl(desc);
   		if(!validaralphanum(desc)){
   			printf("\n\n\tDebe introducir una estructura que solo contenga caracteres alfabeticos. Intente nuevamente.\n\n\t");
			}
		else{
			returnptr = desc;
			return returnptr;
		}
		system("PAUSE");
   		system("CLS");
	}while(1);
};

int leerppuprod(void)
{
	int ppu;
	do{
		printf("\n\n\tIntroduzca el precio por unidad: ");
		fflush(stdin);
		if(scanf("%d", &ppu)!=1){
	 			printf("\n\nEl precio por unidad del producto debe ser numerico(mayor que 0). Pulse cualquier tecla para intentar nuevamente.\n\n\t");
				system("PAUSE");
				system("CLS"); 
			 }
		else{
			return ppu;
		}
	}while(1);
}

int leerdisponibilidadprod(void)
{
	int op;
	do{
		printf("\tIntroduzca la nueva disponibilidad del producto: \n");
		printf("\t\t0. No disponible.\n");
		printf("\t\t1. Disponible.\n\n");
		printf("\t\tOpcion: ");
		fflush(stdin);
		scanf("%d",&op);
		if(op == 1 || op == 0){return op;}
		system("CLS");
	}while(1);
}

/******** FIN FUNCIONES AGREGAR PRODUCTO *******/


/*Funcion que guarda los valores que se pasen como parametros en el registro al que este apuntando el puntero*/
void agregarproducto(struct Empresa *p)
{
	int cprod;
	char *descptr;
	int ppu;
	
	/*Introduccion del codigo*/
	cprod = leercodigoprod();
	system("CLS");
	
	/*Introduccion de la descripcion*/
	descptr = leerdescripcionprod();
	system("CLS");
	
	/*Introduccion del precio por unidad*/
	ppu = leerppuprod();
	system("CLS");	
	
	struct ListaProductos *newprod = (struct ListaProductos *) malloc(sizeof( struct ListaProductos));
	newprod->prod = (struct Producto*) malloc(sizeof(struct Producto));
	newprod->prox = p->p;
	p->p = newprod;
	newprod->prod->cod = cprod;
	newprod->prod->descripcion = (char*) malloc(sizeof(char)*20);
	strcpy(newprod->prod->descripcion,descptr);
	newprod->prod->ppu = ppu;
	newprod->prod->activo = 1;
	return;
};

/*Rutina mediante la cual se busca un producto que retorna el puntero a dicho producto o NULL*/
struct Producto *buscarproducto(struct ListaProductos *pemp)
{
	int cprod = leercodigoprod();
	struct ListaProductos *aux = pemp;
	struct Producto *returnptr = (struct Producto*) malloc(sizeof(struct Producto));
	while(aux){
		if(aux->prod->cod == cprod){
			returnptr = aux->prod;
			return returnptr;
		}
		aux = aux->prox;
	}
	free(returnptr);
	return NULL;
};


/*Funcion que dado un apuntador muestra todos los renglones del producto al que esta apuntando*/
void mostrarproducto(struct Empresa *pi)
{
	struct Empresa *aux = pi;
	struct Producto *actp;
	char nomcpy[20];
	if((actp = buscarproducto(aux->p))){
			strcpy(nomcpy, actp->descripcion);
			strupr(nomcpy);
			printf("\n\t\t%s\t\t\n",nomcpy);
			printf("\n\tCodigo Producto: %d\n", actp->cod);
			printf("\tDescripcion: %s\n", actp->descripcion);
			printf("\tPrecio Por Unidad: %c %d\n", 36, actp->ppu);
			if(actp->activo){
				printf("\tDisponibilidad: DISPONIBLE\n\n\t");
			}
			else{
				printf("\tDisponibilidad: NO DISPONIBLE\n\n\t");
			}
		}
		else{
			printf("\n\tNo existe ningun producto con el codigo introducido en la empresa. Intente nuevamente\n\n\t");
		}
		system("PAUSE");
		system("CLS");
};

/*Rutina que elimina un producto en la lista de productos de una empresa*/
void eliminarprod(struct ListaProductos **pi, struct Producto *pf)
{
	struct ListaProductos *aux = *pi;
	int codigo = pf->cod; 
	if (aux) /*asegurarse que la lista no sea vacia*/
		if(aux->prod->cod == codigo){
			*pi = NULL;
			free(aux);
		}
		else{
			while ((aux->prox)&& (aux->prox->prod->cod != codigo))
				aux = aux->prox;
			if (aux->prox){
				struct ListaProductos *aux2 = aux->prox;
				aux->prox = aux->prox->prox;
				free(aux2);
			}
		}
};


/*Funcion que elimina un producto dado el apuntador a la lista de productos dado el apuntador a la Empresa determinada*/
void eliminarproducto(struct Empresa *pi)
{
	struct Empresa *aux =  pi;
	struct Producto *producto = NULL;
	if(producto = buscarproducto(aux->p)){
		eliminarprod(&aux->p, producto);
		printf("\n\n\tProducto eliminado exitosamente.\n\n\t");
	}
	else{
		printf("\n\n\tEl codigo del producto no se encuentra registrado en la empresa.\n\n\t");
	}
	system("PAUSE");
	system("CLS");
};


/*Rutina mediante la cual el usuario modifica un producto*/
void modificarproducto(struct Empresa *pemp)
{
	struct Empresa *aux = pemp;
	struct Producto *auxprod = NULL;
	int op = 0;

	if(auxprod = buscarproducto(pemp->p)){
		do{
			system("CLS");
		 	printf("\n\n\t\t%c",168); printf("Que desea modificar?: \n");
			printf("\t1. Codigo\n");
			printf("\t2. Descripcion\n");
			printf("\t3. Precio Por Unidad\n");
			printf("\t4. Disponibilidad.\n");
			printf("\t0. Volver al Menu de Productos\n\n");
			printf("\tOpcion: ");
			scanf("%d", &op);
			system("CLS");
			switch(op){
				case 1:
						/*modificar codigo*/
						auxprod->cod = leercodigoprod();
						printf("\n\n\tCodigo modificado exitosamente\n\n\t");
						break;
					
				case 2:
						/*modificar descripcion*/
						strcpy(auxprod->descripcion, leerdescripcionprod());
						printf("\n\n\tDescripcion modificada exitosamente\n\n\t");
						break;
					
				case 3:
						/*modificar precio por unidad*/
						auxprod->ppu = leerppuprod();
						printf("\n\n\tPrecio por unidad modificado exitosamente\n\n\t");
						break;
				
				case 4:
						/*modificar disponibilidad*/
						auxprod->activo = leerdisponibilidadprod();
						printf("\n\n\tDisponibilidad modificada exitosamente\n\n\t");
						break;
						
				case 0:
						break;
				
				default:
						printf("Numero invalido, el numero introducido debe estar entre 0 y 4. Intente nuevamente.\n\n");
						break;
			   }
			   	system("PAUSE");
		}while(op);
	}
	else{
		printf("\n\n\tEl codigo que introdujo no se encuentra en los productos registrados de la empresa.\n\n\t");
		system("\n\n\t");
		system("PAUSE");
		system("CLS");	
	}
};

/*************************************************FIN FUNCIONES PRODUCTOS*******************************************************/



