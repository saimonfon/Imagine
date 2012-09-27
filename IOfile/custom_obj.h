#ifndef custom_obj_header
#define custom_obj_header

#include <vector>
#include "../grammaire/parsing/Noeud.h"

class Custom_obj
{
	void write_obj_file_terminaux(const std::string &filename, std::vector<Noeud*> &forest) const;

};


#endif
