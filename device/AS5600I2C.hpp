//
// Created by zhouj on 2022/12/2.
//

#ifndef WWMOTOR_LIBS_WWDEVICE_DEVICE_AS5600I2C_HPP_
#define WWMOTOR_LIBS_WWDEVICE_DEVICE_AS5600I2C_HPP_
#include "DataSource.hpp"
#include "base.hpp"
#include "peripheral/i2c.hpp"
namespace wibot::device {
#define AS5600_I2C_ADDRESS   0x36
#define AS5600_I2C_ZPOS      0x01
#define AS5600_I2C_MPOS      0x03
#define AS5600_I2C_MANG      0x05
#define AS5600_I2C_CONF      0x07
#define AS5600_I2C_RAWANGLE  0x0C
#define AS5600_I2C_ANGLE     0x0E
#define AS5600_I2C_STATUS    0x0B
#define AS5600_I2C_AGC       0x1A
#define AS5600_I2C_MAGNITUDE 0x1B
#define AS5600_I2C_BURN      0xFF
using namespace wibot::os;
using namespace wibot::peripheral;
struct AS5600I2CConfig {};
class AS5600I2C : public Initializable, public Configurable<AS5600I2CConfig>, public DataSource {
   public:
    AS5600I2C(I2cMaster& i2c, EventGroup& eventGroup) : _i2c(i2c), _wh(eventGroup){};

    Result apply_config() override;

    void zero_set();

    uint16_t get_config();
    uint8_t  get_status();
    uint16_t get_zpos();
    uint16_t get_mpos();

    uint32_t angle_get();

    uint32_t get_data() override;

   protected:
    Result _init() override;
    void   _deinit() override;

   private:
    AS5600I2CConfig    _config;
    I2cMaster&         _i2c;
    wibot::WaitHandler _wh;
};
}  // namespace wibot::device
#endif  // WWMOTOR_LIBS_WWDEVICE_DEVICE_AS5600I2C_HPP_
