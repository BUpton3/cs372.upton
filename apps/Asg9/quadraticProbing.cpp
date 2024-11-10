// used for help: https://www.geeksforgeeks.org/quadratic-probing-in-hashing/
#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int nextPowerOf2(int m)
{
    m--;
    m |= m >> 1;
    m |= m >> 2;
    m |= m >> 4;
    m |= m >> 8;
    m |= m >> 16;
    m |= m >> 32;
    m++;
    return m;
}
void hashing(int table[], int tsize, int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int hv = arr[i] % tsize;
        if (table[hv] == -1)
            table[hv] = arr[i];
        else {
            int m = nextPowerOf2(tsize);
            for (int j = 1; j <= m; j++) {
                int t = (hv + (j + j * j) / 2) % m;
                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
                if (t >= tsize)
                    continue;
            }
        }
    }
    printArray(table, tsize);
}


int main()
{
    int arr[] = { 21, 10, 32, 43, 54, 65, 87, 76 };
    int n = 8;
    const int tsize = 11;
    int hash_table[tsize];
    for (int i = 0; i < tsize; i++) {
        hash_table[i] = -1;
    }
    hashing(hash_table, tsize, arr, n);
    return 0;
}
