#include <string>
#include <memory>

#include <ocs_core_fwk.h>

#include "./axis_hw_adapter/AxisHwAdapter.h"
#include "./axis_main_ctrl/AxisMainCtrl.h"

using namespace std;
using namespace gmt;

class AxisCtrlPkgApp : public CoreApplication
{
    public:

        AxisCtrlPkgApp();

        virtual ~AxisCtrlPkgApp();

        virtual void start(int argc, char* argv[]);

    protected:

        CLIHandler cli;
};

AxisCtrlPkgApp::AxisCtrlPkgApp()
 : CoreApplication()
 , cli("AxisCtrlPkg application", "GMT_")
{
    //setup command line
    cli.add_option<string> ("config",  "Name of the configuration snapshot to apply", "default", "")
       .add_option<string> ("logging", "Logging level", "info")
       .add_option<string> ("ctnr_config", "Name of the container configuration file", "default")
       .add_option<void>   ("help",    "Show help");

    auto cntr = make_unique<CoreContainer>();

    // create axis_hw_adapter instances
    cntr->add (make_unique<AxisHwAdapter>("gmt://127.0.0.1/axis_dcs/axis_hw1_adapter", "axis_hw1_adapter", "127.0.0.1", 10010, "PRIVATE", 100));

    // create axis_main_ctrl instances
    cntr->add (make_unique<AxisMainCtrl>("gmt://127.0.0.1/axis_dcs/axis_main_ctrl", "axis_main_ctrl", "127.0.0.1", 8020, "PRIVATE", 100));

    // create axis_ctrl_app instances


    this->add (std::move(cntr));
}

AxisCtrlPkgApp::~AxisCtrlPkgApp()
{
}

void AxisCtrlPkgApp::start(int argc, char* argv[])
{
    CoreApplication::initialize_rt_system();

    cli.parse_cmd_line (argc, argv, true);

    if (cli.is_opt("help"))
    {
        cout<<cli<<endl;
    }
    else
    {
        auto cli_opts = cli.get_opt_values();
        configure (*cli_opts);
        CoreApplication::start ();
    }
}

int main (int argc, char* argv[])
{
    //create the application
    AxisCtrlPkgApp axis_ctrl_pkg_app;
    
    try
    {
        //configure and start the application
        axis_ctrl_pkg_app.start (argc, argv);

        //wait until execution end
        axis_ctrl_pkg_app.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in axis_ctrl_pkg_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in axis_ctrl_pkg_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in axis_ctrl_pkg_app: unknown exception"<<endl; }

    return 0;
}
