// My name is Caroline Cullen and this is Raytracer: Reloaded.
#include <cstdlib>
#include <iostream>
// I love the name of this CLI parser, Lyra is a BA in HDM.
#include "lyra/lyra.hpp"

int main(int argc, const char **argv) {
  // Values from the command line parser.
  // Big shout out to the people who make CLI parsers.
  int heightInPixels = 430;
  int widthInPixels = 575;
  std::string nameForImage = "reloaded.png";
  std::string povFile;

  // Required for Lyra to provide help.
  bool show_help = false;

  auto cli = lyra::cli_parser() | lyra::help(show_help) |
             lyra::opt(heightInPixels, "height")["-h"]["--height"](
                 "Height in pixels! (Default to 430 pixels)") |
             lyra::opt(widthInPixels, "width")["-w"]["--width"](
                 "Width in pixels! (Default to 575 pixels)") |
             lyra::opt(nameForImage, "name")["-n"]["--name"](
                 "Name the beautiful image that will bring light and color to "
                 "your life. (Default to reloaded.png)") |
             lyra::opt(povFile, "pov")["-p"]["--pov"](
                 "The .pov file to generate the image.");

  auto result = cli.parse({argc, argv});
  if (!result) {
    std::cerr << "Error in command line: " << result.errorMessage()
              << std::endl;
    return 1;
  }

  // Someone asked for help and now we gon give it to em.
  if (show_help) {
    std::cout << cli << "\n";
    return 0;
  }

  return 0;
}