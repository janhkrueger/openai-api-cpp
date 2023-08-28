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
#include "openai.hpp"


int main() {
  const std::string scriptName = "main";
  const std::string konfigDatei = "/workspace/configs/openai-cpp.yaml";

  auto logger = spdlog::rotating_logger_mt(scriptName,
                "/workspace/log/batch.log",
                1048576 * 5, 3);
  logger->flush_on(spdlog::level::info);
  logger->info(scriptName + " started");

    openai::start(); // Will use the api key provided by `OPENAI_API_KEY` environment variable
    // openai::start("your_API_key", "optional_organization"); // Or you can handle it yourself

    auto completion = openai::completion().create(R"({
        "model": "davinci-002",
        "prompt": "Say this is a test",
        "max_tokens": 7,
        "temperature": 0
    })"_json); // Using user-defined (raw) string literals
    std::cout << "Response is:\n" << completion.dump(2) << '\n';



  logger->info(scriptName + " endet");

  return 0;
}
