#include <math.h>

//DISARIDAN DEGERLERI ALIR.
extern double dx;
extern double x;
extern double eq;
extern double sonuc;
double dnklem;

//FONKSIYON
int denklem(double dx,double x)
{
	dnklem = x*x;//DENKLEM GIRISI
	eq = fabs(dx*dnklem);
	sonuc = sonuc + eq; //fabs komutu ile mutlak degerini alir. denklem tanimi burada yapilir.
	return sonuc;
}
