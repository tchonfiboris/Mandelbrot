#include <iostream>
#include <vector>

const int largeur = 100;
const int hauteur = 100;
const int iteration_max = 50;

// calcul le nombre d'itération pour un point donné
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

	// stocker le nombre d'itération dans un tableau
	std::vector <std::vector <int>> mandelbrotSet(hauteur, std::vector <int>(largeur));

	// suite de Mandelbrot
	for (int x = 0; x < largeur; x++) {
		for (int y = 0; y < hauteur; y++) {
			double reel = (x - largeur / 2.0f) * 4.0f / largeur;
			double imaginaire = (y - hauteur / 2.0f) * 4.0f / hauteur;

			mandelbrotSet[x] [y] = mandelbrot(reel, imaginaire);
		}
	}

	// affichenle résultat
	for (int y = 0; y < hauteur; y++) {
		for (int x = 0; x < largeur; x++) {
			std::cout << mandelbrotSet[y][x] << "";
		}

		std::cout << std::endl;
	}

	return 0;
}
