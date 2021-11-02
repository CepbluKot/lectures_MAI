#include <iostream>
#include "hashs_task2.h"
#include <fstream>
#include <streambuf>
#include <algorithm>

std::string getFileIntoStr(std::string fileName)
{
    std::ifstream t(fileName);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    std::string normString;
    for (int i = 0; i < str.size(); i++)
    {
        normString += str[i];
    }
    t.close();
    if (normString[0] == ' ')
    {
        int i = 0;
        while (normString[i] == ' ')
            i++;
        for (int n = 0; n <= i; n++)
            normString.erase(0, i);
    }
    if (normString[normString.size() - 1] == ' ')
    {
        while (normString.rfind(' ') == normString.size() - 1)
            normString.pop_back();
    }
    return normString;
}

int wordsCount(std::string smth)
{

    int i = 0;
    int cnt = 0;
    while (i < smth.size())
    {
        if (i != smth.find(' ', i + 1))
        {
            cnt++;
            i = smth.find(' ', i + 1);
        }
        else
            break;
    }
    return cnt;
}

void wordsToList(std::string fullText, hashTable<std::string> *table)
{
    int wordsLeft = wordsCount(fullText);
    int currPos = 0;
    std::string wort;

    while (wordsLeft != 1)
    {
        for (int i = 0; i < fullText.find(' ', currPos); i++)
            wort += (fullText[i]);
        fullText.erase(currPos, fullText.find(' ', currPos) + 1);
        table->add(wort);
        wort = "";
        wordsLeft--;
    }
    for (int i = 0; i < fullText.size(); i++)
        wort += (fullText[i]);
    table->add(wort);
}

void printResult(hashTable<std::string> *table)
{
    for (int i = 0; i < table->getLen(); i++)
    {
        std::cout << "\n"
                  << i << " ";
        table->printIndex(i);
    }
    std::cout << std::endl;
}

void findAndReplaceAll(std::string &data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while (pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}

std::string makePerfectString(std::string fullText)
{
    std::string separators[7] = {".", ",", ";", ":", "\t", "\"", "\n"};
    for (int i = 0; i < 7; i++)
    {
        findAndReplaceAll(fullText, separators[i], " ");
    }
    while (fullText.find("  ") != std::string::npos)
        findAndReplaceAll(fullText, "  ", " ");
    return fullText;
}

int main(int argc, char **argv)
{
    std::string fileName = argv[1];

    std::string fullText = getFileIntoStr("text.txt");
    fullText = makePerfectString(fullText);

    hashTable<std::string> *table = new hashTable<std::string>(wordsCount(fullText));
    wordsToList(fullText, table);
    printResult(table);
}