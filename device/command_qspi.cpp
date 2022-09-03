// #include "command_qspi.hpp"
// #define LOG_MODULE "cmdqspi"
// #include "log.h"

// namespace ww::device
// {

// using namespace ww::accessor;
// using namespace ww::peripheral;

// CommandQSPI::CommandQSPI(QSPI &qspi, uint32_t timeout) : Command(timeout), _qspi(qspi){};

// Result CommandQSPI::_init(){
//     INIT_BEGIN() 
//     MEMBER_INIT_ERROR_CHECK(_qspi)
//     INIT_END()};
// void CommandQSPI::_deinit()
// {
//     MEMBER_DEINIT(_qspi)
// };

// Result CommandQSPI::media_step_send(CommandFramePhase phase, void *data, uint32_t dataSize,
//                                     DataWidth dataWidth, bool isWrite, WaitHandler &waitHandler)
// {
//     return Result_OK;
// };
// Result CommandQSPI::media_session_start(WaitHandler &waitHandler)
// {
//     _qspi.session_begin();
//     waitHandler.done_set(this);
//     return Result_OK;
// };
// Result CommandQSPI::media_session_finish(WaitHandler &waitHandler)
// {
//     _qspi.session_end();
//     waitHandler.done_set(this);
//     return Result_OK;
// };

// Result CommandQSPI::media_send(CommandFrame &frame, WaitHandler &waitHandler);

// } // namespace ww::device