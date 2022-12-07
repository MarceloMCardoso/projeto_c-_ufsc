#ifndef RTC_HPP
#define RTC_HPP

#include <Wire.h>
#include "RTClib.h"

class rtc{
private:
  RTC_DS1307 rtc;
  uint8_t day, month, year, day_of_week, hour, minute, second;
public:
  uint8_t getDay();
  uint8_t getMonth();
  uint8_t getYear();
  uint8_t getDay_of_week();
  uint8_t getHour();
  uint8_t getMinute();
  uint8_t getSecond();
};



uint8_t rtc::getDay(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  day = now.day();
  return day;
}

uint8_t rtc::getMonth(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  month = now.month();
  return month;}

uint8_t rtc::getYear(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  year = now.year();
  return (uint8_t)year-208;}

uint8_t rtc::getDay_of_week(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  day_of_week = now.dayOfTheWeek();
  return day_of_week;}

uint8_t rtc::getHour(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  hour = now.hour();
  return hour;}

uint8_t rtc::getMinute(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  minute = now.minute();
  return minute;}

uint8_t rtc::getSecond(){
  rtc.begin();
  rtc.isrunning();
  DateTime now = rtc.now();
  second = now.second();
  return second;}


#endif
