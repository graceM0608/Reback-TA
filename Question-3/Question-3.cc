#include <iostream>
#include <fstream>
#include <string>


#include <iomanip>
#include <sstream> 
#include <bitset>
// Ensure stringstream is included
// Question 3: This is an extension task that requires you to decode sensor data from a CAN log file.
// CAN (Controller Area Network) is a communication standard used in automotive applications (including Redback cars)
// to allow communication between sensors and controllers.
//
// Your Task: Using the definition in the Sensors.dbc file, extract the "WheelSpeedRR" values
// from the candump.log file. Parse these values correctly and store them in an output.txt file with the following format:
// (<UNIX_TIME>): <DECODED_VALUE>
// eg:
// (1705638753.913408): 1234.5
// (1705638754.915609): 6789.0
// ...
// The above values are not real numbers; they are only there to show the expected data output format.
// You do not need to use any external libraries. Use the resources below to understand how to extract sensor data.
// Hint: Think about manual bit masking and shifting, data types required,
// what formats are used to represent values, etc.
// Resources:
// https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial
// https://www.csselectronics.com/pages/can-dbc-file-database-intro


using namespace std;


// Extracted from Sensors.dbc:
// - WheelSpeedRR is located at **bit 32**, spanning **16 bits**.
// - Scaling factor: 0.1
// - Unit: km/h
// - CAN ID: 1797 (0x705 in hexadecimal, 11-bit standard CAN ID)
#define WHEEL_SPEED_CAN_ID 0x705  // Corrected CAN ID from Sensors.dbc
#define STANDARD_CAN_MASK 0x7FF   // Mask for 11-bit CAN
#define EXTENDED_CAN_MASK 0x1FFFFFFF // Mask for 29-bit CAN
void decodeCanLog(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        string timestamp, interface, canIDPayload;
        
        // Example log format: "(1705638753.913408) vcan0 705#39C2A37B95B17C57"
        iss >> timestamp >> interface >> canIDPayload;
        
        // Extract CAN ID before the '#' character
        size_t hashPos = canIDPayload.find('#');
        if (hashPos == string::npos) {
            cout << "Error: Invalid CAN log format!" << endl;
            continue;
        }
        string canIDStr = canIDPayload.substr(0, hashPos);
        string dataPayload = canIDPayload.substr(hashPos + 1); // Extract payload after '#'
        
        try {
            int raw_can_id = stoi(canIDStr, nullptr, 16);  // Convert to integer
            int masked_can_id = raw_can_id & STANDARD_CAN_MASK;  // Apply 11-bit mask
            
            if (masked_can_id == WHEEL_SPEED_CAN_ID) {  // Match correct CAN ID
                // Ensure payload is at least 6 bytes (to extract from bit 32 onwards)
                if (dataPayload.length() < 6 * 2) { // Each byte is represented by 2 hex characters
                    cout << "Warning: Insufficient payload data!" << endl;
                    continue;
                }
                
                // Extract WheelSpeedRR from bytes 4 and 5 (bit 32, 16 bits, little-endian)
                int byte4 = stoi(dataPayload.substr(8, 2), nullptr, 16);
                int byte5 = stoi(dataPayload.substr(10, 2), nullptr, 16);
                int rawValue = (byte5 << 8) | byte4;  // Merge bytes in little-endian order
                double wheelSpeed = rawValue * 0.1;  // Apply scaling factor

                // Write to output file
                outFile << timestamp << ": " << fixed << setprecision(1) << wheelSpeed << " km/h" << endl;
            }
        } catch (exception& e) {
            cout << "Error: Invalid CAN ID conversion -> " << canIDStr << endl;
        }
    }

    inFile.close();
    outFile.close();
    cout << "Decoding complete! Output saved to " << outputFile << endl;
}

int main() {
    decodeCanLog("candump.log", "output.txt");
    return 0;
}
