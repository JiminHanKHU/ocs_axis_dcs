#ifndef _AxisMainCtrl_h_
#define _AxisMainCtrl_h_


#include "AxisMainCtrlBase.h"

namespace gmt
{

class AxisMainCtrl : public AxisMainCtrlBase
{
    public:
        AxisMainCtrl(
                        const  std::string& comp_uri,
                        const  std::string& comp_name,
                        const  std::string& comp_host,
                        int    comp_port,
                        const  std::string& comp_acl,
                        double comp_scan_rate = 1.0,
                        int comp_prio = GMT_THREAD_DEFAULT_PRIO,
                        int comp_stack_size = GMT_DEFAULT_STACK_SIZE);

        virtual ~AxisMainCtrl();
        //XXX add your public methods here
	float gfloat_one_rpm_increments;
    protected:

        virtual void step() override;
        virtual void setup() override;
        
	virtual void homing();
	virtual void manual();
        virtual void stop();
        virtual void state_reset();
	virtual void timer_kill();
        virtual void state_msg(std::string msg);

	virtual bool move_to_position(int position_goal);
	virtual bool safety_state();
	virtual void safety_command();
	virtual bool timer_start(int timeout);
	//XXX add your protected class members here

    private:

        //XXX add your private class members here
};

} // namespace gmt

#endif   // _AxisMainCtrl_h_
