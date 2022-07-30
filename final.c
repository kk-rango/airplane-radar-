#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int N(int x,int y, char z[50]);
int W();
int R();

int c1, c2;
int a[10][10] = {0};
int i, j;
int f1, g1, f2, g2, f3, g3;


int main(){

    //displaying of the PIP Radar

   
    for (i =0; i<10;i++)
    {
	    for(j=0;j<10;j++)
	    {
		    printf("%d ", a[i][j]);
		    if(j==9)
		    {
			    printf("\n");
		    }
	    }
    }
	
	
	printf("Give the coordinational point that the plane start when see in the PPI machine at t(0)");
	scanf("%d %d",&c1,&c2);
	f1 = c1;
	g1 = c2;
	c1 = c1 - 1;
	c2 = c2 - 1;
	
	printf("Press any key for exit. You can see all coordinates at program file's");
	N(0, 0, "1");
	
	
	W();
    R();
    getch();
        return 0;
}

int N(int x,int y, char z[50]){
    
	a[c1][c2] = 0;
	
	c1= c1 + x;
	c2 = c2 + y;
    
	if(c1< 0 || c2< 0){
            FILE *inf;
            inf = (fopen("zINFO.txt", "w"));
            
            if(inf == NULL){
                   printf("Error!\n");
                   exit(1);
                   }
            fprintf(inf, "Hedef %s. zamanda gorus alanindan cikti!!! ", z);
            fclose(inf);
            getch();
            }
	else{
	a[c1][c2] = 1;
	
	char buffer[50];
	strcpy(buffer,"t");
	strcat(buffer, z);
	strcat(buffer, ".txt");
	
    FILE *kk;
	kk= (fopen(buffer, "w"));
	
	if(kk == NULL){
		printf("Error!\n");
		exit(1);
	}
	for (i =0; i<10;i++)
    {
	    for(j=0;j<10;j++)
	    {
		    fprintf(kk, "%d ", a[i][j]);
		    if(j==9)
		    {
			    fprintf(kk, "\n");
		    }
	    }
    }
    fclose(kk);
}


}


int W(){
    
    time_t t;
	srand((unsigned) time(&t));
	
	int g = 1+ rand() % 8;
    
    switch(g){
              case 1:
                   N(0,1,"2");
                   N(1,1,"3");
                   N(1,1,"4");
                   N(1,0,"5");
                   N(1,1,"6");
                   N(0,1,"7");
                              break;
              case 2:
                   N(-1,1,"2");
                   N(-1,1,"3");
                   N(0,1, "4");
                   N(-1,1,"5");
                   N(-1,0,"6");
                   N(-1,-1,"7");
                                break;                
              case 3:
                   N(1,0,"2");
                   N(1,0,"3");
                   N(1,1,"4");
                   N(0,1,"5");
                   N(-1,1,"6");
                   N(-1,0,"7");
                       break;
              case 4:
                   N(1,1,"2");
                   N(0,1,"3");
                   N(0,1,"4");
                   N(0,1,"5");
                   N(1,1,"6");
                   N(1,0,"7");
                       break;
              case 5:
                   N(1,-1,"2");
                   N(1,0,"3");
                   N(1,1,"4");
                   N(0,1,"5");
                   N(-1,1,"6");
                   N(-1,0,"7");
                               break;
              case 6:
                   N(-1,0,"2");
                   N(-1,-1,"3");
                   N(0,-1,"4");
                   N(0,-1,"5");
                   N(1,-1,"6");
                   N(1,0,"7");
                       break;
                       
              case 7:
                   N(-1,-1,"2");
                   N(-1,0,"3");
                   N(-1,-1,"4");
                   N(0,-1,"5");
                   N(1,-1,"6");
                   N(1,0,"7");
                              break;                                   
              case 8:
                   N(0,-1,"2");
                   N(0,-1,"3");
                   N(0,-1,"4");
                   N(-1,-1,"5");
                   N(-1,-1,"6");
                   N(0,-1,"7");
                               break;
              }
    }
int R(){
    f2 = c1 + 1;
	g2 = c2 + 1;
    f3  = g2 - g1;
    g3 = f1 - f2;
    char prs[5] = "";
    if(g3>0){
            strcat(prs, "+");
            }    
    
    FILE *vct;
    vct = (fopen("vector.txt", "w"));
    if(vct == NULL){
		printf("Error!\n");
		exit(1);
	}
	fprintf(vct,"The vector is: \t");
	fprintf(vct,"%di %s %dj", f3, prs, g3);
	fclose(vct);
    }
