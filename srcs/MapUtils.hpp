// #ifndef MAPUTILS_HPP
// # define MAPUTILS_HPP

// /* Colors */
// # define CRESET   "\033[0m"
// # define CRED     "\033[31m"
// # define CGREEN   "\033[32m"
// # define CYELLOW  "\033[33m"
// # define CBLUE    "\033[34m"


	// void	print_node(std::string root_path)
	// {
	// 	node_pointer tmp = _root;
	// 	std::cout << ".";
	// 	for (int i = 0; root_path[i]; ++i){
	// 		if (root_path[i] == 'L'){
	// 			if (tmp->_left == NULL)
	// 				return ;
	// 			tmp = tmp->_left;
	// 		}
	// 		if (root_path[i] == 'R'){
	// 			if (tmp->_right == NULL)
	// 				return ;
	// 			tmp = tmp->_right;
	// 		}
	// 	}
	// 	if (tmp->_data.first){
	// 			std::cout << CYELLOW << tmp->_data.first << CRESET;
	// 	}
	// }

	// 				void	print_tree()
	// {
	// 		std::string root_path;
	// 		int layer = 0;
	// 		root_path = "";
	// 		int starting_tabs = 16;
	// 		int starting_gap = 16;
	// 		while (layer < 5)
	// 		{
	// 			root_path.clear();
	// 			int tmp_tabs = starting_tabs;
	// 			int tmp_gap = starting_gap;
	// 			for (int tmp_layer = layer; tmp_layer; --tmp_layer)
	// 			{
	// 				root_path.append("L");
	// 				tmp_gap = tmp_gap / 2;
	// 				tmp_tabs -= tmp_gap;
	// 			}
	// 			while (root_path.find('L') != std::string::npos){
	// 				if (root_path.find('R') == std::string::npos)
	// 					for (; tmp_tabs; --tmp_tabs)
	// 						std::cout << "   ";
	// 				else
	// 					for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
	// 						std::cout << "   ";
	// 				if (_root)
	// 					print_node(root_path);
	// 				size_t L_found = root_path.find_last_of('L');
	// 				root_path[L_found] = 'R';
	// 				++L_found;
	// 				for (;L_found != root_path.size(); ++L_found){
	// 					root_path[L_found] = 'L';
	// 				}
	// 			}
	// 			if (root_path.find('R') == std::string::npos)
	// 				for (; tmp_tabs; --tmp_tabs)
	// 					std::cout << "   ";
	// 			else
	// 				for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
	// 					std::cout << "   ";
	// 			if (_root)
	// 				print_node(root_path);
	// 			std::cout << std::endl << std::endl << std::endl;
	// 			layer++;
	// 		}
	// }
#endif
