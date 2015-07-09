
#include "G4TrackIncl.h"
#include <iostream>
using namespace std;

int get_hubs(int sysId) {
	G4_CMD_STRUCT cs;
	int hubarr[2];
    cs.cmd=G4_CMD_GET_ACTIVE_HUBS;
  	cs.cds.id=G4_CREATE_ID(sysId,0,0);
  	cs.cds.action=G4_ACTION_GET;
  	cs.cds.pParam=hubarr;
  	int res = g4_set_query(&cs);
  	if ( res != G4_ERROR_NONE ) {
  		cerr << "Error querying for hubs" << endl;
  		return -1;
  	}
  	cout << res << endl;
  	cout << hubarr[0] << endl;
  	return cs.cds.iParam;
}

int main() {

	const char* src_file="dual_source_config.g4c";
    int sysId;
    int res;
    res=g4_init_sys(&sysId,src_file,NULL);
    if (res!=G4_ERROR_NONE) {
    	cerr << "Connection to g4 failed - " << res << endl;
        return false;
    }
    cout << "Connected Successfully" << endl;
    // otherwise connection is ok, proceed with business
    int hubs = get_hubs(sysId);
    cout << "Found " << hubs << " hubs" << endl;

    // when ready to quit
    g4_close_tracker();

}