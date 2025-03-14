#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ATM.h"

#define FILENAME "balance.txt"

int main(){
    int ans = 0, commitment = 0;
    int position = accountsMenu();
    do{
        printf("Bienvenido a tu cajero ATM!\nQue accion deseas realizar?:\n");
        printf("1. Consultar saldo\n2. Depositar dinero\n3. Retirar efectivo\n4. salir\n");
        scanf("%d", &commitment);
        switch(commitment){
        case 1:
            //if the password is correct program flow continues
            if(password(position) == 0){
                    checkBalance(position);
            }else{
                printf("intente mas tarde\n");
                ans = 1;
            }
            break;
        case 2:
            //if the password is correct program flow continues
            if(password(position) == 0){
                    deposit(position);
            }else{
                printf("intente mas tarde\n");
                ans = 1;
            }
            break;
        case 3:
            //if the password is correct program flow continues
            if(password(position) == 0){
                    withdrawCash(position);
            }else{
                printf("intente mas tarde\n");
                ans = 1;
            }
            break;
        case 4:
            ans = 1;
            break;
        default:
            printf("opcion no disponible\n");
            break;
        }
    }while(ans != 1);
    return 0;
}
//compares the pin introduced by the user with the real one.

//verifies that the quantity introduced by the user is valid


//returns the current amount in the account

//let the user deposit cash

//let the user withdraw cash

//menu cuentas

