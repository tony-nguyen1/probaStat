#include <stdio.h>
#include <stdlib.h>
#include "../ressources/image_ppm.h"
#include <math.h> // sqrt pow expf

void fctGauss(float mu, float sigma);

int main(int argc, char* argv[])
{
    // printf("Hello, World!\n");
    char cNomImgIn1Lue[250],cNomImgIn2Lue[250],cNomImgOutLue[250];
    int nH, // hauteur
     nW, //largeur
      nTaille;

    if (argc != 4) {
        printf("Usage: ImageIn1.pgm ImageIn2.pgm ImageOut.pgm\n");
        exit(1);
    }

    sscanf (argv[1],"%s",cNomImgIn1Lue);
    sscanf (argv[1],"%s",cNomImgIn2Lue);
    sscanf (argv[1],"%s",cNomImgOutLue);

    OCTET *ImgIn1, *ImgIn2, *ImgOut;
    lire_nb_lignes_colonnes_image_pgm(cNomImgIn1Lue, &nH, &nW);
    nTaille = nH * nW;

    allocation_tableau(ImgIn1, OCTET, nTaille);
    allocation_tableau(ImgIn2, OCTET, nTaille);
    allocation_tableau(ImgOut, OCTET, nTaille);
    lire_image_pgm(cNomImgIn1Lue, ImgIn1, nH * nW);
    lire_image_pgm(cNomImgIn2Lue, ImgIn1, nH * nW);
    lire_image_pgm(cNomImgOutLue, ImgIn1, nH * nW);


    for (int i=0; i < nH; i++) {
        for (int j=0; j < nW; j++) {
            int diff = 0;

            diff = ImgIn1[i*nW+j] - ImgIn2[i*nW+j];
            // if (dif < )
            // diff

            ImgOut[i*nW+j] = diff+128;
        }
    }

    free(ImgIn1);free(ImgIn2);

    return 0;
}

void fctGauss(float mu, float sigma) {
    for (int i = 0; i < 256; i++) {
        float f, numerateur2, denominateur1, denominateur2;
        denominateur1 = (float)sigma*sqrtf(2*M_PI);
        //printf("test1 %f\n", denominateur1);
        numerateur2 = powf((float)(i-mu),2);
        //printf("test2 %f\n", numerateur2);
        denominateur2 = (float)(2*sigma*sigma);
        //printf("test3 %f\n", denominateur2);
        f = (float)(1/denominateur1)*expf(-numerateur2/denominateur2);
        //printf("%d %f\n", i, f);
    }
}