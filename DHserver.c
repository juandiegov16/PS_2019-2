void atender_cliente(int connfd)
{

  char mensaje_start[MAXLINE] = {0};
  // diffie hellman
  uECC_Curve secp160r1 = uECC_secp160r1();
  uint8_t clave_publica[DH_PUBLIC_KEY_SIZE] = {0};
  uint8_t clave_privada[DH_PRIVATE_KEY_SIZE] = {0};
  uint8_t clave_recibida[DH_PUBLIC_KEY_SIZE] = {0};
  uint8_t secreto_compartido[DH_SECRET_SIZE] = {0};

  // sha256
  SHA256_CTX ctx;
  BYTE secreto_hash[SHA256_BLOCK_SIZE];

  // blowfish
  BLOWFISH_KEY key;

  //Lee orden "START" del socket
  Read(connfd, mensaje_start, MAXLINE);

  if(strcmp(mensaje_start, "START\n") == 0){
    //Genera ves DH
    uECC_make_key(clave_publica,clave_privada,secp160r1);

    //Manda clave pública propia al cliente
    send(connfd, clave_publica, DH_PUBLIC_KEY_SIZE, 0);

    //Recibe la clave pública del cliente
    recv(connfd, clave_recibida, DH_PUBLIC_KEY_SIZE, 0);

    //Crea secreto compartido
    uECC_shared_secret(clave_recibida, clave_privada, secreto_compartido, secp160r1);

    sha256_init(&ctx);
    sha256_update(&ctx, secreto_compartido, DH_SECRET_SIZE);
    sha256_final(&ctx, secreto_hash);

    blowfish_key_setup(secreto_hash, &key, BLOWFISH_KEY_SIZE);

  }
