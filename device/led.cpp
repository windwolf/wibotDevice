#include "led.hpp"

namespace ww::device
{

LED::LED(Pwm &pwm, PwmChannel rChannel, PwmChannel gChannel, PwmChannel bChannel)
    : _pwm(pwm), _rChannel(rChannel), _gChannel(gChannel), _bChannel(bChannel){};

Result LED::_init()
{
    return _pwm.init();
};
void LED::_deinit()
{
    _pwm.deinit();
};

Result LED::start()
{
    init();
    _pwm.config_get() = PwmConfig{
        .channelsEnable = (_rChannel | _gChannel | _bChannel),
        .fullScaleDuty = 256,
    };
    return _pwm.start();
}; // namespace ww::device

Result LED::stop()
{
    return _pwm.stop();
};

Result LED::color_set(Color color)
{
    _pwm.duty_set(_rChannel, color.r);
    _pwm.duty_set(_gChannel, color.g);
    _pwm.duty_set(_bChannel, color.b);

    return Result::OK;
};
} // namespace ww::device