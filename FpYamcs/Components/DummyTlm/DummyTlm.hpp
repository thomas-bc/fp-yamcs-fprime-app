// ======================================================================
// \title  DummyTlm.hpp
// \author chammard
// \brief  hpp file for DummyTlm component implementation class
// ======================================================================

#ifndef FpYamcs_DummyTlm_HPP
#define FpYamcs_DummyTlm_HPP

#include "FpYamcs/Components/DummyTlm/DummyTlmComponentAc.hpp"

namespace FpYamcs {

class DummyTlm final : public DummyTlmComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct DummyTlm object
    DummyTlm(const char* const compName  //!< The component name
    );

    //! Destroy DummyTlm object
    ~DummyTlm();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for run
    //!
    //! Example port: receiving calls from the rate group
    void run_handler(FwIndexType portNum,  //!< The port number
                     U32 context           //!< The call order
                     ) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command DUMMY_COMMAND
    //!
    //! Example command
    void DUMMY_COMMAND_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                                  U32 cmdSeq            //!< The command sequence number
                                  ) override;

    U64 m_counter = 0x0;      //!< example counter to send as telemetry
    MyStruct m_sampleStruct;  //!< example struct to send as telemetry
};

}  // namespace FpYamcs

#endif
