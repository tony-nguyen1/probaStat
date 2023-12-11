#include <stdio.h>
#include <stdlib.h>
#include "../ressources/image_ppm.h"

int main(int argc, char* argv[])
{
    // printf("Hello, World!\n");
    char cNomImgLue[250];
    int nH, // hauteur
     nW, //largeur
      nTaille;
    int hist[256] = {0}; //intialisation à 0;

    if (argc != 2) {
        printf("Usage: ImageIn.pgm\n");
        exit(1);
    }

    sscanf (argv[1],"%s",cNomImgLue);

    OCTET *ImgIn;
    lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;

    allocation_tableau(ImgIn, OCTET, nTaille);
    lire_image_pgm(cNomImgLue, ImgIn, nH * nW);

    for (int i=0; i < nH; i++) {
        for (int j=0; j < nW; j++) {
            hist[ImgIn[i*nW+j]]++;
        }
    }

    for (int i=0; i<256; i++) {
        printf("%d %d\n",i,hist[i]);
    }

free(ImgIn);

    return 0;
}