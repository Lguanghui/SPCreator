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

#ifndef SPCREATOR_CREATE_FILE_H
#define SPCREATOR_CREATE_FILE_H

#include <string>
#include "options_parse.h"

#define TEMPLATE_FILE_NAME "IDETemplateMacros.plist"

/**
 * create a file with specific file path and file content.
 * @param file_path 文件路径
 * @param content 文件内容
 */
void CreateFile(const std::string& file_path, const std::string& content);

/**
 * create `IDETemplateMacros.plist` file in `.swiftpm`
 */
void CreateTemplateFile(ProgramOptions &options);

#endif //SPCREATOR_CREATE_FILE_H
