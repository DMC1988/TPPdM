/*
 * Funciones.c
 *
 *  Created on: 18 abr. 2021
 *      Author: damian
 */

#include <sapi.h>
#include <Funciones.h>
#include <TPPdM.h>

#define VBATMIN 837 // Equivalente a 2,7V

void LCDPresentacion(){
	  lcdGoToXY( 0, 0 ); // Poner cursor en 0, 0
	   lcdSendStringRaw( "TP PdM 2021" );

	   lcdGoToXY( 0, 1 );
	   lcdSendStringRaw( "Damian Caputo");
	   delay(3000);
	   lcdClear(); // Borrar la pantalla
}

struct THRm medicionTHR(void){
	float humidity = 0, temperature = 0;
	struct THRm THRmedida;

	if( dht11Read(&humidity, &temperature) ) {
		THRmedida.temperatura= temperature;
		THRmedida.HR = humidity;
	}
	return THRmedida;
}

bool_t EstaBateriaBaja(){
	if(adcRead(CH1) < VBATMIN){return TRUE;}
	else{return FALSE;}
}

estadoLCD TemporzacionIntervalo(struct tiempos Sesion){

	int nRND = Sesion.nRounds;
	char nRNDstr[2];
	int tRND = Sesion.DuracionRound-1;
	char tRNDstr[2];
	int tDSO = Sesion.DuracionDescanso;
	char tDSOstr[2];
	int segundos = 60;
	char segundosstr[3];

	while(nRND>0){
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "RND  tRND  tDSO" );

		sprintf(nRNDstr, "%d", nRND);
		lcdGoToXY( 1, 1 );
		lcdSendStringRaw(nRNDstr);

		/*Si tRND=1, imprimo 0:59 y cuenta*/
		if(tRND < 1){
			lcdGoToXY( 5, 1 );
			lcdSendStringRaw("0:");
		}else{
			sprintf(tRNDstr, "%d:", tRND);
			lcdGoToXY( 5, 1 );
			lcdSendStringRaw(tRNDstr);}

		/*Alinea los segundos segun sean >9 o no*/
		if(tDSO >9){
			sprintf(tDSOstr, "%d", tDSO);
			lcdGoToXY( 12, 1 );
			lcdSendStringRaw(tDSOstr);
		}else{
			sprintf(tDSOstr, "0%d", tDSO);
			lcdGoToXY( 12, 1 );
			lcdSendStringRaw(tDSOstr);
		}

		/*Conteo de los segundos del Round*/
		delay(1000);
		gpioToggle(LED3);
		--segundos;


		if(segundos <=0){
			segundos = 59;
			--tRND;
			if(tRND < 0){
				while(tDSO>0)
				{
					gpioWrite(LED3, OFF);
					delay(1000);
					gpioToggle(LED1);
					--tDSO;

					/*Alinea el conteo de segundos cuando el valor es <10*/
					if(tDSO >9){
						sprintf(tDSOstr, "%d", tDSO);
						lcdGoToXY( 12, 1 );
						lcdSendStringRaw(tDSOstr);
					}else{
						sprintf(tDSOstr, "0%d", tDSO);
						lcdGoToXY( 12, 1 );
						lcdSendStringRaw(tDSOstr);
					}

				}
				gpioWrite(LED1, OFF);
				tDSO = Sesion.DuracionDescanso;
				tRND = Sesion.DuracionRound-1;
				--nRND;
			}
		}

		/*Alinea el conteo de segundos cuando el valor es <10*/
		if(segundos>9){
			sprintf(segundosstr, "%d", segundos);
			lcdGoToXY( 7, 1 );
			lcdSendStringRaw(segundosstr);
		}else{
			sprintf(segundosstr, "0%d", segundos);
			lcdGoToXY( 7, 1 );
			lcdSendStringRaw(segundosstr);
		}
	}

	/*Aviso de finalización de entrenamiento.*/
	gpioWrite(LED3, OFF);
	lcdClear();
	lcdGoToXY( 0, 0 );
	lcdSendStringRaw( "*Entrenamiento*" );
	lcdGoToXY( 0, 1 );
	lcdSendStringRaw( "**Finalizado***" );
	delay(2000);

	return MenuPrincipal;
}

bool_t debounce(gpioMap_t tecla){
	static uint16_t state=0;
	state = (state << 1)|!gpioRead(tecla)|0xE000;
	if(state == 0xF000){return TRUE;}
	return FALSE;
}
