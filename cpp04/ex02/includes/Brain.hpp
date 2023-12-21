#ifndef DEF_BRAIN
#define DEF_BRAIN

#include <iostream>

#define IDEASSIZE 100

class Brain
{
	public:
		Brain();
		Brain(Brain const & src);
		virtual ~Brain();

		Brain & operator=(Brain const & rhs);
		std::string const& getIdea(const int id) const;
		void setIdea(const int id, const std::string& idea);

	private:
		std::string _ideas[IDEASSIZE];
};

#endif
