#include "AxisMainCtrl.h"

using namespace std;
using namespace gmt;

void run() {
    try
    {
        // create instances
        AxisMainCtrl axis_main_ctrl("gmt://127.0.0.1/axis_dcs/axis_main_ctrl", "axis_main_ctrl", "127.0.0.1", 8020, "PRIVATE", 100);

        // start instances
        axis_main_ctrl.start();

        // wait until components finish
        axis_main_ctrl.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in axis_main_ctrl_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in axis_main_ctrl_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in axis_main_ctrl_app: unknown exception"<<endl; }
}

int main() {
    run();
    return(0);
}
