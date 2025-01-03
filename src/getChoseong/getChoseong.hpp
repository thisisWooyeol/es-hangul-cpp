#ifndef GET_CHOSEONG_HPP
#define GET_CHOSEONG_HPP

#include "constants.hpp"
#include <regex>
#include <sstream>
#include <string>

namespace EsHangul {
namespace GetChoseong {

/**
 * @brief 단어에서 초성을 추출합니다. (예: `사과` -> `'ㅅㄱ'`)
 *
 * @param word 초성을 추출할 단어
 * @return A `std::wstring` containing the extracted Choseong characters.
 *
 * @example
 * std::wstring result = getChoseong(L"사과"); // "ㅅㄱ"
 * std::wstring result = getChoseong(L"띄어 쓰기"); // "ㄸㅇ ㅆㄱ"
 */
std::wstring getChoseong(const std::wstring& word);

// intToWideHexString: Helper function to convert an integer to a hexadecimal string
inline const std::wstring intToWideHexString(int value)
{
    std::wostringstream woss;
    woss << std::hex << std::uppercase << value;
    return woss.str();
}

// EXTRACT_CHOSEOONG_REGEX: Remove all characters except Jaso Hangul Choseong, basic consonants
// (ㄱ-ㅎ), and whitespace
inline const std::wregex EXTRACT_CHOSEONG_REGEX =
    std::wregex(L"[^\\u" + intToWideHexString(JASO_HANGUL_NFD::START_CHOSEONG) + L"-\\u" +
                    intToWideHexString(JASO_HANGUL_NFD::END_CHOSEONG) + L"ㄱ-ㅎ\\s]+",
                std::regex_constants::ECMAScript | std::regex_constants::optimize);

// CHOOSE_NFD_CHOSEONG_REGEX: Match Jaso Hangul Choseong characters
inline const std::wregex CHOOSE_NFD_CHOSEONG_REGEX =
    std::wregex(L"[\\u" + intToWideHexString(JASO_HANGUL_NFD::START_CHOSEONG) + L"-\\u" +
                    intToWideHexString(JASO_HANGUL_NFD::END_CHOSEONG) + L"]",
                std::regex_constants::ECMAScript | std::regex_constants::optimize);

} // namespace GetChoseong
} // namespace EsHangul

#endif // GET_CHOSEONG_HPP
