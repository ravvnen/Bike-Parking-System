const express = require('express');
const app = express();
const PORT = process.env.PORT || 3000;

// Sensor data storage (in memory for simplicity)
let sensorData = {
  sensor1: 0,
  sensor2: 0,
};

// Set up EJS as the templating engine
app.set('view engine', 'ejs');
app.use(express.static(__dirname));


// Endpoint for Arduino to send data
app.get('/update', (req, res) => {
  sensorData.sensor1 = req.query.sensor1 || sensorData.sensor1;
  sensorData.sensor2 = req.query.sensor2 || sensorData.sensor2;

  res.send('Data updated');
});

// Endpoint for users to see sensor status
app.get('/', (req, res) => {
  
app.get('/', (req, res) => {
  res.sendFile('index.html', { root: __dirname });
});

});


// Endpoint to get the current sensor data in JSON format
app.get('/sensorData', (req, res) => {
  res.json(sensorData);
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server started on http://localhost:${PORT}`);
});
