#include <string.h>
#include <vector>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <blepp/logging.h>
#include <blepp/pretty_printers.h>
#include <blepp/blestatemachine.h>
#include <blepp/lescan.h>
#include <blepp/uuid.h>

using namespace BLEPP;

//UUIDs of BLE beacons
const BLEPP::bt_uuid_t UUID1;
const BLEPP::bt_uuid_t UUID2;
const BLEPP::bt_uuid_t UUID3;

struct btevent //Stores information when a given UUID is detected
{
    bt_uuid_t UUID;
    unsigned int* t; //Time of event
    int8_t rssi; //RSSI of signal
};

HCIScanner* scanSetup() 
{
    //Scan setup
    HCIScanner::ScanType type = HCIScanner::ScanType::Active;
    HCIScanner::FilterDuplicates filter = HCIScanner::FilterDuplicates::Off; //Needs testing
    HCIScanner scanner(true, filter, type);
    //Probably this should send errors and results somewhere (this will be part of ROS wrapper)
    return &scanner;
}

std::vector<btevent> getResults(HCIScanner scanner, btevent b1, btevent b2, btevent b3) //Run this when you want to get scan results
{
    std::vector<AdvertisingResponse> responses = scanner.get_advertisements();
    std::vector<btevent> events = std::vector<btevent>();
    for (const auto& ad: responses) 
    {
        //Test to see if any of the bluetooth addresses match
        if (ad.uuid_128_bit_complete) //Make sure UUID is correct type- update to whatever our UUID type is
        {
            if (ad.UUIDs.at(2) == UUID::from(UUID1)) 
            {
                //TODO: Get current time t
                btevent event;
                event.UUID = UUID1;
                event.rssi = ad.rssi;
                events.push_back(event);
            }
            else if (ad.UUIDs.at(2) == UUID::from(UUID2))
            {
                btevent event;
                event.UUID = UUID2;
                event.rssi = ad.rssi;
                events.push_back(event);
            }
            else if (ad.UUIDs.at(2) == UUID::from(UUID3))
            {
                btevent event;
                event.UUID = UUID3;
                event.rssi = ad.rssi;
                events.push_back(event);
            }
        }
    }
    return events;
}