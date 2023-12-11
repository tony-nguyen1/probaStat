#include <math.h> // sqrt pow expf
#include <stdio.h>

void fctGauss(float mu, float sigma) {
    for (int i = 0; i < 256; i++) {
        float f, numerateur2, denominateur1, denominateur2;
        denominateur1 = (float)sigma*sqrtf(2*M_PI);
        numerateur2 = powf((float)(i-mu),2);
        denominateur2 = (float)(2*sigma*sigma);
        f = (float)(1/denominateur1)*expf(-numerateur2/denominateur2);
        printf("%d %f\n", i, f);
    }
}

float gauss(float mu, float sigma, int x) {
    float f, numerateur2, denominateur1, denominateur2;
    denominateur1 = (float)sigma*sqrtf(2*M_PI);
    numerateur2 = powf((float)(x-mu),2);
    denominateur2 = (float)(2*sigma*sigma);
    f = (float)(1/denominateur1)*expf(-numerateur2/denominateur2);
    
    return f;
}