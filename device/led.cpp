#include "led.hpp"

namespace wibot::device {

LED::LED(Pwm& pwm, PwmChannel rChannel, PwmChannel gChannel, PwmChannel bChannel)
    : _pwm(pwm), _rChannel(rChannel), _gChannel(gChannel), _bChannel(bChannel){};

Result LED::_init() {
    _pwm.init();
    return Result::OK;
};
void LED::_deinit() {
    _pwm.deinit();
};

Result LED::start() {
    init();
    _pwm.config = PwmConfig{
        .channelsEnable = (_rChannel | _gChannel | _bChannel),
        .fullScaleDuty  = 256,
    };
    _pwm.apply_config();
    return _pwm.all_enable();
};

Result LED::stop() {
    return _pwm.all_disable();
};

Result LED::color_set(Color color) {
    _pwm.duty_set(_rChannel, color.r);
    _pwm.duty_set(_gChannel, color.g);
    _pwm.duty_set(_bChannel, color.b);

    return Result::OK;
};
}  // namespace wibot::device
