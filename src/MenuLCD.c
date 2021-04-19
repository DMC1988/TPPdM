/*
 * MenuLCD.c
 *
 *  Created on: 18 abr. 2021
 *      Author: damian
 */
#include <TPPdM.h>
#include <MenuLCD.h>

#define nRoundMax 5
#define nRoundMin 1
#define tRoundMax 3
#define tRoundMin 1
#define tDescansoMax 60
#define tDescansoMin 1

estadoLCD MenuPrincipalLCD(){
	static int menuIndex = 1;
	static estadoLCD opcionSeleccionada = MenuPrincipal;

	switch(menuIndex){
	case 1:
		/*Imprime la pantalla Config. de Intervalo < y Temp. y HR*/
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "Config. Int.   <" );
		lcdGoToXY( 0, 1 );
		lcdSendStringRaw( "Temp. y HR      ");
		opcionSeleccionada = MenuConfigIntervalo;
		break;

	case 2:
		/*Imprime la pantalla Config.Interv. y Temp. y HR     <*/
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "Config. Int.    ");
		lcdGoToXY( 0, 1 );
		lcdSendStringRaw( "Temp. y HR     <");
		opcionSeleccionada = TemperaturaYHumedad;
		break;

	case 3:
		/*Imprime Tensión de bateria*/
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "Med. Bateria   <");
		opcionSeleccionada = TensionBateria;
		break;
	}
	/*Chquear pulsadores*/

	if(!gpioRead(BTNUP)){
		delay(100); //Tengo que poner antirebote
		++menuIndex;
		if(menuIndex>3){menuIndex = 1;}
		lcdClear();
	}
	if(!gpioRead(BTNDWN)){
		delay(100); //Tengo que poner antirebote
		menuIndex--;
		if(menuIndex<1){menuIndex = 3;}
		lcdClear();
	}
	if(!gpioRead(BTNINTRO)){
		delay(100); //Tengo que poner antirebote
		lcdClear();
		return opcionSeleccionada;
	}
return MenuPrincipal;
}

estadoLCD TempHRLCD(struct THRm THRmedido){
	char tempstr[5];
	char HRstr[5];

	/*Muestra Temp: xx.x C*/
	sprintf(tempstr, "%.1f",THRmedido.temperatura );
	lcdGoToXY( 0, 0 ); // Poner cursor en 0, 0
	lcdSendStringRaw( "Temp:" );
	lcdGoToXY( 5, 0 );
	lcdSendStringRaw(tempstr);
	lcdGoToXY( 10, 0 );
	lcdSendStringRaw("C");

	/*Muestra HR: xx.x %*/
	sprintf(HRstr, "%.1f", THRmedido.HR);
	lcdGoToXY( 0, 1 ); // Poner cursor en 0, 1
	lcdSendStringRaw( "HR:" );
	lcdGoToXY( 5, 1 );
	lcdSendStringRaw(HRstr);
	lcdGoToXY( 10, 1);
	lcdSendStringRaw("%");

	if(!gpioRead(BTNINTRO)){
		delay(100); //Aca poner antirebote
		return MenuPrincipal;
		lcdClear();
	}
	else{
		return TemperaturaYHumedad;
	}
}

void MsgBateriaBajaLCD(void){
	   lcdClear();
	   lcdGoToXY( 0, 0 ); // Poner cursor en 0, 0
	   lcdSendStringRaw( "Bateria Baja" );
	   lcdGoToXY( 0, 1 ); // Poner cursor en 0, 0
	   lcdSendStringRaw( "ConecteCargador" );
	   gpioWrite(LED2, ON);
}

estadoLCD VBatLCD(float Vbat){
	char Vbatstr[5];

	/*Muetra V. Bateria : x.xx V*/
	sprintf(Vbatstr, "%.2f",Vbat);
	lcdGoToXY( 0, 0 ); // Poner cursor en 0, 0
    lcdSendStringRaw( "V. Bateria:" );
    lcdGoToXY( 11, 0 );
    lcdSendStringRaw(Vbatstr);
    lcdGoToXY( 15, 0 );
    lcdSendStringRaw("V");

    if(!gpioRead(BTNINTRO)){
    	delay(100);
    	lcdClear();
    	return MenuPrincipal;
    }
    else{
    	return TensionBateria;
    }
}

struct tiempos ConfiguracionInternavalo(void){
	struct tiempos ConfigSesion;
	static int nRND = 1;
	char nRNDstr[2];
	static int tRND = 1;
	char tRNDstr[2];
	static int tDSO = 1;
	char tDSOstr[2];

	/*Seteo del numero de rounds*/
	while(gpioRead(BTNINTRO)){
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "RND  tRND  tDSO" );

		lcdGoToXY( 0, 1 );
		lcdSendStringRaw(">");

		sprintf(nRNDstr, "%d", nRND);
		lcdGoToXY( 1, 1 );
		lcdSendStringRaw(nRNDstr);

		sprintf(tRNDstr, "%d", tRND);
		lcdGoToXY( 6, 1 );
		lcdSendStringRaw(tRNDstr);

		sprintf(tDSOstr, "%d", tDSO);
		lcdGoToXY( 12, 1 );
		lcdSendStringRaw(tDSOstr);

		if(!gpioRead(BTNUP)){
			delay(100); //Tengo que poner antirebote
			++nRND;
			if(nRND>nRoundMax){nRND = nRoundMin;}
			lcdClear();
		}
		if(!gpioRead(BTNDWN)){
			delay(100); //Tengo que poner antirebote
			nRND--;
			if(nRND<nRoundMin){nRND = nRoundMax;}
			lcdClear();
		}
	}
	delay(200);
	lcdClear();

	/*Seteo de duracion de round*/
	while(gpioRead(BTNINTRO)){
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "RND   tRND  tDSO" );

		lcdGoToXY( 5, 1 );
		lcdSendStringRaw(">");

		sprintf(nRNDstr, "%d", nRND);
		lcdGoToXY( 1, 1 );
		lcdSendStringRaw(nRNDstr);

		sprintf(tRNDstr, "%d", tRND);
		lcdGoToXY( 6, 1 );
		lcdSendStringRaw(tRNDstr);

		sprintf(tDSOstr, "%d", tDSO);
		lcdGoToXY( 12, 1 );
		lcdSendStringRaw(tDSOstr);

		if(!gpioRead(BTNUP)){
			delay(100); //Tengo que poner antirebote
			++tRND;
			if(tRND>tRoundMax){tRND = tRoundMin;}
			lcdClear();
		}
		if(!gpioRead(BTNDWN)){
			delay(100); //Tengo que poner antirebote
			tRND--;
			if(tRND<tRoundMin){tRND = tRoundMax;}
			lcdClear();
		}
	}
	delay(200);
	lcdClear();

	/*Seteo de duracion de descanso*/
	while(gpioRead(BTNINTRO)){
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "RND   tRND  tDSO" );

		lcdGoToXY( 11, 1 );
		lcdSendStringRaw(">");

		sprintf(nRNDstr, "%d", nRND);
		lcdGoToXY( 1, 1 );
		lcdSendStringRaw(nRNDstr);

		sprintf(tRNDstr, "%d", tRND);
		lcdGoToXY( 6, 1 );
		lcdSendStringRaw(tRNDstr);

		sprintf(tDSOstr, "%d", tDSO);
		lcdGoToXY( 12, 1 );
		lcdSendStringRaw(tDSOstr);

		if(!gpioRead(BTNUP)){
			delay(100); //Tengo que poner antirebote
			++tDSO;
			if(tDSO>tDescansoMax){tDSO = tDescansoMin;}
			lcdClear();
		}
		if(!gpioRead(BTNDWN)){
			delay(100); //Tengo que poner antirebote
			tDSO--;
			if(tDSO<tDescansoMin){tDSO = tDescansoMax;}
			lcdClear();
		}
	}
	delay(200);
	lcdClear();

	ConfigSesion.nRounds = nRND;
	ConfigSesion.DuracionRound = tRND;
	ConfigSesion.DuracionDescanso = tDSO;
	ConfigSesion.siguienteEstado = ConteodeIntervalo;

	return ConfigSesion;
}







