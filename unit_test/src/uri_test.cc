#include <laplace/net/uri.hh>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <iostream>
using namespace laplace;

TEST_CASE("URI Unite Test", "[uri]") {
  REQUIRE(net::symbol::basic_slash<char>() == '/');        // the slash
  REQUIRE(net::symbol::basic_slash<wchar_t>() == L'/');    // the wide slash
  REQUIRE(net::symbol::basic_colon<char>() == ':');        // the colon
  REQUIRE(net::symbol::basic_colon<wchar_t>() == L':');    // the wide colon
  REQUIRE(net::symbol::basic_question<char>() == '?');     // the question
  REQUIRE(net::symbol::basic_question<wchar_t>() == L'?'); // the wide question
  REQUIRE(net::symbol::basic_hash<char>() == '#');         // the hash
  REQUIRE(net::symbol::basic_hash<wchar_t>() == L'#');     // the wide hash

  // Alias
  REQUIRE(net::symbol::slash == '/');
  REQUIRE(net::symbol::wslash == L'/');
  REQUIRE(net::symbol::colon == ':');
  REQUIRE(net::symbol::wcolon == L':');
  REQUIRE(net::symbol::question == '?');
  REQUIRE(net::symbol::wquestion == L'?');
  REQUIRE(net::symbol::hash == '#');
  REQUIRE(net::symbol::whash == L'#');

  REQUIRE(net::uri::basic_uri<char>().empty() == true); // default constructor must be empty
  REQUIRE(net::uri::basic_uri<char>(std::string_view("http://example.com/")).empty() == false);
  REQUIRE(net::uri::basic_uri<wchar_t>(std::wstring_view(L"http://example.com/")).empty() == false);
}
