/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:05:35 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/23 14:21:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		int idx = 0;
		while (argv[i][idx] != '\0') {
			argv[i][idx] = std::toupper(argv[i][idx]);
			idx++;
		}
		std::cout << argv[i];	
	}
	std::cout << std::endl;
	return 0;
}