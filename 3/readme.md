INSTRUCCIONES:


** AVISO **

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
2. make run
    
    # Luego del make run:

# Paso 1

Se debe de ingresar el nombre de la imagen a convertir, por ejemplo, nave.jpg. "Imagen a convertir debe de estar en la misma carpeta para respetar la sintaxis escrita"

    " Se utilizará la imagen que está dentro de la carpeta "

Ingrese el nombre de la imagen a convertir: nave.jpg

# Paso 2

Se debe de ingresar el números de hebras a utilizar, por ejemplo 4. Se debe ingresar 4
~ Ingrese el número de hebras a utilizar: 4

# Pase 3

Se debe escoger un nombre para la imagen final. Por ejemplo, el nuevo nombre que le daré a mi imagen será: nuevanave.jpg
~ Ingrese el nombre de la imagen de salida: nuevanave.jpg

	Borrar compilacion y ejecucion
1. make clean

