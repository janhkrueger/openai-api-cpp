/* Copyright 2018 Jan H. Krüger */
#include <unistd.h>
#include <stdlib.h>     /* atoi */
#include "openai.hpp"
#include <yaml-cpp/yaml.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"

using json = nlohmann::json;

int main() {

  const std::string scriptName = "main";
  auto logger = spdlog::rotating_logger_mt(scriptName,
                "/workspace/log/batch.log",
                1048576 * 5, 3);
  logger->flush_on(spdlog::level::info);
  logger->info("Started");

  const std::string konfigDatei = "/workspace/configs/openai-cpp.yaml";
  YAML::Node config = YAML::LoadFile(konfigDatei);

  // Read the parameters from the config file
  logger->debug("  Read parameters");
  std::string apikey;
  json jQuestion;
  if(config["openai"] && config["openai"]["prompt"] ) {
    jQuestion["model"] = config["openai"]["model"].as<std::string>();
    jQuestion["prompt"] = config["openai"]["prompt"].as<std::string>();
    jQuestion["max_tokens"] = config["openai"]["max_tokens"].as<int>();
    jQuestion["temperature"] = config["openai"]["temperature"].as<int>();
    apikey = config["openai"]["apikey"].as<std::string>();
    logger->info(" Prompt: " + config["openai"]["prompt"].as<std::string>());
  }
  else {
    logger->info("Config parameters not found");
    return 2;
  }

  logger->debug("  Send to OpenAI");
  openai::start(apikey);


  // Send the question to OpenAI and store the response
  auto completion = openai::completion().create(jQuestion);

  // Parse JSON data
  logger->debug("  Parse Response");
  json j = json::parse(completion.dump(2));

  // Access the "text" attribute
  std::string text = j["choices"][0]["text"];

  // Output the value and log it
  logger->debug("  Logging Response");
  logger->info("Response: " + text);

  logger->info("Endet");

  return 0;
}
