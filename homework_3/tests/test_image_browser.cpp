// @file      test_image_browser.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "homework_3.h"
#include "trim.hpp"

using ::testing::HasSubstr;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStdout;
using trimming::trim;

namespace {
const std::string title = "Image Browser";
const std::string stylesheet = "style.css";

const image_browser::ScoredImage img1{"data/000000.png", 0.98};
const image_browser::ScoredImage img2{"data/000100.png", 0.96};
const image_browser::ScoredImage img3{"data/000200.png", 0.88};
const image_browser::ScoredImage img4{"data/000300.png", 0.87};
const image_browser::ScoredImage img5{"data/000400.png", 0.80};
const image_browser::ScoredImage img6{"data/000500.png", 0.79};
const image_browser::ScoredImage img7{"data/000600.png", 0.76};
const image_browser::ScoredImage img8{"data/000700.png", 0.75};
const image_browser::ScoredImage img9{"data/000800.png", 0.20};

const image_browser::ImageRow triad_1{img1, img2, img3};
const image_browser::ImageRow triad_2{img4, img5, img6};
const image_browser::ImageRow triad_3{img7, img8, img9};
}  // namespace

TEST(TestImageBrowser, AddFirstFullRow) {
    CaptureStdout();
    image_browser::AddFullRow(triad_1, true);

    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="row">)"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr(R"(style="border: 5px solid green;)"));
    ASSERT_THAT(cout, HasSubstr("<h2>000000.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000000.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.98</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>000100.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000100.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.96</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>000200.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000200.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.88</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestImageBrowser, AddFullRow) {
    CaptureStdout();
    image_browser::AddFullRow(triad_1, false);

    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="row">)"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>000000.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000000.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.98</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>000100.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000100.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.96</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>000200.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/000200.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.88</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestImageBrowser, CreateImageBrowser) {
    CaptureStdout();
    image_browser::CreateImageBrowser(title, stylesheet, {triad_1, triad_2, triad_3});

    std::string cout = GetCapturedStdout();
    std::ifstream html_example("../tests/example.html");
    std::string line;
    while (std::getline(html_example, line)) {
        ASSERT_THAT(cout, HasSubstr(trim(line)));
    }
    html_example.close();
}
