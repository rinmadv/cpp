#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << argv[0] << " [infile] [string1] [string2]" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	std::string s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "Error : s1 cannot be empty" << std::endl;
		return (1);
	}
	std::string s2 = argv[3];
	if (!infile.is_open())
	{
		std::cerr << "Error : cannot open file/does not exists" << std::endl;
		return (1);
	}
	std::string outfileName = argv[1] + (std::string)".replace";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error : cannot open or create " << outfileName << std::endl;
		infile.close();
		return (1);
	}
	std::string buffer;
	size_t pos;
	std::string copy;
	size_t len_s1 = s1.size();
	if (s1 == s2)
	{
		while (getline(infile, buffer))
			outfile << buffer << std::endl;
	}
	else
	{
		while (getline(infile, buffer))
		{
			pos = buffer.find(s1);
			while (pos != std::string::npos)
			{
				buffer.erase(pos, len_s1);
				buffer.insert(pos, s2);
				pos = buffer.find(s1, pos + s2.length());
			}
			outfile << buffer << std::endl;
		}
	}
	infile.close();
	outfile.close();
	return (0);
}
