/*
 * MenuLCD.h
 *
 *  Created on: 18 abr. 2021
 *      Author: damian
 */

#ifndef PRE_INGRESO_TPPDM_INC_MENULCD_H_
#define PRE_INGRESO_TPPDM_INC_MENULCD_H_

#include <TPPdM.h>

/*
 * @brief Presenta en el LCD el menu principal en pantalla y gestiona la selección de funciones.
 *
 * @return Variable tipo estadoLCD con el próximo estado.
 * */
estadoLCD MenuPrincipalLCD(void);


/*
 * @brief Presenta en el LCD la temperatura y huemedad en la pantalla.
 *
 * @param Recibe una estructura THRm con las mediciones de temperatura y humedad.
 * @return Variable tipo estadoLCD con el próximo estado.
 * */
estadoLCD TempHRLCD(struct THRm);


/*
 * \brief Presenta en el LCD el mensaje de bateria baja.
 * */
void MsgBateriaBajaLCD(void);

/*
 * \brief Presenta en el LCD la medición de la tensión de la bateria
 *
 * @param Recibe variable tipo float con la medición de la tensión de la bateria.
 * @return Variable estadoLCD con el proximo estado.
 * */
estadoLCD VBatLCD(float);

/*
 * \brief Presenta en la pantalla LCD la configuración de tiempos de entrenamiento
 *		  gestiona la selección de tiempos mediante los pulsadores.
 *
 *@return Estructura tiempos con los tiempos seleccionados.
 * */

struct tiempos ConfiguracionInternavalo(void);


#endif /* PRE_INGRESO_TPPDM_INC_MENULCD_H_ */
