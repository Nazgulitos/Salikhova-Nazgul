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
    double V, K, N;
    double T, alpha_1, beta_1, alpha_2, beta_2;
    cin >> V >> K >> alpha_1 >> beta_1 >> alpha_2 >> beta_2 >> T >> N;
    double t = 0.00;
    double v0 = V - alpha_2/beta_2;
    double k0 = K - alpha_1/beta_1;

    cout<<"t:"<<endl;
    while (t <= T) {
        cout<<t<<" ";
        t += T/N;
    }
    t = 0.00;
    cout<<endl;
    cout<<"v:"<<endl;
    fprintf(pipe, "plot '-' using 1:2 with lines title 'victims',""'-' using 1:2 with lines title 'killers'\n");
//    while (t <= T) {
//
//        fprintf(pipe, "%f\t%f\n", t, x);
//        t += T/N;
//    }
//    fprintf(pipe, "e\n");
    fprintf(pipe, "plot '-' using 1:2 with lines\n");
    t = 0.00;
    cout<<endl;
    cout<<"k:"<<endl;
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
