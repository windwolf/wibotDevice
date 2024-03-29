#ifndef __WWDEVICE_COMMAND_SPI_HPP__
#define __WWDEVICE_COMMAND_SPI_HPP__
#include "command.hpp"
#include "spi.hpp"
namespace wibot::device {
using namespace wibot::accessor;
using namespace wibot::peripheral;

class CommandSpi : public Initializable, public Command {
   public:
    CommandSpi(SpiWithPins &spi, uint32_t timeout);

   protected:
    Result media_command_send(CommandFrame &frame, WaitHandler &waitHandler) override;
    Result media_session_start(WaitHandler &waitHandler) override;
    Result media_session_finish(WaitHandler &waitHandler) override;
    Result _init() override;
    void   _deinit() override;

   private:
    SpiWithPins &_spi;
    Result _do_step_send(CommandFramePhase phase, void *data, uint32_t size, DataWidth dataWidth,
                         bool isWrite, WaitHandler &waitHandler);
};
}  // namespace wibot::device

#endif  // __WWDEVICE_COMMAND_SPI_HPP__
