#include <iostream>
#include <vector>

const int width = 100;
const int heigth = 100;
const int iteration_max = 50;

int mandelbrot(double reel, double imaginaire) {
	double z_reel = 0;
	double z_imaginaire = 0;
	int iterations = 0;

	while (z_reel * z_reel + z_imaginaire * z_imaginaire < 4 && iterations < iteration_max) {
		double temp_reel = z_reel * z_reel - z_imaginaire * z_imaginaire + reel;
		z_imaginaire = 2 * z_reel * z_imaginaire + imaginaire;
		z_reel = temp_reel;
		iterations++;
	}
	return iterations;
}

int main() {

	std::vector <std::vector <int>> mandelbrotSet(heigth, std::vector <int>(width));

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < heigth; y++) {
			double reel = (x - width / 2.0f) * 4.0f / width;
			double imaginaire = (y - heigth / 2.0f) * 4.0f / heigth;

			mandelbrotSet[x] [y] = mandelbrot(reel, imaginaire);
		}
	}

	for (int y = 0; y < heigth; y++) {
		for (int x = 0; x < width; x++) {
			std::cout << mandelbrotSet[y][x] << "";
		}

		std::cout << std::endl;
	}

	return 0;
}
