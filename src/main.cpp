/* Copyright 2018 Jan H. Krüger */
#include <unistd.h>
#include <stdlib.h>     /* atoi */
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <map>
#include <vector>


int main() {
  const std::string scriptName = "main";
  const std::string konfigDatei = "/workspace/configs/openai-cpp.yaml";

  auto logger = spdlog::rotating_logger_mt(scriptName,
                "/workspace/log/batch.log",
                1048576 * 5, 3);
  logger->flush_on(spdlog::level::info);
  logger->info(scriptName + " started");
  logger->info(scriptName + " endet");

  return 0;
}
