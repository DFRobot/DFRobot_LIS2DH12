/*!
 * @file DFRobot_LIS2DH12.h
 * @brief DFRobot's Read LIS2DH12 data
 * @n This example achieve receiving LIS2DH12  data via serial
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 * @author [Wuxiao](xiao.wu@dfrobot.com)
 * @version  V1.0
 * @date  2016-10-13
 * @https://github.com/DFRobot/DFRobot_LIS2DH12
 */


#ifndef DFRobot_LIS2DH12_h
#define DFRobot_LIS2DH12_h

#include <stdlib.h>
#include <stdint.h>

class DFRobot_LIS2DH12 {
public:
	static uint8_t sensorAddress; ///< IIC address of the sensor
	uint8_t init(void); ///< Initialization function
	void readXYZ(int16_t&, int16_t&, int16_t&); ///< read x, y, z data
	void mgScale(int16_t&, int16_t&, int16_t&); ///< transform data to millig
  /*!
   *  Through the I2C to specify register read a single data
   */
	uint8_t readReg(uint8_t);
  /*!
   *  Through the I2C to specify register read more data
   */
	void readReg(uint8_t, uint8_t *, uint8_t, bool autoIncrement = true);
  /*!
   *  Write a single data through the I2C to specify register
   */
	uint8_t writeReg(uint8_t, uint8_t);
  /*!
   *  Through the I2C write multiple data on the specified register
   */
	uint8_t writeReg(uint8_t, uint8_t *, size_t, bool autoIncrement = true);
	};
	
#endif