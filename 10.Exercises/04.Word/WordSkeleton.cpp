//#include <iostream>
//#include <string>
//#include <sstream>
//
//#include "Initialization.h"
//#include "CommandInterface.h"
//
//int main() {
//    std::string text;
//    std::getline(std::cin, text);
//
//    std::shared_ptr<CommandInterface> interface = buildCommandInterface(text);
//
//    std::string inputLine;
//    std::getline(std::cin, inputLine);
//    while(inputLine != "exit") {
//        interface->handleInput(inputLine);
//        std::getline(std::cin, inputLine);
//    }
//
//    std::cout << text << std::endl;
//
//    return 0;
//}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


int main() {
    int htmlLines, queriesCount;
    cin >> htmlLines >> queriesCount;
    ostringstream ss;

    string str;
    getline(cin, str);
    for (size_t i = 0; i < htmlLines; i++) {
        getline(cin, str);
        ss << str;
    }

    string html = ss.str();
    string query;

    for (size_t i = 0; i < queriesCount; i++) {
        getline(cin, query);

        int indexOfTilda = query.find('~');
        string attrName = query.substr(indexOfTilda + 1);
        string path = query.substr(0, indexOfTilda);

        std::stringstream pathIn(path);
        std::string segment;
        vector<string> pathElements;

        while (std::getline(pathIn, segment, '.'))
        {
            pathElements.push_back(segment);
        }

        string searchedTag = pathElements[pathElements.size() - 1];

        int indexOfSearchedTag = html.find(searchedTag);

        int indexOfAttribute = html.find(attrName, indexOfSearchedTag);
        int indexOfClosingBracket = html.find('>', indexOfSearchedTag);

        if (indexOfAttribute > indexOfClosingBracket) {
            cout << "Not Found!" << endl;
        }
        else {
            int indexOfAttributeValue = indexOfAttribute + attrName.size() + 4;
            int indexOfClosingQuote = html.find('\"', indexOfAttributeValue);
            cout << html.substr(indexOfAttributeValue, indexOfClosingQuote - indexOfAttributeValue) << endl;
        }
    }

    return 0;
}