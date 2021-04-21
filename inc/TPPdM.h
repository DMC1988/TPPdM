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


#define BTNUP TEC1
#define BTNDWN TEC2
#define BTNINTRO TEC3


/*Estados para la MEF*/
typedef enum{
	MenuPrincipal,
	MenuConfigIntervalo,
	TemperaturaYHumedad,
	TensionBateria,
	ConteodeIntervalo,
}estadoLCD;
estadoLCD pantallaActual; //!<- Variable de estado de la MEF.

/*Estructura para el pasajo de datos de T y HR entre funciones*/
struct THRm {
	float temperatura;
	float HR;
};
struct THRm THRmedido;

/*Variable para la tensión de la bateria*/
float Vbat;

/*Estrucutra para los tiempos de entrenamiento*/
struct tiempos {
	int nRounds;
	int DuracionRound;
	int DuracionDescanso;
	estadoLCD siguienteEstado;
};
struct tiempos SesionEntrenamiento;



/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __TPPDM_H__ */
