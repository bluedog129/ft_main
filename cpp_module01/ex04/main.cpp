/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:57:05 by hyojocho          #+#    #+#             */
/*   Updated: 2023/08/07 15:08:24 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string readFileContent(const std::string& filename) {
    std::ifstream inFile(filename);
	
    if (!inFile) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return "";
    }

    std::string content;
    std::string line;

    while (getline(inFile, line)) {
        content += line + "\n";
    }

    inFile.close();

    return content;
}

std::string replaceString(const std::string& original, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t foundPos = original.find(s1);

    while (foundPos != std::string::npos) {
        result.append(original, pos, foundPos - pos);
        result.append(s2);
        pos = foundPos + s1.length();
        foundPos = original.find(s1, pos);
    }

    result.append(original, pos, original.length() - pos);

    return result;
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::string content = readFileContent(filename);
	
    if (content.empty()) {
        return;
    }

    std::string replacedContent = replaceString(content, s1, s2);
    std::string outFile = filename + ".replace";
	
    std::ofstream outStream(outFile);

    if (!outStream) {
        std::cerr << "Error creating output file: " << outFile << std::endl;
        return;
    }

    outStream << replacedContent;
    outStream.close();

    std::cout << "Replacement complete. New file: " << outFile << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceInFile(filename, s1, s2);

    return 0;
}
