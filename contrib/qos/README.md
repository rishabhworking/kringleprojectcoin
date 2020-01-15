### QoS (Quality of service) ###

This is a Linux bash script that will set up tc to limit the outgoing bandwidth for connections to the KringleProjectCoin network. It limits outbound TCP traffic with a source or destination port of 7342, but not if the destination IP is within a LAN.

This means one can have an always-on kringleprojectcoind instance running, and another local kringleprojectcoind/kringleprojectcoin-qt instance which connects to this node and receives blocks from it.
