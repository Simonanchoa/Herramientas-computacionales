CC = g++
CFLAGS = -Wall -O2
PYTHON = python3
EXEC = edo
DATAFILES = *.dat
PLOTS = *.png

all: run plot

build:
	$(CC) $(CFLAGS) ApellidoNombre_S6CASA_EDO.cpp -o $(EXEC)

run: build
	./$(EXEC)

plot:
	$(PYTHON) PLOTS_NombreApellido_S6CASA_EDO.py

clean:
	rm -f $(EXEC) $(DATAFILES) $(PLOTS)

.PHONY: all build run plot clean
