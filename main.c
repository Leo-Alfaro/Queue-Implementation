#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int main() {
    Desc fila;
    createqueue(&fila);
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Add new product\n");
        printf("2. Remove product\n");
        printf("3. View next product\n");
        printf("4. List all products\n");
        printf("5. Get specific data of next product\n");
        printf("6. Quit\n");
        printf("Choose: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                int id;
                char type[31], name[31];
                float price;
                printf("\nNew product -\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Type (max 30 letters): ");
                scanf("%s", type);
                printf("Name (max 30 letters): ");
                scanf("%s", name);
                printf("Price: ");
                scanf("%f", &price);
                addProduct(&fila, id, type, name, price);
                break;
            }
            case 2:
                removeProduct(&fila);
                break;
            case 3:
                showNextItem(&fila);
                break;
            case 4:
                showItems(&fila);
                break;
            case 5: {
                if (emptyQueue(&fila)) {
                    printf("The queue is empty.\n");
                    break;
                }
                int subOption;
                printf("\nChoose the data to retrieve:\n");
                printf("1. ID\n");
                printf("2. Type\n");
                printf("3. Name\n");
                printf("4. Price\n");
                printf("Choose: ");
                scanf("%d", &subOption);
                switch(subOption) {
                    case 1:
                        getIdProductNextItem(&fila);
                        break;
                    case 2:
                        getTypeProductNextItem(&fila);
                        break;
                    case 3:
                        getNameProductNextItem(&fila);
                        break;
                    case 4:
                        getPriceProductNextItem(&fila);
                        break;
                    default:
                        printf("Invalid option!\n");
                }
                break;
            }
            case 6:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 6);
    return 0;
}