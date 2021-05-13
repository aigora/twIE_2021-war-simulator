#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h> 
#include <windows.h>

#define N 30
#define T 30000
//T es el tiempo que dejamos entre cada muerte(30s)

//Estructuras:

//Estructura bots:
typedef struct{
	char nombre[30]; //Nombre y apellido
	int kills; //Las bajas que lleva. Inicialmente son 0.
}bots;
//Estructura fechas:
struct fecha{
	int year; //Año
	int mes;
	int dia; 
};

int menu();
int logo();
int num_aleatorio(int num);
int kill(bots bot1, bots bot2);
int congelar_tiempo(int tiempo);
int leer_nombres();

int main()
{
	logo();
	menu();
}

//EL MENÚ
//la funcion menu imprime el menu y le al jugador opciones a elegir
int menu()
{
	//No me deja hacer con true/false asi que repetir hace de true
	int repetir=1;
	printf("Eliga 1 entre las siguentes opciones(Introduzca el numero): \n");
	int opcion;
	printf("1.Manual simple(Se introducen manualmente los nombre)(todas las rondas se llevan acabo de manera aleatoria) \n");
	printf("2.Automatica simple(Solo introduces un nombre y el resto son puestos por el pc)(todas las rondas se llevan acabo de manera aleatoria)  \n");
	printf("3.Manual complex(Se introducen manualmente los nombre)(El usuario elige en cada ronda que 2 bots se enfrentan) \n");
	printf("4.Automatica complex(Solo introduces un nombre y el resto son puestos por el pc)(El usuario elige en cada ronda que 2 bots se enfrentan)  \n");
	while (repetir=1)
	{
		scanf("%i", &opcion);
		switch (opcion)
		{
		//De momento solo imprime el número introducido.
		case 1:
			printf("Has elegido %i \n", opcion);
			return repetir=0;
			break;
		case 2:
			printf("Has elegido %i \n", opcion);
			return repetir=0;
			break;
		case 3:
			printf("Has elegido %i \n", opcion);
			return repetir=0;
			break;
		case 4:
			printf("Has elegido %i \n", opcion);
			return repetir=0;
			break;
		default:
			printf("%i", opcion);
			printf(" no es una opcion valida. Recuerda que debes introducir 1,2,3 o 4. \n");
		}
	}
	//devuelve la opcion elegida
	return opcion;
}

//Este es el logo(editable)
int logo()
{
	printf("  ***************************************************************************** \n");
	printf("  |                                                                           |\n");
	printf("  |        w           w           w           a           rrrrrrrrrr         |       \n");
	printf("  |         w         w w         w           a a          r         r        |       \n");
	printf("  |          w       w   w       w           a   a         r         r        |       \n");
	printf("  |           w     w     w     w           aaaaaaa        rrrrrrrrrr         |       \n");
	printf("  |            w   w       w   w           a       a       r         r        |       \n");
	printf("  |             w w         w w           a         a      r         r        |       \n");
	printf("  |              w           w           a           a     r         r        |       \n");
	printf("  |                                                                           |\n");
	printf("  ***************************************************************************** \n");
	printf("\n");
	printf("\n");
}

//Esta función devuelve un número aleatorio entre del 1 a num
int num_aleatorio(int num)
{
	int n;
	srand(time(NULL));
	n = rand() % num + 1;
	return n;
}

int kill(bots bot1, bots bot2)
{
	//cada baja suma una probabilidad de 30 puntos
	//realmente el número muerte indica quien se salva
	int muerte;
	muerte = num_aleatorio(200+bot1.kills*30+bot2.kills*30);
	if (muerte<(100+bot1.kills*30))
	{
		//si muerte pertenece a bot1 muere bot2
		printf("%c ha matadao a %c. \n",bot1.nombre,bot2.nombre);
	}
	else 
	{
		printf("%c ha matadao a %c. \n",bot2.nombre,bot1.nombre);
	}
}

//Esta función congela el programa durante un tiempo T
int congelar_tiempo(int tiempo)
{
	int i;
	Sleep(tiempo);
	//for (i=0;i<100;i++)
	//{
		//printf("Cargando...%i /%",i);
		//Sleep(tiempo);
		//system("cls");
	//}
}

//Esta función lee los nombres de los bots vivivos restantes
int leer_nombres()
{
	int i = 0;
	bots nombres[N];
	FILE *fbots_vivos;
	fbots_vivos = fopen("fbots_vivos.txt", "r");
	if (fbots_vivos == NULL)
	{// Si el resultado es NULL mensaje de error
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		printf("Bots vivos: \n");
		while(fscanf(fbots_vivos, "%[^\n]\n", nombres[i].nombre) != EOF)
		{
		    printf("Nombre %i: %s\n", i+1, nombres[i].nombre);
		    i++;
		}
	}
}
