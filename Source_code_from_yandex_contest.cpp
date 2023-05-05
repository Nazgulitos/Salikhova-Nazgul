// Salikhova Nazgul

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
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
    while (t <= T) {
        cout << alpha_2/beta_2 + v0*cos(sqrt(alpha_1*alpha_2) * t)
                - k0*(beta_1* sqrt(alpha_2))/(beta_2 * sqrt(alpha_1)) * sin(sqrt(alpha_1*alpha_2)*t) << " ";
        t += T/N;
    }
    t = 0.00;
    cout<<endl;
    cout<<"k:"<<endl;
    while (t <= T) {
        cout << alpha_1/beta_1 + v0*(beta_2* sqrt(alpha_1))/(beta_1 * sqrt(alpha_2)) * sin(sqrt(alpha_1*alpha_2)*t)
                + k0*cos(sqrt(alpha_1*alpha_2) * t) << " ";
        t += T/N;
    }
    return 0;
}
