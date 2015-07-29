#include "StateMachine.h"
#include <cstring>

#define CHECK_EVENT(in, pos) \
    ( (unsigned int)in & ((unsigned int)1 << pos) )

#define SET_EVENT(out, pos) \
    ( out |= ((unsigned int)1 << pos) )

StateMachine::StateMachine()
{
    inputSize_ = sizeof(input_);
    outputSize_ = sizeof(output_);
    lVarsSize_ = 0;
}

void StateMachine::init()
{
    /* Clear */
    memset((void*)&input_, 0, sizeof(input_));
    memset((void*)&output_, 0, sizeof(output_));
    memset((void*)&state_, 0, sizeof(state_));
    memset((void*)&transition_, 0, sizeof(transition_));
    eventsInPorts_ = 0;
    eventsOutPorts_ = 0;
    /*Set inial transition*/
    transition_.id_ = 1;
    /*Change State*/
    state_.id_ = 1;
    /*Entry action for State_1 */
    //Do nothing
}

bool StateMachine::dispatch(const StateMachineInput* input, int size, int eventsIn)
{
    /*Check for input size*/
    if ( size && size != sizeof(input_) )
    {
        std::cerr << "input size mismatch cannot evaluate the input" << std::endl;
        lastError_ = "input size mismatch";
        return false;
    }
    /*Save current input*/
    input_ = *input;
    /*Save current events input*/
    eventsInPorts_ = eventsIn;
    /*Clear events output*/
    eventsOutPorts_ = 0;
    switch((StateType)state_.id_)
    {
        case State_1:
        {
            if ( true  && input_.in_0==1 )
            {
                /* Set current transition */
                transition_.id_ = 2;
                /*Exit from State_1*/
                ;;
                /*Do Action */
                ;;
                /*Change State to State_3 */
                state_.id_ = 3;
                /*Entry in State_3*/
                ;;
            }
            else
            {
                /*While action for State_1*/
                ;
            }
        }break;
        case State_3:
        {
            if ( true  )
            {
                /* Set current transition */
                transition_.id_ = 3;
                /*Exit from State_3*/
                ;;
                /*Do Action */
                output_.out_1=1;;
                /*Change State to State_4 */
                state_.id_ = 4;
                /*Entry in State_4*/
                ;;
            }
            else
            {
                /*While action for State_3*/
                ;
            }
        }break;
        case State_4:
        {
            if ( true  && input_.in_1==1 )
            {
                /* Set current transition */
                transition_.id_ = 4;
                /*Exit from State_4*/
                ;;
                /*Do Action */
                ;;
                /*Change State to State_5 */
                state_.id_ = 5;
                /*Entry in State_5*/
                ;;
            }
            else
            {
                /*While action for State_4*/
                ;
            }
        }break;
        case State_5:
        {
            if ( true  && input_.in_2==1 )
            {
                /* Set current transition */
                transition_.id_ = 5;
                /*Exit from State_5*/
                ;;
                /*Do Action */
                ;;
                /*Change State to State_1 */
                state_.id_ = 1;
                /*Entry in State_1*/
                ;;
            }
            else
            {
                /*While action for State_5*/
                ;
            }
        }break;
        default:
            std::cerr << "Invalid state, internal error" << std::endl;
            lastError_ = "Invalid state, internal error";
            return false;
        break;
    } // end switch
    return true;
}

const StateMachineInput* StateMachine::input() const
{
    return &input_;
}

const StateMachineOutput* StateMachine::output() const
{
    return &output_;
}

const StateMachineLocalVars* StateMachine::localVariables() const
{
    return &local_var_;
}

const SMStateData* StateMachine::state() const
{
    return &state_;
}

const SMTransitionData* StateMachine::transition() const
{
    return &transition_;
}

int StateMachine::eventsInPorts() const
{
    return eventsInPorts_;
}

unsigned int StateMachine::eventsOutPorts() const
{
    return eventsOutPorts_;
}

/*Global instance of StateMachine*/
StateMachine smInst;


/***** Callbacks *****/
void state_machine_init()
{
    smInst.init();
}

bool state_machine_dispatch(const void* input, int size, int eventsIn)
{
    return smInst.dispatch((StateMachineInput*)input, size, eventsIn);
}

const void* state_machine_output(int* size)
{
    *size = smInst.outputSize();
    return (const void*)smInst.output();
}

const void* state_machine_local_variables(int* size)
{
    *size = smInst.lVarsSize();
    return (const void*)smInst.localVariables();
}

const void* state_machine_input(int* size)
{
    *size = smInst.inputSize();
    return (const void*)smInst.input();
}

const void* state_machine_state(int* size)
{
    *size = sizeof(SMStateData);
    return (const void*)smInst.state();
}

const void* state_machine_transition(int* size)
{
    *size = sizeof(SMTransitionData);
    return (const void*)smInst.transition();
}

int state_machine_events_in_ports()
{
    return smInst.eventsInPorts();
}

unsigned int state_machine_events_out_ports()
{
    return smInst.eventsOutPorts();
}

const char* state_machine_last_error()
{
    return smInst.lastError_.c_str();
}

