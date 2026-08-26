#include <iostream>
#include <vector>


using namespace std;

int main() {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t num_count, bin_count;
    double max, min;

    cerr << "Enter value of numbers: ";
    cin >> num_count;
    
    vector<double> numbers(num_count);
    //numbers.resize(num_count);

    cerr << "\nEnter numbers in vector: \n";
    for (size_t i = 0; i < num_count; i++) {cin >> numbers[i];}

    max = numbers[0];
    min = numbers[0];
    for (double x : numbers) {
        if (x < min) {min = x;}
        else if (x > max) {max = x;}
    }

    cerr << "Enter value of bins: ";
    cin >> bin_count;

    vector<double> bins(bin_count);

    double bin_size = (max - min)/bin_count;

    for (size_t i = 0; i < num_count; i++) {
    bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {bins[bin_count - 1]++;}
    }

    double max_star = bins[0];
    for (size_t i = 1; i < bin_count; i++) {
        if (bins[i] > max_star) {max_star = bins[i];}
    }
    
    for (size_t i = 0; i < bin_count; i++) {
        for (size_t j = 0; j < max_star - bins[i]; j++) {
            cout << " ";
        }
        if (max_star > 76) {
            size_t height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_star);
            for (size_t j = 0; j < height; j++) {
                cout << "*";
            }
        }
        else {
            for (size_t j = 0; j < bins[i]; j++) {
                cout << "*";
            }
        }
        cout << "|";
        if (bins[i] < 10) {cout << "  ";}
        else if (bins[i] < 100) {cout << " ";}
        else {cout << " ";}
        cout << bins[i] << endl;
    }
    
    return 0;
}