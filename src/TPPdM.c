/*=============================================================================
 * Author: Damian Caputo <damcapu@gmail.com>
 * Date: 2021/04/18
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TPPdM.h"
#include "sapi.h"
#include "Funciones.h"
#include "MenuLCD.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   /*Inicilaizacion de LCD*/
   lcdInit( 16, 2, 5, 8 );
   delay( LCD_STARTUP_WAIT_MS );
   lcdCursorSet( LCD_CURSOR_OFF );
   lcdClear();

   /*Inicialización de DHT11*/
   dht11Init( GPIO1 );

   /*Inicialización de ADC*/
   adcConfig( ADC_ENABLE );

   /*Titulo del proyecto en LCD*/
   LCDPresentacion();

   /*Estado inicial para el menu*/
   pantallaActual = MenuPrincipal;
   // ----- Repeat for ever -------------------------
   while( true ) {

	   switch(pantallaActual){
	   case MenuPrincipal:
		   /*Menu principal con 3 opcioenes*/
		   pantallaActual = MenuPrincipalLCD();
		   break;

	   case MenuConfigIntervalo:
		   /*Configuración de intervalo*/
			SesionEntrenamiento = ConfiguracionInternavalo();
			pantallaActual = SesionEntrenamiento.siguienteEstado;
		   break;

	   case TemperaturaYHumedad:
		   /*Medicion de temperatura y humedad*/

		   /*Realiza la medición en el DHT*/
		   THRmedido = medicionTHR();

		   /*Realiza la presentacion en pantalla de los valores medidos*/
		   pantallaActual = TempHRLCD(THRmedido);
		   break;

	   case TensionBateria:
		   /*Medicion de tension de bateria*/

		   /*Aviso de bateria baja*/
			if(EstaBateriaBaja()){
				MsgBateriaBajaLCD();
			while(!debounce(BTNINTRO)){}
			delay(100);
			lcdClear();
			}
			else{
				/*Medicion debateria*/
				gpioWrite(LED2, OFF);
				Vbat =adcRead( CH1 )*0.00322;
				pantallaActual = VBatLCD(Vbat);
			}
		   break;

	   case ConteodeIntervalo:
		   /*Conteo de tiempo de intervalos*/
		   lcdGoToXY( 0, 0 );
		   lcdSendStringRaw( "Conteo Int" );

		   pantallaActual = TemporzacionIntervalo(SesionEntrenamiento);
		   break;


	   }














   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
