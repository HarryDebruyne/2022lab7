#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"


int selectProduct(){
     #ifdef DEBUG
        printf("DEBUGMODE => \n");
     #endif

    int menu;
    printf("\n*** 상품을 고르세요 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 이름검색\n");
    printf("6. 파일저장\n");
    printf("7. 이름검색\n");
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
    #ifdef DEBUG
        printf("DEBUGMODE => \n");
     #endif
   printf("이름  원산지  판매단위  배송방법 \n");
  printf("==================================\n");
  for( int i=0 ; i<count ; i++){
    if(s[i].method==-1) continue;
    printf("%2d",i+1);
    readProduct(s[i]);
  }
	return 0;
}

int readProduct(Product s){
    
    printf ("%8s %s %s  %d\n", s.name, s.exp,s.weight, s.method);
	return 0;
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
      #ifdef DEBUG
        printf("DEBUGMODE => \n");
    #endif
	s->method=-1;
   
    return 1;
}

void saveData(Product *s, int count){
    FILE *fp;
    fp = fopen("score.txt","wt");
    for(int i=0;i<count;i++){
        if(s->price==-1) continue;
        fprintf(fp,"%s %s %s %d\n",s->name, s->exp,s->weight, s->method);
    }
    fclose(fp);
    printf("=>저장됨! ");
}
 int loadData(Product *s){
     int count=0,i=0;
     FILE *fp;
     fp = fopen("score.txt","rt");
    if (fp==NULL)
    {
        printf("=> 파일 없음\n");
        fclose(fp);
        return 0;
    }
    else{
     for(;i<100;i++){
          
             fscanf(fp,"%s %s %s %d\n",s->name, s->exp,s->weight, s->method); 
	     if(feof(fp)) break;   
            
    
         
     }
     fclose(fp);
     printf("=> 로딩성공!\n");
     return i;
    }
 }




 void searchName(Product *s, int count){
      #ifdef DEBUG
        printf("DEBUGMODE => \n");
     #endif
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

