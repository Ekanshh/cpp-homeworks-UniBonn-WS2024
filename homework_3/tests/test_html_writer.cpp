// @file      test_html_writer.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#include <gmock/gmock-matchers.h>
#include <gtest/gtest-death-test.h>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include <string>

#include "homework_3.h"

using ::testing::HasSubstr;
using ::testing::Not;
using ::testing::internal::CaptureStderr;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStderr;
using ::testing::internal::GetCapturedStdout;

TEST(TestHTMLWriter, OpenCloseDocument) {
    CaptureStdout();
    html_writer::OpenDocument();
    html_writer::CloseDocument();
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr("<!DOCTYPE html>"));
    ASSERT_THAT(cout, HasSubstr("<html>"));
    ASSERT_THAT(cout, HasSubstr("</html>"));
}

TEST(TestHTMLWriter, OpenCloseBody) {
    CaptureStdout();
    html_writer::OpenBody();
    html_writer::CloseBody();
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr("<body>"));
    ASSERT_THAT(cout, HasSubstr("</body>"));
}

TEST(TestHTMLWriter, OpenCloseRow) {
    CaptureStdout();
    html_writer::OpenRow();
    html_writer::CloseRow();
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="row">)"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestHTMLWriter, AddTitle) {
    CaptureStdout();
    html_writer::AddTitle("TEST_TITLE");
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr("TEST_TITLE"));
    ASSERT_THAT(cout, HasSubstr("<title>TEST_TITLE</title>"));
}

TEST(TestHTMLWriter, AddCSSStyle) {
    CaptureStdout();
    html_writer::AddCSSStyle("test_stylesheet.css");
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr("<head>"));
    ASSERT_THAT(cout, HasSubstr("test_stylesheet.css"));
    ASSERT_THAT(cout, HasSubstr(R"(<link rel="stylesheet")"));
    ASSERT_THAT(cout, HasSubstr(R"(type="text/css")"));
    ASSERT_THAT(cout, HasSubstr(R"(href="test_stylesheet.css")"));
    ASSERT_THAT(cout, HasSubstr("</head>"));
}

TEST(TestHTMLWriter, AddImageSimple) {
    CaptureStdout();
    html_writer::AddImage("data/filename.png", 0.0, false);
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>filename.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/filename.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.00</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestHTMLWriter, AddImageFirstImage) {
    CaptureStdout();
    html_writer::AddImage("data/filename.png", 0.0, true);
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr(R"(style="border: 5px solid green;)"));
    ASSERT_THAT(cout, HasSubstr("<h2>filename.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/filename.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.00</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestHTMLWriter, AddImageTestScoreFormat) {
    CaptureStdout();
    const float kScore = 0.12345;
    html_writer::AddImage("data/filename.png", kScore, true);
    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, HasSubstr(R"(<div class="column")"));
    ASSERT_THAT(cout, HasSubstr("<h2>filename.png</h2>"));
    ASSERT_THAT(cout, HasSubstr(R"(<img src="data/filename.png")"));
    ASSERT_THAT(cout, HasSubstr("<p>score = 0.12</p>"));
    ASSERT_THAT(cout, HasSubstr("</div>"));
}

TEST(TestHTMLWriter, AddImageTestScoreBounds) {
    CaptureStdout();
    CaptureStderr();
    const float kScore = 1.5;
    html_writer::AddImage("data/filename.png", kScore, true);

    std::string cerr = GetCapturedStderr();
    ASSERT_THAT(cerr, HasSubstr("ERROR"));

    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, Not(HasSubstr(R"(<div class="column")")));
    ASSERT_THAT(cout, Not(HasSubstr("<h2>filename.png</h2>")));
    ASSERT_THAT(cout, Not(HasSubstr(R"(<img src="data/filename.png")")));
    ASSERT_THAT(cout, Not(HasSubstr("<p>score = 0.12</p>")));
    ASSERT_THAT(cout, Not(HasSubstr("</div>")));
}

TEST(TestHTMLWriter, AddImageTestExtensionTypes) {
    CaptureStdout();
    CaptureStderr();

    html_writer::AddImage("data/filename.txt", 0.00, false);

    std::string cerr = GetCapturedStderr();
    ASSERT_THAT(cerr, HasSubstr("ERROR"));

    std::string cout = GetCapturedStdout();
    ASSERT_THAT(cout, Not(HasSubstr(R"(<div class="column")")));
    ASSERT_THAT(cout, Not(HasSubstr("<h2>filename.png</h2>")));
    ASSERT_THAT(cout, Not(HasSubstr(R"(<img src="data/filename.png")")));
    ASSERT_THAT(cout, Not(HasSubstr("<p>score = 0.12</p>")));
    ASSERT_THAT(cout, Not(HasSubstr("</div>")));
}
