CC = gcc
CFLAGS = -Wall -c -I$(I_DIR) $^ -g  -o $@
OFLAGS = $^ -o $@

# Añadir bandera -Wextra a CFLAGS antes de compilar para más advertencias

EXE_DIR = bin
I_DIR = include
SRC_DIR = src
O_DIR = obj

EXE_FILES = $(EXE_DIR)/*
I_FILES = $(wildcard $(IDIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(O_DIR)/%.o, $(SRC_FILES))
