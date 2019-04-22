#include "gtest/gtest.h"

#include "WordExtractor.h"

using namespace Go::GoTextProtocol::Util;

namespace {

TEST(SkipCharacter, printable) {
  for (char character = '!'; character < 127; ++character) {
    EXPECT_FALSE(skip_character(character));
  }
}

TEST(SkipCharacter, nonprintable) {
  for (char character = 0; character <= ' '; ++character) {
    EXPECT_TRUE(skip_character(character));
  }
  EXPECT_TRUE(skip_character(127));
}

class WordExtractorTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {
    EXPECT_EQ("", std::string{mExtractor.nextWord().data()});
    EXPECT_EQ("", std::string{mExtractor.nextWord().data()});
    EXPECT_EQ("", std::string{mExtractor.nextWord().data()});
  }

  WordExtractor mExtractor;
};

TEST_F(WordExtractorTest, Empty) {
  mExtractor = WordExtractor{""};
  EXPECT_EQ("", std::string{mExtractor.nextWord().data()});
}

TEST_F(WordExtractorTest, EmptyConstructor) {
  mExtractor = WordExtractor{};

  EXPECT_EQ("", std::string{mExtractor.nextWord().data()});
}

TEST_F(WordExtractorTest, singleWord) {
  std::string expected;

  for (int i = '!'; i < '!' + maxWordLength(); ++i) {
    expected.push_back(i);
  }
  mExtractor = WordExtractor{expected};

  EXPECT_EQ(expected, std::string{mExtractor.nextWord().data()});
}

TEST_F(WordExtractorTest, multipleWords) {
  std::string expected1;
  std::string expected2;
  std::string expected3;

  std::vector<std::string> wordlist;

  size_t break_counter = 0;
  std::string word;
  for (char i = '!'; i < 127; ++i) {
    word.push_back(i);

    ++break_counter;
    if (break_counter >= maxWordLength()) {
      wordlist.push_back(word);
      word = std::string{};
      break_counter = 0;
    }
  }

  std::string input;
  for (auto &val : wordlist) {
    input.append(val + " ");
  }

  mExtractor = WordExtractor{input};

  for (auto &val : wordlist) {
    EXPECT_EQ(val, std::string{mExtractor.nextWord().data()});
  }
}

} // namespace