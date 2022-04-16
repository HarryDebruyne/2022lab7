typedef struct{
    char name[20];
    char exp[300];
    char weight[10];
    int price;
    int method;
} Product;


int createProduct(Product *p); // 제품을 추가하는 함수
int deleteProduct(Product *s);
int readProduct(Product s); // 하나의 제품 출력 함수
int listProduct(Product *s,int count); // 전체 등록된 제품 리스트 출력
void searchProduct(Product *p[],int count); // 제품이름 검색


