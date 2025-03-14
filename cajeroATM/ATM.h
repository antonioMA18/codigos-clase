#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

int psw = 0;
float balance[3] = {1000, 2000, 10000};
int passwords[3] = {12, 34, 56};

int accountsMenu(){
    int position;
    printf("Que cuenta deseas checar? 0, 1 o 2\n");
    scanf("%d", &position);
    return position;
}

int password(int position){
    int psw;
    int sum = 0;
    do{
    printf("Introduzca pin: ");
    scanf("%d", &psw);
    if(psw == passwords[position]){
        return 0;
    }
    else{
        sum++;
    }
    }while(sum <= 2);
}

float validQuantity(float quantity){
    if(quantity < 0){
        printf("no se pueden introducir cantidades negativas!\n");
        return 1;
    }
    else if(quantity == 0){
        printf("no puede introducir $0!\n");
        return 1;
    }
    else{
        return 0;
    }
}

int checkBalance(int position){
    printf("%.2f\n", balance[position]);
    /*
    FILE* f = fopen("balance.txt", "r");
    if(f != NULL){
        fscanf(f, "%.2f", &balance);
    }
    fclose(f);
    printf("\nsu saldo actual es: $%.2f\n", balance); */
    return 0;
}

void deposit(int position){
    float quantity = 0;
    printf("Que cantidad desea depositar?\n$");
    scanf("%f", &quantity);
    if (validQuantity(quantity) == 0){
        printf("Ingrese los billetes\n");
        sleep(2);
        printf("procesando\n");
        sleep(2);
        balance[position] += quantity;
        FILE* f = fopen("balance.txt", "w");
    if (f != NULL)                       // check for success
 {
     fprintf(f, "%.2f", balance[position]);            // write the number 42 as a string
     fclose(f);                       // close the file
     f = NULL;                        // set file handle to null since f is no longer valid
 }
        checkBalance(position);
    }
    sleep(2);
}

void withdrawCash(int position){
    float amount;
    printf("Ingrese la cantidad que desea retirar:");
    checkBalance(position);
    scanf("%f", &amount);
    if(amount == 0){
        printf("No puedes retirar $0\n");
    }
    else if(amount < 0){
        printf("No puedes retirar cantidades negativas\n");
    }
    else if(amount > balance[position]){
        printf("Usted no cuenta con fondos suficientes para retirar esa cantidad\n");
    }
    else{
        printf("cantidad retirada: %.2f\n", amount);
        balance[position] -= amount;
    }
}


#endif // ATM_H_INCLUDED
