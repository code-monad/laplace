#include <laplace/net/uri.hh>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <chrono>
#include <iostream>
using namespace laplace;

TEST_CASE("URI Unit Test", "[uri]") {
  REQUIRE(net::symbol::basic_slash<char>() == '/');        // the slash
  REQUIRE(net::symbol::basic_slash<wchar_t>() == L'/');    // the wide slash
  REQUIRE(net::symbol::basic_at<char>() == '@');           // the @
  REQUIRE(net::symbol::basic_at<wchar_t>() == L'@');       // the wide @
  REQUIRE(net::symbol::basic_colon<char>() == ':');        // the colon
  REQUIRE(net::symbol::basic_colon<wchar_t>() == L':');    // the wide colon
  REQUIRE(net::symbol::basic_question<char>() == '?');     // the question
  REQUIRE(net::symbol::basic_question<wchar_t>() == L'?'); // the wide question
  REQUIRE(net::symbol::basic_hash<char>() == '#');         // the hash
  REQUIRE(net::symbol::basic_hash<wchar_t>() == L'#');     // the wide hash

  // Alias
  REQUIRE(net::symbol::slash == '/');
  REQUIRE(net::symbol::wslash == L'/');
  REQUIRE(net::symbol::at == '@');
  REQUIRE(net::symbol::wat == L'@');
  REQUIRE(net::symbol::colon == ':');
  REQUIRE(net::symbol::wcolon == L':');
  REQUIRE(net::symbol::question == '?');
  REQUIRE(net::symbol::wquestion == L'?');
  REQUIRE(net::symbol::hash == '#');
  REQUIRE(net::symbol::whash == L'#');

  REQUIRE(net::uri::basic_uri<char>().empty() == true); // default constructor must be empty
  REQUIRE(net::uri::basic_uri<char>(std::string_view("http://example.com/")).empty() == false);
  REQUIRE(net::uri::basic_uri<wchar_t>(std::wstring_view(L"http://example.com/")).empty() == false);

  // Parsing Test
  net::uri::uri http("http://example.com/api/v2/call?param=count&test=true#h1");
  net::uri::uri mail("mailto:me@example.com");
  REQUIRE(http.scheme() == "http");
  REQUIRE(mail.scheme() == "mailto");
  REQUIRE(http.host() == "example.com");
  REQUIRE(mail.auth() == "me");
  REQUIRE(mail.host() == "example.com");
  REQUIRE(http.target() == "/api/v2/call");
  REQUIRE(http.query() == "param=count&test=true");
  REQUIRE(http.fragment() == "h1");
  auto target_seq = http.target_seq();
  std::vector<std::string_view> cmp_seq = {"api", "v2", "call"};
  REQUIRE(std::equal(target_seq.begin(), target_seq.end(), cmp_seq.begin(), cmp_seq.end()));

  std::string request = "http:://me@example.com/api/v3/call?param=123#top";
  auto start = std::chrono::high_resolution_clock::now();
  auto uri = net::uri::parse(request);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  UNSCOPED_INFO("Parse " << request << " cost " << elapsed.count() << "ns.");
  CHECK(true);
}
