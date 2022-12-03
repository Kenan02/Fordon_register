#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions.h"
#include "Struct.h"

#define MAZ_SIZE 50



int main()
{
    
    
    char val;
    bool end = false;

    while (!end)
    {
        puts("\n\n------------VALMENY-------------------");
        printf("\n1. Registerar konto\n");
        printf("2. Logga in\n");
        printf("3. avsluta\n");
        puts("\n----------------------------------------");
        printf("\nVälj: ");

        scanf("%s", &val);

        switch(val){
        
        case '1':
            createAccount();
            break;

        case '2':
            login();
            break;

        case '3':
            end = true;
            break;

        default:
            printf("Fel inmatning försök igen!\n");
        
    }

    
}

return 0;

}