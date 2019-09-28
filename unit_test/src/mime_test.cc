#include <laplace/net/mime.hh>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace laplace::net;

TEST_CASE("MIME Unite Test", "[mime]") {
  REQUIRE(mime_type("www.example.com/index.html") == "text/html");
  REQUIRE(mime_type("www.example.com/index.htm") == "text/html");
  REQUIRE(mime_type("www.example.com/style.css") == "text/css");
  REQUIRE(mime_type("www.example.com/robots.txt") == "text/plain");
  REQUIRE(mime_type("www.example.com/index.js") == "application/javascript");
  REQUIRE(mime_type("www.example.com/test.json") == "application/json");
  REQUIRE(mime_type("www.example.com/rss.xml") == "application/xml");
  REQUIRE(mime_type("www.example.com/font.ttf") == "font/ttf");
  REQUIRE(mime_type("www.example.com/font.otf") == "font/otf");
  REQUIRE(mime_type("www.example.com/image.png") == "image/png");
  REQUIRE(mime_type("www.example.com/image.jpe") == "image/jpeg");
  REQUIRE(mime_type("www.example.com/image.jpeg") == "image/jpeg");
  REQUIRE(mime_type("www.example.com/image.jpg") == "image/jpeg");
  REQUIRE(mime_type("www.example.com/image.gif") == "image/gif");
  REQUIRE(mime_type("www.example.com/image.bmp") == "image/bmp");
  REQUIRE(mime_type("www.example.com/fav.ico") == "image/x-icon");
  REQUIRE(mime_type("www.example.com/image.tiff") == "image/tiff");
  REQUIRE(mime_type("www.example.com/image.tif") == "image/tiff");
  REQUIRE(mime_type("www.example.com/image.svg") == "image/svg+xml");
  REQUIRE(mime_type("www.example.com/image.svgz") == "image/svg+xml");
  REQUIRE(mime_type("www.example.com/image.webp") == "image/webp");
  REQUIRE(mime_type("www.example.com/sound.wav") == "audio/wav");
  REQUIRE(mime_type("www.example.com/sound.ogg") == "application/ogg");
  REQUIRE(mime_type("www.example.com/video.flv") == "video/x-flv");
  REQUIRE(mime_type("www.example.com/video.mp4") == "video/mp4");
  REQUIRE(mime_type("www.example.com/video.webm") == "video/webm");

  REQUIRE(mime_type("www.example.com/") == "application/text");
  REQUIRE(mime_type("www.example.com/api/foo") == "application/text");

  // Test using runtime string
  std::string rt_url = "www.example.com";
  rt_url += "/video.mp4"; // Appending target
  REQUIRE(mime_type(rt_url.c_str()) == "video/mp4");
  rt_url = "www.example.com/api/foo";
  REQUIRE(mime_type(rt_url.c_str()) == "application/text");
}
