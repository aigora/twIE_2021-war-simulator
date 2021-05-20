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
int escribir_nombres(int num_nombres);
int manual_simple(int num_bots);
int automatico_complex(int num_bots);

int main()
{
	int opcion,num_bots;
	logo();
	opcion = menu();
	printf("\n");
	while (1)
	{
		printf("Introduzca el numero de bots (max 30): ");
		scanf("%i",&num_bots);
		if (num_bots>1)
		{
			if (num_bots<31)
			{
				break;
			}
			else
			{
				printf("Error, debes introducir un numero entero mayor que 1 y menor que 31. \n");	
				printf("%d es mayor que 30. \n",num_bots);	
			}
		}
		else
		{
			printf("Error, debes introducir un numero entero mayor que 1 y menor que 31. \n");
			printf("%d es menor que 2. \n",num_bots);
		}
	}
	switch (opcion)
	{
		case 1:
			manual_simple(num_bots);
			break;
		case 2:
			//automatico_simple(num_bots);
			break;
		case 3:
			//manual_complex(num_bots);
			break;
		case 4:
			printf("Todo ok \n");
			automatico_complex(num_bots);
			break;
		case 5:
			//continuar_partida();
			break;
	}
	return 0;
}

//EL MENÚ
//la funcion menu imprime el menu y le al jugador opciones a elegir
int menu()
{
	int repetir=1;
	printf("Eliga 1 entre las siguentes opciones(Introduzca el numero): \n");
	int opcion;
	printf("1.Manual simple(Se introducen manualmente los nombre)(todas las rondas se llevan acabo de manera aleatoria) \n");
	printf("2.Automatica simple(Solo introduces un nombre y el resto son puestos por el pc)(todas las rondas se llevan acabo de manera aleatoria)  \n");
	printf("3.Manual complex(Se introducen manualmente los nombre)(El usuario elige en cada ronda que 2 bots se enfrentan) \n");
	printf("4.Automatica complex(Solo introduces un nombre y el resto son puestos por el pc)(El usuario elige en cada ronda que 2 bots se enfrentan)  \n");
	printf("5.Continuar la partida anterior. \n");
	while (repetir=1)
	{
		scanf("%i", &opcion);
		switch (opcion)
		{
		//De momento solo imprime el número introducido.
		case 1:
			return opcion;
			repetir=0;
			break;
		case 2:
			return opcion;
			repetir=0;
			break;
		case 3:
			return opcion;
			repetir=0;
			break;
		case 4:
			return opcion;
			repetir=0;
			break;
		case 5:
			return opcion;
			repetir=0;
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

//Esta función enfrenta a 2 bots y mata a uno
int kill(bots bot1, bots bot2)
{
	//cada baja suma una probabilidad de 30 puntos
	//realmente el número muerte indica quien se salva
	int muerte;
	muerte = num_aleatorio(200+bot1.kills*30+bot2.kills*30);
	if (muerte<(100+bot1.kills*30))
	{
		//si muerte pertenece a bot1 muere bot2
		printf("%s ha matadao a %s. \n",bot1.nombre,bot2.nombre);
		return 1;
	}
	else 
	{
		printf("%s ha matadao a %s. \n",bot2.nombre,bot1.nombre);
		return 2;
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

//Esta función pregunta al usuario los nombres que quiere introducir y los copia en un fichero
int escribir_nombres(int num_nombres)
{
	int i;
	const b = num_nombres;
	bots nombres[b];
	FILE *fnombres_introducidos;
	fnombres_introducidos = fopen("fnombres_introducidos.txt","w");
	if (fnombres_introducidos == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		for (i=0;i<num_nombres;i++)
		{
			printf("Introduce nombre %i: ",i+1);
			scanf("%s",&nombres[i].nombre);
			fprintf(fnombres_introducidos,"%s \n",nombres[i].nombre);
		}
	}
}

//La función de la primera opción
int manual_simple(int num_bots)
{
	//Bots vivos irá disminuyendo a medida que vayan muriendo
	//Bots total se mantendrá constante para que los vectores no den problemas
	FILE *fbots_vivos;
	FILE *fbajas_bots;
	fbots_vivos = fopen("fbots_vivos.txt","w");
	fbajas_bots = fopen("fbajas_bots.txt","w");
	int num1,num2,num_muertes,i,bot_vivo,ii;
	num_muertes = 0;
	const b = num_bots;	
	bots bot[b];
	for (i=0;i<num_bots;i++)
	{
		printf("Introduce nombre numero %i: ",i+1);
		scanf("%30s", bot[i].nombre);
		bot[i].kills = 0;
		fprintf(fbots_vivos,"%s \n",bot[i].nombre);
		fprintf(fbajas_bots,"0 \n");
	}
	fclose(fbots_vivos);
	fclose(fbajas_bots);
	for (i=0;i<num_bots-1;i++)
	{
		num1 = num_aleatorio(num_bots-num_muertes);
		num2 = num_aleatorio(num_bots-num_muertes);
		//Para que num1 y num2 sean distintos
		while (num1==num2)
		{
			num2 = num_aleatorio(num_bots-num_muertes);
		}
		bot_vivo = kill(bot[num1-1],bot[num2-1]);
		num_muertes += 1;
		if (bot_vivo == 1)
		{
			bot[num1-1].kills += 1;
			for (ii=0;ii<num_bots-num2;ii++)
			{
				strcpy(bot[num2+ii-1].nombre, bot[num2+ii].nombre);
				bot[num2+ii-1].kills = bot[num2+ii].kills;
			}
		}
		else
		{
			bot[num2-1].kills += 1;
			for (ii=0;ii<num_bots-num1;ii++)
			{
				strcpy(bot[num1+ii-1].nombre, bot[num1+ii].nombre);
				bot[num1+ii-1].kills = bot[num1+ii].kills;
			}
		}
		fbots_vivos = fopen("fbots_vivos.txt","w");
		fbajas_bots = fopen("fbajas_bots.txt","w");
		printf("Bots restantes: ");
		for (ii=0;ii<num_bots-num_muertes;ii++)
		{
			printf("%s, ",bot[ii].nombre);
			fprintf(fbots_vivos,"%s \n",bot[ii].nombre);
			fprintf(fbajas_bots,"%i \n",bot[ii].kills);
		}
		fclose(fbots_vivos);
		fclose(fbajas_bots);
		printf("\n");
		if (i == num_bots-2)
		{
			printf("%s ha ganado con %d bajas",bot[0].nombre,bot[0].kills);
		}
		congelar_tiempo(T);
	}
}

int automatico_complex(int num_bots)
{
	FILE *fbots_vivos;
	FILE *fbajas_bots;
	fbots_vivos = fopen("fbots_vivos.txt","w");
	fbajas_bots = fopen("fbajas_bots.txt","w");
	FILE *fnombres_auto;
	fnombres_auto = fopen("fnombres_auto.txt","r");
	int nivel,i=1,ii,ok,num_muertes,num1,num2,bot_vivo;
	num_muertes = 0;
	const b = num_bots;
	char bot1[30], bot2[30];
	bots bot[b];
	while (1)
	{
		printf("Intoduce el nivel de dificultad 1-5: ");
		scanf("%i",&nivel);
		if (nivel > 0)
		{
			if (nivel < 6)
			{
				break;
			}
			else
			{
				printf("Error, debes meter un nivel entre 1 y 5 \n");
				printf("%d es mayor que 5 \n",nivel);
			}
		}
		else
		{
			printf("Error, debes meter un nivel entre 1 y 5 \n");
			printf("%d es menor que 1 \n",nivel);
		}
	}
	//Para dar una ventaja se le da un numero inicial de bajas al personaje
	bot[0].kills = 5-nivel;
	printf("Introduce el nombre de tu personaje: ");
	scanf("%s", bot[0].nombre);
	fprintf(fbots_vivos,"%s \n", bot[0].nombre);
	fprintf(fbajas_bots,"0 \n");
	printf("Los bots son: \n");
	printf("%s \n", bot[0].nombre); 
	while (i<num_bots)
	{
		fscanf(fnombres_auto, "%[^\n]\n", bot[i].nombre);
		if (strcmp(bot[i].nombre,bot[0].nombre) == 0)
		{
			strcpy(bot[i].nombre, "Jackson");
		}
		fprintf(fbots_vivos,"%s \n", bot[i].nombre);
		fprintf(fbajas_bots,"0 \n");
		bot[i].kills = 0;
		printf("%s \n",bot[i].nombre);
		i++;
	}
	fclose(fbots_vivos);
	fclose(fnombres_auto);
	fclose(fbajas_bots);
	for (i=0;i<num_bots-1;i++)
	{
		ok = 0;
		while (ok == 0)
		{
			printf("Introduce el nombre del primer bot: ");
			scanf("%s30", bot1);
			for (ii=0;ii<num_bots-num_muertes;ii++)
			{
				if (strcmp(bot1,bot[ii].nombre) == 0)
				{
					num1 = ii;
					ok = 1;
					break;
				}
				if (ii == num_bots-num_muertes-1)
				{
					printf("Error, has metido un nombre no valido o que ya ha muerto. Vuelve a probar. \n");
				}
			}
		}
		ok = 0;
		while (ok == 0)
		{
			printf("Introduce el nombre del segundo bot: ");
			scanf("%30s",bot2);
			for (ii=0;ii<num_bots-num_muertes;ii++)
			{
				if (strcmp(bot2,bot[ii].nombre) == 0)
				{
					num2 = ii;
					ok = 1;
					break;
				}
				if (ii == num_bots-num_muertes-1)
				{
					printf("Error, has metido un nombre no valido o que ya ha muerto. Vuelve a probar. \n");
				}
			}
			while (1)
			{
				if (strcmp(bot1,bot2) == 0)
				{
					printf("Error, has metido 2 veces el mismo nombre. Vuelve a probar. \n");
				}
				else
				{
					break;
				}
				printf("Introduce el nombre del segundo bot: ");
				scanf("%30s",bot2);
			}
		}
		bot_vivo = kill(bot[num1],bot[num2]);
		num_muertes += 1;
		if (bot_vivo == 1)
		{
			bot[num1].kills += 1;
			for (ii=0;ii<num_bots-num2;ii++)
			{
				strcpy(bot[num2+ii].nombre, bot[num2+ii+1].nombre);
				bot[num2+ii].kills = bot[num2+ii+1].kills;
			}
		}
		else
		{
			bot[num2].kills += 1;
			for (ii=0;ii<num_bots-num1;ii++)
			{
				strcpy(bot[num1+ii].nombre, bot[num1+ii+1].nombre);
				bot[num1+ii].kills = bot[num1+ii+1].kills;
			}
		}
		fbots_vivos = fopen("fbots_vivos.txt","w");
		fbajas_bots = fopen("fbajas_bots.txt","w");
		printf("Bots restantes: ");
		for (ii=0;ii<num_bots-num_muertes;ii++)
		{
			printf("%s, ",bot[ii].nombre);
			fprintf(fbots_vivos,"%s \n",bot[ii].nombre);
			fprintf(fbajas_bots,"%i \n",bot[ii].kills);
		}
		fclose(fbots_vivos);
		fclose(fbajas_bots);
		printf("\n");
		if (i == num_bots-2)
		{
			printf("%s ha ganado con %d bajas",bot[0].nombre,bot[0].kills);
		}
	}
}
