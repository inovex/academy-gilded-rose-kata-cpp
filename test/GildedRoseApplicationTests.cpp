#include "GildedRoseApplication.h"
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

const char *testFileName = "test.txt";
const char *goldenMasterFileName = "GoldenMaster.txt";

std::string ReadFile(const char *filePath)
{
  std::string fileContent(
      std::istreambuf_iterator<char>(std::ifstream(filePath).rdbuf()),
      std::istreambuf_iterator<char>());

  return fileContent;
}

TEST(GildedRoseApplicationTest,
     Run_ComparedToGoldenMaster_ShouldReturnSameValues)
{
  std::streambuf *defaultOutStream = std::cout.rdbuf();
  std::ofstream out(testFileName, std::ofstream::out | std::ofstream::trunc);
  std::cout.rdbuf(out.rdbuf());
  GildedRoseApplication app;

  app.Run();

  std::cout.rdbuf(defaultOutStream);
  std::string actualOutput = ReadFile(testFileName);
  std::string goldenMaster = ReadFile(goldenMasterFileName);
  ASSERT_TRUE(actualOutput == goldenMaster);
}