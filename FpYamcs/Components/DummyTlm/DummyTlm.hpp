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

    U64 m_counter = 0x0;  //!< example counter
};

}  // namespace FpYamcs

#endif
