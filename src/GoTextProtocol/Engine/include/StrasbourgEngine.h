#ifndef GTPSTRASBOURGENGINE_H
#define GTPSTRASBOURGENGINE_H

#include <string_view>

namespace Go::GoTextProtocol::Engine {
class StrasbourgEngine {
public:
  auto run(std::string_view view) noexcept -> std::string;
};

} // namespace Go::GoTextProtocol::Engine

#endif // GTPSTRASBOURGENGINE_H
