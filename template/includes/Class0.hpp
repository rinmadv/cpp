#ifndef DEF_CLASS0
#define DEF_CLASS0

#include <iostream>

class Class0
{
	public:
		Class0();
		Class0(std::string type);
		Class0(Class0 const & src);
		virtual ~Class0();

		Class0 & operator=(Class0 const & rhs);

		std::string const & getType() const;
		void setType(const std::string& type);

	private:
		std::string _type;
};

#endif
