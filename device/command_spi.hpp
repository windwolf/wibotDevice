#ifndef __WWDEVICE_COMMAND_SPI_HPP__
#define __WWDEVICE_COMMAND_SPI_HPP__
#include "command.hpp"
#include "spi.hpp"
namespace ww::device
{
using namespace ww::accessor;
using namespace ww::peripheral;

class CommandSpi : public Command
{
  public:
    CommandSpi(SpiWithPins &spi, EventGroup &eventGroup, uint32_t doneFlag,
               uint32_t errorFlag, uint32_t readyFlag, uint32_t timeout)
        : Command(eventGroup, doneFlag, errorFlag, readyFlag, timeout),
          _spi(spi){};
    Result init();
    Result deinit();

  protected:
    virtual Result media_operate(CommandFramePhase phase, void *data,
                                 uint32_t dataSize, DataWidth dataWidth,
                                 bool isWrite, WaitHandler &waitHandler);
    virtual Result media_session_start(WaitHandler &waitHandler);
    virtual Result media_session_finish(WaitHandler &waitHandler);

  private:
    SpiWithPins &_spi;
};
} // namespace ww::device

#endif // __WWDEVICE_COMMAND_SPI_HPP__