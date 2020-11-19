#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "participantes.h"
#include "inputs.h"

eParticipant* eParticipant_new(void)
{
    return (eParticipant*) malloc(sizeof(eParticipant));
}
/*
char numConcursanteAux[51];
    char nombreAux[51];
    char anioNacimientoAux[5];
    char dniAux[10];
    char temaPresentacionAux[30];
    char puntajePimeraRondaAux[4];

    typedef struct
{
    int numeroConcursante;
    int añoNacimiento;
    char nombre[51];
    int dni;
    //date fechaPresentacion;
    char temaPresentacion[30];
    int puntajePrimeraRonda;
}eParticipant;
*/

eParticipant* eParticipant_newParametros(char* numConcursanteAux,char* nombreAux,char* anioNacimientoAux,char* dniAux, char* temaPresentacionAux,char* puntajePimeraRondaAux )
{
    eParticipant* pParticipant = eParticipant_new();
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    //date fechaPresentacion;
    char temaPresentacion[30];
    int puntajePrimeraRonda;

    numeroConcursante = atoi(numConcursanteAux);
    strcpy(nombre,nombreAux);
    anioNacimiento = atoi(anioNacimientoAux);
    dni = atoi(dniAux);
    strcpy(temaPresentacion,temaPresentacionAux);
    puntajePrimeraRonda = atoi(puntajePimeraRondaAux);

    if(pParticipant!=NULL)
    {
        if( eParticipant_setNumeroConcursante(pParticipant,numeroConcursante)){
            if(eParticipant_setNombre(pParticipant,nombre)){
                if( eParticipant_setDni(pParticipant,dni)){
                     if(eParticipant_setTemaPresentacion(pParticipant,temaPresentacion)){
                        if(eParticipant_setPuntajePrimeraRonda(pParticipant,puntajePrimeraRonda))
                        {
                            eParticipant_setAnioNacimiento(pParticipant,anioNacimiento);
                        }
                     }
                }
            }
        }
    }
    return pParticipant;
}


//-----------------------------Nombre---------------------------------------------
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

//---------------------------------NUMERO CONCURSANTE---------------------------------------
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

//----------------------------------DNI------------------------------

int eParticipant_setDni(eParticipant* this,int dni)
{
    int setteo=0;
    if(this!=NULL && dni>=9000000 && dni<45000000)
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
//-------------------------ANIO NACIMIENTO----------------------------------
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

//---------------------------PUNTAJE--------------------------------------

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

//---------------------Tema---------------------------------------------
int eParticipant_setTemaPresentacion(eParticipant* this,char* temaPresentacion)
{
    int setteo=0;
    if(this!=NULL && temaPresentacion!=NULL)
    {
        if( inputs_isValidName(temaPresentacion,50 ) )
        {
           strcpy(this->temaPresentacion,temaPresentacion);
           setteo=1;
        }
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void eParticipant_showOneeParticipant(eParticipant* participante)
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    int dni;
    //date fechaPresentacion;
    char temaPresentacion[30];
    int puntajePrimeraRonda;

    if(participante != NULL)
    {
        eParticipant_getNumeroConcursante(participante,&numeroConcursante);
        eParticipant_getNombre(participante,nombre);
        eParticipant_getTemaPresentacion(participante,&temaPresentacion);
        eParticipant_getAnioNacimiento(participante,&anioNacimiento);
        eParticipant_getDni(participante,&dni);
        eParticipant_getPuntajePrimeraRonda(participante,&puntajePrimeraRonda);

        printf("\t%d   %-11s %5d   %d   %2d   %s\n",numeroConcursante,nombre,dni,anioNacimiento,puntajePrimeraRonda,temaPresentacion);
    }
}
