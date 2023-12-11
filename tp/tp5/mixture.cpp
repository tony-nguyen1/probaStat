#include <stdlib.h>
#include "../ressources/image_ppm.h"
#include "gauss.h"

int N;
int main(int argc, char* argv[]) {

    // N=3;
    // float mu[3] = {148.458,90.9868,53.7256};
    // float o[3] = {33.7109,18.5974,7.74448};
    // float p[3] = {.731232,.119886,.148882};

    N=5;
    float mu[5] = {210.249,151.649,201.997,102.542,53.9289};
    float o[5] = {4.13583,19.5871,10.4576,21.8029,7.90281};
    float p[5] = {0.0156879,0.45738,0.0823951,0.291846,0.152691};    

    for (int i=0; i<256; i++) {
        float fx = 0;

        for (int n=0; n<N; n++) {
            fx += gauss(mu[n],o[n],i)*p[n];
        }

        printf("%i %f\n",i ,fx);
    }

    return 0;
}