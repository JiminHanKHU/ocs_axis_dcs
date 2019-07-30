#include "AxisHwAdapter.h"

using namespace std;
using namespace gmt;

AxisHwAdapter::AxisHwAdapter(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : AxisHwAdapterBase(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
{
}

AxisHwAdapter::~AxisHwAdapter()
{
}

void AxisHwAdapter::step()
{
    //XXX add your code here

    /*if (is_step_rate(100))
    {
        // this will be executed every 100 steps
        log_info("step  = " + std::to_string(step_counter));
    }*/
}

void AxisHwAdapter::setup()
{
    //setup async input handlers

    //ex: new_async_input_handler ("my_input_name", this, &AxisHwAdapter::my_input_handler);

    //add behaviors to features

    //other initializations

}
