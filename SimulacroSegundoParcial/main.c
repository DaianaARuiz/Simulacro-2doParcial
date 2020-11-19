#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
PARTE 1
1- El área de casting del programa La Voz solicita a nuestra empresa el diseño de un sistema que
permita registrar y administrar los datos de los participantes de la segunda temporada del
programa. Para ello es necesario contar con los siguientes datos de un participante.
Concursante

● numeroConcursante (int)
● año de nacimiento
● nombre (string, 50)
● dni (string, 8, valor entre 9.000.000 y 45.000.000)
● fechaPresentacion (Date)
● temaPresentacion (string, 30)
● puntajePrimeraRonda(int)

Los datos van a estar cargados en un archivo .CSV

El programa contará con el siguiente menú:
1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los
elementos del mismo.
2) Imprimir Datos: Se imprimirá por pantalla la tabla con los datos .
Continua...
*****************************************************/


int main()
{
    printf("\n*********************************************************************************");
    printf("\n\t\t\tSIMULACRO SEGUNDO PARCIAL \n\n Alumna:Ruiz Daiana Ayelen\n Division:1C \n");
    printf("\n*********************************************************************************\n");

    int option = 0;
    char nameArchive[20];
    LinkedList* listaParticipantes = ll_newLinkedList();

    if(listaParticipantes!=NULL)
    {
        do{
            printf("\n1. Cargar los datos (modo texto).\n2.Imprimir los datos.\n10. Salir\n");
            inputs_getAndValidateInt(&option,"\nIngrese su opcion: ","Error.Debe ingresar un numero:","\nError,solo puedes ingresar del [1] al [10]:",1,10);

            switch(option)
            {
                case 1:
                    inputs_PedirNombreArchivo("Ingrese el nombre del archivo: ","Nombre invalido. Reingrese: ",20,nameArchive);
                    if(controller_loadFromText(nameArchive,listaParticipantes))
                    {
                        printf("\nLos datos fueron cargados en modo Texto.\n");
                    }else{
                    printf("\nError al cargar los datos.\n");}
                    break;
                case 2:
                    if(ll_isEmpty(listaParticipantes)==0){
                      if(controller_ListParticipant(listaParticipantes)!=1)
                      {
                           printf("\nError. No se pudo cargar la lista.\n");
                      }
                    }else{
                         printf("\nError. No hay empleados cargados.\n");
                    }
                    break;
                case 3:
                    break;
                case 4:

                    break;
                case 5:
                    break;
                case 6:

                    break;
                case 7:

                    break;
                case 8:
                    break;
                case 9:
                    break;
            }
        }while(option != 10);
    }else
    {
        printf("Error. No hubo espacio en memoria para cargar la lista.");
    }

    return 0;
}
