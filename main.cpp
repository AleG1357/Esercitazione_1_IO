#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <numbers>
#include <iomanip>





// Funzione che mappa il valore da [1,5] a [-1,2]
double mappa_valore(double valore) {
    return -1.0 + (valore - 1.0) * (3.0 / 4.0);
}

// Funzione che calcola la media progressiva
std::vector<double> calcola_media_progressiva(const std::vector<double>& valori) 
{
    std::vector<double> medie;
    double somma = 0.0;

    for (size_t i = 0; i < valori.size(); i++)
	  {
        somma += mappa_valore(valori[i]);
        medie.push_back(somma / (i + 1));
    }

    return medie;
}

// Funzione che scrive il risultato nel file
void scrivi_su_file(const std::vector<double>& medie, const std::string& nome_file) {
    std::ofstream file(nome_file);
    if (!file) 
	{
        std::cerr << "Errore nell'apertura di " << nome_file << std::endl;
        return;
    }

    file << "# N Mean\n";
	file << std::scientific << std::setprecision(16); // Lo faccio per aggiustare il formato
    for (size_t i = 0; i < medie.size(); i++) 
	{
        file << i + 1 << " " << medie[i] << "\n";
    }
    file.close();
}



//Check 1per commento (prova per vedere push)


int main() {
    std::ifstream file("data.txt");
    if (!file) {
        std::cerr << "Errore: impossibile aprire data.txt" << std::endl;
        return 1;
    }

    std::vector<double> valori;
    double numero;
    while (file >> numero) {
        valori.push_back(numero);
    }
    file.close();

    std::vector<double> medie = calcola_media_progressiva(valori);
    scrivi_su_file(medie, "result.txt");

    std::cout << "Operazione completata. File 'result.txt' generato.\n";
    return 0;
}

