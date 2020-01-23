/*
* Remueve nodos con temperatura = 0.0
* Retorna la cantidad de nodos removidos.
*/
int remover_ceros(nodo_t ** cabecera) {

    nodo_t *itr_nodo;
    nodo_t *temp_nodo = NULL;
    nodo_t *ant_nodo = NULL;

    int counter = 0;

    if(cabecera == NULL)
    	return 0;

    itr_nodo = *cabecera;

    if(itr_nodo == NULL)
    	return 0;

    while(itr_nodo != NULL) {

    	if(itr_nodo->temperatura == 0.0){
    		
    		if(ant_nodo == NULL) //Caso límite cabecera == 0.0
    			*cabecera = itr_nodo->siguiente;	
    		else
    			ant_nodo->siguiente = itr_nodo->siguiente;

    		temp_nodo = itr_nodo;
    		itr_nodo = itr_nodo->siguiente;
    		free(temp_nodo);
    		counter++;
    	}else{
    		ant_nodo = itr_nodo;
    		itr_nodo = itr_nodo->siguiente;
    	}
	}

	return counter;
}