//  TUGAS 1 - Program Fisika
//  Kelas A | GENAP 2025/2026
//  GERAK 2 DIMENSI (GERAK PELURU)
//  NPM : 4525210001

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
 
using namespace std;
 
const double g = 9.8;   
const double PI = acos(-1.0);
 
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
 
// --------------------------------------------------------
// Pilihan 1: Hitung kecepatan arah X dan Y
// Diketahui : kecepatan awal (v0), sudut (theta)
// Rumus     :
//   vx = v0 * cos(theta)
//   vy = v0 * sin(theta)
// --------------------------------------------------------
void hitungKecepatanXY() {
    double v0, theta, vx, vy;
 
    cout << "\n--- Menghitung Kecepatan Arah X dan Y ---\n";
    cout << "Masukkan kecepatan awal (v0)    [m/s]    : ";
    cin >> v0;
    cout << "Masukkan sudut lempar   (theta) [derajat]: ";
    cin >> theta;
 
    double rad = theta * PI / 180.0;
    vx = v0 * cos(rad);
    vy = v0 * sin(rad);
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal (v0)    = " << v0    << " m/s\n";
    cout << "Sudut Lempar   (theta) = " << theta << " derajat\n";
    cout << "----------------------------\n";
    cout << "Kecepatan Arah X (vx)  = " << vx   << " m/s\n";
    cout << "Kecepatan Arah Y (vy)  = " << vy   << " m/s\n";
    cout << "============================\n";
}
 
// --------------------------------------------------------
// Pilihan 2: Hitung tinggi maksimum
// Diketahui : kecepatan awal (v0), sudut (theta)
// Rumus     :
//   vy = v0 * sin(theta)
//   h_max = vy^2 / (2 * g)
// --------------------------------------------------------
void hitungTinggiMaksimum() {
    double v0, theta, vy, hmax;
 
    cout << "\n--- Menghitung Tinggi Maksimum ---\n";
    cout << "Masukkan kecepatan awal (v0)    [m/s]    : ";
    cin >> v0;
    cout << "Masukkan sudut lempar   (theta) [derajat]: ";
    cin >> theta;
 
    double rad = theta * PI / 180.0;
    vy   = v0 * sin(rad);
    hmax = (vy * vy) / (2.0 * g);
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal    (v0)    = " << v0    << " m/s\n";
    cout << "Sudut Lempar      (theta) = " << theta << " derajat\n";
    cout << "Kecepatan Vert.   (vy)    = " << vy   << " m/s\n";
    cout << "----------------------------\n";
    cout << "Tinggi Maksimum   (h_max) = " << hmax << " m\n";
    cout << "============================\n";
}
 
// --------------------------------------------------------
// Pilihan 3: Hitung jarak maksimum (jangkauan)
// Diketahui : kecepatan awal (v0), sudut (theta)
// Rumus     :
//   R = v0^2 * sin(2*theta) / g
// --------------------------------------------------------
void hitungJarakMaksimum() {
    double v0, theta, R;
 
    cout << "\n--- Menghitung Jarak Maksimum ---\n";
    cout << "Masukkan kecepatan awal (v0)    [m/s]    : ";
    cin >> v0;
    cout << "Masukkan sudut lempar   (theta) [derajat]: ";
    cin >> theta;
 
    double rad = theta * PI / 180.0;
    R = (v0 * v0 * sin(2.0 * rad)) / g;
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal  (v0)    = " << v0    << " m/s\n";
    cout << "Sudut Lempar    (theta) = " << theta << " derajat\n";
    cout << "----------------------------\n";
    cout << "Jarak Maksimum  (R)     = " << R    << " m\n";
    cout << "============================\n";
}
 
int main() {
    int pilihan;
 
    cout << "============================================\n";
    cout << "   PROGRAM GERAK 2 DIMENSI (GERAK PELURU)\n";
    cout << "   NPM  : 4525210001\n";
    cout << "============================================\n";
    cout << "Konstanta gravitasi (g) = " << g << " m/s2\n";
 
    do {
        cout << "\nPILIHAN MENU:\n";
        cout << "  1. Menghitung Kecepatan Arah X dan Y\n";
        cout << "  2. Menghitung Tinggi Maksimum\n";
        cout << "  3. Menghitung Jarak Maksimum\n";
        cout << "  0. Keluar\n";
        cout << "Masukkan pilihan [0-3] : ";
        cin >> pilihan;
 
        switch (pilihan) {
            case 1: hitungKecepatanXY();     break;
            case 2: hitungTinggiMaksimum();  break;
            case 3: hitungJarakMaksimum();   break;
            case 0: cout << "\nProgram selesai. Terima kasih!\n"; break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Coba lagi.\n";
                clearInput();
        }
 
    } while (pilihan != 0);
 
    return 0;
}
 
