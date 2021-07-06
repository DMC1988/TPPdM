# Programación de microprocesadores: Trabajo Final
Trabajo final para la asignatura Programación de Microprocesadores para la Especialización en Sistemas Embebidos de FIUBA.

### Alumno: Damián Caputo
### Plataforma embebida: EDU-CIAA-NXP
## Aplicación:
El firmware controla un display que exhibe un menú de 3 opciones. El menu se recorre mediante la acción de dos pulsadores y un tercero oficia como pulsador de enter.
1. Config. Int: El usuario setea la cantidad de intervalos de entrenamiento (maximo 5), tiempo de intervalo (maximo 3) y el tiempo de descanso entre intervalos (maximo 60s).
Al aceptar la configuración el dispositivo exhibe una pantalla con el intervalo en curso, la cuenta regresiva del tiempo de intervalo restante y el tiempo de descanso,
tambien en cuenta regresiva.
2. Temp y HR.: El display LCD exhibe la temperatura ambiente y la humedad relativa medida.
3. Med. Bateria: El display exhibe la tensión de la batería. Si mide una tensión menor a 2,7V se exhibe en pantalla un aviso de bateria baja y se enciende el LED rojo.
Luego del aviso se vuelve al menu principal presionando el pulsador enter cuando la tensión es mayor a 2.7V.

## Periféricos:
GPIO, ADC, TIMER.

## Descripción de los estados:
Presentación: Exhibe en pantalla el título del proyecto durante 3 s.

MenuPrincipal,: Exhibe en pantalla 3 opciones seleccionables mediante teclado:
1. *Config. Int.*
2. *Temp. y HR.*
3. *Med. Bateria*

- **MenuConfigIntervalo:** Exhibe en pantalla la opción de setear la cantidad de intervalos, tiempo de intervalo y tiempo entre intervalos mediante teclado.
- **Pantalla Conteo:** Exhibe el intervalo actual, la cuenta regresiva del tiempo de intervalo y el tiempo de descanso, tambien en forma regresiva. Durante el tiempo de intervalo parpadea el LED verde y durante el tiempo de descanso parapadea el LED amarillo.
- **ConteodeIntervalo:** Rutina de temporización de 1 s y actualización periódica de display.
- **Pantalla Temp. y humedad:** Exhibe la temperatura y la humedad medidas.
- **TemperaturaYHumedad:** Rutina para realizar la medición de temperatura y humedad.
- **TensionBateria:** Exhibe la tensión de la temperatura.
- **Medición de  batería:** Rutina para medir la tensión de la batería.

## Modulos de software
TPPdM.c y TPPdM.h, contine la maquina de estado y variables de estado.

MenuLCD.c y MenuLCD.h,contiene los menu y variables asociadas a ellos.

Funciones.c y funciones.h, contiene funciones de temporización y medición de magnituds físicas.

### MenuLCD.h

\brief Presenta en el LCD el menu principal en pantalla y gestiona la selección de funciones.

*estadoLCD MenuPrincipalLCD(void);*


\brief Presenta en el LCD la temperatura y huemedad en la pantalla.

*estadoLCD TempHRLCD(struct THRm);*


\brief Presenta en el LCD el mensaje de bateria baja.

*void MsgBateriaBajaLCD(void);*


\brief Presenta en el LCD la medición de la tensión de la bateria
 
*estadoLCD VBatLCD(float);*


\brief Presenta en la pantalla LCD la configuración de tiempos de entrenamiento gestiona la selección de tiempos mediante los pulsadores.

*struct tiempos ConfiguracionInternavalo(void);*


### Funciones.h

\brief Exhibe en LCD el titulo del proyecto y el nombre del alumno

*void LCDPresentacion(void);*


\brief Realiza la medición de temperatura y humedad a traves del DHT11.

*struct THRm medicionTHR(void);*


\brief Detecta bateria baja.

*bool_t EstaBateriaBaja(void);*


\brief Función que exhibe y realiza la cuenta de tiempos de entrenamiento.

*estadoLCD TemporzacionIntervalo(struct tiempos);*


\brief Función antirrebote de pulsadores.

*bool_t debounce(gpioMap_t );*

\brief Función para temporizar un segundo.
*void BasedeTiempo();*
