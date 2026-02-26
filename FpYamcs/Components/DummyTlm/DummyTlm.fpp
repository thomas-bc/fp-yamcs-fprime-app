module FpYamcs {

    struct MyStruct {
        x: U32
        y: Fw.On
    }

    @ Send a simple channel value
    passive component DummyTlm {

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        @ Example telemetry counter
        telemetry DummyCounter: U64
        telemetry DummyStruct: MyStruct

        @ Example command
        sync command DUMMY_COMMAND()

        @ Reports the state we set to blinking.
        event DummyEvent(dummyArg: U8) \
            severity activity high \
            format "My super useful event value {}"

        @ Example port: receiving calls from the rate group
        sync input port run: Svc.Sched


        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}