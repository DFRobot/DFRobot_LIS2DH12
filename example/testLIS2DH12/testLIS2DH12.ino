/*!
 * @file testLIS2DH12.ino
 * @brief DFRobot's Read LIS2DH12 data
 * @n This example is in order to achieve the serial port to receive LIS2DH12 back to the data
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 * @author [Wuxiao](xiao.wu@dfrobot.com)
 * @version  V1.0
 * @date  2016-10-13
 * @https://github.com/DFRobot/DFRobot_LIS2DH12
 */

#include <Wire.h>
#include <DFRobot_LIS2DH12.h>


DFRobot_LIS2DH12 LIS; //Accelerometer

void setup(){
  Wire.begin();
  Serial.begin(115200);
  LIS.init();
  delay(100);
}
void loop(){
  while(!Serial);
  Serial.println("Serial open");
  acceleration();
}
/*!
 *  @brief Print the position result.
 */
void acceleration(void)
{
  LIS.init();
  int x, y, z;
  while(true)
  {
    delay(100);
    LIS.readXYZ(x, y, z);
    LIS.mgScale(x, y, z);
    Serial.print("Acceleration x: "); //print acceleration
    Serial.print(x);
    Serial.print(" mg \ty: ");
    Serial.print(y);
    Serial.print(" mg \tz: ");
    Serial.print(z);
    Serial.println(" mg");
    if(Serial.available())
    {
      Serial.read();
      break;
    }
  }
}
