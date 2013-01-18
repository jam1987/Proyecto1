#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    char *nombreCentro;
    int capacidadMaxima;
    int inventario;
    int tiempo;
    int suministro;

    if (argc!=11) {
        perror("Error: El numero de parametros no es valido");
        exit(-1);
    } else {
        if (argv[1] && *argv[1]=='-' && *(argv[1]+1)=='n') {
            if (argv[2]) {
                nombreCentro = argv[2];
                if (argv[3] && *argv[3]=='-' && *(argv[3]+1)=='c' && *(argv[3]+2)=='p') {
                    if (argv[4]) {
                        capacidadMaxima = atoi(argv[4]);
                        if (capacidadMaxima<0 || capacidadMaxima>3800000) {
                            perror("Error: La capacidad Maxima debe estar entre 0 y 3800000 Litros");
                            exit(-1);
                        } else {
                            if (argv[5] && *argv[5]=='-' && *(argv[5]+1)=='i') {
                                if (argv[6]) {
                                    inventario = atoi(argv[6]);
                                    if (inventario<0 || inventario>capacidadMaxima) {
                                        perror("Error: El inventario debe estar entre Cero y la Capacidad Maxima del Centro");
                                        exit(-1);
                                    } else {
                                        if (argv[7] && *argv[7]=='-' && *(argv[7]+1)=='t') {
                                            if (argv[8]) {
                                                tiempo = atoi(argv[8]);
                                                if (tiempo<0 || tiempo>180) {
                                                    perror("Error: El tiempo debe estar entre 0 y 180 minutos");
                                                    exit(-1);
                                                } else {
                                                    if (argv[9] && *argv[9]=='-' && *(argv[9]+1)=='s' ) {
                                                        if (argv[10]) {
                                                            suministro= atoi(argv[10]);
                                      						if (suministro<0 || suministro>10000) {
                                      						     perror("Error: El suministro debe estar entre 0 y 10000 litros");
                                      						}
                                                        } else {
                                                            perror("Error: Falta el suministro");
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
    
}
