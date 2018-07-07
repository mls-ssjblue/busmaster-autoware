# Autoware CAN Simulation
Code to connect between autoware and busmaster

## Getting Started


### Prerequisites

Install Busmaster from online. 
Clone Autoware and run from Github


### Using

/Split1 and 2 contains code for different splits
/AW_changes contains changes in geo_pos_conv.cpp from the Autoware localization package
/BMNodes contains the server, node1(calculation node) and several dummy nodes

/BMNodes need to be imported in a Busmaster project and started

/AW_changes needs to be used in the Autoware instance running 

Disable firewall while connecting both.


