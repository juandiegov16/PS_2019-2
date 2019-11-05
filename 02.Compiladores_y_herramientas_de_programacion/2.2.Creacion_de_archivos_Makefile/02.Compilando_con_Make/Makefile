CC = gcc
CFLAGS = -Wall -c -std=c99 -I$(I_DIR) $^ -g  -o $@
OFLAGS = $^ -o $@

EXE_DIR = .
I_DIR = .
SRC_DIR = .
OBJ_DIR = .

EXE_FILES = $(EXE_DIR)/usuarios
I_FILES = $(wildcard $(I_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

ZIPF_DIR = Taller-Cunalata_Vallejo
ZIPF_ARCHIVE = $(ZIPF_DIR).tar.gz
# Bandera -c genera código objeto para archivos separados
# Opción -g habilita modo depuración/debug
# Opción -Wall habilita mensajes de advertencia
# Opción -I seguido de directorio le dice dónde buscar las librerías

## all : Genera archivos objeto, ejecutable y archivo TAR del código relevante
.PHONY: all
all: $(EXE_FILES) $(ZIPF_ARCHIVE)

$(ZIPF_ARCHIVE) : $(ZIPF_DIR)
	tar -czf $@ $<

$(ZIPF_DIR): Makefile $(SRC_FILES) $(I_FILES)
	mkdir -p $@
	cp -r $^ $@
	touch $@

$(EXE_FILES): $(OBJ_FILES)
	$(CC) $(OFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)

## run: Llama ./usuarios
.PHONY: run
run:
	./usuarios

## dir: Muestra contenido del directorio en formato largo
.PHONY: dir
dir:
	ls -lhR

## dir-report: Muestra contenido del directorio en formato largo y lo guarda en un archivo
.PHONY: dir-report
dir-report:
	ls -lhR > dir_report.txt

## clean: Limpia archivos autogenerados
.PHONY: clean
clean:
	rm -f $(EXE_FILES)
	rm -f $(OBJ_FILES)
	rm -f *.txt
	rm -rf $(ZIPF_DIR)
	rm -f $(ZIPF_ARCHIVE)

.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<
