#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <utility>

class Company {
public:
    Company();

    Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

    int getId() const;

    std::string getName() const;

    std::vector<std::pair<char, char> > getEmployees() const;

    std::string getInfo() const;

    std::ostream& operator<<(std::ostream& stream, const Company& c);
};

#endif // !COMPANY_H
