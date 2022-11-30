#ifndef LDR_HPP
#define LDR_HPP

#include <Arduino.h>
#define LUX_CALC_SCALAR           12518931
#define LUX_CALC_EXPONENT         -1.405


class ldr{
private:
  uint8_t pin;
  uint32_t max_adc;
  float adc_ref;
  float ref_resistence;
  int   ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;
public:
  void LDR_Config(uint8_t _pin, uint32_t _max_adc, float _adc_ref, float _ref_resistence);
  float getLuxValue();


};


void ldr::LDR_Config(uint8_t _pin, uint32_t _max_adc, float _adc_ref, float _ref_resistence){
  pin = _pin;
  max_adc = _max_adc;
  adc_ref = _adc_ref;
  ref_resistence = _ref_resistence;
}

float ldr::getLuxValue(){
  ldrRawData = analogRead(pin);
  resistorVoltage = (float)ldrRawData / max_adc * adc_ref;
  ldrVoltage = (float) adc_ref - resistorVoltage;
  ldrResistance = (float)ldrVoltage/resistorVoltage * ref_resistence;
  ldrLux = (float)LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
  return ldrLux;
}











#endif