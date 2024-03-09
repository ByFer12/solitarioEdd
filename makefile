# QUI ESPECIFICO EL COMPILADOR 
COMPILADOR = g++

# Bandera de compilación
BANDERA = -std=c++11 -Wall

# Directorios de los archivos de cabecera y de implementación
CARPETASCABECERA = Cabeceras
CARPETASCPP = ClasesCpp

# Obtén la lista de archivos de implementación
SRCS = $(wildcard $(CARPETASCPP)/*.cpp)

# Agrega el archivo main.cpp a la lista de archivos de implementación
SRCS += main.cpp

# Objetos generados a partir de los archivos de implementación
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
NOMBRE = Solitario

# Regla para construir el ejecutable
$(NOMBRE): $(OBJS)
	$(COMPILADOR) $(BANDERA) -o $@ $^

# Regla para construir los objetos
%.o: %.cpp
	$(COMPILADOR) $(BANDERA) -I$(CARPETASCABECERA) -c -o $@ $<

# Regla para limpiar los archivos generados
clean:
	rm -f $(NOMBRE) $(OBJS)

# Regla para ejecutar el programa
run: $(NOMBRE)
	./$(NOMBRE)
