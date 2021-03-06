#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "participantes.h"
#include "inputs.h"
#include "funcionesAuxiliares.h"

eParticipant* eParticipant_new(void)
{
    return (eParticipant*) malloc(sizeof(eParticipant));
}

eParticipant* eParticipant_newParametros(char* numConcursanteAux,char* anioNacimientoAux,char* nombreAux,char* dniAux, char* fechaPresentacionAux,char* temaPresentacionAux, char* puntajePimeraRondaAux )
{
    eParticipant* pParticipant = eParticipant_new();
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    char temaPresentacion[30];
    int puntajePrimeraRonda;
    char fechaPresentacion[15];

    numeroConcursante = atoi(numConcursanteAux);
    strcpy(nombre,nombreAux);
    anioNacimiento = atoi(anioNacimientoAux);
    dni = atoi(dniAux);
    strcpy(temaPresentacion,temaPresentacionAux);
    puntajePrimeraRonda = atoi(puntajePimeraRondaAux);
    strcpy(fechaPresentacion,fechaPresentacionAux);

    if(pParticipant!=NULL)
    {
        eParticipant_setNumeroConcursante(pParticipant,numeroConcursante);
        eParticipant_setNombre(pParticipant,nombre);
        eParticipant_setDni(pParticipant,dni);
        eParticipant_setTemaPresentacion(pParticipant,temaPresentacion);
        eParticipant_setPuntajePrimeraRonda(pParticipant,puntajePrimeraRonda);
        eParticipant_setAnioNacimiento(pParticipant,anioNacimiento);
        eParticipant_setPuntajeFechaPresentacion(pParticipant,fechaPresentacion);
    }

    return pParticipant;
}

//-----------------------------Nombre------------------------------------------------------
int eParticipant_setNombre(eParticipant* this,char* nombre)
{
    int setteo=0;
    if(this!=NULL && nombre!=NULL)
    {
        if( inputs_isValidName(nombre,50 ) )
        {
           strcpy(this->nombre,nombre);
           setteo=1;
        }
    }
    return setteo;
}

int eParticipant_getNombre(eParticipant* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

//---------------------------------NUMERO CONCURSANTE-----------------------------------------
int eParticipant_setNumeroConcursante(eParticipant* this,int numeroConcursante)
{
    int setteo=0;
    if(this!=NULL && numeroConcursante>=0)
    {
        setteo=1;
        this->numeroConcursante =numeroConcursante;
    }
    return setteo;
}


int eParticipant_getNumeroConcursante(eParticipant* this,int* numeroConcursante)
{
   int retorno=0;
    if(this!=NULL && numeroConcursante!=NULL)
    {
        *numeroConcursante=this->numeroConcursante;
        retorno=1;
    }
    return retorno;
}

//----------------------------------DNI------------------------------------------

int eParticipant_setDni(eParticipant* this,int dni)
{
    int setteo=0;
    if(this!=NULL)
    {
        this->dni=dni;
        setteo=1;
    }
    return setteo;

}
int eParticipant_getDni(eParticipant* this,int* dni)
{
    int retorno=0;
    if(this!=NULL && dni!=NULL)
    {
        *dni=this->dni;
        retorno=1;
    }
    return retorno;
}
//-------------------------ANIO NACIMIENTO----------------------------------------------
int eParticipant_setAnioNacimiento(eParticipant* this,int anioNacimiento)
{
    int setteo=0;
    if(this!=NULL && anioNacimiento<2019 && anioNacimiento>1940)
    {
        this->anioNacimiento=anioNacimiento;
        setteo=1;
    }
    return setteo;
}
int eParticipant_getAnioNacimiento(eParticipant* this,int* anioNacimiento)
{
    int retorno=0;
    if(this!=NULL && anioNacimiento!=NULL)
    {
        *anioNacimiento=this->anioNacimiento;
        retorno=1;
    }
    return retorno;
}

//--------------------------- 1 PUNTAJE--------------------------------------------------------

int eParticipant_setPuntajePrimeraRonda(eParticipant* this,int puntajePrimeraRonda)
{
    int setteo=0;
    if(this!=NULL && puntajePrimeraRonda<101 && puntajePrimeraRonda>-1)
    {
        this->puntajePrimeraRonda=puntajePrimeraRonda;
        setteo=1;
    }
    return setteo;
}
int eParticipant_getPuntajePrimeraRonda(eParticipant* this,int* puntajePrimeraRonda)
{
    int retorno=0;
    if(this!=NULL && puntajePrimeraRonda!=NULL)
    {
        *puntajePrimeraRonda=this->puntajePrimeraRonda;
        retorno=1;
    }
    return retorno;
}

//---------------------TEMA---------------------------------------------------------
int eParticipant_setTemaPresentacion(eParticipant* this,char* temaPresentacion)
{
    int setteo=0;
    if(this!=NULL && temaPresentacion!=NULL)
    {
        strcpy(this->temaPresentacion,temaPresentacion);
        setteo=1;

    }
    return setteo;
}

int eParticipant_getTemaPresentacion(eParticipant* this,char* temaPresentacion)
{
    int retorno=0;
    if(this!=NULL && temaPresentacion!=NULL)
    {
        strcpy(temaPresentacion, this->temaPresentacion);
        retorno=1;
    }
    return retorno;
}


//---------------------FECHA PRESENTACION---------------------------------------------------
int eParticipant_setPuntajeFechaPresentacion(eParticipant* this,char* fechaPresentacion)
{
    int setteo=0;
    if(this!=NULL && fechaPresentacion!=NULL)
    {

        strcpy(this->fechaPresentacion,fechaPresentacion);
        setteo=1;
    }
    return setteo;
}

int eParticipant_getPuntajeFechaPresentacion(eParticipant* this,char* fechaPresentacion)
{
    int retorno=0;
    if(this!=NULL && fechaPresentacion!=NULL)
    {
        strcpy(fechaPresentacion, this->fechaPresentacion);
        retorno=1;
    }
    return retorno;
}

//---------------------------PUNTAJE-2------------------------------------------------------

int eParticipant_setPuntajeSegundaRonda(eParticipant* this,int puntajeSegundaRonda)
{
    int setteo=0;
    if(this!=NULL && puntajeSegundaRonda<101 && puntajeSegundaRonda>-1)
    {
        this->puntajeSegundaRonda=puntajeSegundaRonda;
        setteo=1;
    }
    return setteo;
}
int eParticipant_getPuntajeSegundaRonda(eParticipant* this,int* puntajeSegundaRonda)
{
    int retorno=0;
    if(this!=NULL && puntajeSegundaRonda!=NULL)
    {
        *puntajeSegundaRonda=this->puntajeSegundaRonda;
        retorno=1;
    }
    return retorno;
}

//---------------------------PROMEDIO PUNTAJE--------------------------------------------------------

int eParticipant_setPromedioPuntaje(eParticipant* this,float promedioPuntaje)
{
    int setteo=0;
    if(this!=NULL)
    {
        this->promedioPuntaje = promedioPuntaje;
        setteo=1;
    }
    return setteo;
}

int eParticipant_getPromedioPuntaje(eParticipant* this,float* promedioPuntaje)
{
    int retorno=0;
    if(this!=NULL && promedioPuntaje!=NULL)
    {
        *promedioPuntaje=this->promedioPuntaje;
        retorno=1;
    }
    return retorno;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void eParticipant_showOneeParticipant2daRonda(eParticipant* participante)
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    char fechaPresentacion[15];
    char temaPresentacion[128];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;


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
        //eParticipant_getPromedioPuntaje(participante,&promedio);
        //printf("\n %d %7d %10s %15d %20s %25s %15d %20d %20f\n",numeroConcursante,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,promedio);
        printf("\n %d %7d %10s %15d %20s %25s %15d %20d \n",numeroConcursante,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda);
    }
}

void eParticipant_showOneeParticipant(eParticipant* participante)
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    char fechaPresentacion[15];
    char temaPresentacion[128];
    int puntajePrimeraRonda;


    if(participante != NULL)
    {
        eParticipant_getNumeroConcursante(participante,&numeroConcursante);
        eParticipant_getNombre(participante,nombre);
        eParticipant_getAnioNacimiento(participante,&anioNacimiento);
        eParticipant_getDni(participante,&dni);
        eParticipant_getPuntajeFechaPresentacion(participante,fechaPresentacion);
        eParticipant_getTemaPresentacion(participante,temaPresentacion);
        eParticipant_getPuntajePrimeraRonda(participante,&puntajePrimeraRonda);

        printf("\n %d %7d %10s %15d %20s %25s %20d\n",numeroConcursante,anioNacimiento,nombre,dni,fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
    }
}
