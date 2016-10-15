
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<unsigned int> encode(int size, const vector<unsigned int>& a)
{
  //unsigned int* a = new unsigned int[size / 16]; // <- input tab to encrypt
  //unsigned int* b = new unsigned int[size / 16]; // <- output tab

  vector<unsigned int> b(size / 16, 0);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) &
               (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
  }

  return b;
}

vector<unsigned int> decode(int size, const vector<unsigned int>& b) {
    vector<unsigned int> a(b.begin(), a.end());

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < size; j += 1) {
        }
    }

    return a;
}

int main()
{
    int size;
    cin >> size;

    vector<unsigned int> a(size / 16);
    for (int i = 0; i < size / 16; i += 1) {
        cin >> hex >> a[i];
    }

    vector<unsigned int>b = encode(size, a);

    for (int i = 0; i < size / 16; i += 1) {
        if (i > 0) {
            cout << " ";
        }
        cout << setfill('0') << setw(8) << hex << b[i];
    }

    return 0;
}

