#pragma once
#include <vector>
#include "Node.h"

//Returner sekvensen av noder som b;r f;lges. huretic er ponteren til funkjsonen.
std::vector<Node> searchTree(Node startNode, Node endNode, int(*heuretic) (Pair<int>));