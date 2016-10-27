//
// Created by Rafael Kallis on 10.10.16.
//

#include "../task1/pset.h"
#include <unordered_set>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

void write_file(std::string file_name, const std::string content) {
    std::ofstream file_ofs(file_name);
    file_ofs << content;
    file_ofs.close();
}

void capitalise(std::string &word) {
    word[0] = toupper(word[0]);
}

void decapitalise(std::string &word) {
    word[0] = tolower(word[0]);
}

void append_dot(std::string &word) {
    word.push_back('.');
}

void append_whitespace(std::string &word) {
    word.push_back(' ');
}

void check_word(std::string &word,
                std::string &checked_content,
                pset<std::string> &dictionary,
                std::unordered_set<std::string> &ignored_words,
                bool &starts_with_capital,
                bool &has_trailing_dot) {
    bool word_was_replaced = false;

    if (!dictionary.count(word) && !ignored_words.count(word)) {
        std::cout << word << std::endl << "(a)dd, (i)gnore, (r)eplace? ";
        char option;
        std::cin >> option;
        switch (option) {
            case 'a':
                dictionary.insert(word);
                break;
            case 'r':
                std::cout << "Type corrected word: ";
                std::cin >> word;
                std::cout << std::endl;
                check_word(word,
                           checked_content,
                           dictionary,
                           ignored_words,
                           starts_with_capital,
                           has_trailing_dot);
                word_was_replaced = true;
                break;
            case 'i':
                ignored_words.insert(word);
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }

    if (!word_was_replaced) {
        if (starts_with_capital) capitalise(word);
        if (has_trailing_dot) append_dot(word);
        append_whitespace(word);
        checked_content += word;
    }

}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "spell_check <file_name> <dictionary_file>" << std::endl;
        return 1;
    }
    std::string file_name(argv[1]), dictionary_file_name(argv[2]), checked_content;
    pset<std::string> dictionary(dictionary_file_name);
    std::unordered_set<std::string> ignored_words;

    std::ifstream file_ifs(file_name);
    std::string word;
    while (std::getline(file_ifs, word, ' ')) {
        std::regex starts_with_capital_regex("^[A-Z]");
        std::regex has_trailing_dot_regex("\\.$");
        bool starts_with_capital = std::regex_search(word, starts_with_capital_regex);
        bool has_trailing_dot = std::regex_search(word, has_trailing_dot_regex);
        if (starts_with_capital) decapitalise(word);
        if (has_trailing_dot) word.pop_back();
        check_word(word,
                   checked_content,
                   dictionary,
                   ignored_words,
                   starts_with_capital,
                   has_trailing_dot);
    }
    file_ifs.close();
    checked_content.pop_back();

    write_file(file_name + ".corrected", checked_content);

    return 0;
}
