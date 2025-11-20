
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int fanPin = 9;        // PWM fan
const int peltierPin = 10;   // MOSFET → Peltier

float setTemp = 29.0;        // setpoint
float peltierDiff = 2.0;     // enables peltier when 2°C above setpoint

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(fanPin, OUTPUT);
  pinMode(peltierPin, OUTPUT);

  analogWrite(fanPin, 0);
  digitalWrite(peltierPin, LOW);
}

int pwmPercentToValue(int pwmPercent) {
  return map(pwmPercent, 0, 100, 0, 255);
}

int getFanPWM(float temp, float setTemp) {
  float diff = temp - setTemp;

  if (diff <= 0) return 0;     // below or equal set temp → OFF
  else if (diff <= 1) return 12;  // slight increase
  else if (diff <= 2) return 25;  // medium
  else if (diff <= 3) return 38;  // high
  else return 100;                // full fan
}

void loop() {

  float temp = dht.readTemperature();  // raw DHT temp
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }

  int pwmPercent = getFanPWM(temp, setTemp);
  int pwmValue = pwmPercentToValue(pwmPercent);

  // Fan control
  analogWrite(fanPin, pwmValue);

  // Peltier control
  if (temp > setTemp + peltierDiff) {
    digitalWrite(peltierPin, HIGH);
  } else {
    digitalWrite(peltierPin, LOW);
  }

  // Serial monitor output
  Serial.print("Temp: ");
  Serial.print(temp, 2);
  Serial.print("C, Set Temp: ");
  Serial.print((int)setTemp);
  Serial.print("C, Fan PWM: ");
  Serial.println(pwmPercent);

  delay(1000); 
}
