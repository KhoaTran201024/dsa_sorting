#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int main() {
  const int array_size = 1000000;
  double ascending_array[array_size];
  double descending_array[array_size];
  double random_arrays[8][array_size];

  // Fill the arrays with random numbers
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<double> dist(0.0, 100.0);

  for (int i = 0; i < array_size; i++) {
    ascending_array[i] = dist(gen);
    descending_array[i] = ascending_array[i];

    for (int j = 0; j < 8; j++) {
      random_arrays[j][i] = ascending_array[i];
    }
  }

  // Sort the first array in ascending order
  sort(ascending_array, ascending_array + array_size);

  // Sort the second array in descending order
  sort(descending_array, descending_array + array_size, greater<double>());

  // Shuffle the other eight arrays randomly
  for (int i = 0; i < 8; i++) {
    shuffle(random_arrays[i], random_arrays[i] + array_size, gen);
  }

  // Write each array to a separate file
  for (int i = 1; i <= 10; i++) {
    string filename = "test" + to_string(i) + ".txt";
    FILE* fp = freopen(filename.c_str(), "w", stdout);
    double* array_to_write = nullptr;

    switch (i) {
      case 1:
        array_to_write = ascending_array;
        break;
      case 2:
        array_to_write = descending_array;
        break;
      case 3:
        array_to_write = random_arrays[0];
        break;
      case 4:
        array_to_write = random_arrays[1];
        break;
      case 5:
        array_to_write = random_arrays[2];
        break;
      case 6:
        array_to_write = random_arrays[3];
        break;
      case 7:
        array_to_write = random_arrays[4];
        break;
      case 8:
        array_to_write = random_arrays[5];
        break;
      case 9:
        array_to_write = random_arrays[6];
        break;
      case 10:
        array_to_write = random_arrays[7];
        break;
    }

    for (int j = 0; j < array_size; j++) {
      cout << array_to_write[j] << " ";
    }

    fclose(fp);
  }

  return 0;
}