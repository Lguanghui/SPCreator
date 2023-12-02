// Copyright (c) 2023, Guanghui Liang. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by Guanghui Liang on 2023/11/29.
//

#include "create_file.h"
#include <fstream>
#include <filesystem>
#include "error.h"

void CreateFile(const std::string& file_path, const std::string& content) {
    std::filesystem::path path(file_path);
    std::filesystem::path directory_path = path.parent_path();

    if (!directory_path.empty()) {
        if (!std::filesystem::exists(directory_path)) {
            std::filesystem::create_directories(directory_path);
        }
    }

    std::ofstream dest_file(file_path, std::ios::out | std::ios::trunc);
    dest_file << content;
    dest_file.close();
}

void CreateTemplateFile(ProgramOptions &options) {
    auto current_path = std::filesystem::current_path();
    auto xcworkspace_path = std::filesystem::current_path() / ".swiftpm/xcode/package.xcworkspace";
    auto xcshareddata_path = current_path / ".swiftpm/xcode/package.xcworkspace/xcshareddata";

    if (!std::filesystem::exists(xcworkspace_path)) {
        ExitWithError("path `.swiftpm/xcode/package.xcworkspace` does not exist!");
    }

    if (!std::filesystem::exists(xcshareddata_path)) {
        std::filesystem::create_directory(xcshareddata_path);
    }

    std::string template_content = ""
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
"<plist version=\"1.0\">\n"
"<dict>\n"
    "<key>FILEHEADER</key>\n"
    "<string>\n"
"//  ___FILENAME___\n"
"//  ___WORKSPACENAME___\n"
"//\n"
"//  Created by ___FULLUSERNAME___ on ___DATE___.\n"
"//  Copyright © ___YEAR___ __author__. All rights reserved.\n"
"//</string>\n"
    "<key>FILEBASENAMEASIDENTIFIER</key>\n"
    "<string>__file_prefix_____FILENAME:deletingPathExtension,identifier___</string>\n"
"</dict>\n"
"</plist>\n";
    template_content.replace(template_content.find("__author__"), sizeof("__author__") - 1, options.author_name);
    template_content.replace(template_content.find("__file_prefix__"), sizeof("__file_prefix__") - 1, options.class_prefix);

    auto template_file_path = xcshareddata_path / TEMPLATE_FILE_NAME;
    CreateFile(template_file_path.string(), template_content);
}