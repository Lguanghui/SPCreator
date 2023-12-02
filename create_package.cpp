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
// Created by Guanghui Liang on 2023/12/2.
//

#include "create_package.h"
#include "exec_command.h"
#include <filesystem>
#include <iostream>

void CreatePackage(ProgramOptions &options) {
    auto current_path = std::filesystem::current_path();

    if (options.package_name != current_path.filename().string()) {
        // create a directory
        current_path /= options.package_name;
        std::filesystem::create_directory(current_path);
    }

    // set current working directory
    std::filesystem::current_path(current_path);

    std::cout << Exec("swift package init") << std::endl;
    // open the package, so that `.swiftpm` can be created automatically.
    std::cout << Exec("open Package.swift") << std::endl;
}