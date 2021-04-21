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
 *\brief Realiza la medición de temperatura y humedad a traves del DHT11.
 *
 *@return Variable tipo struct THRm con la temperatura y la humedad.
 */
struct THRm medicionTHR(void);


/*
 * \brief Detecta bateria baja.
 *
 * @return Devuelve el estado de la bateria, TURE = Bateria baja.
 */
bool_t EstaBateriaBaja(void);


/*
 * \brief Función que exhibe y realiza la cuenta de tiempos de entrenamiento.
 *
 * @param Variable de tipo tiempos.
 * @return Variable del tipo estadoLCD.
 * */
estadoLCD TemporzacionIntervalo(struct tiempos);


/*
 * \brief Función antirrebote de pulsadores.
 *
 * @param Variable de tipo gpioMap_t indicando la tecla sobre la cual aplicat la función.
 * @return El estado del pulsador.
 * */
bool_t debounce(gpioMap_t );


#endif /* PRE_INGRESO_TPPDM_INC_FUNCIONES_H_ */
