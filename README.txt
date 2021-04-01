WS2812 16x16 frame 

Proyecto para crear un cuadro para imágenes de 16x16 píxeles usando un Arduino Pro Mini, controlado por control remoto infrarrojos. 

Descripción:

El proyecto se propone implementar un programa que muestre una imagen RGB de 16x16 píxeles usando una matriz de leds WS2812 controlada por un Arduino Pro Mini. El programa cargado en el Arduino realizará las siguientes tareas:

- Lectura de ficheros de imagen desde Tarjeta SD: El programa leerá archivos en formato "led", generados por el programa "imgextract". 
- Control por mando infrarrojos (actualmente desactivado): Desde el mando se pueden cambiar las imágenes por defecto usando otras guardadas en la tarjeta SD.
- Control de la matriz WS2812

El proyecto está dividido en los siguientes directorios:

Directorio raíz:
- Proyecto para arduino IDE.
Directorio Extras:
- Librerías NEO Pixel y IR remote
Directorio ImgExtract:
- Programa extra para generar ficheros de imagen en formato commpatible con el programa grabadon en el arduino. Se tienen archivos "png" de muestra compatibles, y archivos "led" de salida para poder colocar en la tarjeta SD.


