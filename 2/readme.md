INSTRUCCIONES:


** AVISO **

# Se recomienda hacer un make clean antes de ejecutar el make

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
    ./converter nombre_de_la_imagen.jpg nombre_de_la_nueva_imagen.jpg numero_de_hebras
# Ejemplo:
    ./converter starwars.jpg starwarsNuevo.jpg 4

explicación de las lineas:

# ./converter-> Es para ejecutar el programa.

# nombre_de_la_imagen -> Se debe escribir el nombre de la imagen a transformar. ¡Debe de estar en la misma carpeta o se debe especificar bien la ruta!

# nombre_de_la_nueva_imagen.png -> Nombre que se le debe dar a la imagen a transformar.

# numero_de_hebras -> Escribir el numero de hebras

	Borrar compilacion y ejecucion
3. make clean

