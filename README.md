# Bike Parking System for S-Trains

## Overview

The Bike Parking System for S-Trains is a networked embedded system designed to enhance urban mobility by providing real-time information about bike parking availability on S-Trains. This project aims to streamline the commuter experience in Copenhagen by integrating advanced sensor technology with cloud computing services.

## System Architecture

This project employs a multi-tier architecture involving sensing units, data aggregators, a master controller, and a cloud-based server. The system's workflow encompasses data collection, aggregation, processing, and user interface display.

- **Sensing Units**: Utilizes HC-SR05 Ultrasonic Sensors for detecting bike presence.
- **Data Aggregators**: Arduino Uno microcontrollers serve as intermediaries to collect and process sensor data.
- **Master Controller**: An Arduino Uno R4 WIFI microcontroller acts as the central processing unit.
- **Cloud Server**: Hosted on AWS Elastic Beanstalk, it manages data storage and user interface display.

## Repository Structure

This repository is organized into several directories, each containing specific components of the system:

- `/Arduino`: Contains the Arduino sketches for the different modules.
  - `Data Aggregator`: Code for the Arduino Unos attached to the HC-SR05 Ultrasonic Sensors. This sketch handles the distance measurement and transmits the status to the master controller.
  - `Master Controller`: Arduino Uno R4 WIFI code. It aggregates sensor data and sends it to the cloud server.
- `/Server`: Includes all the code for the cloud server hosted on AWS Elastic Beanstalk
  - `server.js`: Node.js server script managing incoming data and updating the UI in real-time.
  - `index.html`: Main HTML file for the user interface.
  - `/css`: Styling files for the UI.
  - `/js`: JavaScript files for frontend logic.

## Hardware Setup

The project utilizes the following hardware components:

- 2 x HC-SR05 Ultrasonic Sensors: Attached to separate Arduino Uno boards.
- 2 x Arduino Uno: Each programmed with `Data Aggregator` for sensor data collection.
- 1 x Arduino Uno R4 WIFI: Flashed with `Master Controller` for data aggregation and cloud communication.

## Getting Started

To set up the system:

1. **Hardware Assembly**: Connect the HC-SR05 sensors to the respective Arduino Uno units as per the circuit diagrams provided in `/Diagrams`.
2. **Flashing the Code**:
   - Flash `Data Aggregator` code onto each Arduino Uno.
   - Flash `Master Controller` code onto the Arduino Uno R4 WIFI.
3. **Server and UI Setup**:
   - Deploy `server.js` to AWS Elastic Beanstalk.
   - Host the contents of `/ClientUI` on a suitable web server.

## Usage

Once the system is set up and running:

- The sensing units detect bike presence and relay this information to the data aggregators.
- The master controller processes this data and sends it to the cloud server.
- Commuters can access the web interface to view real-time bike parking availability.

## Contributing

Contributions to the Bike Parking System project are welcome. Please read `CONTRIBUTING.md` for details on our code of conduct, and the process for submitting pull requests.

## Contact

Phillip Ravn Boe Jensen - [phillip.boe.jensen@gmail.com](mailto:phillip.boe.jensen@gmail.com)

Project Link: [https://github.com/ravvnen/Bike-Parking-System](https://github.com/ravvnen/Bike-Parking-System)
