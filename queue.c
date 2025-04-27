#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void createqueue(Desc* q){
    q->start = NULL;
    q->final = NULL;
    return;
}

int emptyQueue(Desc* q){
    if(q->start == NULL){
        return 1;
    }
    return 0;
}

void addProduct(Desc* q, int id, char* type, char* name, float price){
    No* new = (No*) malloc(sizeof(No));
    new->item.id = id;
    strcpy(new->item.name, name);
    strcpy(new->item.type, type);
    new->item.price = price;
    new->prox = NULL;
    if(emptyQueue(q)){
        q->start = new;
        q->final = new;
        printf("Added product: ID=%d, Type=%s, Name=%s, Price=%.2f\n", id, type, name, price);
        return;
    }
    q->final->prox = new;
    q->final = new;
    printf("Added product: ID=%d, Type=%s, Name=%s, Price=%.2f\n", id, type, name, price);
    return;
}

void removeProduct(Desc* q){
    if(emptyQueue(q)){
        printf("The queue is empty.\n");
        return;
    }
    No* temp = q->start;
    q->start = temp->prox;
    if(emptyQueue(q)){
        q->final = NULL;
    }
    printf("Removed product: ID=%d, Type=%s, Name=%s, Price=%.2f\n", temp->item.id, temp->item.type, temp->item.name, temp->item.price);
    free(temp);
    return;
}

int getIdProductNextItem(Desc* q){
    if(emptyQueue(q)){
        printf("The queue is empty.\n");
        return -1;
    }
    printf("Next item ID: %d\n", q->start->item.id);
    return q->start->item.id;
}

char* getTypeProductNextItem(Desc* q){
    if(emptyQueue(q)){
        printf("The queue is empty.\n");
        return NULL;
    }
    printf("Next item type: %s\n", q->start->item.type);
    return q->start->item.type;
}

char* getNameProductNextItem(Desc* q){
    if(emptyQueue(q)){
        printf("The queue is empty.\n");
        return NULL;
    }
    printf("Next item name: %s\n", q->start->item.name);
    return q->start->item.name;
}

float getPriceProductNextItem(Desc* q){
    if(emptyQueue(q)){
        printf("The queue is empty.\n");
        return 0.0;
    }
    printf("Next item price: %.2f\n", q->start->item.price);
    return q->start->item.price;
}

void showItem(Product i){
    printf("Product:\n");
    printf(" - ID: %d\n", i.id);
    printf(" - Type: %s\n", i.type);
    printf(" - Name: %s\n", i.name);
    printf(" - Price: %.2f\n", i.price);
}

void showNextItem(Desc* q){
    if (emptyQueue(q)) {
        printf("The queue is empty.\n");
        return;
    }
    showItem(q->start->item);
    return;
}

void showItems(Desc* q){
    if (emptyQueue(q)) {
        printf("The queue is empty.\n");
        return;
    }
    No* temp = q->start;
    while(temp != NULL){
        showItem(temp->item);
        temp = temp->prox;
    }
    return;
}