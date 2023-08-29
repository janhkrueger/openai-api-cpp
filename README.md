# openai-api-cpp



## Introduction

A short demo how to use the OpenAI api via a C++ program based on [olrea/openai-cpp](https://github.com/olrea/openai-cpp)

Also included [nlohmann/json](https://github.com/nlohmann/json) as dependency for openai-cpp.

For reading the config value, [jbeder/yaml-cpp](https://github.com/jbeder/yaml-cpp) is used.

The entire project can be build and run inside Visual Studio Code and the shipped dev container.


## Adjust the config file

The shipped config file consists of:

```yaml
openai:
  model: davinci-002
  prompt: Say this is a test.
  max_tokens: 9
  temperature: 0
loglevel:
  level: info
```

Feel free to adjust the model and the prompt regarding the desired question send to openai.

It is only intended to act as a sample, not as a production ready application.

## Compile the application

```bash
make -f build/makefile
```

## Set the environment variable with the openai token

```bash
export OPENAI_API_KEY='sk-abcdefghijklmnopqrstuvwxyz1234567890'
```

## Run the application
Then you can run the application with

```bash
bin/main
```

## Sample Prompt and Response

In the folder **samples** there are the sample json send to openai and the response.

## Project status

Finished. It is only there to demonstrate the usage.