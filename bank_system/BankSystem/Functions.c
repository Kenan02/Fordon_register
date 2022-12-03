
#include "Struct.h"
#include <string.h>
#include <stdio.h>

void createAccount()
{

    FILE *fp;
    char filename[50];

    printf("Ange kontonummer: \t");
    scanf("%s", usr.accNum);
    printf("Ange Telefonnummer: \t");
    scanf("%s", usr.phone);
    printf("Ange Lösenord: \t");
    scanf("%s", usr.password);
    usr.balance = 0;

    strcpy(filename, usr.phone);
    fp = fopen(strcat(filename, ".dat"), "w");
    fwrite(&usr, sizeof(struct User), 1, fp);

    if (fp != NULL)
    {
        printf("\nKontot skapades\n");
    }
    else
    {
        printf("\nNågot blev fel, prova igen\n");
    }

    fclose(fp);
}

void login()
{

    char tele[50], pword[50], filename[50], cont = 'y';
    FILE *fp;
    int val;
    float summa;
    

    printf("\n\n-----------------INLOGGNING---------------------\n\n");
    printf("Ange Telefonnummer: ");
    scanf("%s", tele);
    printf("Ange lösenord: ");
    scanf("%s", pword);

    strcpy(filename, tele);
    fp = fopen(strcat(filename, ".dat"), "r");

    fread(&usr, sizeof(struct User), 1, fp);
    fclose(fp);

    if (!strcmp(pword, usr.password))
    {   

        while(cont == 'y'){
        printf("\n--------------INLOGGAD----------------\n");
        printf("\n1. Se saldo");
        printf("\n2. Lägg in pengar");
        printf("\n3. Ta ut pengar");
        printf("\n4. Överföring av pengar");
        printf("\n5. Byt lösenord");
        printf("\nVälj: ");
        scanf("%d", &val);

        switch (val)
        {
        case 1:
            printf("Saldo: %.2lf KR\n", usr.balance);
            break;
            
        case 2:
            printf("\nAnge summan du vill lägga till: ");
            scanf("%f", &summa);
            usr.balance += summa;

            fp = fopen(filename, "w");
            fwrite(&usr, sizeof(struct User), 1, fp);

            if(fp != NULL) printf("\nÖverföringen godkänd!");

            fclose(fp);
                
            break;

        case 3:
            printf("\nAnge summan du vill ta ut: ");
            scanf("%f", &summa);
            if(summa > usr.balance){
                printf("\nDu har inte tillräckligt med pengar på kontot\n");
            }else{
            usr.balance -= summa;

            fp = fopen(filename, "w");
            fwrite(&usr, sizeof(struct User), 1, fp);

            if(fp != NULL) printf("\nUttag godkänt!\n");

            fclose(fp);
            }
            break;

        case 4:
            printf("\nAnge telefon nummer du vill överföra pengar till: ");
            scanf("%s", tele);
            printf("\nAnge summan att överföra: ");
            scanf("%f", &summa);
            if(summa > usr.balance) printf("\nDu har inte tillräckligt med pengar på kontot\n");

            else{
                strcpy(filename, tele);
                fp = fopen(strcat(filename, ".dat"), "r");
                fread(&usr1, sizeof(struct User), 1, fp);
                fclose(fp);

                fp = fopen(filename, "w");
                usr1.balance += summa;
                fwrite(&usr1, sizeof(struct User), 1, fp);
                fclose(fp);
                if(fwrite != NULL){
                    printf("\nÖverföringen av %.2f KR till %s är godkänd!\n", summa, tele);
                    strcpy(filename, usr.phone);
                    fp = fopen(strcat(filename, ".dat"), "w");
                    usr.balance -= summa;
                    fwrite(&usr, sizeof(struct User), 1, fp);
                    fclose(fp);

                }
            }


            break;
        
        default:
            printf("Felaktig inmatning\n");
            break;
        }

        printf("\nVill du fortsätta [y/n]\n");
        scanf("%s", &cont);
        }
    }
    else
    {
        printf("\nOgiltigt lösenord\n");
    }
}
