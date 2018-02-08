#include <iostream>
#include <tins/tins.h>

using namespace Tins;
using namespace std;

int main() {
 	RadioTap radio = RadioTap() / Dot11Beacon();
	Dot11Beacon *beacon = radio.find_pdu<Dot11Beacon>();
 	PacketSender sender;
	
 	beacon->addr1(Dot11::BROADCAST);
 	beacon->addr2("49:27:4d:49:4d:4c");
 	beacon->addr3(beacon->addr2());

	beacon->timestamp(0x1fad2341289301faLL);
	beacon->interval(0x14fa);
 	beacon->ssid("FUCKYOU");
	beacon->ds_parameter_set(8);
	beacon->supported_rates({ 1.0f, 5.5f, 11.0f });
	beacon->extended_supported_rates({0.5f,1.0f,5.5f,7.5f});
	beacon->qos_capability(0xfa);
	beacon->power_capability(0xfa,0xa2);
	beacon->rsn_information(RSNInformation::wpa2_psk());

 	while(1){
 		sender.send(radio,"wlan0");
 	}
 	return 0;
}
    
