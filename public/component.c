#include <stdio.h>

int main(){
    int paquete = 10;
    double monto = 50, diferencia, descuento, total;

    if (paquete < 5){ /* condition */
        /* code */
        printf("No se permiten ventas minoristas\n");
        printf("Cantidad de paquetes menores a 5");
    }
    else{
        /* code */
        if (paquete >= 5 && paquete <= 15){ /* condition */
            /* code */
            monto += 10;

            printf("El costo de envio es de 10 USD\n");
            printf("¡Muchas gracias por su compra!\n");
        }
        else{
            /* code */
            printf("Usted no tiene costo de envio\n");
            printf("¡Muchas gracias por su compra!\n");
        }
        if (monto < 100){ /* condition */
            /* code */
            diferencia = 100 - monto;

            printf("El monto es menor a 100 USD por lo que no posee promociones\n");
            printf("Necesita comprar %d", diferencia, " USD para entrar en la promo\n");
        }
        else{
            /* code */
            if (monto >= 100 && monto <= 300){ /* condition */
                /* code */
                descuento = monto * 0.05;
                total = monto - descuento;

                printf("Por su compra tiene un descuento del cinco por ciento\n");
                printf("El monto total con descuento es de: %d\n", total);
            }
            else{
                /* code */
                descuento = monto * 0.1;
                total = monto - descuento;

                printf("Por su compra tiene un descuento del diez por ciento\n");
                printf("El monto total con descuento es de: %d\n", total);
            }
        }
    }

    return 0;
}