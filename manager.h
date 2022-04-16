#include <stdio.h>

typedef struct{
    char name[20];
    char exp[300];
    char weight[10];
    int price;
    int method;
} Product;

void searchName(Product *s, int count);

void saveData(Product *s, int count);
int loadData(Product *s);

int selectProduct();
int addProduct(Product *s);

int listProduct(Product *s, int count);

int readProduct(Product s);

int updateProduct(Product *s);
int selectDataNo(Product *s, int count);

int deleteProduct(Product *s);
