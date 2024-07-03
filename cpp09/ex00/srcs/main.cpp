#include "../includes/Format.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>
#include <climits>

int displayError(std::string str)
{
	std::cerr << _BOLD _RED << "⚠️ Error: " << str << " ⚠️" << _END << std::endl;
	return (1);
}

std::pair<std::string, std::string> split(const std::string& str, char delimiter) {
	
	std::vector<std::string> result;
	std::istringstream iss(str);
	std::string item;

	while (std::getline(iss, item, delimiter)) {
		result.push_back(item);
	}

	// Vérifier s'il y a plus de trois éléments
	if (result.size() > 3) {
		throw std::runtime_error("La chaîne contient plus de trois éléments après la division.");
	}

	// Initialiser les éléments de la paire avec des chaînes vides
	std::pair<std::string, std::string> pair("", "");

	// Assigner les valeurs à la paire selon le nombre d'éléments
	if (result.size() > 0) {
		pair.first = result[0];
	}
	if (result.size() > 1) {
		pair.second = result[1];
	}
	return pair;
}

int dateToInt(const std::string& dateStr)
{
    int year, month, day;
    char delimiter1, delimiter2;

    std::istringstream iss(dateStr);
    if (!(iss >> year >> delimiter1 >> month >> delimiter2 >> day) || delimiter1 != '-' || delimiter2 != '-' || iss.fail()) {
        throw std::runtime_error("Error : Invalid date format");
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::runtime_error("Error : Invalid date");
    }

    // Combiner année, mois et jour en un seul entier
    return year * 10000 + month * 100 + day;
}

// attention ils doivent être positifs
double stringToDouble(const std::string& str, double limit) // normalement c'est des float
{
	std::istringstream iss(str);
	double value;
	iss >> value;

	// Vérifiez s'il y a des caractères résiduels dans la chaîne après la conversion
	if (iss.fail() || !iss.eof() ) {
		throw std::runtime_error("Error: bad value (" + str + ")");
	}
	if (value > limit)
		throw std::runtime_error("Error: too large a number.");
			if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	return value;
}
	int main(int argc, char **argv)
	{
	if (argc != 2)
		return (displayError("./btc [inputName.csv]"));

	//handle csv database (source)
		std::ifstream database("data.csv");
		if (!database.is_open())
			return(displayError("cannot open database/database does not exists"));
		std::string buffer;

		std::map<int, double> dictionnary;//attention aux negatifs ? + attention aux doubles
		int i = 0;
		while (getline(database, buffer)) //attention si bdd vide ou bien plusieurs \n
		{
			if (i > 0)
			{
				std::pair<std::string, std::string> pair;
				try
				{
					pair = split(buffer, ',');
					int date = dateToInt(pair.first);
					double rate = stringToDouble(pair.second, INT_MAX); // gerer les exceptions
					dictionnary[date] = rate; // penser à gerer les doublons
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				// check pair
			}
			i++;
		}
		// std::map<int, double>::iterator it;
		// for (it = dictionnary.begin(); it != dictionnary.end(); ++it) {
		// 	std::cout << "Clé: " << it->first << ", Valeur: " << std::fixed << std::setprecision(2) << it->second << std::endl;
		// }
		(void) argv;

	// handle txt input (input)
		std::ifstream input(argv[1]);
		if (!input.is_open())
			return(displayError("cannot open input/input does not exists"));
		buffer.erase();
		i = 0;
		while (getline(input, buffer)) //attention si bdd vide ou bien plusieurs \n
		{
			if (i > 0)
			{
				std::pair<std::string, std::string> pair;
				try
				{
					pair = split(buffer, '|');
					int date = dateToInt(pair.first);
					int inputVal = stringToDouble(pair.second, 1000); // gerer les exceptions
					double convertVal;
					std::map<int, double>::iterator it = dictionnary.upper_bound(date);
					if (it != dictionnary.begin()) {
						--it; // Déplacer vers l'élément précédent //add si date inférieur à date de debut !
						convertVal = it->second;
						std::cout << pair.first << "=> " << pair.second << " = " << inputVal * convertVal << std::endl; 
					} else {
						throw std::runtime_error("No value found (date inferior to the first data base date)");;
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			i++;
		}

	}