#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "driv.h"
#include "node.h"
#include "list.h"
#include "node.h"

int main()
{
    bool end = false;
    node *head = NULL;
    node *tmp;
    int val;
    int func_val;
    int n;
    int index;
    int size = get_list_size(head);

    while (!end)
    {
        printf("\n<--------------------------------------------------->\n");
        printf("0. Avsluta \n");
        printf("1. Skriv ut listan\n");
        printf("2. Skriv ut listans storlek\n");
        printf("3. Lägg till ett heltal sist i listan\n");
        printf("4. Lägg till ett heltal (valfri plats)\n");
        printf("5. Ta bort ett givet tal\n");
        printf("6. Ta bort ett givet tal (valfri plats)\n");
        printf("7. Töm listan\n");
        printf("8. Vänd på listan\n");
        printf("9. Skifta listan ett steg åt vänster (lägg första heltalet sist)\n");
        printf("10. Skifta hela listan ett steg åt höger (lägg sista heltalet talet först)\n");
        printf("11. Sortera listan (lägsta heltalet först)\n");
        printf("12. Skriv ut startadresse för listan\n");
        printf("13. Kolla om listan är tom eller inte\n");
        printf("14. Kolla om ett visst element finns i listan eller inte\n");
        printf("15. Returnera elementet på en viss plats i listan\n");
        printf("16. Returnera platsen för första förekomst av ett vistt element i listan\n");
        printf("17. Lägg till ett element\n");
        printf("<--------------------------------------------------->\n\n");

        printf("Gör ditt val: ");

        scanf("%d", &val);

        switch (val)
        {
        case 0:
            end = true;
            break;

        case 1:
            printList(head);
            break;
        case 2:
            printf("Listans storlek: %d\n", get_list_size(head));
            break;
        case 3:
            printf("Ange talet du vill lägga till sist i listan: ");
            scanf("%d", &func_val);
            add_last_to_list(head, func_val);
            break;
        case 4:
            printf("Ange elementet samt indexet du vill lägga till på: ");
            scanf("%d %d", &func_val, &index);
            insert_specific_index(&head, func_val, index);
            break;

        case 5:

            printf("Ange ett element du vill ta bort: ");
            scanf("%d", &func_val);
            tmp = remove_by_value(head, func_val);
            if (!tmp)
                printf("\nDet angivna elementet [%d], finns inte i listan\n\n", func_val);
            else
            {
                printf("\nDet angivna elementet: [%d], har raderats från listan\n\n", func_val);
                printList(head);
            }

            break;

        case 6:
            printf("Ange index där du vill radera ett element: ");
            scanf("%d", &index);
            remove_by_index(head, index);
            break;

        case 7:
            delete_list(&head);
            break;

        case 8:
            printf("\nListan innan vändning: \n\n");
            printList(head);
            reverse_list(&head);
            printf("\nListan efter vändning: \n\n");
            printList(head);
            break;

        case 9:

            printf("\nLista före rotation:\n");
            printList(head);
            rotate_list_left(&head, 1);
            printf("\nLista efter rotation:\n");
            printList(head);
            break;

        case 10:
            rotate_list_right(head, 1);
            break;

        case 11:
            printf("\nListan före sortering: \n");
            printList(head);
            Sort_list(head);
            printf("\nListan efter Sortering: \n");
            printList(head);

            break;

        case 12:
            print_start_adress(head);
            break;

        case 13:
            isEmpty(head);
            break;

        case 14:
            printf("Ange ett element för att se om det finns i listan eller inte: ");
            scanf("%d", &func_val);
            if (Search_node(&head, func_val))
            {
                printf("\n%d finns\n", func_val);
            }
            else
            {
                printf("\n%d finns inte\n", func_val);
            }
            break;

        case 15:
            printf("\nAnge index: ");
            scanf("%d", &index);
            Get_element_at_index(head, index);
            break;

        case 16:
            printf("Ange tal för att hitta första förkomst: ");
            scanf("%d", &func_val);
            first_occurrence(head, func_val);
            break;

        case 17:
            printf("\nHur många element vill du lägga till?: ");
            scanf("%d", &n);
            if(n < 0){
                printf("\nOgiltig inmatning, prova igen\n\n");
                break;
            }
            for (int i = 0; i < n; i++)
            {
                printf("\nAnge talet du vill lägga till i listan: ");
                scanf("%d", &func_val);
                push(&head, func_val);
            }

            break;

        default:
            printf("\nFelaktig inmatning försök igen\n");
        }
    }

    return 0;
}