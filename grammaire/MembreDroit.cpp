#include "MembreDroit.h"
#include "Parser.h"
#include "Regle.h"

void MembreDroit::init (Regle* parent, int position)
{
this->parent = parent;
this->position = position;
}