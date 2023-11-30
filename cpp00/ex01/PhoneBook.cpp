#include "PhoneBook.hpp"
#include <iostream>

	//add constructeur
	//add destructeur
void	PhoneBook::welcome() const
{	
	std::string choice ;

	std::cout << "Bonjour, bienvenu dans votre répertoire" << std::endl;
	while (1)
	{
		displayMenu();
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == "1")
			displayList();
		// else if (choice == "2")
		// 	add(); // attention ou 
		// else if (choice == "3")
		// 	remove();// attention ou 
		else if (choice == "x")
		{
			goodBye();
			return ;
		}
		else
			error();
	}
}

void	PhoneBook::displayMenu() const
{	
	std::cout <<"Que souhaitez vous faire ?" << std::endl;
	std::cout <<"	[1] Afficher mes contacts" << std::endl;
	std::cout <<"	[2] Ajouter un nouveau contact" << std::endl;
	std::cout <<"	[3] Supprimer un contact" << std::endl;
	std::cout <<"	[x] Quitter le répertoire" << std::endl;
	std::cout <<"Votre choix : ";
}

int	PhoneBook::goodBye() const
{	
	std::cout <<"See you soon !" << std::endl;
	return (0);
}

void	PhoneBook::error() const
{	
	std::cout <<"Entrée invalide, merci de réitérer votre demande" << std::endl << std::endl;
}

void	PhoneBook::displayOneLong(std::string index) const
{
	Contact contact;
	if (index == "0")
		contact = m_List[0];
	else if (index == "1")
		contact = m_List[1];
	else if (index == "2")
		contact = m_List[2];
	else if (index == "3")
		contact = m_List[3];	
	else if (index == "4")
		contact = m_List[4];
	else if (index == "5")
		contact = m_List[5];
	else if (index == "6")
		contact = m_List[6];
	else if (index == "7")
		contact = m_List[7];
	contact.displayOneLong();
}

void	PhoneBook::displayListMore() const
{
	std::string	choice;

	std::cout << "		Que souhaitez vous faire ?" << std::endl;
	std::cout << "		[n] Afficher le détail du contact" << std::endl;
	std::cout << "		[+] Modifier un contact" << std::endl;
	std::cout << "		[x] Retour au menu principal" << std::endl;
	while (1)
	{
		std::cout << "		Votre choix : ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == "x")
			return ;
		else if (choice == "0" || choice == "1" || choice == "2" || choice == "3"
					|| choice == "4" || choice == "5" || choice == "6" || choice == "7")
		{
			displayOneLong(choice);
			return ;
		}
		else
			std::cout << std::endl << std::endl;
			error();
	}
}

void	PhoneBook::displayList() const
{
	std::string	choice;

	std::cout <<"	Voici la liste de vos contacts" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "	[" << i << "] ";
		m_List[i].displayOneShort();
	}
	std::cout << "	Que souhaitez vous faire ?" << std::endl;
	std::cout << "	[x] Retour au menu principal" << std::endl;
	std::cout << "	[+] Plus d'options" << std::endl;
	while (1)
	{
		std::cout << "	Votre choix : ";
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == "x")
			return ;
		else if (choice == "+")
		{
			displayListMore();
			return ;
		}
		else
		{
			std::cout << std::endl;
			error();
		}
	}
}

void	PhoneBook::display() const
{
	Contact	contact;
	for (int i = 0; i < 8; i++)
	{
		contact = m_List[i];
		contact.displayOneShort();
	}
}

void	PhoneBook::add()
{
	std::string choice;
	std::cout <<"		Votre répertoire est plein. L'ajout d'un contact écrasera le contact [0]" << std::endl;
	std::cout <<"		[x] Annuler" << std::endl;
	std::cout <<"		[v] Continuer" << std::endl;
	std::cout << "	Votre choix : ";
	std::cin >> choice;
	if (choice == "v")
	{
		std::cout <<"		Ajout d'un nouveau contact" << std::endl;
		Contact contact;
		m_List[0] = contact;
	}
}

void	PhoneBook::remove(std::string choice = NULL)
{	
	std::cout <<"		Suppression d'un contact" << std::endl;
}
