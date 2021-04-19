/*
 * MenuLCD.h
 *
 *  Created on: 18 abr. 2021
 *      Author: damian
 */

#ifndef PRE_INGRESO_TPPDM_INC_MENULCD_H_
#define PRE_INGRESO_TPPDM_INC_MENULCD_H_

#include <TPPdM.h>

estadoLCD MenuPrincipalLCD(void);

estadoLCD TempHRLCD(struct THRm);

void MsgBateriaBajaLCD(void);

estadoLCD VBatLCD(float);

struct tiempos ConfiguracionInternavalo(void);


#endif /* PRE_INGRESO_TPPDM_INC_MENULCD_H_ */
