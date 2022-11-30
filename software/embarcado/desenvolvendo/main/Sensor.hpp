#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_AHTX0.h>





static const uint8_t dht_11{11};  /**< DHT TYPE 11 */
static const uint8_t aht_20{20};  /**< DHT TYPE 11 */

class Sensor{
private:
  int32_t temperature;
  int32_t humidity;
  uint8_t pin;
  uint8_t type;
  bool state = false;
  Adafruit_AHTX0 aht;
  Adafruit_Sensor *aht_humidity, *aht_temp;
  bool stateError = 0;
public:
  void setPin(uint8_t _pin);
  void setType(uint8_t _type);
  void setConfig(uint8_t _pin, uint8_t _type);
  void setConfig(uint8_t _type);
  int32_t getTemperature();
  int32_t getHumidity();
};

void Sensor::setPin(uint8_t _pin){
  pin = _pin;
}

void Sensor::setType(uint8_t _type){
  type = _type;
}

void Sensor::setConfig(uint8_t _pin, uint8_t _type){
  DHT_Unified dht(_pin, _type);
}

void Sensor::setConfig(uint8_t _type){
  //if(_type != 20){stateError = 1;}
  type = _type;
  aht_temp = aht.getTemperatureSensor();
  aht_humidity = aht.getHumiditySensor();
}






int32_t Sensor::getTemperature(){
  if(type = dht_11){
  // Get temperature event and print its value.
  sensors_event_t event;
  DHT_Unified dht(4, dht_11);
  delay(50);
  dht.temperature().getEvent(&event);
  int32_t temp;
  temp = event.temperature;
  while((temp>120)||(temp<-10)){
    dht.temperature().getEvent(&event);
    temp = event.temperature;
  }
  return temp;
  }

  if(type = aht_20){
    sensors_event_t temp;
    Adafruit_Sensor *aht_temp;
    aht_temp->getEvent(&temp);
    return temp.temperature;
  }
}

int32_t Sensor::getHumidity(){
  // Get temperature event and print its value.
  if(type == dht_11){
    sensors_event_t event;
    DHT_Unified dht(4, dht_11);
    delay(50);
    dht.humidity().getEvent(&event);
    int32_t humidity;
    humidity = event.relative_humidity;
    while((humidity>100)||(humidity<0)){
      dht.humidity().getEvent(&event);
      humidity = event.relative_humidity;
    }
    return humidity;
  }

  if(type == aht_20){
    sensors_event_t humidity;
    Adafruit_Sensor *aht_humidity;
    aht_humidity->getEvent(&humidity);
    return (humidity.relative_humidity);
  }
}


#endif