#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <utility>
#include <sstream>

struct HasInfo {
	virtual std::string getInfo() const = 0;
};

struct HasId {
	virtual int getId() const = 0;
};

class Company : public HasInfo, public HasId {
	int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;
public:
    Company();

    Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

    int getId() const;

    std::string getName() const;

    std::vector<std::pair<char, char> > getEmployees() const;

    std::string getInfo() const;

	friend std::ostream& operator<<(std::ostream& stream, const Company& c);

	friend std::istream& operator>>(std::istream& stream, Company& c);
};

#endif // !COMPANY_H
