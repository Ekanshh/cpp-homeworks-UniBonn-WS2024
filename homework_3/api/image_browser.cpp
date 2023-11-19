#include "image_browser.hpp"

#include "html_writer.hpp"

namespace image_browser {

void AddFullRow(const ImageRow& row, bool first_row) {
    html_writer::OpenRow();
    for (const auto& [image_path, score] : row) {
        html_writer::OpenColumn(first_row);
        html_writer::AddImage(image_path, score);
        html_writer::CloseColumn();
        first_row = false;
    }
    html_writer::CloseRow();
}

void CreateImageBrowser(const std::string& title,
                        const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    for (size_t i = 0; i < rows.size(); ++i) {
        AddFullRow(rows[i], i == 0);
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}
}  // namespace image_browser