// Salikhova Nazgul

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#ifdef WIN32
#define GNUPLOT_NAME "C:\\gnuplot\\bin\\gnuplot -persist"
#else
#define GNUPLOT_NAME "gnuplot -persist"
#endif
int main() {
#ifdef WIN32
    FILE* pipe = _popen(GNUPLOT_NAME, "w");
#else
    FILE* pipe = popen(GNUPLOT_NAME, "w");
#endif
    cout<<fixed<<setprecision(2);
    double V = 112.0;
    double K = 45.0;
    double alpha_1 = 0.5;
    double beta_1 = 0.005;
    double alpha_2 = 0.4;
    double beta_2 = 0.006;
    double T = 55.0;
    double N = 200.0;

    double t = 0.00;
    double v0 = V - alpha_2/beta_2;
    double k0 = K - alpha_1/beta_1;

    fprintf(pipe, "plot '-' using 1:2 with lines title 'v(k)' \n");
    while (t <= T) {
        double victim = alpha_2/beta_2 + v0*cos(sqrt(alpha_1*alpha_2) * t)
                        - k0*(beta_1* sqrt(alpha_2))/(beta_2 * sqrt(alpha_1)) * sin(sqrt(alpha_1*alpha_2)*t);
        double killer = alpha_1/beta_1 + v0*(beta_2* sqrt(alpha_1))/(beta_1 * sqrt(alpha_2)) * sin(sqrt(alpha_1*alpha_2)*t)
                        + k0*cos(sqrt(alpha_1*alpha_2) * t);
        fprintf(pipe, "%f\t%f\n", killer, victim);
        t += T/N;
    }

    fprintf(pipe, "e\n");
    fflush(pipe);
    return 0;
#ifdef WIN32
    _pclose(pipe);
#else
    pclose(pipe);
#endif
}
