#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

template <typename T>
void write_limits_readable(ofstream &outfile, const string &type_name) {
    outfile << setw(20) << type_name
            << setw(10) << (long double) sizeof(T)
            << setw(20) << (long double) numeric_limits<T>::lowest()
            << setw(20) << (long double) numeric_limits<T>::min()
            << setw(20) << (long double) numeric_limits<T>::max()
            << setw(10) << (long double) numeric_limits<T>::digits10
            << endl;
}

template <typename T>
void write_limits_csv(ofstream &outfile, const string &type_name) {
    outfile << type_name
            << "," << (long double) sizeof(T)
            << "," << (long double) numeric_limits<T>::lowest()
            << "," << (long double) numeric_limits<T>::min()
            << "," << (long double) numeric_limits<T>::max()
            << "," << (long double) numeric_limits<T>::digits10
            << endl;
}

void create_readable_table() {
    ofstream outfile("numeric_limits.txt");

    outfile << setw(20) << "type"
            << setw(10) << "size"
            << setw(20) << "lowest()"
            << setw(20) << "min()"
            << setw(20) << "max()"
            << setw(10) << "digits10"
            << endl;

    outfile << string(100, '-') << endl;

    // Integral types
    write_limits_readable<bool>(outfile, "bool");
    write_limits_readable<char>(outfile, "char");
    write_limits_readable<wchar_t>(outfile, "wchar_t");
    write_limits_readable<short>(outfile, "short");
    write_limits_readable<int>(outfile, "int");
    write_limits_readable<long>(outfile, "long");
    write_limits_readable<long long>(outfile, "long long");

    // Unsigned integral types
    write_limits_readable<unsigned char>(outfile, "unsigned char");
    write_limits_readable<unsigned short>(outfile, "unsigned short");
    write_limits_readable<unsigned int>(outfile, "unsigned int");
    write_limits_readable<unsigned long>(outfile, "unsigned long");
    write_limits_readable<unsigned long long>(outfile, "unsigned long long");

    // Floating point types
    write_limits_readable<float>(outfile, "float");
    write_limits_readable<double>(outfile, "double");
    write_limits_readable<long double>(outfile, "long double");

    outfile << string(100, '-') << endl;
    outfile.close();
}

void create_csv_table() {
    ofstream outfile("numeric_limits.csv");

    outfile << "type,size,lowest(),min(),max(),digits10" << endl;

    // Integral types
    write_limits_csv<bool>(outfile, "bool");
    write_limits_csv<char>(outfile, "char");
    write_limits_csv<wchar_t>(outfile, "wchar_t");
    write_limits_csv<short>(outfile, "short");
    write_limits_csv<int>(outfile, "int");
    write_limits_csv<long>(outfile, "long");
    write_limits_csv<long long>(outfile, "long long");

    // Unsigned integral types
    write_limits_csv<unsigned char>(outfile, "unsigned char");
    write_limits_csv<unsigned short>(outfile, "unsigned short");
    write_limits_csv<unsigned int>(outfile, "unsigned int");
    write_limits_csv<unsigned long>(outfile, "unsigned long");
    write_limits_csv<unsigned long long>(outfile, "unsigned long long");

    // Floating point types
    write_limits_csv<float>(outfile, "float");
    write_limits_csv<double>(outfile, "double");
    write_limits_csv<long double>(outfile, "long double");
    
    outfile.close();
}

int main() {
    create_readable_table();
    create_csv_table();
    return 0;
}
