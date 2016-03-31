/**
 * ECE408 
 * net.cpp
 * Purpose: Network Simulator Object
 * 
 * @author Kangqiao Lei
 * @version 0.1 03/28/16
 */

#include <iostream>

net::net(){

}

// If used returns true
bool net::usedID(std::string id){
	auto result = std::find(std::begin(ids), std::end(ids), id);
	return result != std::end(ids));
}

float net::setEnd(float stop) {
	endtime = stop;
	return endtime;
}

int net::addHost(std::string id){
	if (!usedID(id)) {
		// Create a new host object
		hosts[id] = host(id);

		// Update dictionaries
		ids.push_back(id);
		nodes.push_back(hosts[id]);
		
		// TODO: Create initial events
		
		return 0;
	} else {
		cerr << "Failed to create Host with id " << id << ". ID already exists." << endl;
		return -1;
	}
	
}

int net::addRouter(std::string id){
	if (!usedID(id)) {
		// Create a new router object
		routers[id] = router(id);

		// Update dictionaries
		ids.push_back(id);
		nodes.push_back(routers[id]);
		
		// TODO: Create initial events
		
		return 0;
	} else {
		cerr << "Failed to create Router with id " << id << ". ID already exists." << endl;
		return -1;
	}
	
}

//http://codereview.stackexchange.com/questions/59997/contains-algorithm-for-stdvector Create contains and overload 
//http://stackoverflow.com/questions/6939129/how-to-use-stdfind-stdfind-if-with-a-vector-of-custom-class-objects
//http://stackoverflow.com/questions/30406408/stdfind-on-vector-of-objects-with-overloaded-operator
//http://stackoverflow.com/questions/19187766/find-using-overloaded-operator
int net::addLink(std::string id, std::string node_id1, std::string node_id2, float rate, float delay, float buffer){
	// Check if there exists a link with this id already
	if (!usedID(id)) {
		// Check if both IDs are valid nodes
		
		// if in nodes, then continue, else cerr
		
		// Get the nodes
		n1 = nodes[node_id1];
		n2 = nodes[node_id2];
		
		links[id] = Link(id, n1, n2, rate, delay, buffer);
		
		// Update dictionaries
		n1.addLink(links[id]);
		n2.addLink(links[id]);
		ids.push_back(id);
		
		// TODO: Create initial events
		// Initialization of routing tables
		// Refresh router tables
		return 0;
	} else {
		// TODO: Refactor to allow multiple names? using the vectors of links and use list of nodeIDs for Host and Router
		cerr << "Failed to create Link with id " << id << ". ID already exists." << endl;
		return -1;
	}
}

// TODO: Add TCP param and create flow accordingly
int net::addFlow(std::string id, std::node_src, std::node_dst, float data_size, float start_time){
	// Check if there exists a flow with this id already
	if (!usedID(id)) {
		// Check if both IDs are valid nodes
		
		// if in nodes, then continue, else cerr
		
		// Get the nodes
		n1 = nodes[node_id1];
		n2 = nodes[node_id2];
		
		// TODO: Given TCP algo
		flows[id] = flow(id, src, dst, data_size, start_time);
		nflows++;
		
		// Update dictionaries
		n1.addFlow(flows[id]);
		n2.addFlow(flows[id]);
		ids.push_back(id);
		
		// TODO: Create initial events
		flowStart e = new flowStart(start_time, flows[id]);
		// for TCP protocols update windows
		return 0;
	} else {
		// TODO: Refactor to allow multiple names? using the vectors of flows and use list of nodeIDs for Host and Router
		cerr << "Failed to create Flow with id " << id << ". ID already exists." << endl;
		return -1;
	}
}

int net::flowFinished() {
	return --n;
}

int net::addEvent(event e, float delay){
	e.time = time + delay;
	events.push(e);
}


int net::run(){
	while ((!events.empty() && nFlows != 0)) {
		if (endtime > 0 && time > endtime) {
			//Simulation ends at user specified time
			break;
		}
		// Get current event
		// Update time with peek
		// Run current event
	}
}