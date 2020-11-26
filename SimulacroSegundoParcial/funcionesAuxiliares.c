#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<time.h>
#include "LinkedList.h"
#include "participantes.h"
#include "inputs.h"
#include "funcionesAuxiliares.h"

void participants_showAllParticipants(LinkedList* pListeParticipant)
{
    eParticipant* participante;
    int lengthListeParticipant = ll_len(pListeParticipant);

    printf("\n*********************************************************************************************************************\n");
    printf("\nID \tANIO\tNOMBRE\t\tDNI\tFECHA PRESENTACION\t\tTEMA PRESENTACION\tPUNTAJE 1ER RONDA\n");

    for(int i=0;i<lengthListeParticipant;i++)
    {
        participante =(eParticipant*)ll_get(pListeParticipant,i);
        eParticipant_showOneeParticipant(participante);
    }
    printf("*****************************************************************************************************************************\n");
}

void participants_showAllParticipants2daRonda(LinkedList* pListeParticipant)
{
    eParticipant* participante;
    int lengthListeParticipant = ll_len(pListeParticipant);

    printf("\n****************************************************************************************************************************************\n");
    printf("\nID \tANIO\tNOMBRE\t\tDNI\tFECHA PRESENTACION\t\tTEMA PRESENTACION\tPUNTAJE 1ER RONDA     PUNTAJE 2DA RONDA     PROMEDIO\n");

    for(int i=0;i<lengthListeParticipant;i++)
    {
        participante =(eParticipant*)ll_get(pListeParticipant,i);
        eParticipant_showOneeParticipant2daRonda(participante);
    }
    printf("************************************************************************************************************************************************\n");
}

/*
int participants_Puntajes2daRonda(void* nodoAux)
{
    eParticipant* participanteAux;
    //int tam;
    int puntajeSegundaRonda;
    int puntajePrimeraRonda;
    int retorno=0;

    if(nodoAux!=NULL)
    {
        participanteAux = nodoAux;
        puntajeSegundaRonda= 1+rand()%(101-1);
        eParticipant_setPuntajeSegundaRonda(participanteAux,puntajeSegundaRonda);
        //eParticipant_getPuntajePrimeraRonda(participanteAux,puntajePrimeraRonda);

        retorno=1;
    }
    return retorno;
}
*/
int participants_Puntajes2daRonda(void* nodoAux)
{
    eParticipant* participanteAux;
    int puntajeSegundaRonda;
    int puntajePrimeraRonda;
    int puntajeTotal;
    float promedio;
    int retorno=0;

    if(nodoAux!=NULL)
    {
        participanteAux = nodoAux;
        puntajeSegundaRonda= 1+rand()%(101-1);
        eParticipant_setPuntajeSegundaRonda(participanteAux,puntajeSegundaRonda);

        eParticipant_getPuntajePrimeraRonda(participanteAux,&puntajePrimeraRonda);
        puntajeTotal = puntajePrimeraRonda+puntajeSegundaRonda;
        promedio= puntajeTotal/(float)2;
        eParticipant_setPromedioPuntaje(participanteAux,promedio);

        retorno=1;
    }
    return retorno;
}


int participants_contarParticipantesConMenosde10(void* item1)
{
    eParticipant* unParticipante;
    int puntajePrimerRonda;
    int dni;
    char dniStr[50];
    char nombreArchivo[50];
    int contador=0;

    if(item1 !=NULL)
    {
       unParticipante=item1;
       eParticipant_getPuntajePrimeraRonda(unParticipante,&puntajePrimerRonda);

       if(puntajePrimerRonda<10)
       {
          contador++;
          eParticipant_showOneeParticipant(unParticipante);
          eParticipant_getDni(unParticipante,&dni);
          itoa(dni,dniStr,10);
          strcpy(nombreArchivo,dniStr);
          strcat(nombreArchivo,".csv");

          controller_participantsaveAsText(nombreArchivo,unParticipante);

       }
    }
    return contador;
}




