/*
 * Funciones.h
 *
 *  Created on: 18 abr. 2021
 *      Author: damian
 */

#ifndef PRE_INGRESO_TPPDM_INC_FUNCIONES_H_
#define PRE_INGRESO_TPPDM_INC_FUNCIONES_H_

#include <TPPdM.h>

/**
 * \brief Exhibe en LCD el titulo del proyecto y el nombre del alumno
 */
void LCDPresentacion(void);

/**
 *\brief Devuelve una estructura con los float de las mediciones de temperatura y humedad
 *
 */
struct THRm medicionTHR(void);

/*
 * \brief Detecta bateria baja
 */
bool_t EstaBateriaBaja(void);

estadoLCD TemporzacionIntervalo(struct tiempos);

bool_t debounce(gpioMap_t );

#endif /* PRE_INGRESO_TPPDM_INC_FUNCIONES_H_ */
