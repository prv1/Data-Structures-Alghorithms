#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iterator>

using namespace std;

// TODO You will want to do this later
void print_AdjacencyList(vector< list<int> >& adjacencylist ) {

	ostream_iterator<int> out(cout, ", ");
	vector< list<int> >::iterator adjacencylistIterator = adjacencylist.begin();

	for (adjacencylistIterator = adjacencylist.begin(); 
		 adjacencylistIterator != adjacencylist.end(); 
		 ++adjacencylistIterator) {

		copy(adjacencylistIterator->begin(), adjacencylistIterator->end(), out);
		cout << endl;
	}
	
	
}



/**
 * graph data from the book. SSD5 5.1.2 Fundamential Graph Algorithms
 */
void buildAdacencyList1(vector< list<int> >& adjacencyList) {

	adjacencyList[0].push_back(2);
    adjacencyList[0].push_back(1);

    adjacencyList[1].push_back(0);
    adjacencyList[1].push_back(2);

    adjacencyList[2].push_back(4);
    adjacencyList[2].push_back(3);
    adjacencyList[2].push_back(0);
    adjacencyList[2].push_back(1);

    adjacencyList[3].push_back(2);
    adjacencyList[3].push_back(4);
    adjacencyList[3].push_back(5);

    adjacencyList[4].push_back(6);
    adjacencyList[4].push_back(5);
    adjacencyList[4].push_back(3);
    adjacencyList[4].push_back(2);


    adjacencyList[5].push_back(4);
    adjacencyList[5].push_back(3);

    adjacencyList[6].push_back(4);
}


// very large and ugly hard coded list :-(
void buildAdacencyList2(vector< list<int> >& adjacencyList) {

	adjacencyList[1].push_back(26);

	adjacencyList[26].push_back(1);
	adjacencyList[26].push_back(51);

    adjacencyList[51].push_back(26);
    adjacencyList[51].push_back(52);

    adjacencyList[52].push_back(51);
    adjacencyList[52].push_back(53);

    adjacencyList[53].push_back(52);
    adjacencyList[53].push_back(54);

    adjacencyList[54].push_back(53);
    adjacencyList[54].push_back(79);

    adjacencyList[79].push_back(54);
    adjacencyList[79].push_back(104);

	adjacencyList[104].push_back(79);
    adjacencyList[104].push_back(129);

    adjacencyList[127].push_back(128);
    adjacencyList[127].push_back(152);

	adjacencyList[128].push_back(127);
    adjacencyList[128].push_back(129);

    adjacencyList[129].push_back(104);
    adjacencyList[129].push_back(128);

	adjacencyList[152].push_back(127);
    adjacencyList[152].push_back(177);

    adjacencyList[177].push_back(152);
    adjacencyList[177].push_back(178);

	adjacencyList[178].push_back(177);
    adjacencyList[178].push_back(179);

    adjacencyList[179].push_back(178);
    adjacencyList[179].push_back(180);

	adjacencyList[180].push_back(179);
    adjacencyList[180].push_back(181);

    adjacencyList[181].push_back(180);
    adjacencyList[181].push_back(182);

	adjacencyList[182].push_back(181);
    adjacencyList[182].push_back(183);

    adjacencyList[183].push_back(182);
    adjacencyList[183].push_back(184);

	adjacencyList[184].push_back(183);
    adjacencyList[184].push_back(185);

    adjacencyList[185].push_back(184);
    adjacencyList[185].push_back(186);

	adjacencyList[186].push_back(185);
    adjacencyList[186].push_back(211);

    adjacencyList[211].push_back(186);
    adjacencyList[211].push_back(236);

	adjacencyList[236].push_back(211);
    adjacencyList[236].push_back(261);

    adjacencyList[261].push_back(236);
    adjacencyList[261].push_back(286);

	adjacencyList[286].push_back(261);
    adjacencyList[286].push_back(311);

    adjacencyList[289].push_back(290);
    adjacencyList[289].push_back(314);

	adjacencyList[290].push_back(289);
    adjacencyList[290].push_back(291);

    adjacencyList[291].push_back(290);
    adjacencyList[291].push_back(292);

	adjacencyList[292].push_back(291);
    adjacencyList[292].push_back(293);

    adjacencyList[293].push_back(292);
    adjacencyList[293].push_back(294);

	adjacencyList[294].push_back(293);
    adjacencyList[294].push_back(319);

    adjacencyList[311].push_back(286);
    adjacencyList[311].push_back(336);

	adjacencyList[314].push_back(289);
    adjacencyList[314].push_back(339);

    adjacencyList[319].push_back(294);
    adjacencyList[319].push_back(344);

	adjacencyList[336].push_back(311);
    adjacencyList[336].push_back(361);

    adjacencyList[339].push_back(314);
    adjacencyList[339].push_back(364);

	adjacencyList[344].push_back(319);
    adjacencyList[344].push_back(369);

    adjacencyList[361].push_back(336);
    adjacencyList[361].push_back(386);

	adjacencyList[364].push_back(339);
    adjacencyList[364].push_back(389);

    adjacencyList[369].push_back(344);
    adjacencyList[369].push_back(394);

	adjacencyList[386].push_back(361);
    adjacencyList[386].push_back(411);

    adjacencyList[389].push_back(364);
    adjacencyList[389].push_back(414);

	adjacencyList[394].push_back(369);
    adjacencyList[394].push_back(419);

    adjacencyList[411].push_back(386);
    adjacencyList[411].push_back(436);

    adjacencyList[414].push_back(389);
    adjacencyList[414].push_back(439);

	adjacencyList[419].push_back(394);
    adjacencyList[419].push_back(444);

    adjacencyList[436].push_back(411);
    adjacencyList[436].push_back(461);

	adjacencyList[439].push_back(414);
    adjacencyList[439].push_back(464);

    adjacencyList[444].push_back(419);
    adjacencyList[444].push_back(469);

    adjacencyList[461].push_back(436);
    adjacencyList[461].push_back(486);

	adjacencyList[464].push_back(439);
    adjacencyList[464].push_back(489);

    adjacencyList[467].push_back(468);
    adjacencyList[467].push_back(492);

	adjacencyList[468].push_back(467);
    adjacencyList[468].push_back(469);

    adjacencyList[469].push_back(444);
    adjacencyList[469].push_back(468);

    adjacencyList[486].push_back(461);
    adjacencyList[486].push_back(511);

	adjacencyList[489].push_back(464);
    adjacencyList[489].push_back(514);

    adjacencyList[492].push_back(467);
    adjacencyList[492].push_back(517);

	adjacencyList[511].push_back(486);
    adjacencyList[511].push_back(536);

    adjacencyList[514].push_back(489);
    adjacencyList[514].push_back(539);

    adjacencyList[517].push_back(492);
    adjacencyList[517].push_back(542);

	adjacencyList[536].push_back(511);
    adjacencyList[536].push_back(537);

    adjacencyList[537].push_back(536);
    adjacencyList[537].push_back(538);

	adjacencyList[538].push_back(537);
    adjacencyList[538].push_back(539);

    adjacencyList[539].push_back(538);
    adjacencyList[539].push_back(514);

    adjacencyList[542].push_back(517);
    adjacencyList[542].push_back(567);

	adjacencyList[567].push_back(542);
    adjacencyList[567].push_back(592);

    adjacencyList[592].push_back(567);
    adjacencyList[592].push_back(617);

	adjacencyList[617].push_back(592);
    adjacencyList[617].push_back(618);

    adjacencyList[618].push_back(617);
    adjacencyList[618].push_back(619);

    adjacencyList[619].push_back(618);
    adjacencyList[619].push_back(620);

	adjacencyList[620].push_back(619);
    adjacencyList[620].push_back(621);

    adjacencyList[621].push_back(620);
    adjacencyList[621].push_back(646);

	adjacencyList[646].push_back(621);
    adjacencyList[646].push_back(671);

    adjacencyList[671].push_back(646);
    adjacencyList[671].push_back(696);

    adjacencyList[696].push_back(671);
    adjacencyList[696].push_back(721);

	adjacencyList[721].push_back(696);
    adjacencyList[721].push_back(746);

    adjacencyList[746].push_back(721);

  

}




/**
 * A breadth-first search is an algorithm that explores the nodes in a graph
 * in order of increasing distance from the starting node. A breadth-first 
 * search can be used to answer questions about reachability. In other words 
 * we can perform a breadth-first search to determine which nodes can be reached
 * from a starting node. This is an important application since graphs can 
 * contain nodes that are disconnected from other nodes.
 *
 */
void bfs(vector< list<int> >& adjacencyList, int start_node) {

    queue<int> not_yet_explored;
    set<int> discovered;

    // Mark the start node as being discovered,
    // and place it in the queue of nodes to explore
    not_yet_explored.push(start_node);
    discovered.insert(start_node);

    while (! not_yet_explored.empty()) {

        // Get a node to explore.
        int node_to_explore = not_yet_explored.front();
        not_yet_explored.pop();

        // Examine all the edges of that node
        list<int>::iterator edges = adjacencyList[node_to_explore].begin();
        for ( ; edges != adjacencyList[node_to_explore].end(); edges++) {

            // See if the edge leads to a node that we
            // have not yet discovered
            if (discovered.count(*edges) == 0) {

                // We have discovered a new node!
                // Add this node to the queue of nodes
                // to explore.
                discovered.insert(*edges);
                not_yet_explored.push(*edges);

				// debug output statement
                cout << "Found " << *edges << " from " << node_to_explore << endl;

            }
        }
    }

}





/**
 * A depth-first search implementation differs from a breadth-first search implementation 
 * only in the container used to store unexplored nodes. In a breadth-first search, we 
 * explore nodes in the order that they are discovered. Thus, a queue is used to maintain 
 * the discovered but not explored nodes. A depth-first search algorithm always explores 
 * the most recently discovered node. To facilitate this, a stack is used instead of a 
 * queue to store the unexplored nodes. In all actuality, though, we can leverage the 
 * fact that the run-time system maintains function calls in a stack, and code the routine 
 * recursively. This altogether eliminates the need to use a container to store unexplored nodes.
 */
void dfs_helper(vector< list<int> >& adjacencyList, set<int>& discovered, int node) {

    // Examine all the edges of the node
    list<int>::iterator edges = adjacencyList[node].begin();
    for ( ; edges != adjacencyList[node].end(); edges++) {

        // See if the edge leads to a node that we
        // have not yet discovered
        if (discovered.count(*edges) == 0) {

            // We have discovered a new node!
            // Add this node to the queue of nodes
            // to explore.
            discovered.insert(*edges);
            cout << "Found " << *edges <<
            " from " << node << endl;
            dfs_helper(adjacencyList, discovered, *edges);
        }
    }
}




void dfs(vector< list<int> >& adjacencyList, int start_node) {

    // Mark the start node as being discovered
    set<int> discovered;
    discovered.insert(start_node);
    dfs_helper(adjacencyList, discovered, start_node);
}


int main(int argc, char* argv[]) {

	vector< list<int> > adjacencyList(10, list<int>());

	buildAdacencyList1(adjacencyList);

	print_AdjacencyList(adjacencyList);
	system("pause");

    cout << "Breadth-first search\n";
    bfs(adjacencyList, 0);

   // cout << "\nDepth-first search\n";
   // dfs(adjacencyList, 0);

	system("pause");

    return EXIT_SUCCESS;
}

/*
		Breadth-first search
		Found 2 from 0
		Found 1 from 0
		Found 4 from 2
		Found 3 from 2
		Found 6 from 4
		Found 5 from 4

		Depth-first search
		Found 2 from 0
		Found 4 from 2
		Found 6 from 4
		Found 5 from 4
		Found 3 from 5
		Found 1 from 2
		Press any key to continue . . .

*/
