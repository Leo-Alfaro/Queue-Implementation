#ifndef _QUEUE_H_
#define _QUEUE_H_

struct product{
    int id;
    char type[31];
    char name[31];
    float price;
};
typedef struct product Product;

struct no{
    Product item;
    struct no* prox;
};
typedef struct no No;

struct desc{
    No* start;
    No* final;
};
typedef struct desc Desc;

void createqueue(Desc* q);
void addProduct(Desc* q, int id, char* type, char* name, float price);
void removeProduct(Desc* q);
int getIdProductNextItem(Desc* q);
char* getTypeProductNextItem(Desc* q);
char* getNameProductNextItem(Desc* q);
float getPriceProductNextItem(Desc* q);
void showNextItem(Desc* q);
void showItems(Desc* q);

#endif