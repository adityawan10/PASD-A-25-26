//  TUGAS 1 - Program Fisika
//  Kelas A | GENAP 2025/2026
//  GERAK 1 DIMENSI
//  NPM : 4525210001
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
 
using namespace std;
 
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
 
void hitungWaktuTempuh() {
    double v0, a, vt, t;
 
    cout << "\n--- Menghitung Waktu Tempuh ---\n";
    cout << "Masukkan kecepatan awal  (v0) [m/s]  : ";
    cin >> v0;
    cout << "Masukkan percepatan      (a)  [m/s2] : ";
    cin >> a;
    cout << "Masukkan kecepatan akhir (vt) [m/s]  : ";
    cin >> vt;
 
    if (a == 0) {
        cout << "\n[ERROR] Percepatan tidak boleh nol untuk menghitung waktu tempuh.\n";
        return;
    }
 
    t = (vt - v0) / a;
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal  (v0) = " << v0 << " m/s\n";
    cout << "Percepatan      (a)  = " << a  << " m/s2\n";
    cout << "Kecepatan Akhir (vt) = " << vt << " m/s\n";
    cout << "----------------------------\n";
    cout << "Waktu Tempuh    (t)  = " << t  << " s\n";
    cout << "============================\n";
}
 

void hitungJarak() {
    double v0, a, t, s;
 
    cout << "\n--- Menghitung Jarak Tempuh ---\n";
    cout << "Masukkan kecepatan awal (v0) [m/s]  : ";
    cin >> v0;
    cout << "Masukkan percepatan     (a)  [m/s2] : ";
    cin >> a;
    cout << "Masukkan waktu tempuh   (t)  [s]    : ";
    cin >> t;
 
    s = v0 * t + 0.5 * a * t * t;
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal (v0) = " << v0 << " m/s\n";
    cout << "Percepatan     (a)  = " << a  << " m/s2\n";
    cout << "Waktu Tempuh   (t)  = " << t  << " s\n";
    cout << "----------------------------\n";
    cout << "Jarak Tempuh   (s)  = " << s  << " m\n";
    cout << "============================\n";
}
 
// --------------------------------------------------------
// Pilihan 3: Hitung percepatan
// Diketahui : kecepatan awal (v0), waktu tempuh (t), kecepatan akhir (vt)
// Rumus     : a = (vt - v0) / t
// --------------------------------------------------------
void hitungPercepatan() {
    double v0, vt, t, a;
 
    cout << "\n--- Menghitung Percepatan ---\n";
    cout << "Masukkan kecepatan awal  (v0) [m/s] : ";
    cin >> v0;
    cout << "Masukkan waktu tempuh    (t)  [s]   : ";
    cin >> t;
    cout << "Masukkan kecepatan akhir (vt) [m/s] : ";
    cin >> vt;
 
    if (t == 0) {
        cout << "\n[ERROR] Waktu tempuh tidak boleh nol.\n";
        return;
    }
 
    a = (vt - v0) / t;
 
    cout << fixed << setprecision(2);
    cout << "\n========== HASIL ==========\n";
    cout << "Kecepatan Awal  (v0) = " << v0 << " m/s\n";
    cout << "Waktu Tempuh    (t)  = " << t  << " s\n";
    cout << "Kecepatan Akhir (vt) = " << vt << " m/s\n";
    cout << "----------------------------\n";
    cout << "Percepatan      (a)  = " << a  << " m/s2\n";
    cout << "============================\n";
}
 
int main() {
    int pilihan;
 
    cout << "============================================\n";
    cout << "   PROGRAM GERAK 1 DIMENSI\n";
    cout << "   NPM  : 4525210001\n";
    cout << "============================================\n";
 
    do {
        cout << "\nPILIHAN MENU:\n";
        cout << "  1. Menghitung Waktu Tempuh\n";
        cout << "  2. Menghitung Jarak Tempuh\n";
        cout << "  3. Menghitung Percepatan\n";
        cout << "  0. Keluar\n";
        cout << "Masukkan pilihan [0-3] : ";
        cin >> pilihan;
 
        switch (pilihan) {
            case 1: hitungWaktuTempuh(); break;
            case 2: hitungJarak();       break;
            case 3: hitungPercepatan();  break;
            case 0: cout << "\nProgram selesai. Terima kasih!\n"; break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Coba lagi.\n";
                clearInput();
        }
 
    } while (pilihan != 0);
 
    return 0;
}
 
