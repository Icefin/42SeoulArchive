/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:31:14 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/06 01:52:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 4)
	{
        std::cout << "Usage: ./replace <filename> <string1> <string2>\n";
        return 1;
    }

    std::string inFileName = argv[1];
	std::string outFileName = inFileName + ".replace";
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inFile(inFileName);
    if (!inFile.is_open())
	{
        std::cout << "Unable to open file: " << inFileName << std::endl;
        return 1;
    }

    std::string line;
    std::ofstream outFile(outFileName);

    while (std::getline(inFile, line))
	{
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();

    std::cout << "Replacement completed. Output written to '" << outFileName << "'" << std::endl;
    return 0;
}