#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double ozvektor(double, double, double);
double schur(double, double, double);
int matris[10][10],t,k;
int ozdeger(int ymatris[10][10],int v,int k);
int nilpotent();
int cark();
int main()
{
    printf("\n----------MATEMATIK CARKI PROGRAMINA HOS GELDINIZ-----------\n");
    srand(time(NULL));
    cark();
    return 0;
}

int cark()
{
    printf("CARK FONSIYONUNDASINIZ\n");
    int i,j,b;
    printf("Cark Kac Kez Sayi Uretsin ?\n");
    scanf("%d",&i);
    int say[i];
    printf("\n");
    for(j=0; j<i; j++)
    {
        say[j]=rand()%241;
        printf("%d\n",say[j]);
    }
    if(say[i-1]%4==0)
    {
        b=0;
        printf("OZ DEGER BUL ISLEMINDESINIZ\n\n");
        printf("\nMatrisin Boyutunu Giriniz\n");
        scanf("%d",&t);
        if(t>3 || t<2)
        {
            printf("YANLIS DEGER GIRDINIZ\n");
            printf("LUTFEN 2 VEYA 3 RAKAMI GIRINIZ\n");
            scanf("%d",&t);
        }
        for(i=0; i<t; i++)
        {
            for(j=0; j<t; j++)
            {
                printf("matris[%d][%d]: ",i+1,j+1);
                scanf("%d",&matris[i][j]);
            }
        }

        ozdeger(matris,t,b);
    }
    else if(say[i-1]%4==1)
    {
        b=1;
        printf("SCHUR ISLEMINDESINIZ\n\n");
        printf("\nMatrisin Boyutunu Giriniz\n");
        scanf("%d",&t);
        if(t>3 || t<2)
        {
            printf("YANLIS DEGER GIRDINIZ\n");
            printf("LUTFEN 2 VEYA 3 RAKAMI GIRINIZ\n");
            scanf("%d",&t);
        }
        for(i=0; i<t; i++)
        {
            for(j=0; j<t; j++)
            {
                printf("matris[%d][%d]: ",i+1,j+1);
                scanf("%d",&matris[i][j]);
            }
        }
        ozdeger(matris,t,b);
    }
    else if(say[i-1]%4==2)
    {
        b=2;
        printf("OZ VEKTOR ISLEMINDESINIZ\n\n");
        printf("\nMatrisin Boyutunu Giriniz\n");
        scanf("%d",&t);
        if(t>3 || t<2)
        {
            printf("YANLIS DEGER GIRDINIZ\n");
            printf("LUTFEN 2 VEYA 3 RAKAMI GIRINIZ\n");
            scanf("%d",&t);
        }
        for(i=0; i<t; i++)
        {
            for(j=0; j<t; j++)
            {
                printf("matris[%d][%d]: ",i+1,j+1);
                scanf("%d",&matris[i][j]);
            }
        }
        ozdeger(matris,t,b);
    }
    else if(say[i-1]%4==3)
    {
        nilpotent();
    }
    return 0;
}
int ozdeger(int ymatris[][10],int x, int y)
{

    double a=1,b,c,d,kok1,kok2,i,j;
    double e,z,g,h,k,l,m,n,p,r,s,t,u,x1,x2,x3;
    int durum,satir,sutun;
    FILE *f=fopen("ozdeger.txt","w");
    if(f==NULL)
    {
        printf("Hata Olustu Dosya Acilamadi!\n");
        exit(1);
    }
    fprintf(f,"GIRILEN MATRIS\n\n");
    for(satir=0; satir<x; satir++)
    {
        for(sutun=0; sutun<x; sutun++)
        {
            fprintf(f,"%d\t",ymatris[satir][sutun]);
        }
        fprintf(f,"\n");
    }
    if(x==2)
    {
        b=(-1)*(ymatris[0][0]+ymatris[1][1]);
        c=(ymatris[0][0]*ymatris[1][1])-(ymatris[0][1]*ymatris[1][0]);
        d=b*b-4*a*c;
        kok1=((-1)*b+sqrt(d))/(2*a);
        kok2=((-1)*b-sqrt(d))/(2*a);
        if(y==0)
        {
            printf("\nkok 1: %.2f\n",kok1);
            printf("\nkok 2: %.2f\n",kok2);
            fprintf(f,"\nKOKLER\n\n");
            fprintf(f,"KOK1: %.2lf\tKOK2: %.2lf",kok1,kok2);
        }
        if(y==1)
        {
            schur(kok1,kok2,0);
        }
        if(y==2)
        {
            ozvektor(kok1,kok2,0);
        }
    }
    if(x==3)
    {
        a=-1;
        b=ymatris[0][0]+ymatris[1][1]+ymatris[2][2];
        c=(ymatris[0][2]*ymatris[2][0])+(ymatris[1][2]*ymatris[2][1])+(ymatris[0][1]*ymatris[1][0])-(ymatris[0][0]*ymatris[2][2])-(ymatris[0][0]*ymatris[1][1])-(ymatris[1][1]*ymatris[2][2]);
        d=(ymatris[1][0]*ymatris[2][1]*ymatris[0][2])+(ymatris[2][0]*ymatris[0][1]*ymatris[1][2])+(ymatris[0][1]*ymatris[1][1]*ymatris[2][2])-(ymatris[0][2]*ymatris[1][1]*ymatris[2][0])-(ymatris[0][0]*ymatris[1][2]*ymatris[2][1])-(ymatris[0][1]*ymatris[1][0]*matris[2][2]);

        /* BU KISIM http://www.dreamincode.net/forums/topic/21670-cubic-equation/ WEB SITESINDEN ALINTIDIR !!!!!!!
           KOD WEB SITEDEN ALINMIS OLUP ÜZERINDE ÇESITLI OYNAMALAR YAPILMISTIR !!!!!!!!!!!!  */
        e=2.7182818284590;

        z=((3*c/a)-(b*b/a*a))/3;

        g=((2*b*b*b/a*a*a)-(9*b*c/a*a)+(27*d/a))/27;

        h=(g*g/4)+(z*z*z/27);

        i=sqrt(((g*g/4)-h));

        j=exp(log10(i)/log10(e)/3);

        k=acos((-1)*(g/(2*i)));

        l=j*(-1);

        m=cos(k/3);

        n=sqrt(3)*sin(k/3);

        p=(b/3*a)*(-1);

        r=(-1)*(g/2)+sqrt(h);

        s=exp(log10(r)/log10(e)/3);

        t=(-1)*(g/2)-sqrt(h);

        u=exp(log10(t)/log10(e)/3);

        if (h>0)
            durum=1;

        if (h<=0)
            durum=3;

        if ((z==0) && (g==0) && (h==0))
            durum=2;

        switch (durum)
        {

        case 1:

            printf("Denklemin Sanal Kokleri Vardir\n");
            x1=(s+u)-(b/3*a);

            x2=(-1)*(s+u)/2-(b/3*a);

            x3=(s-u)*sqrt(3)/2;

            printf("\n 3 kok:\n%.2lf\n%.2lf +i*%.2lf\n%.2lf -i*%.2lf", x1, x2, x3, x2, x3);
            fprintf(f,"\n 3 kok:\n%.2lf\t%.2lf +i*%.2lf\t%.2lf -i*%.2lf",x1, x2, x3, x2, x3);
            if(y==1)
            {
                schur(x1,x2,x3);
            }
            break;

        case 2:

            printf("Denklemin Tek Koku Vardir\n");
            x1=exp(log10(d/a)/log10(e)/3)*(-1);

            printf("\n\n%.2f", x1);
            fprintf(f,"\n\n%.2f",x1);
            if(y==1)
            {
                schur(x1,0,0);
            }

            break;

        case 3:

            printf("Denklemin 3 Reel Koku Vardir\n");
            x1=2*j*cos(k/3)-(b/3*a);

            x2=l*(m+n)+p;

            x3=l*(m-n)+p;

            printf("\n%.2f     %.2f     %.2f", x1, x2, x3);
            fprintf(f,"\n%.2f     %.2f     %.2f",x1,x2,x3);
            if(y==1)
            {
                schur(x1,x2,x3);
            }
            break;

        }

        system("PAUSE");

    }

    return 0;
}
double schur(double x1,double x2,double x3)
{
    FILE *f=fopen("schur.txt","w");
    if(f==NULL)
    {
        printf("Hata Olustu Dosya Acilamadi!\n");
        exit(1);
    }
    double sinir;
    int x,m,k;
    printf("Matrisin Boyutunu Tekrar Giriniz:");
    scanf("%d",&x);
    int smatris[x][x];
    printf("Matrsin Elemanlarini Tekrar Giriniz\n");
    for(k=0; k<x; k++)
    {
        for(m=0; m<x; m++)
        {
            printf("matris[%d][%d]: ",k+1,m+1);
            scanf("%d",&smatris[k][m]);
        }
    }
    int topla;
    double sonuc=0;
    for(k=0; k<x; k++)
    {
        for(m=0; m<x; m++)
        {
            topla=matris[k][m]*matris[k][m];
            sonuc=topla+sonuc;
        }
    }
    sinir=sqrt((pow(x1,2)+pow(x2,2)+pow(x3,2)));
    fprintf(f,"GIRILEN KARE MATRIS\n");
    for(k=0; k<x; k++)
    {
        for(m=0; m<x; m++)
        {
            fprintf(f,"%d\t",smatris[k][m]);
        }
        fprintf(f,"\n");
    }
    printf("\n SINIR DEGER : %.2lf\n",sonuc);
    fprintf(f,"\n SINIR DEGER : %.2lf\n\n",sonuc);
    if (sinir<sqrt(sonuc))
    {
        fprintf(f,"MATRIS VE OZ DEGERLER SHUR TEOREMINI SAGLAR\n\n");
        printf("\n\nMatris Ve Ozdegerler Schur Teoremini Saglar");
        printf("\n\n%.2lf < %.2lf",sinir,sonuc);
        fprintf(f,"\n\n%.2lf < %.2lf",sinir,sonuc);
    }
    else
    {
        fprintf(f,"MATRIS VE OZ DEGERLER SHUR TEOREMINI SAGLAMAZ\n\n");
        printf("\n\nMatris Ve Ozdegerler Schur Teoremini Saglamaz");
        printf("\n\n%.2lf > %.2lf",sinir,sonuc);
        fprintf(f,"\n\n%.2lf > %.2lf",sinir,sonuc);
    }
    return 0;
}
double ozvektor(double z1, double z2, double z3)
{
    FILE *f=fopen("ozvektor.txt","w");
    if(f==NULL)
    {
        printf("Hata Olustu Dosya Acilamadi!\n");
        exit(1);
    }
    double m,n,k,l;
    int i,j,t;
    printf("MATRISIN BOYUTUNU TEKRAR GIRINIZ:\n");
    scanf("%d",&t);

    float matris[t][t];
    float mat[t][t],kat[t][t],top[t][t];
    printf("MATRISI TEKRAR GIRINIZ\n");
    for(i=0; i<t; i++)
    {
        for(j=0; j<t; j++)
        {
            printf("Matris[%d][%d]: ",i+1,j+1);
            scanf("%f",&matris[i][j]);
        }
    }

    for(i=0; i<t; i++)
    {
        for(j=0; j<t; j++)
        {
            if(i==j)
            {
                mat[i][j]=(-1)*z1;
                kat[i][j]=matris[i][j]+mat[i][j];
            }
            else
            {
                mat[i][j]=0*z1;
                kat[i][j]=matris[i][j]+mat[i][j];
            }

        }

    }

    for(i=0; i<t; i++)
    {
        for(j=0; j<t; j++)
        {
            if(i==j)
            {
                mat[i][j]=(-1)*z2;
                top[i][j]=matris[i][j]+mat[i][j];
            }
            else
            {
                mat[i][j]=0*z2;
                top[i][j]=matris[i][j]+mat[i][j];
            }
        }
    }
    fprintf(f,"GIRILEN KARE MATRIS\n\n");
    for(i=0; i<t; i++)
    {
        for(j=0; j<t; j++)
        {
            fprintf(f,"%.2f\t",matris[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\nOZDEGERLER\n");
    fprintf(f,"kok1: %.2lf\t kok2: %.2lf\t kok3: %.2lf",z1,z2,z3);
    printf("kok1: %.2lf\t kok2: %.2lf\t kok3: %.2lf",z1,z2,z3);
    if(t==2)
    {

        m=(-1)*kat[0][1]/kat[0][0];
        n=(-1)*m*kat[0][0]/kat[0][1];
        printf("\n\nKOK1 ICIN OZ VEKTORLER\n");
        printf("%.2lf\t%.2lf\n",n,m);
        fprintf(f,"\n\nKOK1 ICIN OZ VEKTORLER\n");
        fprintf(f,"%.2lf\t%.2lf\n",n,m);

        k=(-1)*top[0][1]/top[0][0];
        l=(-1)*k*top[0][0]/top[0][1];
        printf("\n\nKOK2 ICIN OZ VEKTORLER\n");
        printf("%.2lf\t%.2lf\n",k,l);
        fprintf(f,"\nKOK2 ICIN OZ VEKTORLER\n");
        fprintf(f,"%.2lf\t%.2lf",k,l);

    }

    return 0;
}
int nilpotent()
{
    printf("NILPOTENT FONSIYONUNDASIN\n\n");
    FILE *f=fopen("nilpotenttt.txt","w");
    if(f==NULL)
    {
        printf("Hata Olustu Dosya Acilamadi!\n");
        exit(1);
    }
    int boyut,i,j,k,toplam=0;
    printf("Kare Matrisin Boyutlarini Giriniz\n");
    scanf("%d",&boyut);
    int mak[boyut][boyut];
    int kat[boyut][boyut];
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            mak[i][j]=-15+rand()%30;
        }
    }
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            printf("%d\t",mak[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            for(k=0; k<boyut; k++)
            {
                toplam+=mak[i][k]*mak[k][j];
            }
            kat[i][j]=toplam;
            toplam=0;
        }
    }
    int test=0;
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            if(kat[i][j]!=0)
            {
                printf("Bu Bir Nilpotent Matris Degildir\n");
                fprintf(f,"\nBu Bir Nilpotent Matris Degildir\n");
                test=1;
                break;
            }
        }
        if(test)
            break;
    }
    if(test==0)
    {
        printf("Bu Bir Nilpotent Matristir\n");
        fprintf(f,"Bu Bir Nilpotent Matristir\n");
    }
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            printf("%d\t",kat[i][j]);
        }
        printf("\n");
    }
    fprintf(f,"Uretilen Kare Matris\n");
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            fprintf(f,"%d\t",mak[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"Karsilastirilan Kare Matris\n");
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            fprintf(f,"%d\t",kat[i][j]);
        }
        fprintf(f,"\n");
    }

    return 0;
}
