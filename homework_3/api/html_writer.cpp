#include "html_writer.hpp"

#include <fmt/core.h>

#include <filesystem>
#include <iostream>

namespace html_writer {

void OpenDocument() {
    fmt::print("<!DOCTYPE html>");
    fmt::print("<html>");
}  // namespace )

void CloseDocument() { fmt::print("</html>"); }

void AddCSSStyle(const std::string &stylesheet) {
    fmt::print("<head>");
    fmt::print(R"(<link rel="stylesheet" type="text/css" href="{}">)", stylesheet);
    fmt::print("</head>");
}

void AddTitle(const std::string &title) { fmt::print("<title>{}</title>", title); }

void OpenBody() { fmt::print("<body>"); }

void CloseBody() { fmt::print("</body>"); }

void OpenRow() { fmt::print(R"(<div class="row">)"); }

void CloseRow() { fmt::print("</div>"); }

void OpenColumn(bool highlight) {
    if (highlight) {
        fmt::print(R"(<div class="column" style="border: 5px solid green;">)");
    } else {
        fmt::print(R"(<div class="column">)");
    }
}

void CloseColumn() { fmt::print("</div>"); }

void AddImage(const std::string &img_path, float score, bool highlight) {
    std::filesystem::path full_path(img_path);
    std::string filename = full_path.filename().string();
    std::string extension = full_path.extension().string();

    if (extension != ".png" && extension != ".jpg") {
        fmt::print(std::cerr, "File {} is not a valid image file", filename);
        return;
    }

    if (score < 0.0 || score > 1.0) {
        fmt::print(std::cerr, "Score {} is not in the range [0.0, 1.0]", score);
        return;
    }

    OpenColumn(highlight);
    fmt::print("<h2>{}</h2>", filename);
    fmt::print(R"(<img src="{}" />)", img_path);
    fmt::print(R"(<p>score = {:.2f}</p>)", score);
    CloseColumn();
}
}  // namespace html_writer