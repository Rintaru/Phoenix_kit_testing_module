#include <Arduino.h>
#include <ros.h>
#include <rpi_logger/voltages.h>

ros::NodeHandle nh;

rpi_logger::voltages voltages_msg;
ros::Publisher p("voltages", &voltages_msg);

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(p);
}


void loop()
{ 
  voltages_msg.header.stamp = nh.now();
  voltages_msg.V1=800;
  voltages_msg.V2=600;
  
  p.publish(&voltages_msg);

  delay(500);
  voltages_msg.header.stamp = nh.now();
  voltages_msg.V1=450;
  voltages_msg.V2=250;

  p.publish(&voltages_msg);

  delay(500);
  nh.spinOnce();
}