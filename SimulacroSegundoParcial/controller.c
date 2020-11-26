#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "participantes.h"
#include "funcionesAuxiliares.h"
#include "parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListeParticipant)
{
    FILE* pFile;
    int retorno=0;

    if(pArrayListeParticipant!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            retorno = parser_eParticipantFromText(pFile,pArrayListeParticipant);
            fclose(pFile);
        }
    }
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListeParticipant)
{
    FILE *pFile;
    int retorno=0;

    if(path!=NULL && pArrayListeParticipant!=NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            printf("\nEl archivo no existe. Realize la carga desde el archivo en modo binario(opcion 1)\n");
        }else{
            retorno=  parser_eParticipantFromBinary( pFile , pArrayListeParticipant);
        }
        fclose(pFile);
    }
    return retorno;
}


/*
int controller_addeParticipant(LinkedList* pArrayListeParticipant)
{
     return eParticipant_registereParticipant(pArrayListeParticipant);
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_editeParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;
    return retorno;
}


int controller_removeParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;
    return retorno;
}


int controller_ListParticipant(LinkedList* pListeParticipant)
{
    int retorno=0;

    if(pListeParticipant!=NULL)
    {
        participants_showAllParticipants(pListeParticipant);
        retorno = 1;
    }
    return retorno;
}

int controller_ListParticipant2daRonda(LinkedList* pListeParticipant)
{
    int retorno=0;

    if(pListeParticipant!=NULL)
    {
        participants_showAllParticipants2daRonda(pListeParticipant);
        retorno = 1;
    }
    return retorno;
}

int controller_sortParticipant(LinkedList* pArrayListeParticipant)
{
    int retorno=1;

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeParticipant)
{
   int retorno=1;
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeParticipant LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListeParticipant)
{
    FILE* pFile = fopen(path,"wb");
    eParticipant* participante;
    int len;
    int retorno = 0;

    if(pFile!=NULL && pArrayListeParticipant!=NULL)
    {
        len = ll_len(pArrayListeParticipant);

        for(int i=0;i<len;i++)
        {
            participante = ll_get(pArrayListeParticipant,i);
            fwrite(participante,sizeof(participante),1,pFile);
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}

int controller_secondRound( LinkedList* listaParticipantes)
{
    int retorno=0;

    if(ll_map(listaParticipantes,participants_Puntajes2daRonda))
    {
        controller_ListParticipant2daRonda(listaParticipantes);
        retorno=1;
    }else{
        printf("Hubo un error al asignar nuevos puntajes");
    }
    return retorno;
}

int controller_ContarParticipantesPuntajeMenor( LinkedList* listaParticipantes)
{
    int retorno=0;
    int acumuladorParticipantes;

    acumuladorParticipantes= ll_count(listaParticipantes,participants_contarParticipantesConMenosde10);
    if(acumuladorParticipantes>0)
    {
        printf("La cantidad de concursantes que sacaron menos de 10 en la segunda ronda es: %d",acumuladorParticipantes );
    }else
    {
        printf("No hay participantes con un puntaje menor a 10 en la primer ronda.");
    }

    retorno=1;

    return retorno;
}

int controller_participantsaveAsText(char* path, eParticipant* participante)
{
    FILE* pData;
    int retorno=0;
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    char fechaPresentacion[15];
    char temaPresentacion[128];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;

     pData = fopen(path, "w");
    if(pData!=NULL)
    {
        if(participante != NULL)
        {
            eParticipant_getNumeroConcursante(participante,&numeroConcursante);
            eParticipant_getNombre(participante,nombre);
            eParticipant_getAnioNacimiento(participante,&anioNacimiento);
            eParticipant_getDni(participante,&dni);
            eParticipant_getPuntajeFechaPresentacion(participante,fechaPresentacion);
            eParticipant_getTemaPresentacion(participante,temaPresentacion);
            eParticipant_getPuntajePrimeraRonda(participante,&puntajePrimeraRonda);
            eParticipant_getPuntajeSegundaRonda(participante,&puntajeSegundaRonda);
            eParticipant_getPromedioPuntaje(participante,&promedio);
        }
        fprintf(pData, "\n %d %7d %10s %15d %20s %25s %15d %20d %20f\n",numeroConcursante,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,promedio);
        fclose(pData);
        retorno=1;
    }


    return 1;
}
