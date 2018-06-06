#include <gtest/gtest.h>
#include <ArabicToRoman.h>

TEST(ArabicToRomanTest, CheckIf12equalsXII)
{
    EXPECT_EQ("XII", ArabicToRoman(12));
}

TEST(ArabicToRomanTest, CheckIf667equalsDCLXVII)
{
    EXPECT_EQ("DCLXVII", ArabicToRoman(667));
}

TEST(ArabicToRomanTest, CheckIfMinus1ThrowsInvalidArg)
{
    EXPECT_THROW(ArabicToRoman(-1),std::invalid_argument);
}

TEST(RomanToArabicTest, CheckIfXIIIequals13)
{
    EXPECT_EQ(13,RomanToARrabic("XIII"));
}

TEST(RomanToArabicTest, CheckIfDCLXVIIequals667)
{
    EXPECT_EQ(667,RomanToARrabic("DCLXVII"));
}

TEST(RomanToArabicTest, CheckIfThrowsInvalidArgumentNonExistentCharacters)
{
    EXPECT_THROW(RomanToARrabic("ABC"), std::invalid_argument);
}

TEST(RomanToArabicTest, CheckIfThrowsInvalidArgumentTooManySameCharacters)
{
    EXPECT_THROW(RomanToARrabic("XXXIIII"), std::invalid_argument);
}
