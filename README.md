# proyecto_señales

## PÁGINA WEB ESTÁTICA
Para ver la página, ubica el archivo de la página (_pagina_estatica.html_) en la biblioteca de archivos y haz sobre él doble click. Esto abrirá la página web en el navegador.

Una vez abierta la página, si quieres ver los console.log(): <br/>
haz click derecho > inspeccionar > console.

Para editar el código de la página, simplemente abre el archivo en Visual Studio Code. No necesitas instalar nada adicional.

## PÁGINA WEB EN VIVO
1. En el  el script [NODEMCU_PROGRAMER_LAB4](NODEMCU_PROGRAMER_LAB4/NODEMCU_PROGRAMER_LAB4.ino) escribir el nombre y la clave de la red wifi a la cual se va a conectar la ESP8266. **Nota:** el computador debe estar conectado a esa misma red.
2. Subir el script a la ESP8266, esperar a que se conecte a la red e imprima la dirección IP.
3. Abrir el archivo con el código de la página web [pagina_en_vivo.html](pagina_en_vivo.html) en Visual Studio Code.
4. Ir a la función `requestECG()` contenida en el código de la pagina web  y escribir la IP de la ESP8266.
5. Ubicar el archivo de la página (_pagina_en_vivo.html_) en tu biblioteca de archivos y haz sobre el doble click. Esto abrirá la página web en el navegador.

# Arduino
En File > Preferences > Additional Boards Manager URLs copiar y pegar el siguiente link:
http://arduino.esp8266.com/stable/package_esp8266com_index.json

