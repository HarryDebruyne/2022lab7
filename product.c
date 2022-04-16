#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"


int selectProduct(){
    int menu;
    printf("\n*** 상품을 고르세요 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int addProduct(Product *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("원산지는? ");
    scanf("%s", s->exp);
    printf("판매 단위는? ");
    scanf("%s", s->weight);

    printf("배송방법은?");
    scanf("%d", &s->method);
    printf("=>추가됨!");
    return 1;
}

int listProduct(Product *s, int count){
  printf("이름  원산지  판매단위  배송방법 \n");
  printf("==================================\n");
  for( int i=0 ; i<count ; i++){
    if(s[i].method==-1) continue;
    printf("%2d",i+1);
    readProduct(s[i]);
  }
}

int readProduct(Product s){
    
    printf ("%8s %s %s  %d\n", s.name, s.exp,s.weight, s.method);

}

int updateProduct(Product *s){
    printf("이름은? ");
    scanf("%s", s->name);
    printf("원산지는? ");
    scanf("%s", s->exp);
    printf("판매 단위는? ");
    scanf("%s", s->weight);
    printf("배송방법은?");
    scanf("%d", &s->method);
    printf("=> 수정성공!\n");
    return 1;
}
int selectDataNo(Product *s, int count){
  int no;
  listProduct(s,count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  return no;
  
}

int deleteProduct(Product *s){
    int i;
    
    s->method=-1;
   
    return 1;
}


 void searchName(Product *s, int count){
     int scnt=0;
     char search[20];
     printf("검색할 이름은? ");
     scanf("%s", search);

     printf("이름  원산지  판매단위  배송방법 \n");
     printf("==================================\n");
     for( int i=0; i<count;i++){
         if(s[i].method==-1) continue;
         if(strstr(s[i].name,search)){
             printf("%2d",i+1);
             readProduct(s[i]);
             scnt++;
         }
     }
     if(scnt==0) printf("=> 검색된 데이터 없음!");
     printf("\n");
 }

int main(void){
Product slist[20];
    int count = 0, menu,result=0;
    int index=0;//데이터번호



    while (1){
        menu = selectProduct();
        if (menu == 0) break;
        if(menu==1||menu==3 ||menu==4)
            if(count==0) continue;
        if (menu == 1){
            listProduct(slist,index);
        }
        else if (menu == 2){
             count += addProduct(&slist[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no==0){
              printf("=> 취소됨!\n");
              continue;
            }
          updateProduct(&slist[no-1]);
        }
        else if (menu == 4){
            int no =selectDataNo(slist, index);
            if(no==0){
              printf("=>취소됨");
              continue;
            }
          int deleteok;
          printf("정말로 삭제하시겠습니까?(삭제 :1)");
          scanf("%d", &deleteok);
          if(deleteok ==1){
            if(deleteProduct(&slist[no-1])) count--;
          }
          printf("=> 삭제됨\n");
            count--;
        }
        else if (menu ==5){
            searchName(slist , index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
