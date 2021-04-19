/*=============================================================================
 * Author: Damian Caputo <damcapu@gmail.com>
 * Date: 2021/04/18
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __TPPDM_H__
#define __TPPDM_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include <sapi.h>
/*=====[Definition macros of public constants]===============================*/
#define BTNUP TEC1
#define BTNDWN TEC2
#define BTNINTRO TEC3
/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
/*Estados para la MEF*/
typedef enum{
	MenuPrincipal,
	MenuConfigIntervalo,
	TemperaturaYHumedad,
	TensionBateria,
	ConteodeIntervalo,
}estadoLCD;
estadoLCD pantallaActual;

/*Estructura para el pasajo de datos de T y HR entre funciones*/
struct THRm {
	float temperatura;
	float HR;
};
struct THRm THRmedido;

float Vbat;

struct tiempos {
	int nRounds;
	int DuracionRound;
	int DuracionDescanso;
	estadoLCD siguienteEstado;
};
struct tiempos SesionEntrenamiento;
/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __TPPDM_H__ */
