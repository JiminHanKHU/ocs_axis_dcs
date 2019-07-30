#include "AxisHwAdapter.h"

using namespace std;
using namespace gmt;

void run() {
    try
    {
        // create instances
        AxisHwAdapter axis_hw1_adapter("gmt://127.0.0.1/axis_dcs/axis_hw1_adapter", "axis_hw1_adapter", "127.0.0.1", 10010, "PRIVATE", 100);

        // start instances
        axis_hw1_adapter.start();

        // wait until components finish
        axis_hw1_adapter.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in axis_hw_adapter_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in axis_hw_adapter_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in axis_hw_adapter_app: unknown exception"<<endl; }
}

int main() {
    run();
    return(0);
}
