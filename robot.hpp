/* #include "dev_xxx.hpp" */
#include "comp_cmd.hpp" #include "dev_ai.hpp"
#include "dev_can.hpp"
#include "dev_cap.hpp"
#include "dev_referee.hpp"
#include "mod_launcher.hpp"

void robot_init();

namespace Robot {
class Launcher {
 public:
  typedef struct Param {
    Module::Launcher::Param launcher;
    Device::Cap::Param cap{};
  } Param;

  Component::CMD cmd_;

  Device::Referee referee_;
  Device::Can can_;
  Device::Cap cap_;

  Module::Launcher launcher_;

  Launcher(Param& param, float control_freq)
      : cap_(param.cap), launcher_(param.launcher, control_freq) {}
};
}  // namespace Robot
