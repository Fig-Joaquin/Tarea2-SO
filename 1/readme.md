INSTRUCCIONES:


** AVISO **

# Si existen los archivos NuevaImagen.png y funcion_secuencial.exe se recomienda hacer un make clean para que la compilación y ejecución sea correcta #


Para ejecutar correctamente el programa, se debe de seguir los siguientes pasos:

Primero que nada los requisitos:

#  SI NO ESTÁ INSTALADO, SE DEBE INSTALAR

1. Compilador de C++ / Gnu C++
2. Librería de OpenCV

# Instalación librería OpenCV Linux-Debian y derivados.

# sudo apt-get update
# sudo apt-get install libopencv-dev


- Comandos de ejecución

	Compilar el programa
1. make


	Ejecutar el programa 
2. se debe escribir la siguiente linea:
    ./funcion_secuencial nombre_de_la_imagen.png nombre_de_la_nueva_imagen.png 0.5

explicación de las lineas:

# ./funcion_secuencial -> Es para ejecutar el programa.

# nombre_de_la_imagen -> Se debe escribir el nombre de la imagen a transformar. ¡Debe de estar en la misma carpeta o se debe especificar bien la ruta!

# nombre_de_la_nueva_imagen.png -> Nombre que se le debe dar a la imagen a transformar.

# Para la escala de grises se debe escoger un minimo que es 0.0 y un maximo de 1.0

	Borrar compilacion y ejecucion
3. make clean

