#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<unistd.h>
#define PORT 538072

int main(int argc, char *argv[]) {
    char *nombreBomba;
    int capacidadMaxima;
    int inventario;
    int consumo;
    char *nombreArchivo;
    int socketfd;
    struct sockaddr_in direccionServidor;
    char *servidor = "127.0.0.1";

    if (argc!=11) {
        perror("Error: El numero de parametros no es valido");
        exit(-1);
    } else {
        if (argv[1] && *argv[1]=='-' && *(argv[1]+1)=='n') {
            if (argv[2]) {
                nombreBomba = argv[2];
                if (argv[3] && *argv[3]=='-' && *(argv[3]+1)=='c' && *(argv[3]+2)=='p') {
                    if (argv[4]) {
                        capacidadMaxima = atoi(argv[4]);
                        if (capacidadMaxima<0 || capacidadMaxima>380000) {
                            perror("Error: La capacidad Maxima debe estar entre 0 y 380000 Litros");
                            exit(-1);
                        } else {
                            if (argv[5] && *argv[5]=='-' && *(argv[5]+1)=='i') {
                                if (argv[6]) {
                                    inventario = atoi(argv[6]);
                                    if (inventario<0 || inventario>capacidadMaxima) {
                                        perror("Error: El inventario debe estar entre Cero y la Capacidad Maxima de la Bomba");
                                        exit(-1);
                                    } else {
                                        if (argv[7] && *argv[7]=='-' && *(argv[7]+1)=='c') {
                                            if (argv[8]) {
                                                consumo = atoi(argv[8]);
                                                if (consumo<0 || consumo>1000) {
                                                    perror("Error: El consumo debe estar entre 0 y 1000 Litros");
                                                    exit(-1);
                                                } else {
                                                    if (argv[9] && *argv[9]=='-' && *(argv[9]+1)=='f' && *(argv[9]+2)=='c' ) {
                                                        if (argv[10]) {
                                                            nombreArchivo= argv[10];
                                                        } else {
                                                            perror("Error: Falta el nombre del archivo");
                                                            exit(-1);
                                                        }
                                                    
                                                    } else {
                                                        perror("Error: Falta el comando -fc o Comando Incorrecto");
                                                        exit(-1);
                                                    }
                                                }
                                                
                                            } else {
                                                perror("Error: Falta el consumo");
                                                exit(-1);
                                            }
                                        } else {
                                            perror("Error: Falta el comando -c o Comando Incorrecto");
                                        }
                                    }
                                } else {
                                    perror("Error: Falta el inventario inicial");
                                    exit(-1);
                                }
                            } else {
                                perror("Error: Falta el comando -i o Comando Incorrecto");
                                exit(-1);
                            }
                        }
                    } else {
                        perror("Error: Falta la Capacidad Maxima");
                        exit(-1);
                    }
                } else {
                    perror("Error: Falta el comando -cp o Comando Incorrecto");
                    exit(-1);
                }
            } else {
                perror("Error: Falta el nombre de la Bomba");
                exit(-1);
            }
        } else {
            perror("Error: Falta el parametro -n o Parametro incorrecto");
            exit(-1);
        }
    }
    
    
    bzero(&direccionServidor, sizeof(direccionServidor));
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = inet_addr(servidor);
    direccionServidor.sin_port = htons(PORT);
    socketfd = socket(AF_INET, SOCK_STREAM,0);
    if (socketfd<0) {
        perror("Error: No se pudo abrir el socket");
        exit(-1);
    }
    
    
    if (connect(socketfd,(struct sockaddr *) &direccionServidor, sizeof(direccionServidor))<0) {
        perror("Error: No se pudo conectar con el servidor");
    }
    
    char *infoLlegada= (char*)malloc(sizeof(char)*33);

    if (read(socketfd,infoLlegada, 33)<0) {
        perror("Error: No se pudo leer del socket");
        exit(-1);
    } else {
    
        printf("El servidor envio el siguiente mensaje:\n");
    }
    printf("%s\n",infoLlegada);
    sleep(48000);
    
    inventario = inventario - consumo;
    
    
    
    printf("%d\n",inventario);
    
}
