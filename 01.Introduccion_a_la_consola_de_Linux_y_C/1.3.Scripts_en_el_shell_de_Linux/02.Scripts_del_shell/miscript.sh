#!/usr/bin/env bash

head -2 /proc/meminfo > $1
sed -i 's/MemTotal/Memoria total/g' $1
sed -i 's/MemFree/Memoria libre/g' $1
printf 'Usuarios conectados: ' >> $1
whoami | wc -l >> $1
printf 'Total procesos: ' >> $1
cat /proc/stat | grep "processes" >> $1
sed -i 's/processes//g' $1
printf 'Procesos en ejecución: ' >> $1
cat /proc/stat | grep "procs_running" >> $1
sed -i 's/procs_running//g' $1
cat $1
printf '\nEsta información fue almacenada en %s\n' $1
